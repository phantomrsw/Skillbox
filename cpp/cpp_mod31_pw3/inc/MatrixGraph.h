#ifndef CPP_MOD31_PW3_MATRIXGRAPH_H
#define CPP_MOD31_PW3_MATRIXGRAPH_H

#pragma once

#include <memory>
#include <vector>
#include "IGraph.h"

class MatrixGraph : public IGraph {
    std::vector<std::vector<int>> matrix;
    std::string type{"matrix"};
public:
    MatrixGraph();

    explicit MatrixGraph(IGraph *_oth);

    //MatrixGraph(const IGraph &copy);
    explicit MatrixGraph(IGraph &copy);

    //MatrixGraph& operator=(const IGraph& other);
    MatrixGraph& operator=(IGraph& other);

    //MatrixGraph& operator&();

    void AddEdge(int from, int to) override;

    int VerticesCount() override;

    void GetNextVertices(int vertex, std::vector<int> &vertices)override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices)override;

    void print() override;

    std::string getType() override;

private:

    void copyFromListGraph(IGraph& other);
};

#endif //CPP_MOD31_PW3_MATRIXGRAPH_H
