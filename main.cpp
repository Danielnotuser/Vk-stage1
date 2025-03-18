#include "graph.h"
#include <fstream>


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
    if (!vert_num || !edge_num)
    {
        std::cerr << "Failed to count the distances. Incorrect number of edges or vertices." << std::endl;
        return 2;
    }
    std::vector<std::unique_ptr<Vertex>> verts(vert_num);
    for (int i = 0; i < vert_num; i++) verts[i] = std::make_unique<Vertex>(i);
    for (int i = 0; i < edge_num; i++)
    {
        int from, to;
        f >> from >> to;
        verts[from]->edges_dest.push_back(to);
        verts[to]->edges_dest.push_back(from);
    }
    Graph g(std::move(verts), vert_num);
    int from_vert;
    f >> from_vert;
    std::vector<int> res = g.shortest_distance(from_vert);
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
