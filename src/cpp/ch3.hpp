#ifndef CH3_HPP
#define CH3_HPP

#include "stack.hpp"
#include <ostream>

namespace fellowseb_ctci
{

class runner;
/**
 * Chapter 3 | Stacks and Queues
 **/
namespace ch3
{
    void run(fellowseb_ctci::runner& rnr);
    /**
     * CH3.4 | Hanoi towers
     **/
    void hanoi_towers(stack<int> *towers, std::ostream &o);
    /**
     * CH3.6 | Sort a stack
     **/
    stack<int> sort_stack(stack<int> s);
}; // namespace ch3
}; // namespace fellowseb_ctci

#endif // CH3_HPP
