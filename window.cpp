#include "window.h"
// #include "lib/spdlog/spdlog.h"
// logger = spdlog::create("logger");


static std::unique_ptr<Window> window = std::make_unique<Window>(1000, 1000);
std::vector<Quat> quats;
Axis absAxis;
Axis relAxis;
Rad rad;
MoveStack movestack;
Color colors;
Rotations rotations;


Window::Window(int _width, int _height)  
{ 
    width = _width;
    height = _height;
    active = true;
}

void Window::start() const
{
    createWindow();
    startMainLoop();
}


void Window::createWindow() const
{
    int argc = 0;
    char* argv[1] = { (char*)"" };
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutCreateWindow("Qubit");
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
}


void Window::startMainLoop() const
{
    glutMainLoop();
}

void Window::exit() const
{
    glutDestroyWindow(glutGetWindow());
}

void Window::renderFrame() const
{
    glutSwapBuffers();
}


void Window::drawLine(Quat& a, Quat& b) const
{
    glBegin(GL_LINES);
    Color::rgb color = b.getColor();
    std::cout << "color values: " << color.r << " " << color.b << " " << color.g << std::endl;
    glColor3f(color.r, color.g, color.b);
    glVertex2d(a.i, a.j);
    glVertex2d(b.i, b.j);
    glEnd();
}


void Window::clearBuffer() const
{
    glClearColor(0, 0, 0, 0xFF / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void display()
{
    window->clearBuffer();
    customLoop();
    window->renderFrame();
}

void reshape(int width, int height)
{
    glutReshapeWindow(width, height);
}


void rotateAll(Quat &axis, double theta)
{
    for (int i = 0; i < quats.size(); i += 1)
    {
        quats[i] = quats[i].rotate(axis, theta);
    }
}


void drawLine(Quat &a, Quat &b)
{
    Color::rgb color = b.getColor();
    glBegin(GL_LINES);
    glColor3f(color.r, color.g, color.b);
    glVertex2d(a.i, a.j);
    glVertex2d(b.i, b.j);
    glEnd();
}


void customLoop()
{
    movestack.update();

    Shape shape = defaultWorld.findShape("frame");
    quats = shape.getFrame();



    Quat origin = Quat(0, 0, 0, 0);

    for (int i = 0; i < quats.size(); i ++)
    {
        drawLine(origin, quats[i]);
    }
}


void keyboard(unsigned char key, int x, int y)
{
    switch (glutGetModifiers()) 
    {
        case 0: 
            if ('a' <= key && key <= 'z') key -= 32;
            break;
    }

    Shape& frame = defaultWorld.findShape("frame");

    if (key == 'A')
        movestack.add(rotations.left(frame));

    if (key == 'D')
        movestack.add(rotations.right(frame));

    if (key == 'W')
        movestack.add(rotations.up(frame));

    if (key == 'S')
        movestack.add(rotations.down(frame));

    std::cout << "You pressed a key: " << key << std::endl;
    std::cout << "Code: " << (int)key << std::endl;
    if (key == 'a') { std::cout << "You just pressed the 'a' key down." << std::endl; }
}



void keyboardUp(unsigned char key, int x, int y)
{
    switch (glutGetModifiers()) 
    {
        case 0: 
            if ('a' <= key && key <= 'z') key -= 32;
            break;
    }
    
    std::cout << "You just let go of a key: " << key << std::endl;
    if (key == 'a') { std::cout << "You just let go of the 'a' key." << std::endl; }

};


void idle()
{
    glutPostRedisplay();
}




bool pressAkey(KeyPress &keyPressEvent)
{
    if (keyPressEvent.getKey() == 97)
    {
        std::cout << "Yes, the 'a' key was pressed." << std::endl;
        return true;
    }

    std::cout << "No, the 'a' key was not pressed." << std::endl;
    return false;
}

bool doSomethingElse(int x) { return false; }

void eventHandler(QubitEvent &event)
{
    if (event.getType() == anyButton)
    {
        KeyPress keypress = *(KeyPress*) &event;
        std::cout << "The key that was pressed: " << keypress.getKey() << std::endl;
    }
}



template<typename T>
void anyFunction(T arg)
{

}





bool crossProductTest1()
{
    // q cross -q should cancel eachother out.
    Quat crossQ = Quat(0, 1, 0, 0);
    Quat crossMinusQ = Quat(0, 1, 0, 0);
    Quat crossResult = crossMinusQ.cross(crossQ);

    std::cout << "cross product test 1" << std::endl;
    crossResult.print();
    std::cout << "---" << std::endl;
    return (crossResult.mag() == 0);
}

bool conjugateTest1()
{
    // qc * q == q.a^2 + q*q
    Quat q = Quat(0, 1, 0, 0);
    Quat qc = q.conj();
    
    Quat result = qc * q;
    std::cout << "conjugate test 1" << std::endl;
    result.print();
    std::cout << "---" << std::endl;
    return true;
}

Quat createRotor(double theta, Quat& n)
{
    n = n.unit();
    n.a = cos(theta / 2);
    n.i = n.i * sin(theta / 2);
    n.j = n.j * sin(theta / 2);
    n.k = n.k * sin(theta / 2);
    return n;
}


bool rotationOperatorTest1()
{
    //cos (theta) = q0
    //sin (theta) = ||q||

    Quat p = Quat(0, 1, 0, 0);
    Quat a = Quat(0, 0, 0, 1);
    Quat unitVector = a.unit();
    unitVector.print();

    Quat rotor = createRotor(rad.fromDegrees(90), a);
    
    //Quat rotor = Quat(cos(rad.fromDegrees(90)), a.i sin), sin(a.j), sin(a.k));
    
    Quat rotorc = rotor.conj();

    Quat result = rotor * p * rotorc;

    std::cout << "rotation operator test 1" << std::endl;
    std::cout << "the result of rotating 90 degrees around the z axis of a x coordinate:" << std::endl;
    result.print();
    return true;
}




int main(int argc, char *argv[])
{
    crossProductTest1();
    conjugateTest1();
    rotationOperatorTest1();
    
    Shape& shape = defaultWorld.findShape("frame");

    Quat xR = shape.x.unit().rotor(rad.fromDegrees(-90));
    Quat yR = shape.y.unit().rotor(rad.fromDegrees(-45));
    Quat xR2 = shape.x.unit().rotor(rad.fromDegrees(15));
    Quat rR = xR2 * yR * xR;

    shape.rotate(rR);
    window->start(); 
    
    return 0;

    
    // Quat xRotor = shape.x.unit().rotor(rad.fromDegrees(-75));
    // Quat combinedRotor = zRotor * xRotor;

    // std::cout << "---combinedRotor---" << std::endl;
    // combinedRotor.print();    
    // double theta = acos(combinedRotor.a) * 2;
    
    // // combinedRotor.i = combinedRotor.i / (theta);
    // // combinedRotor.j = combinedRotor.j / (theta);
    // // combinedRotor.k = combinedRotor.k / (theta);

    // combinedRotor.print();
    // combinedRotor.a = 0;

    return 0;

    KeyPress a = KeyPress('a');
    EventDelegate keypressDelegate = EventDelegate(a);
    keypressDelegate.delegate<KeyPress>(pressAkey);

    
    movestack = MoveStack();

    // Starting position
    // Demo of multiple axis interpolation! Very exciting stuff

    
    Shape rotated = shape;

    Quat zAxis = Quat(rad.fromDegrees(-45), 0, 0, 1).unit();
    Quat xAxis = Quat(rad.fromDegrees(-75), 1, 0, 0).unit();


    Quat newAxis = zAxis * xAxis;
    newAxis.print();
    std::cout << "Magnitude of this bad boy: " << newAxis.mag() << std::endl;
    newAxis = newAxis.unit();
    std::cout << "Magnitude of this bad boy: " << newAxis.mag() << std::endl;
    newAxis.print();

    std::cout << "Using angle: " <<rad.fromRad(newAxis.a) << std::endl;

    shape.printFrame();
    shape.rotate(newAxis, newAxis.a);
    shape.printFrame();

    std::cout << std::endl << std::endl;

    rotated.printFrame();
    rotated.rotate(Quat(0, 0, 0, 1), rad.fromDegrees(-45));
    rotated.rotate(Quat(0, 1, 0, 0), rad.fromDegrees(-75));
    rotated.printFrame();


    window->start();

    return 0;



    rotated.rotateX(rad.fromDegrees(-75));
    rotated.rotateZ(rad.fromDegrees(-45));

    //Rotating through some axis should be similar to

    Quat axis1 = shape.x * rotated.x;
    Quat axis2 = shape.y * rotated.y;
    Quat axis3 = shape.z * rotated.z;

    axis1.print();
    axis2.print();
    axis3.print();

    return 0;
    
    movestack.add(Movement(shape, rotated, 200, false));


    window->start();
    return 0;
}








void tests()
{
    // Quat tl = Quat(0, -0.5, 0.5, 0);
    // Quat tr = Quat(0, 0.5, 0.5, 0);
    // Quat br = Quat(0, 0.5, -0.5, 0);
    // Quat bl = Quat(0, -0.5, -0.5, 0);

    // tl.setColor(colors.green);
    // tr.setColor(colors.red);
    // br.setColor(colors.blue);
    // bl.setColor(colors.green);

    // square = Square(tl, tr, br, bl);



    // Quat a = Quat(0, 1, 0, 0);
    // Quat b = Quat(0, 0, 1, 0);

    // Quat perp = a * b;

    // std::cout << "Perendicular: " << std::endl;
    // perp.print();
    // perp.inv().print();


    // b = a.rotate(axis.z, rad.fromDegrees(45));
    // perp = a * b;
    // perp.print();


    // std::cout << "Axis to rotate around: " << std::endl;
    // perp.a = 0;
    // perp.unit().print();

    // a = Quat(0, 0, 1, 0);
    // b = Quat(0, 0, 0, 1);
    // perp = a * b;
    // std::cout << "Perendicular: " << std::endl;
    // perp.print();
    // perp.a = 0;
    // std::cout << "Axis to rotate around: " << std::endl;
    // perp.unit().print();

    //return 0;

    //rotateAll(quats, axis.x, rad.fromDegrees(-45));
    //rotateAll(quats, axis.z, rad.fromDegrees(45));
    
    // Quat w1 = Quat(0, 0, 0, 1);
    //Quat w2 = Quat(0, 0, 0, -1);

    // Quat w3 = w1.rotate(axis.y, rad.fromDegrees(-45));

    // std::cout << "rotated point" << std::endl;
    // w3.print();

    // Movement w = Movement(w1, w3, 150);

    // Quat customaxis = w.getAxis();
    // customaxis.setColor(colors.white);

    // quats.push_back(customaxis);
    
    // movestack = MoveStack(quats);
    // movestack.add(w);

    // Color::rgb color3 = movestack.quats[0].getColor();
    // std::cout << "color values: " << color3.r << " " << color3.b << " " << color3.g << std::endl;
}




