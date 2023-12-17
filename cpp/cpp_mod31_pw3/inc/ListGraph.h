#ifndef CPP_MOD31_PW3_LISTGRAPH_H
#define CPP_MOD31_PW3_LISTGRAPH_H

#pragma once

#include <memory>
#include <vector>
#include "IGraph.h"

class ListGraph : public IGraph {
    std::vector<std::vector<int>> list;
    std::string type{"list"};
public:
    ListGraph();

    explicit ListGraph(IGraph *_oth);

    explicit ListGraph(IGraph &copy);

    ListGraph& operator=(IGraph& other);

    void AddEdge(int from, int to) override;

    int VerticesCount() override;

    void GetNextVertices(int vertex, std::vector<int> &vertices)override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices)override;

    void print() override;

    std::string getType() override;

private:

    void copyFromMatrixGraph(IGraph& other);
};

#endif //CPP_MOD31_PW3_LISTGRAPH_H
