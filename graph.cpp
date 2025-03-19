#include "graph.h"

std::vector<int> Graph::shortest_distance(int from)
{
    int min_dist, min_ind;
    std::vector<int> visited(vert_num, 0), dist(vert_num, INT_MAX);
    dist[from] = 0;
    do
    {
        min_dist = INT_MAX;
        min_ind = 0;
        for (int i = 0; i < vert_num; i++)
        {
            if (!visited[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                min_ind = i;
            }
        }
        if (min_dist == INT_MAX) break;

        for (int i = 0; i < verts[min_ind]->edges_dest.size(); i++)
        {
            int new_dist = min_dist + 1;
            if (min_ind != verts[min_ind]->edges_dest[i] && new_dist < dist[verts[min_ind]->edges_dest[i]])
                dist[verts[min_ind]->edges_dest[i]] = new_dist;
        }
        visited[min_ind] = 1;
    } while (min_dist != INT_MAX);

    return dist;
}