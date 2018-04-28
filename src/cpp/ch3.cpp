#include "ch3.hpp"
#include "runner.hpp"
#include "stack_ch3_1.hpp"
#include "stack_ch3_2.hpp"
#include "stack.hpp"
#include <string>

using std::endl;
using std::string;

void fellowseb_ctci::ch3::run(fellowseb_ctci::runner& rnr)
{
    auto run3_1 = [](runner& rnr) {
        rnr.output() << "3.1 single_array_stack" << endl;
        stack_ch3_1<string> my_stack, my_stack_bis;
        my_stack.push("A1");
        my_stack_bis.push("B1");
        my_stack_bis.pop();
        my_stack.push("A2");
        my_stack.push("A3");
        my_stack_bis.push("B2");
        rnr.output() << "my_stack: " << my_stack << endl;
        rnr.output() << "my_stack_bis: " << my_stack_bis << endl;
        my_stack.pop();
        my_stack_bis.push("B3");
        my_stack_bis.push("B4");
        my_stack.push("A4");
        my_stack.push("A5");
        my_stack_bis.push("B5");
        my_stack.pop();
        rnr.output() << "my_stack: " << my_stack << endl;
        rnr.output() << "my_stack_bis: " << my_stack_bis << endl;
        my_stack_bis.pop();
        my_stack_bis.pop();
        my_stack_bis.pop();
        my_stack_bis.pop();
        rnr.output() << "my_stack_bis: " << my_stack_bis << endl;
        stack<string> my_stack_ter;
        my_stack_ter.push("C1");
        my_stack_ter.push("C2");
        my_stack_ter.pop();
        my_stack_ter.push("C3");
        rnr.output() << "my_stack_ter: " << my_stack_ter << endl;
    };

    auto run3_2 = [](runner& rnr) {
        rnr.output() << "3.2 min in stack" << endl;
        stack_ch3_2<int> my_stack;
        my_stack.push(1000);
        my_stack.push(20);
        my_stack.push(3);
        my_stack.push(4);
        my_stack.push(5);
        my_stack.push(9);
        my_stack.push(1);
        my_stack.push(1);
        my_stack.push(1);
        my_stack.push(832);
        my_stack.push(1001);
        my_stack.pop();
        my_stack.pop();
        my_stack.pop();
        my_stack.pop();
        my_stack.pop();
        rnr.output() << "min value: " << my_stack.min() << endl;
    };

    rnr.output() << "CH3 - Stacks and queues" << endl;
    rnr.runAskRetry(run3_1, "3.1");
    rnr.runAskRetry(run3_2, "3.2");
}
