#include <iostream>
#define MAX_VERTICES 30
class maze
{
    private:
        class cell
        {
            friend class maze;
            public:
                cell():m_flag{false},m_visited{false}{};
                cell(bool flag):m_flag{flag},m_visited{false}{};
                friend std::istream& operator>>(std::istream &is, class maze &m);
                friend std::ostream& operator<<(std::ostream &os, class maze &m);
            private:
                bool m_flag;
                bool m_visited;   
        };

    public:
        maze(int num_vertices):
        m_vertices_num{num_vertices}
        {
            if(m_vertices_num>MAX_VERTICES)
            {
                throw "vertices count exceed";
            }
        }
        friend std::istream& operator>>(std::istream &is, class maze &m);
        friend std::ostream& operator<<(std::ostream &os, class maze &m);

        bool is_there_path(int x1, int y1, int x2, int y2)
        {
            m_maze[x1][y1].m_visited = true;
            if(x1==x2 && y1==y2)
                return true;
            if(is_valid_cell(x1-1,y1) && m_maze[x1-1][y1].m_flag && !m_maze[x1-1][y1].m_visited && is_there_path(x1-1,y1,x2,y2))
            {
                return true;
            }
            if(is_valid_cell(x1+1,y1) && m_maze[x1+1][y1].m_flag && !m_maze[x1+1][y1].m_visited && is_there_path(x1+1,y1,x2,y2))
            {
                return true;
            }
            if(is_valid_cell(x1,y1-1) && m_maze[x1][y1-1].m_flag && !m_maze[x1][y1-1].m_visited && is_there_path(x1,y1-1,x2,y2))
            {
                return true;
            } 
            if(is_valid_cell(x1,y1+1) && m_maze[x1][y1+1].m_flag && !m_maze[x1][y1+1].m_visited && is_there_path(x1,y1+1,x2,y2))
            {
                return true;
            }
            
            return false;

        }

        
    private:
        cell m_maze[MAX_VERTICES][MAX_VERTICES];
        int m_vertices_num;


        bool is_valid_cell(int x,int y)
        {
            bool is_valid = false;
            if(x>=0 && x<m_vertices_num && y>=0 && y<m_vertices_num)
            {
                is_valid = true;
            }
            return is_valid;
        }
};

std::istream& operator>>(std::istream &is, maze &m)
{
    int flag;
    for(int i=0;i<m.m_vertices_num;++i)
    {
        for(int j=0;j<m.m_vertices_num;++j)
        {
            is>>flag;
            m.m_maze[i][j].m_flag = flag;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream &os, class maze &m)
{
    for(int i=0;i<m.m_vertices_num;++i)
    {
        for(int j=0;j<m.m_vertices_num;++j)
        {
            os << m.m_maze[i][j].m_flag << " ";
        }
        os << std::endl;
    }
    return os;
}


#if 1
#include <iostream>
int main()
{
    int num_vertices;
    std::cin >> num_vertices;
    std::cout << "Number of vertices = " << num_vertices << std::endl;
    maze m(num_vertices);
    std::cout << "maze object created" << std::endl;
    std::cin >> m;
    std::cout << m;
    int x1,y1,x2,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if(m.is_there_path(x1,y1,x2,y2))
    {
        std::cout << "path is available"<<std::endl;
    }
    else
    {
        std::cout << "path is not available" << std::endl;
    }

}
#endif