#include "ch3.hpp"
#include "queue_ch3_5.hpp"
#include "runner.hpp"
#include "set_of_stacks.hpp"
#include "stack_ch3_1.hpp"
#include "stack_ch3_2.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using std::endl;
using std::function;
using std::getchar;
using std::getline;
using std::logic_error;
using std::max;
using std::ostream;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::swap;

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

    auto run3_3 = [](runner& rnr) {
        set_of_stacks<string> my_stack;
        for (int i = 1; i < 23; ++i)
        {
            stringstream ss;
            ss << "test" << i << endl;
            string str;
            getline(ss, str);
            my_stack.push(str);
        }
        rnr.output() << my_stack << endl;
        // my_stack.pop_at(1);
        // my_stack.pop_at(3);
        // rnr.output() << my_stack << endl;
    };

    auto run3_4 = [](runner& rnr) {
        stack<int> towers[3];
        for (int i = 10; i >= 1; --i)
        {
            towers[0].push(i);
        }
        hanoi_towers(towers, rnr.output());
    };

    auto run3_5 = [](runner& rnr) {
        queue_ch3_5<string> my_queue;
        my_queue.enqueue("cat");
        my_queue.enqueue("rabbit");
        assert(my_queue.dequeue() == "cat");
        my_queue.enqueue("duck");
        my_queue.enqueue("owl");
        assert(my_queue.dequeue() == "rabbit");
        assert(my_queue.dequeue() == "duck");
        my_queue.enqueue("parrot");
        my_queue.enqueue("elephant");
        assert(my_queue.dequeue() == "owl");
    };

    auto run3_6 = [](runner& rnr) {
        stack<int> stack_to_sort = { 7, 3, 8, 9, 22, 2, 4 };
        rnr.output() << stack_to_sort << endl;
        stack_to_sort = sort_stack(stack_to_sort);
        rnr.output() << stack_to_sort << endl;
    };

    rnr.output() << "CH3 - Stacks and queues" << endl;
    rnr.runAskRetry(run3_1, "3.1");
    rnr.runAskRetry(run3_2, "3.2");
    rnr.runAskRetry(run3_3, "3.3");
    rnr.runAskRetry(run3_4, "3.4");
    rnr.runAskRetry(run3_5, "3.5");
    rnr.runAskRetry(run3_6, "3.6");
}

void fellowseb_ctci::ch3::hanoi_towers(stack<int>* towers, ostream& os)
{
    const int largest_disk_value = [](const stack<int>& initial_tower) -> int {
        stack<int> tmp{ initial_tower };
        int return_value = 0;
        while (!tmp.is_empty())
        {
            int disk(tmp.peek());
            tmp.pop();
            if (return_value > disk)
            {
                throw runtime_error("wrong input: check hanoi tower disk order");
            }
            return_value = disk;
        }
        return return_value;
    }(towers[0]);

    auto print_tower_at_line = [&largest_disk_value](int line, stack<int>& rod) -> string {
        int largest_disk_value_for_print = largest_disk_value * 2;
        string s;
        if (line == rod.size() && !rod.is_empty())
        {
            const int current_value = rod.peek() * 2;
            rod.pop();
            for (int i = 0; i < (largest_disk_value_for_print - current_value) / 2; ++i)
                s += ' ';
            s += '|';
            for (int i = 0; i < current_value / 2; ++i)
                s += '_';
            s += "||";
            for (int i = 0; i < current_value / 2; ++i)
                s += '_';
            s += '|';
            for (int i = 0; i < (largest_disk_value_for_print - current_value) / 2; ++i)
                s += ' ';
        }
        else
        {
            for (int i = 0; i < largest_disk_value_for_print + 4; ++i)
                s += ' ';
        }
        return s;
    };
    auto print_current_state = [&print_tower_at_line](stack<int>* towers) -> string {
        stack<int> t1{ towers[0] },
            t2{ towers[1] },
            t3{ towers[2] };
        int max_num_lines = max(max(t1.size(),
                                    t2.size()),
                                t3.size());
        string s;
        for (int line = max_num_lines; line >= 0; --line)
        {
            s += print_tower_at_line(line, t1);
            s += print_tower_at_line(line, t2);
            s += print_tower_at_line(line, t3);
            s += '\n';
        }
        return s;
    };
    auto step = [&print_current_state](stack<int>* t, int origin_idx, int target_idx, ostream& os) -> bool {
        stack<int>& origin{ t[origin_idx] };
        stack<int>& target{ t[target_idx] };
        if (origin.is_empty())
        {
            throw logic_error("origin stack is empty");
        }
        if (!target.is_empty() && origin.peek() > target.peek())
        {
            char details[9];
            sprintf(details, "(%d > %d)", origin.peek(), target.peek());
            throw logic_error("moved disk is greater than target top disk " + string(details));
        }
        target.push(origin.peek());
        origin.pop();
        os << print_current_state(t);
        return getchar() != 'q';
        //return true;
    };
    auto count_stack_items_num = [](const stack<int>& s, int largest_plate) {
        stack<int> tmp(s);
        int count(0);
        while (!tmp.is_empty() && tmp.peek() <= largest_plate)
        {
            count++;
            tmp.pop();
        }
        return count;
    };
    function<void(stack<int>*, int, int, int, ostream&)> move_stack_of_plates =
        [&step, &move_stack_of_plates, &count_stack_items_num](stack<int>* towers, int origin_idx, int target_idx, int largest_plate, ostream& os) {
            stack<int>& origin_stack(towers[origin_idx]);
            stack<int>& target_stack(towers[target_idx]);
            int count_plates(count_stack_items_num(origin_stack, largest_plate));
            int i = 1;
            while (!origin_stack.is_empty())
            {
                int disk_value{ origin_stack.peek() };
                if (disk_value > largest_plate)
                {
                    break;
                }
                int plate_target_idx = (origin_idx + 1) % 3,
                    other_rod_idx = (origin_idx + 2) % 3;
                if (other_rod_idx == target_idx)
                {
                    swap(plate_target_idx, other_rod_idx);
                }
                if (i % 2 != count_plates % 2)
                {
                    swap(plate_target_idx, other_rod_idx);
                }
                step(towers, origin_idx, plate_target_idx, os);
                move_stack_of_plates(towers, other_rod_idx, plate_target_idx, disk_value, os);
                ++i;
            }
        };
    // Initial state print
    os << print_current_state(towers);
    move_stack_of_plates(towers, 0, 2, largest_disk_value, os);
}

fellowseb_ctci::stack<int> fellowseb_ctci::ch3::sort_stack(stack<int> s)
{
    stack<int> sorted_stack;
    while (!s.is_empty())
    {
        int current{ s.peek() };
        s.pop();
        while (!sorted_stack.is_empty() && current > sorted_stack.peek())
        {
            s.push(sorted_stack.peek());
            sorted_stack.pop();
        }
        sorted_stack.push(current);
    }
    return sorted_stack;
}
