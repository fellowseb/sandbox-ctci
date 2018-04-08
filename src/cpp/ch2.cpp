#include "ch2.hpp"
#include "runner.hpp"
#include "utils.hpp"
#include <algorithm>
#include <exception>
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
            throw new std::exception();
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

    rnr.output() << "CH2 - Linked Lists" << endl;
    rnr.runAskRetry(run2_1, "2.1");
    rnr.runAskRetry(run2_1bis, "2.1bis");
    rnr.runAskRetry(run2_2, "2.2");
}
};
