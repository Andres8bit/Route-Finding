#ifndef NODE_H
#define NODE_H
#include"point.h"
#include<iostream>
#include<vector>
#include<float.h>
class Node
{
public:
    Node();
    Node(point pos, std::string name);
    Node(point pos, std::string id, float weight);
    Node(const point& pos, const std::string& id, float weight, const std::vector<std::string> routes);
    Node(const Node& obj);
    Node& operator=(Node other);
    ~Node();
    //setters:
    void set_position(const point& pos){loc = pos;}
    void set_id(std::string val){id = val;}
    void set_source(std::string node){source = node;}
    void add_adj_node(std::string node);
    void set_adj_list(std::vector<std::string> node_ids){adj_list = node_ids;}
    void set_cost(const float val){cost = val;}
    //getters:
    std::string get_id()const{return id;}
    std::string get_source()const{return source;}
    std::vector<std::string> get_adj_nodes()const{return adj_list;}
    point get_position()const{return loc;}
    float get_cost()const{return cost;}
    unsigned int route_count()const{return adj_list.size();}
    std::string route(unsigned int i);
    //friends:
    friend float distance(Node& x,Node& y);
    friend bool operator==(const Node& x,const Node& y);
    friend bool operator!=(const Node& x,const Node& y);
    friend bool operator<(const Node& x,const Node& y);
    friend bool operator<=(const Node& x,const Node& y);
    friend bool operator>=(const Node& x,const Node& y);
    friend bool operator>(const Node& x,const Node& y);
    friend void swap(Node& x,Node& y);
    friend void print(Node obj);
   /// friend std::string route(size_t i,Node obj);
private:
point loc;
std::string id;
std::string source;//used to track path,source is the nearset possible node pointing to this node
std::vector<std::string> adj_list;//stored as strings to represent ids this  allows us to set up adj_list
                            //without needing to refrence an object until abs. needed
float cost;
void copy(const Node& obj);
void init(const point& pos = point(), const std::string& name = std::string(), float weight = float(), const std::vector<std::string> routes = std::vector<std::string>());
};
#endif // NODE_H
