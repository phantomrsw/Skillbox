#ifndef CPP_MOD31_PW3_IGRAPH_H
#define CPP_MOD31_PW3_IGRAPH_H
#pragma once

#include <vector>

#define DEBUG 0

class IGraph {
public:
    virtual ~IGraph() {} ;
    IGraph() {};
    IGraph(IGraph *_oth) {};
    IGraph(const IGraph &copy){};

    /*Метод принимает вершины начала и конца ребра и добавляет ребро*/
    virtual void AddEdge(int from, int to) = 0;

    /* Метод должен считать текущее количество вершин*/
    virtual int VerticesCount() = 0;

    /*Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной*/
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) = 0;

    /*Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную*/
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) = 0;

    virtual void print() = 0;

    virtual std::string getType() = 0;


};

#endif //CPP_MOD31_PW3_IGRAPH_H
