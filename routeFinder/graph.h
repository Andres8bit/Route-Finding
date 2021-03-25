#ifndef GRAPH_H
#define GRAPH_H
#include<unordered_map>
#include<stack>
#include"node.h"
#include"heap.h"
class Graph{
public:
    Graph();
    Graph(Graph &other);
    Graph(const std::vector<std::string> keys, std::vector<Node> values);
    Graph(const std::vector<std::string> keys,const std::vector<Node*> values);
    Graph& operator=(Graph other);
    ~Graph();
    void shortest_path(std::string source, std::string dest);
    //setters:
    void insert(Node &add);
    void remove(const std::string &key);
    //friends:
    friend void swap(Graph x,Graph y);
    friend void copy(const Graph& source,Graph& dest);
private:
    std::unordered_map<std::string,Node*> map;
    void fill(std::vector<std::string> keys,std::vector<Node*> values);
    void sort_reachable_nodes(heap<Node*>& priority_queue, Node* current,
                          std::unordered_map<std::string,Node*>& visted_set);
    void print_path(std::string source, std::string dest);
};
#endif // GRAPH_H
