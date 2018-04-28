#ifndef STACK_CH3_2_HPP
#define STACK_CH3_2_HPP

#include "stack.hpp"

namespace fellowseb_ctci
{
template <typename T>
class stack_ch3_2
{
public:
    stack_ch3_2()
        : top(nullptr)
    {
    }
    void pop();
    const T& peek() const;
    T& peek();
    void push(const T& data);
    bool is_empty() const;
    const T& min() const;
    void print(std::ostream &os) const;

private:
    list_node<T>* top;
    stack<T> mins;
};

//
// Implementation details
//

template <typename T>
void stack_ch3_2<T>::pop()
{
    if (!top)
    {
        throw std::logic_error("can't pop an empty stack");
    }
    bool pop_min = peek() == mins.peek();
    list_node<T>* popped = top;
    top = top->next;
    delete popped;
    if (pop_min)
    {
        mins.pop();
    }
}

template <typename T>
const T& stack_ch3_2<T>::peek() const
{
    if (!top)
    {
        throw std::logic_error("empty stack");
    }
    return top->data;
}

template <typename T>
T& stack_ch3_2<T>::peek()
{
    if (!top)
    {
        throw std::logic_error("empty stack");
    }
    return top->data;
}

template <typename T>
void stack_ch3_2<T>::push(const T& data)
{
    list_node<T>* second = top;
    top = new list_node<T>(data);
    top->next = second;
    if (mins.is_empty() || data <= mins.peek())
    {
        mins.push(data);
    }
}

template <typename T>
const T& stack_ch3_2<T>::min() const
{
    if (is_empty())
    {
        throw std::runtime_error("stack is empty");
    }
    return mins.peek();
}


template <typename T>
bool stack_ch3_2<T>::is_empty() const
{
    return top == nullptr;
}

template <typename T>
void stack_ch3_2<T>::print(std::ostream& os) const
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
#endif //STACK_CH3_2_HPP
