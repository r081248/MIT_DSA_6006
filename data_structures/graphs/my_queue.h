#ifndef MY_QUEUE_H
#define MY_QUEUE_H
template<typename T>
class my_queue
{
public:
    my_queue(int size);
    void enqueue(T key);//Throws exception
    T dequeue();//Throws exception
    bool isQueueFull();
    bool isQueueEmpty();
   ~my_queue();
private:
    int m_front;
    int m_rear;
    int m_size;
    T *m_data;
};
#endif