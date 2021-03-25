#include "node.h"
Node::Node()
{
    loc = point();
    source = "NULL";
    id = "NULL";
    cost = FLT_MAX;

}
Node::Node(point pos,std::string name)
{
    loc = pos;
    id = name;
   source = "NULL";
    cost = FLT_MAX;
}
Node::Node(point pos,std::string name,float weight)
{
    loc = pos;
    id = name;
    source = "NULL";
    cost = weight;
}
Node::Node(const point& pos, const std::string& name, float weight, const std::vector<std::string> routes)
{
    loc = pos;
    id = name;
    adj_list = routes;
    cost =  weight;
   source = "NULL";
}
Node::Node(const Node& obj)
{
    copy(obj);
}
Node& Node::operator=(Node other)
{
    swap(*this,other);
    return *this;
}
Node::~Node()
{
    this->cost = 0;
    this->id = "NULL";
    this->loc = point();
    this->source = "NULL";
}
//setters:
void Node::add_adj_node(std::string node)
{
    adj_list.push_back(node);
}
//getters:
std::string Node::route(unsigned int i)

{
    if( i <  adj_list.size())
        return adj_list.at(i);
    return "NULL";
}
//private:
void Node::copy(const Node& obj)
{
    this->adj_list = obj.adj_list;
    this->cost = obj.cost;
    this->id = obj.id;
    this->loc = obj.loc;
    this->source = obj.source;
}
//friends:
float distance( Node& x, Node& y)
{
    return distance(x.loc,y.loc);
}
bool operator==(const Node& x,const Node& y)
{
    return x.cost == y.cost;
}
bool operator!=(const Node& x,const Node& y)
{
    return x.id != y.id;
}
bool operator<(const Node& x,const Node& y)
{
    return x.cost < y.cost;
}
bool operator<=(const Node& x,const Node& y)
{
    return x < y && x == y;
}
bool operator>=(const Node& x,const Node& y)
{
    return x > y && x == y;
}
bool operator>(const Node& x,const Node& y)
{
    return x.cost > y.cost;
}
void swap(Node& x,Node& y)
{
    std::swap(x.adj_list,y.adj_list);
    std::swap(x.cost,y.cost);
    std::swap(x.loc,y.loc);
   std::swap(x.source,y.source);
}
void print(Node obj)
{
    std::cout<<std::endl<<"==============================="<<std::endl;
    std::cout<<"Node:"<<obj.get_id()<<std::endl;
    std::cout<<"pos:"<<obj.loc;
    std::cout<<"Cost:"<<obj.cost<<std::endl;
    std::cout<<"source:"<<obj.get_source()<<std::endl;
    std::cout<<std::endl<<"adj_list:";
    for(unsigned int i = 0;i<obj.adj_list.size();i++){
        std::cout<<obj.adj_list.at(i)<<",";
    }
    std::cout<<std::endl<<"==============================="<<std::endl;
}
