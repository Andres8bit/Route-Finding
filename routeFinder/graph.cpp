#include "graph.h"
Graph::Graph()
{

}
Graph::Graph(Graph& other){
    copy(*this,other);
}
Graph::~Graph()
{
    for(std::unordered_map<std::string,Node*>::iterator itr = map.begin(); itr != map.end(); itr++)
        delete itr->second;
    map.clear();
}
Graph::Graph(const std::vector<std::string> keys,std::vector<Node> values)
{
    for(unsigned int i = 0; i < keys.size();i++){
        Node* ptr = new Node(values.at(i));
        map[keys.at(i)] = ptr;
    }
}
void Graph::shortest_path(std::string source,std::string dest)
{
    Node* current = map[source];
    std::unordered_map<std::string,Node*> visited_set;
    heap<Node*>priority_queue;
    current->set_cost(0);

    while(current->get_id() != dest){
        sort_reachable_nodes(priority_queue,current,visited_set);
        visited_set[current->get_id()] = current;
        current = priority_queue.remove_min();
    }
    print_path(source,dest);
}
Graph::Graph(const std::vector<std::string> keys, const std::vector<Node *> values){
    fill(keys,values);
}
Graph& Graph::operator=(Graph other){
    swap(*this,other);
    return *this;
}
//setters:
void Graph::insert(Node& add){
    if(map.find(add.get_id()) != map.end())
        return;
    Node* ptr = new Node();
    ptr = &add;
    map.insert(std::pair<std::string,Node*>(add.get_id(),ptr));//creating a pair type to insert into map
}
void Graph::remove(const std::string& key){
    if(map.find(key) == map.end())
        return;
    map.erase(key);
}
//private:
void Graph::print_path(std::string source,std::string dest)
{
    Node* current;
    std::stack<std::string> list;
    unsigned int i;
    current = map.at(dest);
    std::cout<<"path from "<<source<<" to "<<dest<<": ";
    list.push(current->get_id());

    while( current->get_source() != "NULL"){
        list.push(current->get_source());
        current = map[current->get_source()];
    }

    i = list.size()-1;
    for(;i > 0;i--){
        std::cout<<list.top()<<"->";
        list.pop();
    }
    std::cout<<list.top()<<std::endl;
}
void Graph::fill(std::vector<std::string> keys, std::vector<Node *> values){
    for(unsigned int i = 0; i < keys.size();i++)
        map[keys.at(i)] = values.at(i);
}
void Graph::sort_reachable_nodes(heap<Node*>& priority_queue, Node* current,std::unordered_map<std::string,Node*>& visted_set){
    unsigned int N = current->route_count();
    heap<Node*> temp;
    Node* route;
    float cost;

    for(unsigned i = 0;i < N;i++){
        cost = current->get_cost();//reset our cost of travel for each route
        route = map[current->route(i)];
        if(visted_set.find(route->get_id())!= visted_set.end())continue;//skip route if in visited set
        cost += distance(*current,*route);
        if(cost < route->get_cost()){
            route->set_cost(cost);
            route->set_source(current->get_id());
            temp.insert(route);
        }
    }
    merge(temp,priority_queue);//combine temp heap of currents neighbors and the existing priority queue
}
//friends:
void swap(Graph x,Graph y){std::swap(x.map,y.map);}
void copy(const Graph &source,Graph& dest){dest.map = source.map;}
