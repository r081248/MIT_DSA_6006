#include <iostream>
#define MAX_VERTICES 30

class maze
{
    private:
        class cell
        {
            friend class maze;
            friend std::ostream &operator<<(std::ostream &os, maze& m);
            public:
                cell():m_ways{0}{};
            private:
                int m_ways;
        };

        friend std::ostream &operator<<(std::ostream &os, maze& m);
    public:
        maze(int vertices_count):
        m_vertices_count{vertices_count}
        {
            if(m_vertices_count>MAX_VERTICES)
            {
                throw "vertices count exceeded";
            }
            find_num_ways();
            return;
        }
        void find_num_ways()//number of ways from {0,0}th cell to {i,j}th cell
        {
            for(int i=0;i<m_vertices_count;++i)
            {
                m_maze[i][0].m_ways = m_maze[0][i].m_ways = 1;
            }
            for(int i=1;i<m_vertices_count;++i)
            {
                for(int j=1;j<m_vertices_count;++j)
                {
                    m_maze[i][j].m_ways = m_maze[i-1][j].m_ways + m_maze[i][j-1].m_ways;          
                }
            }
        }
        
        int find_num_ways(int i, int j)
        {
            return m_maze[i][j].m_ways;
        }

    private:
        cell m_maze[MAX_VERTICES][MAX_VERTICES];
        int m_vertices_count;

};

std::ostream &operator<<(std::ostream &os, maze& m)
{
    for(int i=0;i<m.m_vertices_count;++i)
    {
        for(int j=0;j<m.m_vertices_count;++j)
        {
            os << m.m_maze[i][j].m_ways << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

#if 1
int main()
{
    maze m(10);
    std::cout << m;
    return 0;
}
#endif