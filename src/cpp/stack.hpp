#ifndef STACK_HPP
#define STACK_HPP

#include "linked_list.hpp"
#include "stack_base.hpp"
#include <stdexcept>
#include <ostream>

namespace fellowseb_ctci
{

//
// Classic stack, implemented with a linked list
// List Storage Policy for stack_base
//
template <typename T>
class slsp
{
public:
    slsp()
        : top(nullptr)
    {
    }
    void pop();
    const T& peek() const;
    T& peek();
    void push(const T& data);
    bool is_empty() const;
    void print(std::ostream &os) const;

private:
    list_node<T>* top;
};

// Define 'normal' stack template type
template <typename T>
using stack = stack_base<T, slsp<T>>;

//
// Implementation details
//

template <typename T>
void slsp<T>::pop()
{
    if (!top)
    {
        throw std::logic_error("can't pop an empty stack");
    }
    list_node<T>* popped = top;
    top = top->next;
    delete popped;
}

template <typename T>
const T& slsp<T>::peek() const
{
    if (!top)
    {
        throw std::logic_error("empty stack");
    }
    return top->data;
}

template <typename T>
T& slsp<T>::peek()
{
    if (!top)
    {
        throw std::logic_error("empty stack");
    }
    return top->data;
}

template <typename T>
void slsp<T>::push(const T& data)
{
    list_node<T>* second = top;
    top = new list_node<T>(data);
    top->next = second;
}

template <typename T>
bool slsp<T>::is_empty() const
{
    return top == nullptr;
}

template <typename T>
void slsp<T>::print(std::ostream& os) const
{
    list_node<T> *current_node = top;
    while (current_node)
    {
        os << current_node->data;
        current_node = current_node->next;
        if (current_node)
        {
            os << "->";
        }
    }
}
};
#endif //STACK_HPP
