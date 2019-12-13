#include "list.h"

template<typename T>
bool list<T>::insert(T value)
{
    m_data = new node<T>(value,m_data);
    return m_data;
}

template<typename T>
bool list<T>::delete(T value)
{
;
}