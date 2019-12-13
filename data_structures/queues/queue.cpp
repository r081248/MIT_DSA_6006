#include "queue.h"


template<typename T>
queue<T>::queue(int size):
    m_size{size},
    m_front{-1},
    m_rear{-1}
{
    m_data = new T[m_size];
}

template<typename T>
bool queue<T>::isQueueFull()
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
bool queue<T>::isQueueEmpty()
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
void queue<T>::enqueue(T key)
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
T queue<T>::dequeue()
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
queue<T>::~queue()
{
    delete[] m_data;
    return;
}


#if 0
#include <iostream>

int main()
{
    queue<int> *q = nullptr;
    bool alive = true;
    char c;
    int size;
    while(alive)
    {
        std::cout << "create new queue :(c)\n";
        std::cout << "exit : (e)\n";
        std::cin >> c;
        switch (c)
        {
        case 'c':
            if(q)
            {
                delete q;
                q = nullptr;
            }
            std::cout << "enter queue size\n";
            std::cin >> size;
            q = new queue<int>(size);
            if(q)
            {
                std::cout << "queue is successfully created with size = " << size << std::endl;
                bool alive1 = true;
                while(alive1)
                {
                    std::cout << "enqueue : (e)\n";
                    std::cout << "dequeue : (d)\n";
                    std::cout << "back to previous menu : (b)\n";
                    char operation;
                    std::cin >> operation;
                    switch (operation)
                    {
                    case 'e':
                        try
                        {
                            std::cout << "enter the data to enqueue" ;
                            int data ;
                            std::cin >> data;
                            q->enqueue(data);
                        }
                        catch(char *excep)
                        {
                            std::cerr << excep << '\n';
                        }
                        
                        break;
                    
                    case 'd':
                        try
                        {
                            int data = q->dequeue();
                            std::cout << "dequeued element = " << data << std::endl;
                        }
                        catch(char *excep)
                        {
                            std::cerr << excep << '\n';
                        }
                        
                        break;
                    case 'b':
                        alive1 = false;
                        break;
                        
                    }
                }
            }
            break;
        
        case 'e':
            alive = false;
            break;
        
        default:
            std::cout << "Invalid option selected...please try again" << std::endl;
            break;
        }


        
    }
    


}
#endif