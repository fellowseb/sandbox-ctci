#ifndef CH2_HPP
#define CH2_HPP

#include "linked_list.hpp"
#include <unordered_set>

namespace fellowseb_ctci
{

class runner;
/**
 * Chapter 2 | Linked Lists
 **/
namespace ch2
{
    void run(fellowseb_ctci::runner& rnr);
    /**
     * 2.1
     * Write code to remove duplicates from an unsorted linked list.
     **/
    template <typename T>
    void remove_duplicates(list_node<T>* head);
    template <typename T>
    void remove_duplicates2(list_node<T>* head);
    /**
     * 2.2
     * Implement an algorithm to find the nth last element of a singly linked list.
     **/
    template <typename T>
    list_node<T>* find_nth_to_last(list_node<T>* head, int n);
    /**
     * 2.3
     * Implement an algorithm to delete a node in the middle of a single linked list,
     * given only access to that node.
     **/
    template <typename T>
    bool remove_node(list_node<T>* node);
    /**
     * 2.4
     * Write a function that adds the two numbers and returns the sum as a linked list.
     **/
    template <typename T>
    list_node<T>* sum_numbers(list_node<T>* number1,
                              list_node<T>* number2);
    /**
     * 2.5
     * Given a circular (corrupt) linked list, implement an algorithm which
     * returns the node at the beginning of the loop.
     **/
    template <typename T>
    list_node<T>* loop_start(list_node<T>* head);
}; // namespace ch1
}; // namespace fellowseb_ctci

template <typename T>
void fellowseb_ctci::ch2::remove_duplicates(list_node<T>* head)
{
    list_node<T>* p = nullptr;
    list_node<T>* n = head;
    std::unordered_set<T> done_set;
    while (n)
    {
        if (done_set.find(n->data) != done_set.cend())
        {
            p->next = n->next;
            delete n;
        }
        else
        {
            done_set.insert(n->data);
            p = n;
        }
        n = n->next;
    }
}

template <typename T>
void fellowseb_ctci::ch2::remove_duplicates2(list_node<T>* head)
{
    if (head)
    {
        list_node<T>* previous = head;
        list_node<T>* current = head->next;
        while (current)
        {
            list_node<T>* lookup = head;
            bool found_duplicate(false);
            while (lookup != current)
            {
                if (lookup->data == current->data)
                {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                    found_duplicate = true;
                    break;
                }
                lookup = lookup->next;
            }
            if (!found_duplicate)
            {
                previous = current;
                current = current->next;
            }
        }
    }
}

template <typename T>
fellowseb_ctci::list_node<T>* fellowseb_ctci::ch2::find_nth_to_last(list_node<T>* head, int n)
{
    list_node<T>* current = head;
    list_node<T>* n_behind = head;
    while (current && n + 1 > 0)
    {
        current = current->next;
        --n;
    }
    if (!current && n + 1 > 0)
    {
        return nullptr;
    }
    while (current)
    {
        n_behind = n_behind->next;
        current = current->next;
    }
    return n_behind;
}

template <typename T>
bool fellowseb_ctci::ch2::remove_node(list_node<T>* node)
{
    if (node && node->next)
    {
        *node = *(node->next);
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
fellowseb_ctci::list_node<T>* fellowseb_ctci::ch2::sum_numbers(list_node<T>* number1,
                                                               list_node<T>* number2)
{
}

template <typename T>
fellowseb_ctci::list_node<T>* fellowseb_ctci::ch2::loop_start(list_node<T>* head)
{
}

#endif // CH2_HPP
