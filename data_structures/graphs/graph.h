#ifndef GRAPH_H
#define GRAPH_H
#include "linked_list.h"
#include "my_queue.h"

class graph
{

class vertex;

public:
    graph(int vertex_count):m_vertex_count{vertex_count},m_vertices{new vertex[vertex_count]}{};
    bool add_edge(int vertex_id, int neighbour_vertex_id);
    bool bfs(int vertex_id);
    bool dfs(int vertex_id);
    ~graph();
private:
    void dfs_util(int vertex_id);
    class vertex
    {
        friend class graph;
        public:
            vertex():m_edges{},m_visited{false}{};
            ~vertex()
            {
                m_edges.~linked_list();
            }
        private:
            linked_list<int> m_edges;
            bool m_visited;
    };
    int m_vertex_count;
    vertex *m_vertices;      
};
#endif