#include "list.h"
#include <iostream>

template<typename T>
bool list<T>::insert(T value) //Add at beginning
{
    m_data = new node<T>(value,m_data);
    return m_data;
}

template<typename T>
bool list<T>::deletion(T value)
{
    node<T> *temp = m_data;
    node<T> *prev;
    while(temp)
    {
        if(temp->value == value)
        {
            if(temp == m_data)
            {
                m_data = temp->next; // If the element deleted to be the first one
            }
            else
            {
                prev->next = temp->next;       
            }
            delete temp;
            return true;//if key is deleted successfully
        }
        prev = temp;
        temp = temp->next;
    }
    return false; //If key is not found in the list
}

template<typename T>
void list<T>::printList()
{
    node<T> *iter = m_data;
    while(iter) 
    {
        std::cout << iter->value << " ";
        iter = iter->next; 
    }
    std::cout << std::endl;  
}

template<typename T>
list<T>::~list()
{
    if(m_data)
    {
        delete m_data;
    }
}


#if 0
int main()
{
    list<int> ll;
    bool alive = true;
    char decision;
    int data;
    while(alive)
    {
        std::cout << "insert data : (i)\n";
        std::cout << "delete data : (d)\n";
        std::cout << "show the list:(s)\n";
        std::cout << "exit the application : (e)\n";
        std::cin >> decision;
        switch(decision)
        {
            case 'i':
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                ll.insert(data);           
                break;
            case 'd':
                std::cout << "Enter the data that to be deleted from list: ";
                std::cin >> data;
                if(ll.deletion(data))
                {
                    std::cout << data << " has been deleted from the list\n";
                }
                else
                {
                    std::cout << data << " is not found in the list\n";
                }
                
                break;
            case 's':
                ll.printList();
                break;
            case 'e':
                alive = false;
                break;
            default:
                std::cout << "invalid option selected... Try again\n";
                break;
        }
        
    }
}
#endif