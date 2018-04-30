#ifndef STACK_HPP
#define STACK_HPP

#include "stack_base.hpp"
#include <list>
#include <ostream>
#include <stdexcept>

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
    void pop();
    const T& peek() const;
    T& peek();
    void push(const T& data);
    bool is_empty() const;
    int size() const;
    void print(std::ostream& os) const;

private:
    std::list<T> l;
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
    if (l.empty())
    {
        throw std::logic_error("can't pop an empty stack");
    }
    l.pop_front();
}

template <typename T>
const T& slsp<T>::peek() const
{
    if (l.empty())
    {
        throw std::logic_error("empty stack");
    }
    return *l.cbegin();
}

template <typename T>
T& slsp<T>::peek()
{
    if (l.empty())
    {
        throw std::logic_error("empty stack");
    }
    return *l.begin();
}

template <typename T>
void slsp<T>::push(const T& data)
{
    l.push_front(data);
}

template <typename T>
bool slsp<T>::is_empty() const
{
    return l.empty();
}

template <typename T>
int slsp<T>::size() const
{
    return l.size();
}

template <typename T>
void slsp<T>::print(std::ostream& os) const
{
    if (l.empty())
        return;
    auto iter = l.cbegin();
    const auto iter_end = --(l.cend());
    for (; iter != iter_end; iter++)
    {
        os << *iter;
        os << "->";
    }
    os << *iter;
}
};
#endif //STACK_HPP
