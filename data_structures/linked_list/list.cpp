#include "list.h"
#include <iostream>

template<typename T>
<<<<<<< HEAD
bool list<T>::add(T value)
=======
bool list<T>::insert(T value) //Add at beginning
>>>>>>> 6031b641e4dc36b5ffc5e95e98564d093af32208
{
    m_data = new node(value, m_data);
    return m_data;
}

template<typename T>
<<<<<<< HEAD
bool list<T>::remove(T value)
{
    
    node *temp = m_data;
    node *prev;
=======
bool list<T>::deletion(T value)
{
    node<T> *temp = m_data;
    node<T> *prev;
>>>>>>> 6031b641e4dc36b5ffc5e95e98564d093af32208
    while(temp)
    {
        if(temp->value == value)
        {
            if(temp == m_data)
            {
<<<<<<< HEAD
                m_data = m_data->next;
            }   
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return true;
            
=======
                m_data = temp->next; // If the element deleted to be the first one
            }
            else
            {
                prev->next = temp->next;       
            }
            delete temp;
            return true;//if key is deleted successfully
>>>>>>> 6031b641e4dc36b5ffc5e95e98564d093af32208
        }
        prev = temp;
        temp = temp->next;
    }
<<<<<<< HEAD
    return false;
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
=======
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
>>>>>>> 6031b641e4dc36b5ffc5e95e98564d093af32208
}
#endif