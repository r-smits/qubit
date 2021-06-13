#pragma once

#include <iostream>
#include <cmath>
#include <vector>

struct Color
{
    struct rgb
    {
        float r;
        float g;
        float b;

        rgb() { r = 1; g = 1; b = 1; }
        rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
    };

    rgb white;
    rgb black;
    rgb red;
    rgb green;
    rgb blue;

    Color() 
    {
        white = rgb();
        black = rgb(0, 0, 0);
        red = rgb(1, 0, 0);
        green = rgb(0, 1, 0);
        blue = rgb(0, 0, 1);
    }
};

struct Quat
{
    double a;
    double i;
    double j;
    double k;
    
    Color::rgb color;

    Quat();
    Quat(const Quat& other);
    Quat(double _a, double _i, double _j, double _k);
    Quat(double _a, double _i, double _j, double _k, Color::rgb _color);

    Quat unit();

    Quat operator+(Quat &other);
    Quat operator/(double num);
    Quat operator*(double num);
    Quat operator*(Quat &q);
    friend bool operator==(const Quat& p, const Quat& q);
    Quat inv();
    Quat conj();
    Quat cross(Quat &p);
    Quat slerp(Quat &p, double t);
    Quat rnd();
    Quat rotor(double angle);

    double dot(Quat &other) const;
    double rad(Quat &p);
    double mag();
    double mag2();

    Color::rgb getColor();
    void setColor(Color::rgb _color);

    void print();

    Quat rotate(const Quat &axis, double theta) const;
    Quat rotate(const Quat &rotor) const;
};


struct Axis
{
    Quat x;
    Quat y;
    Quat z;

    Axis();
};


struct Rad
{
    double tau;
    double pi;
    double tangent;

    Rad();

    double fromDegrees(double degrees);
    double fromRad(double rad);
};

double round(double num);
