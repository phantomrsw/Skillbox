#include <iostream>
#include <unordered_set>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(){}

MatrixGraph::MatrixGraph(IGraph *_oth){
#if DEBUG
    std::cout << "MatrixGraph::Constructor with args called " << this << "\n";
#endif
    int size = _oth->VerticesCount();
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        _oth->GetNextVertices(i,vec);
        for(auto &v : vec){
            MatrixGraph::AddEdge(i,v);
        }
        vec.clear();
    }
}

//MatrixGraph::MatrixGraph(const IGraph &copy): IGraph(copy){
MatrixGraph::MatrixGraph(IGraph &copy): IGraph(copy){
#if DEBUG
    std::cout << "MatrixGraph::Copy constructor called " << this << "\n";
#endif
    if(&copy != this) {
        MatrixGraph::copyFromListGraph(copy);
    }
}

//MatrixGraph& MatrixGraph::operator=(const IGraph& other){
MatrixGraph& MatrixGraph::operator=(IGraph& other){
#if DEBUG
    std::cout << "MatrixGraph::Operator= called " << this << std::endl;
#endif
    if(&other != this){
        MatrixGraph::copyFromListGraph(other);
#if DEBUG
        std::cout << "MatrixGraph::Type of copied object is " << other.getType()<< std::endl;
#endif
    }
    return *this;
}

/*MatrixGraph& MatrixGraph::operator& (){
    return *this;
};*/

void MatrixGraph::AddEdge(int from, int to){
    /*Resize matrix*/
    if(matrix.size() <= from){
        matrix.resize(from +  1);
        for(auto &s : matrix)
            s.resize(from + 1);
    }
    if(matrix.size() <= to){
        matrix.resize(to +  1);
        for(auto &s : matrix)
            s.resize(to + 1);
    }

    /*Check for unidirectional*/
    if(matrix[to][from] == 0 && from != to) matrix[from][to] = 1;
#if DEBUG
    else std::cout << "MatrixGraph::Such an edge is unacceptable! Define another edge." << std::endl;
#endif
}

int MatrixGraph::VerticesCount() {
    std::unordered_set<int> set;
    for(auto & s : matrix)
        for(int i = 0; i < s.size(); i++)
            set.insert(i);
    return (int)set.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices){
    for(int i = 0; i < matrix[vertex].size(); i++){
        if(!matrix[vertex].empty())
            if(matrix[vertex][i] == 1)
                vertices.push_back(i);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices){
    for(int i = 0; i < matrix.size(); i++){
        if(!matrix[i].empty())
            if(matrix[i][vertex] == 1)
                vertices.push_back(i);
    }
}

void MatrixGraph::print(){
    std::cout << "=== Print matrix ===" << std::endl;
    for (auto &s : matrix){
        for(auto &c : s){
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

std::string MatrixGraph::getType(){
    return type;
}

void MatrixGraph::copyFromListGraph(IGraph& other){
    int size = other.VerticesCount();
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        other.GetNextVertices(i,vec);
        for(auto &v : vec){
            MatrixGraph::AddEdge(i,v);
        }
        vec.clear();
    }
}
