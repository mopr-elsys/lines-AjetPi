#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001) {
    return abs(d2 - d1) < eps;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x;
    in >> p.y;
    
    return in;
}

struct Line {
    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {}

    Line(const Point& p1, const Point& p2) {
        A = p1.y - p2.y;
        B = p2.x - p1.x;
        C = -(A * p1.x + B * p1.y);
    }

    bool parallel(const Line& other) const {
    	if((A == 0 && other.A == 0) || (B == 0 && other.B == 0)) return true;
        return bool(((A / other.A) == (B / other.B)) && ((A / other.A) != (C / other.C)));
    }

    Line parallel(const Point& p) {
        return Line(A, B, -(A * p.x + B * p.y));
    }

    bool perpendicular(const Line& other) const {
        return bool((A * other.A) + (B * other.B) == 0);
    }

    Line perpendicular(const Point& p) {
        return Line(-B, A, B * p.x - A * p.y));
    }

    void print(ostream& out) const {
        out<< A << "x + "<< B<< "y + "<< C<< " = 0";
    }
};

ostream& operator<<(ostream& out, const Line& l) {
    l.print(out);
    return out;
}

istream& operator>>(istream& in, Line& l) {
    in >> l.A;
    in >> l.B;
    in >> l.C;
    
    return in;
}
