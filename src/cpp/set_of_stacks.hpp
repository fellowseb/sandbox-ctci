#ifndef SET_OF_STACKS_HPP
#define SET_OF_STACKS_HPP

#include "stack.hpp"
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>

namespace fellowseb_ctci
{

struct DefaultSetOfStackTraits
{
    static const int TRESHOLD = 5;
};

//
// Set of stacks used in CH3.3
//
template <typename T, typename SetOfStackTraits = DefaultSetOfStackTraits>
class set_of_stacks
{
public:
    set_of_stacks();
    const T& peek() const;
    T& peek();
    void push(const T& new_entry);
    void pop();
    void print(std::ostream& os) const;
    void pop_at(const size_t substack_index);

private:
    static void printStack(std::ostream& os, const stack<T>& s);
    void shift_down(size_t index);

    std::vector<stack<T>> underlying_stacks;
};

//
// Implementation
//
template <typename T, typename S>
set_of_stacks<T, S>::set_of_stacks()
{
}

template <typename T, typename S>
const T& set_of_stacks<T, S>::peek() const
{
    if (!underlying_stacks.size() == 0)
    {
        throw std::logic_error("stack is empty");
    }
    return underlying_stacks.at(underlying_stacks.size() - 1).peek();
}

template <typename T, typename S>
T& set_of_stacks<T, S>::peek()
{
    if (underlying_stacks.empty())
    {
        throw std::logic_error("stack is empty");
    }
    return underlying_stacks.at(underlying_stacks.size() - 1).peek();
}

template <typename T, typename S>
void set_of_stacks<T, S>::push(const T& new_entry)
{
    if (underlying_stacks.empty()
        || underlying_stacks.rbegin()->size() >= S::TRESHOLD)
    {
        underlying_stacks.push_back(stack<T>{});
    }
    underlying_stacks.rbegin()->push(new_entry);
}

template <typename T, typename S>
void set_of_stacks<T, S>::pop()
{
    if (underlying_stacks.empty())
    {
        throw std::logic_error("stack is empty");
    }
    underlying_stacks.rbegin()->pop();
    if (underlying_stacks.rbegin().is_empty())
    {
        underlying_stacks.pop_back();
    }
}

// template <typename T, typename S>
// void set_of_stacks<T, S>::pop_at(const size_t substack_index)
// {
//     if (substack_index < 0 || substack_index >= underlying_stacks.size())
//     {
//         throw std::logic_error("given index is out of bounds");
//     }
//     underlying_stacks[substack_index].pop();
//     shift_down(substack_index + 1);
// }

// template <typename T, typename S>
// void set_of_stacks<T, S>::shift_down(size_t index)
// {
//     if (index < underlying_stacks.size())
//     {
//         underlying_stacks[index - 1].push(underlying_stacks[index].peek_bottom());
//         underlying_stacks[index].remove_bottom();
//         shift_down(index + 1);
//     }
// }

template <typename T, typename S>
void set_of_stacks<T, S>::printStack(std::ostream& os, const stack<T>& s)
{
    os << "[";
    os << s;
    os << "]";
}

template <typename T, typename S>
void set_of_stacks<T, S>::print(std::ostream& os) const
{
    std::for_each(underlying_stacks.rbegin(),
                  underlying_stacks.rend() - 1,
                  [&os](const stack<T>& s) {
                      printStack(os, s);
                      os << "->";
                  });
    printStack(os, *underlying_stacks.begin());
}

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const set_of_stacks<T, S>& s)
{
    s.print(os);
    return os;
}
};

#endif // SET_OF_STACKS_HPP
