#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <ostream>

namespace fellowseb_ctci
{
template <typename T>
class list_node
{
public:
    list_node(T data)
        : data(data)
        , next(nullptr){};
    void append(T data);
    void print(std::ostream& os) const;

    T data;
    list_node<T>* next;
};

template <typename T>
void list_node<T>::print(std::ostream& os) const
{
    os << data;
    if (next)
    {
        os << "->";
        next->print(os);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const list_node<T>& l)
{
    l.print(os);
    return os;
}

template <typename T>
void list_node<T>::append(T data)
{
    list_node<T>* newNode = new list_node(data);
    list_node<T>* n = this;
    while (n->next)
    {
        n = n->next;
    }
    n->next = newNode;
}

template <typename T>
void delete_node(list_node<T>* head, T data)
{
    list_node<T>* n = head;
    list_node<T>* p = nullptr;
    while (n && n->data != data)
    {
        p = n;
        n = n->next;
    }
    if (n)
    {
        if (p)
        {
            p->next = n->next;
        }
        else
        {
            head = n->next;
        }
        delete n;
    }
}
};

#endif //LINKED_LIST_HPP
