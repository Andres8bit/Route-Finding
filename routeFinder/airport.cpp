#include "airport.h"
AirPort::AirPort(){
    name = "";
    lat = lng = 0;
    routes = std::vector<route>();
}
AirPort::~AirPort(){
    name = "";
    lat = lng = 0;
}
AirPort::AirPort(const AirPort& other){
    copy(other);
}
AirPort& AirPort::operator=(AirPort other){
    swap(*this,other);
    return *this;
}
AirPort::AirPort(const std::string& label,const float latitude,const float longitude){
    name = label;
    lat = latitude;
    lng = longitude;
}
void AirPort::addRoute(AirPort& destination){
    route tempRoute =  route(*this,destination);
    routes.push_back(tempRoute);
    SortRoutes();
}
void AirPort::removeNearestRoute(){
    if(routes.size())
        routes.erase(routes.end());
}
//private functions:
void AirPort::copy(const AirPort& other){
    name = other.getId();
    lat = other.getLat();
    lng = other.getLng();
    routes = other.getRoutes();
}
void AirPort::SortRoutes(){
    //heap<route> temp(routes);
    //routes = temp.sort();
}
//friends:
bool operator ==(const AirPort& x,const AirPort& y){
    return x.getId() == y.getId();
}
bool operator !=(const AirPort& x,const AirPort& y){
    return x.getId() != y.getId();
}
void swap(AirPort& x,AirPort& y){
    std::swap(x.name,y.name);
    std::swap(x.lat,y.lat);
    std::swap(x.lng,y.lng);
    //std::swap(x.routes,y.routes);
}
float distance(const AirPort& x,const AirPort& y){
    float latDist = x.lat - y.lat;
    float lngDist = x.lng - y.lng;

    return sqrtf(latDist*latDist + lngDist*lngDist);
}
