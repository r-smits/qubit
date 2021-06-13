#pragma once
#include "quat.h"


class Orientation
{
public:
    Quat x;
    Quat y;
    Quat z;
    Quat o;

    Orientation() : x(Quat(0, 1, 0, 0, Color::rgb(1, 0, 0))), y(Quat(0, 0, 1, 0, Color::rgb(0, 1, 0))), z(Quat(0, 0, 0, 1, Color::rgb(0, 0, 1))), o(Quat()) {}

    Orientation(std::vector<Quat> _points)
    {
        if (_points.size() == 3)
        {
            x = _points[0];
            y = _points[1];
            z = _points[2];
            o = Quat();
        } else
        {
            this->x = Quat();
            this->y = Quat();
            this->z = Quat();
            this->o = Quat();
        }
    }

    Orientation(const Quat& _x, const Quat& _y, const Quat& _z) : x(_x), y(_y), z(_z) {}

    void rotateFrame(Quat const &axis, double theta)
    {
        x = x.rotate(axis, theta);
        y = y.rotate(axis, theta);
        z = z.rotate(axis, theta);
    }

    void rotateFrame(const Quat &rotor)
    {
        x = x.rotate(rotor);
        y = y.rotate(rotor);
        z = z.rotate(rotor);
    }

    std::vector<Quat> getFrame()
    {
        std::vector<Quat> frame;
        frame.push_back(this->x);
        frame.push_back(this->y);
        frame.push_back(this->z);
        return frame;
    }
};


class Shape : public Orientation
{
private:
    std::string name;

public:
    std::vector<Quat> points;

public:
    Shape(const std::vector<Quat> &_points, std::string _name) : points(_points), name(_name) {}
    Shape(std::string _name) : name(_name) {}
    Shape(const Quat& _point, std::string _name) : name(_name)
    {
        points.push_back(_point);
    }
  
    std::vector<Quat> getPoints()
    {
        return points;
    }

    std::string getName() const
    {
        return name;
    }

    Shape& rotate(Quat const &axis, double theta)
    {
        rotateFrame(axis, theta);
        for (Quat &q : points)
        {
            q = q.rotate(axis, theta);
        }
        
        return *this;
    }

    Shape& rotate(const Quat &rotor)
    {
        rotateFrame(rotor);
        for (Quat &q : points)
            q = q.rotate(rotor);
        return *this;
    }

    Shape& rotateX(double theta) { return rotate(x, theta); }
    Shape& rotateY(double theta) { return rotate(y, theta); }
    Shape& rotateZ(double theta) { return rotate(z, theta); }

    void printFrame()
    {
        std::cout << "x:" << std::endl;
        x.print();
        std::cout <<"y:" << std::endl;
        y.print();
        std::cout << "z:" << std::endl;
        z.print();
    }
};


class World : public Orientation
{
private:
    std::vector<Shape> shapes;

public:
    World(Shape &shape) { shapes.push_back(shape); }
    World(std::vector<Shape> _shapes) : shapes(_shapes) {}

    void rotate(Quat &axis, double theta)
    {
        for (Shape& shape : shapes)
        {
            for (Quat &q : shape.getPoints())
            {
                q = q.rotate(axis, theta);
            }
        }
    }

    Shape& findShape(std::string _name)
    {
        for (Shape& shape : shapes)
            if (shape.getName() == _name) { return shape; }
        
        std::cout << "Could not find shape with name: " << _name << std::endl;
        return shapes[0];
    }

    void rotateX(double theta) { rotate(x, theta); }
    void rotateY(double theta) { rotate(y, theta); }
    void rotateZ(double theta) { rotate(z, theta); }
};


extern World defaultWorld;
