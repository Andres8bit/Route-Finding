#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<math.h>
class point
{
public:
    point();
    point(const float xVal,const float yVal);
    point(const point& obj);
    point& operator=(point obj);
    ~point();
    //setters:
    void setX(const float val){x = val;}
    void setY(const float val){y = val;}
    //getters:
    float xPos()const{return x;}
    float yPos()const{return y;}
    //friends:
    friend float distance(const point x,const point y);
    friend bool operator==(const point x,const point y);
    friend bool operator!=(const point x,const point y);
    friend void swap(point& x, point& y);
    friend std::ostream& operator<<(std::ostream& out,const point& obj);
private:
    float x;
    float y;
    void copy(const point& obj);
};
#endif // POINT_H
