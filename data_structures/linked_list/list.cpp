#include "list.h"
#include <iostream>

template<typename T>
bool list<T>::add(T value)
{
    m_data = new node(value, m_data);
    return m_data;
}

template<typename T>
bool list<T>::remove(T value)
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
list<T>::~list()
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

/*template<typename T>
list<T>::iterator list<T>::begin() noexcept
{
    return iterator(m_data);
}

template<typename T>
list<T>::iterator list<T>::end() noexcept
{
    return iterator(nullptr);
}
*/
#if 0
#include<iostream>
#include<vector>
int main()
{

    list<int> lst;
    bool alive = true;
    char option;
    int value;
    while(alive)
    {
        std::cout << "add node : [a]\n";
        std::cout << "remove node: [r]\n";
        std::cout << "print list: [p]\n";
        std::cout << "exit: [e]\n";
        std::cin >> option;
        switch (option)
        {
        case 'a':
            std::cout << "Enter value: ";
            std::cin >> value;
            lst.add(value);
            break;
        case 'r':
            std::cout << "Enter the value to be deleted: ";
            std::cin >> value;
            if(lst.remove(value))
            {
                std::cout << value << " has been deleted from the list" << std::endl;
            }
            else
            {
                std::cout << value << " is not found from the list" << std::endl;
            }
            break;
        case 'p':
            /*for(list<int>::iterator it = lst.begin(); it != lst.end();it++)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            */

            for(auto it:lst)
            {
                std::cout << it << " ";
                it = -50;
            }
            std::cout << std::endl;
            break;
        case 'e':
            alive = false;
            break;
        
        default:
            std::cout << "Invalid option... retry\n";
            break;
        }     
    }
    return 0;
}
#endif