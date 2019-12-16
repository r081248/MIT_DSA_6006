#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<typename T>
class list
{

public:

//Farward Declarations
    class node;
    class iterator;
//==========================

    list():m_data{nullptr}{};
    bool add(T value);
    bool remove(T value);
    iterator begin() 
    {
        return iterator(m_data);
    }
    iterator end() 
    {
        return iterator(nullptr);
    }
    ~list();

    class iterator
    {
        public:
            iterator():currentNode{m_data}{};
            iterator(node* startingNode):
            currentNode{startingNode}
            {
            };
            T operator*(){return currentNode->value;};
            iterator& operator++()
            {
                if(currentNode)
                {
                    currentNode = currentNode->next;
                }
                return *this;   
            }
            iterator operator++(int)
            {
                iterator it = *this;
                ++*this;
                return it;
            }
            bool operator!=(const iterator &it)
            {
                return !(this->currentNode==it.currentNode);
            }

        private:
            node *currentNode;
    };


private:
    node* m_data;

    class node // Making not available to outside
    {
    friend class list;
    
    public:
        node(T data, node *ptr):value{data},next{ptr}{}
    
    private:
        T value;
        node *next;
    };

};

#endif