#ifndef _PROGJOGOS_GEOMETRY_H_
#define _PROGJOGOS_GEOMETRY_H_

#include "Types.h"
#include <list>
using std::list;

enum GeometryTypes
{
    UNKNOWN_T,
    POINT_T,
    LINE_T,
    RECTANGLE_T,
    CIRCLE_T,
    POLYGON_T,
    MIXED_T
};

class Geometry
{
protected:
    float x, y;
    uint type;

public:
    Geometry();
    virtual ~Geometry();

    virtual float X() const
    { return x; }
    virtual float Y() const
    { return y; }
    virtual uint Type() const
    { return type; }
    virtual void Translate(float dx, float dy)
    { x += dx; y += dy; }
    virtual void MoveTo(float px, float py)
    { x = px; y = py; }
};

class Point : public Geometry
{
public:
    Point();
    Point(float posX, float posY);
    Point(int posX, int posY);

    float Distance(const Point & p) const;
};

class Line : public Geometry
{
public:
    Point a, b;

    Line();
    Line(float x1, float y1, float x2, float y2);
    Line(Point& pa, Point& pb);

    float Ax() const { return x + a.X(); }
    float Ay() const { return y + a.Y(); }
    float Bx() const { return x + b.X(); }
    float By() const { return y + b.Y(); }
};

class Rect : public Geometry
{
public:
    float left;
    float top;
    float right;
    float bottom;

    Rect();
    Rect(float x1, float y1, float x2, float y2);
    Rect(Point& a, Point& b);

    float Left() const   { return x + left; }
    float Top() const    { return y + top; }
    float Right() const  { return x + right; }
    float Bottom() const { return y + bottom; }
};

class Circle : public Geometry
{
public:
    float radius;

    Circle();
    Circle(float r);

    float CenterX() const { return x; }
    float CenterY() const { return y; }
};

class Poly : public Geometry
{
public:
    uint      vertexCount;
    Point*    vertexList;

    Poly();
    Poly(Point * vList, uint vCount);
    Poly(const Poly& p);
    ~Poly();

    const Poly& operator=(const Poly& p);
};

class Mixed : public Geometry
{
public:
    list<Geometry*> shapes;

    Mixed();
    ~Mixed();

    void Insert(Geometry * s);
    void Remove(Geometry * s);

    void Translate(float dx, float dy);
    void MoveTo(float px, float py);
};

#endif
