#include <iostream>
#include "MatrixGraph.h"
#include "ListGraph.h"

typedef struct{
    int from;
    int to;
} edge_t;

edge_t edges[]={{1,3},{1,7},{1,5},{2,4},{4,7},{3,5},{3,1},{0,6},{0,7},{7,5}};

void print_next_vertices(IGraph &g, int vertex);
void print_prev_vertices(IGraph &g, int vertex);
void copy_graph(IGraph &from, const std::string &dir);

int main() {

    /*MatrixGraph*/
    MatrixGraph m;
    for(auto &e : edges) m.AddEdge(e.from,e.to);
    print_next_vertices(m, 1);
    print_next_vertices(m, 6);
    print_prev_vertices(m, 5);
    print_prev_vertices(m, 2);
    std::cout << "Current number of vertices = " << m.VerticesCount() << std::endl;
    m.print();

    /*ListGraph*/
    ListGraph l;
    for(auto &e : edges) l.AddEdge(e.from,e.to);
    print_next_vertices(l, 1);
    print_next_vertices(l, 6);
    print_prev_vertices(l, 5);
    print_prev_vertices(l, 2);
    std::cout << "Current number of vertices = " << l.VerticesCount() << std::endl;
    l.print();

    /*Copy ListGraph to new MatrixGraph*/
    copy_graph(m, "l2m");

    /*Copy MatrixGraph to new MatrixGraph*/
    copy_graph(m, "m2m");

    /*Copy MatrixGraph to new ListGraph*/
    copy_graph(m, "m2l");

    /*Copy ListGraph to new ListGraph*/
    copy_graph(m, "l2l");


    MatrixGraph m4(l);
    m4.print();

    ListGraph l4(m);
    l4.print();

    IGraph *pm = &m;
    MatrixGraph m5(pm);
    m5.print();

    IGraph *pl = &l;
    ListGraph l5(pl);
    l5.print();

    return 0;
}

void print_next_vertices(IGraph &g, int vertex){
    std::vector<int> vec;
    std::cout << "Next vertices from vertex " << vertex << ": ";
    g.GetNextVertices(vertex, vec);
    if(vec.empty())
        std::cout << "Not found!";
    else
        for(auto & e : vec) std::cout << e << " ";
    std::cout << std::endl;
}

void print_prev_vertices(IGraph &g, int vertex){
    std::vector<int> vec;
    std::cout << "Previous vertices to vertex " << vertex << ": ";
    g.GetPrevVertices(vertex, vec);
    if(vec.empty())
        std::cout << "Not found!";
    else
        for(auto & e : vec) std::cout << e << " ";
    std::cout << std::endl;
}

void copy_graph(IGraph &from, const std::string &dir){
    MatrixGraph m;
    ListGraph l;
    if(dir == "m2m"){
        std::cout << "***********Copy MatrixGraph to new MatrixGraph***********" << std::endl;
    }
    else if(dir == "m2l"){
        std::cout << "*************Copy MatrixGraph to new ListGraph***********" << std::endl;
    }
    else if(dir == "l2l"){
        std::cout << "**************Copy ListGraph to new ListGraph************" << std::endl;
    }
    else if(dir == "l2m"){
        std::cout << "************Copy ListGraph to new MatrixGraph************" << std::endl;
    }

    if(dir[2] == 'm') {
        m = from;
        std::cout << "*****Print copy*****" << std::endl;
        m.print();
    }
    else if(dir[2] == 'l') {
        l = from;
        std::cout << "*****Print copy*****" << std::endl;
        l.print();
    }
}