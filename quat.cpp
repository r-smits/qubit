#include "quat.h"


Quat::Quat() : a(0), i(0), j(0), k(0), color(Color::rgb(1, 1, 1)) {}
Quat::Quat(const Quat& other) : a(other.a), i(other.i), j(other.j), k(other.k), color(other.color) {}
Quat::Quat(double _a, double _i, double _j, double _k) : a(_a), i(_i), j(_j), k(_k), color(Color::rgb(1, 1, 1)) {}
Quat::Quat(double _a, double _i, double _j, double _k, Color::rgb _color) :  a(_a), i(_i), j(_j), k(_k), color(_color) {};
Quat Quat::operator+(Quat &other) { return Quat(this->a + other.a, this->i + other.i, this->j + other.j, this->k + other.k, getColor()); }
Quat Quat::operator*(double num) { return Quat(this->a * num, this->i * num, this->j * num, this->k * num, getColor()); }
Quat Quat::operator/(double num) { return Quat(this->a / num, this->i / num, this->j / num, this->k / num, getColor()); }
bool operator==(const Quat &p, const Quat& q) { return (round(p.a) == round(q.a)) && (round(p.i) == round(q.i)) && (round(p.j) == round(q.j)) && (round(p.k) == round(q.k)); }
Quat Quat::unit() { return Quat(a, i / mag(), j / mag(), k / mag()); }
Quat Quat::conj() { return Quat(this->a, -this->i, -this->j, -this->k, getColor()); }
Quat Quat::inv() { return (conj() / mag() * mag()); }
Quat Quat::rnd() { return Quat(round(this->a), round(this->i), round(this->j), round(this->k), this->color); }
Quat Quat::rotor(double theta) { theta = theta / 2; return Quat(cosf(theta), i * sinf(theta), j * sinf(theta), k * sinf(theta)); }
double Quat::dot(Quat &other) const { return this->i * other.i + this->j * other.j + this->k * other.k; }

double Quat::mag() { return sqrtf(i*i + j*j + k*k); }
double Quat::mag2() { return sqrtf(a*a + i*i + j*j + k*k); }

double Quat::rad(Quat &p) { return asin((this->inv() * p).unit().mag()); }

void Quat::print() {  std::cout << "Quat | " << this->a << " + " << this->i << "i +" << this->j << "j + " << this->k << "k" << std::endl; }

Quat Quat::cross(Quat &p) { 
    return Quat(
        this->a,
        (this->j * p.k) - (p.j * this->k), 
        (this->k * p.i) - (p.k * this->i), 
        (this->i * p.j) - (p.i * this->j),
        this->getColor()
    ); 
}


Quat Quat::operator*(Quat &q)
{
    Quat p = *this;

    double p0q0 = p.a * q.a;
    double pdq = p.dot(q);
    
    Quat p0q = q * p.a;
    Quat q0p = p * q.a;
    Quat pcq = p.cross(q);

    Quat res = p0q + q0p + pcq;
    res.a = p0q0 - pdq;
    res.setColor(p.getColor());
    return res;
}


Quat Quat::rotate(const Quat &axis, double theta) const
{
    // source: http://graphics.stanford.edu/courses/cs348a-17-winter/Papers/quaternion.pdf
    Quat q = *this;
    Quat ax = axis;
    if (ax.rnd() == q.rnd()) return q;
    Quat a = q * cos(theta);
    Quat b = ax * (1 - cos(theta)) * ax.dot(q);    
    Quat c = ax.cross(q) * sin(theta);
    Quat r = a + b + c;
    r.setColor(q.getColor());
    return r;
}

Quat Quat::rotate(const Quat& rotor) const
{
    Quat p = *this;
    Quat r = rotor;
    Quat rc = r.conj();
    Quat res = r * p * rc;
    res.setColor(p.getColor());
    return res;
}

//You have points
//Keep track of these points;
//That's it.
//Seems to only work on a point by point basis.
Quat Quat::slerp(Quat &p, double dt)
{}
    // to get the angle
    //
    /*
    s -= 1;
    if (s <= 0) s = t;
 
    std::cout << "steps: " << this->s << std::endl;
    Quat q = this->inv();
    Quat axis = (p*q).unit();
    double dTheta = asin(this->mag()) * (1/s);
    std::cout << "Angle: " << dTheta * s * (180 / M_PI) << std::endl;
    Quat res = this->rotate(axis, dTheta);
    res.s = this->s;
    return res;
    */

// void Quat::slerp_init()
// {
//     steps = _steps;
//     dTheta = acos(start.dot(dest) / (start.mag() * dest.mag())) * (1/steps);
//     start = start.inv();
//     axis = (dest*start).unit();
//     done = false;

// }

Color::rgb Quat::getColor()
{
    return color;
}

void Quat::setColor(Color::rgb _color)
{
    color = _color;
}

Axis::Axis()
{
    x = Quat(0, 1, 0, 0).unit();
    y = Quat(0, 0, 1, 0).unit();
    z = Quat(0, 0, 0, 1).unit();
}


Rad::Rad() 
{
    tau = M_PI * 2;
    pi = M_PI;
    tangent = M_PI /2;
}


double Rad::fromDegrees(double degrees) {return pi / 180 * degrees; }
double Rad::fromRad(double rad) {return 180 / pi * rad; }

double round(double num) { return std::ceil(num * 100) / 100; }



