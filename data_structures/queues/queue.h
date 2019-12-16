#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class queue
{
public:
    queue(int size);
    void enqueue(T key);//Throws exception
    T dequeue();//Throws exception
    bool isQueueFull();
    bool isQueueEmpty();
   ~queue();
private:
    int m_front;
    int m_rear;
    int m_size;
    T *m_data;
};
#endif