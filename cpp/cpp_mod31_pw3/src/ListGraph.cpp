#include <iostream>
#include "ListGraph.h"
#include <unordered_set>

ListGraph::ListGraph(){}

ListGraph::ListGraph(IGraph *_oth){
#if DEBUG
    std::cout << "ListGraph::Constructor with args called " << this << "\n";
#endif
    int size = _oth->VerticesCount();
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        _oth->GetNextVertices(i,vec);
        for(auto &v : vec){
            ListGraph::AddEdge(i,v);
        }
        vec.clear();
    }
}

//ListGraph::ListGraph(const IGraph &copy): IGraph(copy){
ListGraph::ListGraph(IGraph &copy): IGraph(copy){
#if DEBUG
    std::cout << "ListGraph::Copy constructor called " << this << "\n";
#endif
    if(&copy != this) {
        ListGraph::copyFromMatrixGraph(copy);
    }
}

ListGraph& ListGraph::operator=(IGraph& other){
#if DEBUG
    std::cout << "ListGraph::Operator= called " << this << "\n";
#endif
    if(&other != this){
        ListGraph::copyFromMatrixGraph(other);
#if DEBUG
        std::cout << "ListGraph::Type of copied object is " << other.getType()<< std::endl;
#endif
    }
    return *this;
}

void ListGraph::AddEdge(int from, int to){
    if(list.size() <= from)
        list.resize(from + 1);

    if(list[from].empty())
        list[from].push_back(from);

    for(int i : list[from])
        if(i == to)
            return;

    list[from].push_back(to);
}

int ListGraph::VerticesCount() {
    std::unordered_set<int> set;
    for(auto &s : list){
        for(auto &e : s){
            set.insert(e);
        }
    }
    return (int)set.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices){
    for(auto &s : list){
        if(!s.empty() && s[0] == vertex){
            for(int i = 1; i < s.size(); i++){
                vertices.push_back(s[i]);
            }
            return;
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices){
    for(auto & s : list) {
        if (!s.empty() && s[0] != vertex){
            for (int i = 1; i < s.size(); i++){
                if (s[i] == vertex) {
                    vertices.push_back(s[0]);
                    break;
                }
            }
        }
    }
}

void ListGraph::print() {
    std::cout << "===Print list===" << std::endl;
    for (auto &i: list){
        for (auto &e: i) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}

std::string ListGraph::getType(){
    return type;
}

void ListGraph::copyFromMatrixGraph(IGraph& other){
    int size = other.VerticesCount();
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        other.GetNextVertices(i,vec);
        for(auto &v : vec){
            ListGraph::AddEdge(i,v);
        }
        vec.clear();
    }
}