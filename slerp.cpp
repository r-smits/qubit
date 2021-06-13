#include "slerp.h"


Slerp::Slerp(const Quat &start, const Quat &dest, double steps, bool longest)
{
    // https://www.cs.cmu.edu/~kiranb/animation/p245-shoemake.pdf
    if (start == dest)
    {
        this->dTheta = 0;
        this->axis = start;

        std::cout << "The axis to rotate around: " << std::endl;
        axis.print();
        std::cout << "Angle to be covered: " << dTheta * steps * (180 / M_PI) << std::endl;
        std::cout << "Actual dt: " << dTheta << std::endl;
        return;
    }

    Quat s = start;
    Quat d = dest;

    s = s.unit();
    d = d.unit();
    s.a = 0;
    d.a = 0;
    axis = s * d;

    double theta = acos(-axis.a);
    double tau = 2 * M_PI;
    theta = (longest) ? (theta >= 0) ? theta - tau : theta + tau : theta;
    std::cout << "shortest: " << acos(-axis.a) << " longest: " << theta << std::endl;
    
    this->dTheta = theta * (1/steps);
    this->axis = axis.unit();

    std::cout << "The axis to rotate around: " << std::endl;
    axis.print();
    std::cout << "Angle to be covered: " << dTheta * steps * (180 / M_PI) << std::endl;
    std::cout << "Actual dt: " << dTheta << std::endl;
}


// TODO: Check if it is possible to interpolate between two different objects if they have the same amount of points
// If they don't I need some kind of algorithm to create those extra points arbitrarily between the 'actual points' the object has.
Movement::Movement(const Shape& start, const Shape& end, double _steps, bool _longest)
{
    this->shapeName = start.getName();
    this->steps = _steps;
    this->done = false;

    Slerp slerpX = Slerp(start.x, end.x, steps, _longest);
    Slerp slerpY = Slerp(start.y, end.y, steps, _longest);
    Slerp slerpZ = Slerp(start.z, end.z, steps, _longest);

    slerps.push_back(slerpX);
    slerps.push_back(slerpY);
    slerps.push_back(slerpZ);
    
    for (int i = 0; i < start.points.size(); i += 1)
    {
        Slerp slerp = Slerp(start.points[i], end.points[i], _steps, _longest);
        this->slerps.push_back(slerp);
    }     
}


void Movement::next()
{
    if (this->steps == 0)
    {
        this->done = true;
        return;
    }

    Shape& shape = defaultWorld.findShape(this->shapeName);
    for (int i = 0; i < shape.points.size(); i += 1)
    {
        shape.points[i].print();
        shape.points[i] = shape.points[i].rotate(slerps[i+3].axis, slerps[i+3].dTheta);
        shape.points[i].print();
    }

    shape.x.print();

    std::cout << "some info" << std::endl;
    std::cout << slerps[0].dTheta << std::endl;
    slerps[0].axis.print();
    shape.x = shape.x.rotate(slerps[0].axis, slerps[0].dTheta);
    shape.y = shape.y.rotate(slerps[1].axis, slerps[1].dTheta);
    shape.z = shape.z.rotate(slerps[2].axis, slerps[2].dTheta);

    this->steps -= 1;
}


void MoveStack::update()
{

    for (int i = 0; i < movements.size(); i+=1)
    {
        if (movements[i].done)
        {
            std::cout << "erasing movement " << i << std::endl;
            movements.erase(movements.begin() + i);
        } 
        else
        {
            std::cout << "moving quats for movement " << i << std::endl;
            movements[i].next();

            // Concurrent mode // debug // TODO
            // Multiple movements remain in the stack and will follow the current movement
            break;
        }
    }
}

void MoveStack::add(const Movement &movement)
{
    movements.push_back(movement);
}


Movement Rotations::left(Shape shape)
{
    Shape start = shape;
    return Movement(start, shape.rotateZ(rad.fromDegrees(90)), 100, false);
}


Movement Rotations::right(Shape shape)
{
    Shape start = shape;
    return Movement(start, shape.rotateZ(rad.fromDegrees(-90)), 100, false);
}


Movement Rotations::up(Shape shape)
{
    Shape start = shape;
    return Movement(start, shape.rotateX(rad.fromDegrees(90)), 100, false);
}


Movement Rotations::down(Shape shape)
{
    Shape start = shape;
    return Movement(start, shape.rotateX(rad.fromDegrees(-90)), 100, false);
}
