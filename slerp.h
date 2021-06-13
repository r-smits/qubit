#pragma once
#include "quat.h"
#include "world.h"


struct Slerp
{
public:
    Quat axis;
    double dTheta;
    Slerp(const Quat &start, const Quat &dest, double steps, bool longest);
};


struct Movement
{
private:
    std::vector<Slerp> slerps;
    std::string shapeName;
    double steps;

public:
    bool done;

public:
    Movement(const Shape& _start, const Shape& _end, double _steps, bool _longest);
    void next();
};


struct MoveStack
{
private:
    std::vector<Movement> movements;

public:
    MoveStack() {}
    void update();
    void add(const Movement &movement);
    void move();
    int size() { return movements.size(); }
};


struct Rotations
{
private:
    Rad rad;

public:
    Movement left(Shape shape);
    Movement right(Shape shape);
    Movement up(Shape shape);
    Movement down(Shape shape);
    Rotations() {};
};