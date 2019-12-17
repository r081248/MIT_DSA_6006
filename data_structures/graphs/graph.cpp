#include "graph.h"
#include <iostream>
#include "my_queue.h"

template<typename T>
bool linked_list<T>::add(T value)
{
    m_data = new node(value, m_data);
    return m_data;
}

template<typename T>
bool linked_list<T>::remove(T value)
{
    
    node *temp = m_data;
    node *prev;
    while(temp)
    {
        if(temp->value == value)
        {
            if(temp == m_data)
            {
                m_data = m_data->next;
            }   
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return true;
            
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

template<typename T>
linked_list<T>::~linked_list()
{
    node *temp;

    while(m_data)
    {
        temp = m_data;
        m_data = m_data->next;
        delete temp;
    }

    return;
}

template<typename T>
my_queue<T>::my_queue(int size):
    m_size{size},
    m_front{-1},
    m_rear{-1}
{
    m_data = new T[m_size];
}

template<typename T>
bool my_queue<T>::isQueueFull()
{
    if((m_rear + 1)%m_size == m_front)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template<typename T>
bool my_queue<T>::isQueueEmpty()
{
    if(m_front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template<typename T>
void my_queue<T>::enqueue(T key)
{
    if(!isQueueFull())
    {
        m_rear = (m_rear + 1)%m_size;
        m_data[m_rear] = key;
        if(m_front == -1)
        {
            m_front = 0;
        }
    }
    else
    {
        throw "queue overflow";
    }
    
}

template<typename T>
T my_queue<T>::dequeue()
{
    if(isQueueEmpty())
    {
        throw "queue is empty";
    } 
    else
    {
        T key = m_data[m_front];
        if(m_front==m_rear)
        {
            m_front = m_rear = -1;
        }
        else
        {
            m_front = (m_front + 1)%m_size;
        }
        return key;
    }
    
}

template<typename T>
my_queue<T>::~my_queue()
{
    delete[] m_data;
    return;
}

bool graph::add_edge(int vertex_id, int neighbor_vertex)
{
    if(vertex_id>m_vertex_count && neighbor_vertex>m_vertex_count)
    {
        return false;    
    }
    m_vertices[vertex_id].m_edges.add(neighbor_vertex);
    return true;
}

bool graph::bfs(int vertex_id)
{
    if(vertex_id > m_vertex_count)
    {
        return false;
    }

    for(int i=0;i!=m_vertex_count;++i)
    {
        m_vertices[i].m_visited = false;
    }

    my_queue<int> vertex_queue(m_vertex_count);
    vertex_queue.enqueue(vertex_id);
    m_vertices[vertex_id].m_visited = true;

    while(!vertex_queue.isQueueEmpty())
    {
        int id = vertex_queue.dequeue();
        std::cout << id << " ";
        for(auto neighbour:m_vertices[id].m_edges)
        {
            if(!m_vertices[neighbour].m_visited)
            {
                m_vertices[neighbour].m_visited = true;
                vertex_queue.enqueue(neighbour);
            }
        }
    }
    std::cout << std::endl;
    return true;
}

bool graph::dfs(int vertex_id)
{
    if(vertex_id>m_vertex_count)
        return false;
    for(int i=1;i!=m_vertex_count;++i)
    {
        m_vertices[i].m_visited = false;
    }

    dfs_util(vertex_id);
    std::cout << std::endl;
    return true;
}

void graph::dfs_util(int vertex_id)
{
    m_vertices[vertex_id].m_visited = true;
    std::cout << vertex_id << " ";
    for(auto neighbour: m_vertices[vertex_id].m_edges)
    {
        if(!m_vertices[neighbour].m_visited)
        {
            dfs_util(neighbour);
        }
            
    }
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
    graph g(6);
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

    g.dfs(1);
    g.dfs(2);
    g.dfs(3);
    g.dfs(4);
    g.dfs(5);


    return 0;

}
#endif