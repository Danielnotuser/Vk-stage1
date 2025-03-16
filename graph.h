#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <memory>

class Vertex {
    public:
        int id;
        std::vector<int> edges;

        Vertex() {};
        Vertex(int id) : id(id) {};
        explicit Vertex(int id, std::vector<int> &edges) : id(id), edges(edges) {};
        ~Vertex() = default;
};

class Graph {
    private:
        std::vector<std::shared_ptr<Vertex>> verts;
        int vert_num;
    public:
        Graph() = default;
        Graph(std::vector<std::shared_ptr<Vertex>> &verts, int vert_num) : verts(verts), vert_num(vert_num) {};

        std::vector<int> shortest_distance(int from);
};

#endif //GRAPH_H
