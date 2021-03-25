#include "point.h"
point::point()
{
    x = y = 0;
}
point::point(const point& obj)
{
    copy(obj);
}
point::point(const float xVal,const float yVal){
    x = xVal;
    y = yVal;
}
point& point::operator=(point obj){
    swap(*this,obj);
    return *this;
}
//destructor:
point::~point()
{
    x = y = 0;
}
void point::copy(const point& obj)
{
    this->x = obj.xPos();
    this->y = obj.yPos();
}
//friends:
float distance(const point x,const point y)
{
    float xDist = x.x - y.x;
    float yDist = x.y - y.y;
    return sqrt(xDist* xDist + yDist * yDist);
}
bool operator==(const point x,const point y)
{
    return x.x == y.x && x.y == y.y;
}
bool operator!=(const point x,const point y)
{
    return x != y;
}
void swap(point& x, point& y)
{
 std::swap(x.x,y.x);
 std::swap(x.y,y.y);
}
std::ostream& operator<<(std::ostream& out,const point& obj)
{
    out<<"("<<obj.xPos()<<","<<obj.yPos()<<")";
    return out;
}
