#include <iostream>
#include"airport.h"
#include"heap.h"
#include<time.h>
#include <ctime>
#include"node.h"
#include"graph.h"
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
    Node a(point(1,3),"A");
    Node b(point(2,4),"B");
    Node c(point(2,1),"C");
    Node d(point(3,3),"D");
    Node e(point(3,5),"E");
    Node f(point(5,4),"F");
    Node g(point(6,3),"G");
    Node h(point(7,4),"H");
    Node i(point(7,1),"I");
    vector<string>keys;
    vector<Node> node_list;
    //setting up a adj_list:
    a.add_adj_node(b.get_id());
    a.add_adj_node(c.get_id());
    a.add_adj_node(d.get_id());
    //a.add_adj_node(d.get_id());
   // print(a);
    //setting up b adj_list:
    b.add_adj_node(d.get_id());
    b.add_adj_node(e.get_id());
    //settig up c adj_list:
    c.add_adj_node(d.get_id());
    c.add_adj_node(g.get_id());
    c.add_adj_node(i.get_id());
    //setting up d adj_list:
    d.add_adj_node(g.get_id());
    //setting up e adj_list:
    e.add_adj_node(f.get_id());
    //setting up f adj_list:
    f.add_adj_node(h.get_id());
    f.add_adj_node(g.get_id());
    //setting up g adj_list:
    g.add_adj_node(h.get_id());
    g.add_adj_node(i.get_id());
    //setting up h adj_list:
    h.add_adj_node(i.get_id());

    //setting up node list:
    node_list.push_back(a);
    node_list.push_back(b);
    node_list.push_back(c);
    node_list.push_back(d);
    node_list.push_back(e);
    node_list.push_back(f);
    node_list.push_back(g);
    node_list.push_back(h);
    node_list.push_back(i);
    //setting up keys:
    keys.push_back("A");
    keys.push_back("B");
    keys.push_back("C");
    keys.push_back("D");
    keys.push_back("E");
    keys.push_back("F");
    keys.push_back("G");
    keys.push_back("H");
    keys.push_back("I");

    Graph map(keys,node_list);

    map.shortest_path("E","I");

    return 0;
}
