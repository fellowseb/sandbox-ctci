#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "stack.hpp"
#include <stdexcept>

namespace fellowseb_ctci
{
template <typename T>
class queue_ch3_5
{
public:
    queue_ch3_5()
    {
    }
    void enqueue(const T& data);
    T dequeue();

private:
    stack<T> enqueue_stack,
        dequeue_stack;
};

template <typename T>
void queue_ch3_5<T>::enqueue(const T& data)
{
    while (!dequeue_stack.is_empty())
    {
        enqueue_stack.push(dequeue_stack.peek());
        dequeue_stack.pop();
    }
    enqueue_stack.push(data);
}

template <typename T>
T queue_ch3_5<T>::dequeue()
{
    while (enqueue_stack.size() > 1)
    {
        dequeue_stack.push(enqueue_stack.peek());
        enqueue_stack.pop();
    }
    if (enqueue_stack.size() == 1)
    {
        const T return_value = enqueue_stack.peek();
        enqueue_stack.pop();
        return return_value;
    }
    else
    {
        if (dequeue_stack.is_empty())
        {
            throw std::runtime_error("queue is empty");
        }
        const T return_value = dequeue_stack.peek();
        dequeue_stack.pop();
        return return_value;
    }
}
};

#endif //QUEUE_HPP
