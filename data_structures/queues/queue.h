template<typename T>
class queue
{
public:
    queue(int size);
    void enqueue(T key);//Throws exception
    T dequeue();//Throws exception
    ~queue();
private:
    bool isQueueFull();
    bool isQueueEmpty();
    int m_front;
    int m_rear;
    int m_size;
    T *m_data;
};
