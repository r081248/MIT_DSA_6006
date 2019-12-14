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
    list():m_data{nullptr}{};
    bool insert(T value);
    bool deletion(T value);
    void printList();
    ~list();
private:
    node<T> *createNode(T value, node<T>*next);
    node<T> *m_data;

};