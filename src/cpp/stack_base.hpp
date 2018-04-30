#ifndef STACK_BASE_HPP
#define STACK_BASE_HPP

#include "linked_list.hpp"
#include <ostream>
#include <stdexcept>

namespace fellowseb_ctci
{

//
// Base class for stack implementation.
//
template <typename T, typename StoragePolicy>
class stack_base : private StoragePolicy
{
public:
    stack_base() {}
    stack_base(const std::initializer_list<T>& il);
    stack_base(const stack_base<T, StoragePolicy>& other);
    //stack_base<T, StoragePolicy>& operator=(const stack_base<T, StoragePolicy>& other);
    void pop();
    const T& peek() const;
    T& peek();
    void push(const T& data);
    bool is_empty() const;
    int size() const;
    void print(std::ostream& os) const;
};

template <typename T, typename StoragePolicy>
stack_base<T, StoragePolicy>::stack_base(const stack_base<T, StoragePolicy>& other)
    : StoragePolicy(other)
{
}

template <typename T, typename StoragePolicy>
stack_base<T, StoragePolicy>::stack_base(const std::initializer_list<T>& il)
{
    auto iter = il.begin();
    auto iter_end = il.end();
    for (; iter != iter_end; ++iter)
    {
        push(*iter);
    }
}

// template <typename T, typename StoragePolicy>
// stack_base<T, StoragePolicy>& stack_base<T, StoragePolicy>::operator=(const stack_base<T, StoragePolicy>& other)
// {
//     StoragePolicy::operator=(*this, other);
//     return *this;
// }

template <typename T, typename StoragePolicy>
void stack_base<T, StoragePolicy>::pop()
{
    StoragePolicy::pop();
}

template <typename T, typename StoragePolicy>
const T& stack_base<T, StoragePolicy>::peek() const
{
    return StoragePolicy::peek();
}

template <typename T, typename StoragePolicy>
T& stack_base<T, StoragePolicy>::peek()
{
    return StoragePolicy::peek();
}

template <typename T, typename StoragePolicy>
void stack_base<T, StoragePolicy>::push(const T& data)
{
    StoragePolicy::push(data);
}

template <typename T, typename StoragePolicy>
bool stack_base<T, StoragePolicy>::is_empty() const
{
    return StoragePolicy::is_empty();
}

template <typename T, typename StoragePolicy>
int stack_base<T, StoragePolicy>::size() const
{
    return StoragePolicy::size();
}

template <typename T, typename StoragePolicy>
void stack_base<T, StoragePolicy>::print(std::ostream& os) const
{
    StoragePolicy::print(os);
}

template <typename T, typename StoragePolicy>
std::ostream& operator<<(std::ostream& os, const stack_base<T, StoragePolicy>& s)
{
    s.print(os);
    return os;
}
};
#endif //STACK_BASE_HPP
