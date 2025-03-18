#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <memory>

class Vertex {
    public:
        int id;
        std::vector<int> edges_dest;

        Vertex(int id) : id(id) {};
        explicit Vertex(int id, std::vector<int> &edges_dest) : id(id), edges_dest(edges_dest) {};
};

class Graph {
    private:
        std::vector<std::unique_ptr<Vertex>> verts;
        int vert_num = 0;
    public:
        Graph(std::vector<std::unique_ptr<Vertex>> &&verts, int vert_num) : verts(std::move(verts)), vert_num(vert_num) {};
        std::vector<int> shortest_distance(int from);
};

#endif //GRAPH_H
