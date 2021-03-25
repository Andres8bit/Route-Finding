#ifndef AIRPORT_H
#define AIRPORT_H
#include<iostream>
#include<math.h>
#include<vector>
//#include"heap.h"
#include<float.h>

/*to do:
 * constructor with a set of routes
 * build map of airports where KEY = ID,PAIR = AirPort*
 * build map one airport at a time adding
 * build output functions<< for both airPort and Routes
*/

/*Side Note:
 * when finding the shortest path how are we going to remove routes from a visted set??
 * could use an external vector to store all nearest routes.
 * once we've visted each route we simply replace the route using the vector assignment
 * operator.This would make each path find stable.Meaning you wouldn't need to
 * reconstruct the entire struct.Simply pick and new source/dest and repeat
 * use remove route each time we get the nearest route.
 * if removeRoute iterates through an already sorted vector
 * then the nearest route will be the first route giving us O(1) time in removing
 * each nearest path.
 */

class AirPort{
public:
    enum AIRPORT_ERRORS{NO_ROUTES_FOUND};
    //inner route class:
    class route{
    private:
        AirPort* from;
        AirPort* dest;
        float weight;
        void copy(const route& other){
            this->dest = &other.getDestination();
            this->from = &other.getSource();
            this->weight = other.cost();
        }
    public:
        //constructors:
        route(AirPort* source = NULL,AirPort* destination = NULL){
            from = source;
            dest = destination;
            weight = FLT_MAX;
        }
        route(AirPort& source, AirPort& destination){
            dest = new AirPort;
            from =  new AirPort;
            dest = &destination;
            from = &source;
            weight = distance(source,destination);
        }
        route& operator=(route other){
            swap(*this,other);
            return *this;
        }
        route(const route& other){copy(other);}
        //destructor:
        ~route(){
            delete from;
            delete dest;
            weight = FLT_MAX;
        }
        //getters:
        AirPort& getSource()const{return *from;}
        AirPort& getDestination()const{ return *dest;}
        std::string sourceId()const{return from->getId();}
        std::string destinationId()const{return dest->getId();}
        float cost()const{return weight;}
        //setters:
        void setSource(AirPort &home){
            from = &home;
            weight = distance(*from,*dest);
        }
        void setDest(AirPort& destination){
            dest = &destination;
            weight = distance(*from,*dest);
        }
        //friends:
        friend
        bool operator ==(const route& x,const route& y){return x.cost() == y.cost();}
        friend
        bool operator !=(const route& x,const route& y){return !(x==y);}
        friend
        bool operator >(const route& x,const route& y){return x.cost() > y.cost();}
        friend
        bool operator >=(const route& x,const route& y){return x > y &&  x == y;}
        friend
        bool operator <(const route& x,const route& y){return x.cost() < y.cost();}
        friend
        bool operator <=(const route& x,const route& y){return x<y && x == y;}
        friend
        void swap(route& x, route& y){
            std::swap(x.weight,y.weight);
            std::swap(x.from,y.from);
            std::swap(x.dest,y.dest);
        }
        friend
        route min(const route& x,const route& y){
            if(x < y)return x;
            return y;
        }
        friend
        route max(const route& x,const route& y){
            if(min(x,y) == x)return y;
            return x;
        }
    };
    //Airport declaration:
    AirPort();
    ~AirPort();
    AirPort(const AirPort& other);
    AirPort& operator=(AirPort other);
    AirPort(const std::string& val,const float latitude,const float longitude);
    //setters:
    void setName(const std::string& val){ name = val;}
    void setLat (const float& val){lat = val;}
    void setLng(const float& val){lng = val;}
    void addRoute(AirPort &destination);
    //void removeRoute(const std::string id);
    void removeNearestRoute();
    //getters
    std::string getId()const{return name;}
    float getLat()const{return lat;}
    float getLng()const {return lng;}
    std::vector<route> getRoutes()const{return routes;}
    route getNearest(){
        if(routes.size())
        return routes.at(0);
        return route();
    }
    //friends:
    friend bool operator ==(AirPort& x,const AirPort& y);
    friend bool operator !=(AirPort& x,const AirPort& y);
    friend void swap(AirPort& x,AirPort& y);
    friend float distance(const AirPort& x,const AirPort& y);
private:
    std::string name;
    float lat;
    float lng;
    std::vector<route> routes;
    void copy(const AirPort& other);
    void SortRoutes();
};
#endif // AIRPORT_H
