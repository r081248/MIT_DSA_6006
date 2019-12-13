template<typename T>
class node
{
public:
    node(T data, node *ptr):
    value{data},
    next{ptr}
    {
    }
    T value;
    node *next;
};

template<typename T>
class list
{
public:
    list(){};
    bool insert(T value);
    bool delete(T value);

private:
    node<T> *createNode(T value, node<T>*next);
    node<T> *m_data;

};