#ifndef NODE_H
#define NODE_H

#include <math.h>
#include <vector>

class Node
{
public:
    Node();
    Node(const double x, const double y, const double z);
    Node(const Node& node);
    Node(Node&& node);
    ~Node();

    Node& operator=(const Node& node);
    Node& operator=(Node&& node);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    void shift(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotateX(const double angle);
    void rotateY(const double angle);
    void rotateZ(const double angle);

private:
    double x;
    double y;
    double z;
};

class Point
{
private:
    double fx = 0;
    double fy = 0;
    double fz = 0;
    double x = 0;
    double y = 0;
    double z = 0;
public:
    Point();
    Point(int x, int y, int z);

    void set(int x, int y, int z);
    void setf(int x, int y, int z);

    double getx() {return this->x;}
    double gety() {return this->y;}
    double getz() {return this->z;}
    std::vector<double> get_coord();
    void reset();

    bool operator ==(Point &p2);
};

class PointConnection
{
private:
    std::shared_ptr<Point> p1;
    std::shared_ptr<Point> p2;
public:
    PointConnection() = delete;
    PointConnection(Point *_p1, Point *_p2);

    std::shared_ptr<Point> get_p1();
    std::shared_ptr<Point> get_p2();
};

#endif // NODE_H

