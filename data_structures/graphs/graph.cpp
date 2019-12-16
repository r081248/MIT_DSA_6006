#include "graph.h"
#include <iostream>

bool graph::add_edge(int vertex_id, int neighbor_vertex)
{
    if(vertex_id<m_vertex_count && neighbor_vertex<m_vertex_count)
    {
        return false;    
    }
    m_vertices[vertex_id].m_edges.add(neighbor_vertex);
    return true;
}

bool graph::bfs(int vertex_id)
{
    if(vertex_id < m_vertex_count)
    {
        return false;
    }

    for(int i=0;i!=m_vertex_count;++i)
    {
        m_vertices[i].m_visited = false;
    }

    queue<int> vertex_queue(m_vertex_count);
    vertex_queue.enqueue(vertex_id);

    while(!vertex_queue.isQueueEmpty())
    {
        int id = vertex_queue.dequeue();
        m_vertices[id].m_visited = true;
        std::cout << id << " ";
        for(auto neighbour:m_vertices[id].m_edges)
        {
            if(!m_vertices[neighbour].m_visited)
            {
                vertex_queue.enqueue(neighbour);
            }
        }
    }
    return true;
}

graph::~graph()
{
    if(m_vertices)
    {
        delete[] m_vertices;
    }
}



#if 1
int main()
{
    graph g(5);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(1,5);
    g.add_edge(3,1);
    g.add_edge(3,5);
    g.add_edge(4,1);
    g.add_edge(4,2);
    g.add_edge(4,5);
    g.add_edge(5,1);
    g.add_edge(5,3);
    g.add_edge(5,4);
    g.add_edge(5,2);
    g.add_edge(2,5);
    g.add_edge(2,4);

    g.bfs(1);
    g.bfs(2);
    g.bfs(3);
    g.bfs(4);
    g.bfs(5);

    return 0;

}
#endif