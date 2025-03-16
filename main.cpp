#include <iostream>
#include <fstream>
#include "graph.h"

int main()
{
    std::string filename;
    std::cout << "Input filename: ";
    std::cin >> filename;
    std::ifstream f(filename);
    if (!f.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    int vert_num, edge_num;
    f >> vert_num >> edge_num;
    if (!vert_num || !edge_num) return 0;
    std::vector<std::shared_ptr<Vertex>> verts(vert_num);
    for (int i = 0; i < vert_num; i++) verts[i] = std::make_shared<Vertex>(i);
    for (int i = 0; i < edge_num; i++)
    {
        int from, to;
        f >> from >> to;
        verts[from]->edges.push_back(to);
        verts[to]->edges.push_back(from);
    }
    Graph g(verts, vert_num);
    int from_vert;
    f >> from_vert;
    std::vector<int> res = g.shortest_distance(from_vert);
    std::cout << "Distances are: " << std::endl;
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << i << " - " << res[i] << std::endl;
    }
    return 0;
}
