#include "ch2.hpp"
#include "runner.hpp"
#include "utils.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

using std::endl;
using std::for_each;
using std::string;
using std::vector;

namespace fellowseb_ctci
{
namespace
{
    list_node<int>* build_list(const string& str)
    {
        vector<int> data_vector(split_ints(str, '>'));
        if (data_vector.empty())
        {
            throw std::logic_error("invalid input");
        }
        list_node<int>* head = new list_node<int>(data_vector[0]);
        for_each(data_vector.cbegin() + 1, data_vector.cend(), [&head](const int data) { head->append(data); });
        return head;
    };
}
void ch2::run(runner& rnr)
{
    auto run2_1 = [](runner& rnr) {
        rnr.output() << "2.1 remove_duplicates" << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        list_node<int>* head = build_list(str);
        remove_duplicates(head);
        rnr.output() << "Result: " << *head << endl;
    };

    auto run2_1bis = [](runner& rnr) {
        rnr.output() << "2.1bis remove_duplicates2" << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        list_node<int>* head = build_list(str);
        remove_duplicates2(head);
        rnr.output() << "Result: " << *head << endl;
    };

    auto run2_2 = [](runner& rnr) {
        rnr.output() << "2.2 find_nth_to_last" << endl
                     << "Input list: ";
        string str;
        unsigned short n = 0;
        rnr.input() >> str;
        rnr.output() << "Input n: ";
        rnr.input() >> n;
        list_node<int>* head = build_list(str);
        list_node<int>* nth_to_last = find_nth_to_last(head, n);
        rnr.output() << "Result: " << (nth_to_last ? nth_to_last->data : -1) << endl;
    };

    auto run2_3 = [](runner& rnr) {
        rnr.output() << "2.3 remove_node" << endl
                     << "Input list: ";
        string str;
        unsigned short n = 0;
        rnr.input() >> str;
        rnr.output() << "Input item pos to remove: ";
        rnr.input() >> n;
        list_node<int>* head = build_list(str);
        list_node<int>* to_remove = head;
        for (int i = 0; i < n && to_remove; ++i)
            to_remove = to_remove->next;
        remove_node(to_remove);
        rnr.output() << "Result: " << *head << endl;
    };

    auto run2_4 = [](runner& rnr) {
        rnr.output() << "2.4 sum_nodes" << endl
                     << "Input list #1: ";
        string str, str2;
        rnr.input() >> str;
        rnr.output() << "Input list #2: ";
        rnr.input() >> str2;
        list_node<int>* number1 = build_list(str);
        list_node<int>* number2 = build_list(str2);
        list_node<int>* result = sum_numbers(number1, number2);
        rnr.output() << "Result: " << *result << endl;
    };

    auto run2_5 = [](runner& rnr) {
        rnr.output() << "2.5 loop_start" << endl
                     << "Input circular list: ";
        string str;
        rnr.input() >> str;
        unsigned int n = 0;
        rnr.output() << "Input loop start pos: ";
        rnr.input() >> n;
        list_node<int>* circular_list = build_list(str);
        list_node<int>* loop_start_node = circular_list;
        for (int i = 0; i < n && loop_start_node; ++i)
            loop_start_node = loop_start_node->next;
        list_node<int>* tail = circular_list;
        while (tail && tail->next)
        {
            tail = tail->next;
        }
        tail->next = loop_start_node;
        list_node<int>* result = loop_start(circular_list);
        rnr.output() << "Result: " << (result ? result->data : -1) << endl;
    };

    rnr.output() << "CH2 - Linked Lists" << endl;
    rnr.runAskRetry(run2_1, "2.1");
    rnr.runAskRetry(run2_1bis, "2.1bis");
    rnr.runAskRetry(run2_2, "2.2");
    rnr.runAskRetry(run2_3, "2.3");
    rnr.runAskRetry(run2_4, "2.4");
    rnr.runAskRetry(run2_5, "2.5");
}
list_node<int>* ch2::sum_numbers(list_node<int>* number1,
                                 list_node<int>* number2)
{
    if (number1 || number2)
    {
        int retenue = 0;
        list_node<int>* ret = nullptr;
        do
        {
            int sum = retenue;
            if (number1)
            {
                sum += number1->data;
            }
            if (number2)
            {
                sum += number2->data;
            }
            retenue = sum / 10;
            if (ret)
            {
                ret->append(sum % 10);
            }
            else
            {
                ret = new list_node<int>(sum % 10);
            }
            if (number1)
                number1 = number1->next;
            if (number2)
                number2 = number2->next;
        } while (number1 || number2 || retenue);
        return ret;
    }
    return nullptr;
}
};
