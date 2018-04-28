#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "linked_list.hpp"
#include <stdexcept>

namespace fellowseb_ctci
{
template <typename T>
class queue
{
public:
    queue()
        : head(nullptr)
        , tail(nullptr)
    {
    }
    void enqueue(const T& data);
    T dequeue();

private:
    linked_list<T>* head;
    linked_list<T>* tail;
};
};

template <typename T>
void fellowseb_ctci::enqueue(T data)
{
    if (tail)
    {
        tail->append(data);
        tail = tail->next;
    }
    else
    {
        head = tail = linked_list<T>(data);
    }
}

template <typename T>
T fellowseb_ctci::dequeue()
{
    if (!head)
    {
        throw std::logic_error("empty queue");
    }
    list_node<T> * dequeued = head;
    T cpy(dequeued->data);
    head = dequeued->next;
    delete dequeued;
    return cpy;
}

#endif //QUEUE_HPP
