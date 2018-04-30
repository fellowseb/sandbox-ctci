#ifndef STACK_CH3_1_HPP
#define STACK_CH3_1_HPP

#include "stack_base.hpp"
#include <cassert>
#include <ostream>
#include <stdexcept>

namespace fellowseb_ctci
{

//
// Shared Array Storage Policy for stack_base
//
template <typename T>
class ssas_policy
{
protected:
    ssas_policy();
    ssas_policy(const ssas_policy<T>& other);
    ssas_policy<T>& operator=(const ssas_policy<T>& other);
    void pop();
    const T& peek() const;
    T& peek();
    void push(const T& data);
    bool is_empty() const;
    int size() const;
    void print(std::ostream& os) const;

private:
    int count_free_slots() const;

    struct shared_array_node
    {
        int next;
        T value;
    };
    static shared_array_node* sa;
    static int free_head_slot;
    static int free_slot_partition_start;
    static int capacity;
    int head_slot;
};

// Define stack template type, used in ch3 #1.
template <typename T>
using stack_ch3_1 = stack_base<T, ssas_policy<T>>;

//
// Implementation
//

template <typename T>
typename ssas_policy<T>::shared_array_node* ssas_policy<T>::sa = new typename ssas_policy<T>::shared_array_node[ssas_policy<T>::capacity];

template <typename T>
int ssas_policy<T>::free_head_slot = -1;

template <typename T>
int ssas_policy<T>::free_slot_partition_start = 0;

template <typename T>
int ssas_policy<T>::capacity = 32;

template <typename T>
ssas_policy<T>::ssas_policy()
    : head_slot(-1)
{
}

template <typename T>
ssas_policy<T>::ssas_policy(const ssas_policy<T>& other)
{
    *this = other;
}

template <typename T>
ssas_policy<T>& ssas_policy<T>::operator=(const ssas_policy<T>& other)
{
    if (head_slot >= 0)
    {
        if (size() > count_free_slots())
        {
            throw std::runtime_error("no space left in stack");
        }
        int current_slot = head_slot;
        int tail_slot = -1;
        while (current_slot >= 0)
        {
            int free_slot;
            if (free_head_slot >= 0)
            {
                free_slot = free_head_slot;
            }
            else if (free_slot_partition_start < capacity)
            {
                free_slot = free_slot_partition_start;
            }
            else
            {
                assert(false);
            }
            int new_free_slot = sa[free_slot].next;
            sa[free_slot].next = tail_slot;
            tail_slot = free_slot;
            sa[tail_slot].data = sa[current_slot].data;
            free_slot = new_free_slot;
        }
    }
}

template <typename T>
void ssas_policy<T>::pop()
{
    if (head_slot < 0)
    {
        throw std::logic_error("empty stack");
    }
    int new_head = sa[head_slot].next;
    sa[head_slot].next = free_head_slot;
    free_head_slot = head_slot;
    head_slot = new_head;
}

template <typename T>
const T& ssas_policy<T>::peek() const
{
    if (head_slot < 0)
    {
        throw std::logic_error("empty stack");
    }
    return sa[head_slot].value;
}

template <typename T>
void ssas_policy<T>::push(const T& data)
{
    const int new_slot_idx = free_head_slot >= 0
        ? free_head_slot
        : free_slot_partition_start;
    if (new_slot_idx >= capacity)
    {
        throw std::logic_error("no space left in stack");
    }
    int next_free_slot;
    if (free_head_slot >= 0)
    {
        next_free_slot = sa[free_head_slot].next;
    }
    sa[new_slot_idx] = shared_array_node{ head_slot, data };
    head_slot = new_slot_idx;
    if (free_head_slot >= 0)
    {
        free_head_slot = next_free_slot;
    }
    else
    {
        ++free_slot_partition_start;
    }
}

template <typename T>
bool ssas_policy<T>::is_empty() const
{
    return head_slot == -1;
}

template <typename T>
int ssas_policy<T>::size() const
{
    int ret(0);
    int current = head_slot;
    while (current >= 0)
    {
        ret++;
        current = sa[current].next;
    }
    return ret;
}

template <typename T>
void ssas_policy<T>::print(std::ostream& os) const
{
    int current_slot = head_slot;
    while (current_slot >= 0)
    {
        os << sa[current_slot].value;
        current_slot = sa[current_slot].next;
        if (current_slot >= 0)
        {
            os << "->";
        }
    }
}

template <typename T>
int ssas_policy<T>::count_free_slots() const
{
    int count = 0;
    int current_free_slot = free_head_slot;
    while (current_free_slot >= 0)
    {
        ++count;
        current_free_slot = sa[current_free_slot].next;
    }
    count += free_slot_partition_start;
}
};
#endif //STACK_CH3_1_HPP
