#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define MAXN 100 + 5
#define INF 0x3f3f3f3f
const int MAXint = 2147483647;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
typedef pair<int, int> P;

bool eq(double x, double y) { return fabs(x - y) < eps; }
bool gt(double x, double y) { return x - y > eps; }
bool ls(double x, double y) { return y - x > eps; }
bool ge(double x, double y) { return x - y > -eps; }
bool le(double x, double y) { return y - x > -eps; }

struct Point {
    double x, y;
    Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    void input() { cin >> x >> y; }
    void output(int n = 2) {
        cout << fixed << setprecision(n) << x << " " << y << '\n';
    }
    double distance(const Point &p) { return hypot(x - p.x, y - p.y); }
    bool operator==(const Point &p) { return (eq(x, p.x) && eq(y, p.y)); }
    bool operator!=(const Point &p) { return !(*this == p); }
    bool operator<(const Point &p) {
        if (eq(x, p.x)) {
            return ls(y, p.y);
        }
        return ls(x, p.x);
    }
    double area(Point a, Point b) {
        return 0.5 *
               (x * a.y + a.x * b.y + y * b.x - b.x * a.y - a.x * y - x * b.y);
    }
};

struct Vec {
    double x, y;
    Vec(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    Vec(Point p) : x(p.x), y(p.y) {}
    Vec(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}
    void input() { cin >> x >> y; }
    void output() { cout << x << " " << y << '\n'; }
    double dot(const Vec &p) { return x * p.x + y * p.y; }
    double det(const Vec &p) { return x * p.y - y * p.x; }
    double len() { return hypot(x, y); }
    double len2() { return x * x + y * y; }
    double k() const {
        if (eq(x, 0)) return inf;
        return y / x;
    }
    Vec operator+(const Vec &p) { return Vec(x + p.x, y + p.y); }
    Vec operator-(const Vec &p) { return Vec(x - p.x, y - p.y); }
    Vec operator*(double k) { return Vec(x * k, y * k); }
    Vec operator/(double k) { return Vec(x / k, y / k); }
    bool operator==(const Vec &p) { return (eq(this->k(), p.k())); }
    bool operator!=(const Vec &p) { return !(*this == p); }
    Vec norm() {
        double l = len();
        x /= l, y /= l;
        return *this;
    }
};

struct Line {
    Point p;
    Vec v;
    Line(Point p, Vec v) : p(p), v(v) {}          
    Line(Point p, double k) : p(p), v(1, k) {}      
    Line(double k, double b) : p(0, b), v(1, k) {} 
    Line(Point p1, Point p2) : p(p1), v(p1, p2) {}  
    Line(double x1, double y1, double x2, double y2)
        : p(x1, y1), v(x2 - x1, y2 - y1) {}
    double find_y(double x) const {
        return p.y + (x - p.x) * v.y / v.x;
    }  // ����x��y
    double find_x(double y) const {
        return p.x - (y + p.y) * v.x / v.y;
    }                                               
    double a() const { return (*this).find_x(0); }  
    double b() const { return (*this).find_y(0); } 
    double k() const {                              
        if (eq(v.x, 0)) return inf;
        return v.y / v.x;
    }
    Vec vec() const { return v; }
    bool IsParallel(const Line &x) const {
        if (!eq(k(), x.k()))
            return false;
        else if (eq(k(), x.k()) && k() == inf) {
            if (eq(p.x, x.p.x)) return false;
            return true;
        } else {
            if (eq(b(), x.b())) return false;
            return true;
        }
    }
    bool IsCoincidence(const Line &x) const {
        if (!eq(k(), x.k()))
            return false;
        else if (eq(k(), x.k()) && k() == inf) {
            if (eq(p.x, x.p.x)) return true;
            return false;
        } else {
            if (eq(b(), x.b())) return true;
            return false;
        }
    }
    bool IsIntersect(const Line &x) const {
        if (!eq(k(), x.k())) return true;
        return false;
    }
    bool OnTheLine(const Point &x) const {
        Vec temp(p, x);
        if (temp == v) return true;
        return false;
    }
    Point Intersection(const Line &l) const {
        if (IsParallel(l) || IsCoincidence(l)) return Point(inf, inf);
        if (fabs(l.k()) == inf)
            return Point(l.p.x, find_y(l.p.x));
        else if (fabs(k() == inf))
            return Point(p.x, l.find_y(p.x));
        double x = (l.b() - b()) / (k() - l.k());
        return Point(x, find_y(x));
    }
};

double area(const vector<Point> &p) {
    double ans = 0;
    for (int i = 1; i < p.size() - 1; i++) {
        Vec a(p[0], p[i]), b(p[0], p[i + 1]);
        ans += (a.det(b));
    }
    return ans / 2;
}