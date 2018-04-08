#include "runner.hpp"
#include "utils.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

namespace fellowseb_ctci
{

runner::runner(int argc, char* argv[])
{
    read_params(argc, argv);
}

std::ostream& runner::output()
{
    return out
        ? *out
        : cout;
}

std::istream& runner::input()
{
    return in
        ? *in
        : cin;
}

void runner::read_params(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        string arg(argv[i]);
        if (arg == "-p" && i < argc - 1)
        {
            procSelec = split(argv[i + i], ',');
        }
        if (arg == "-i" && i < argc - 1)
        {
            vector<string> inputs = split(argv[i + 1], ',');
            in = make_unique<stringstream>();
            for (auto r : inputs)
            {
                *in << r << endl;
            }
        }
    }
}

bool runner::test_proc(const std::string& proc_id)
{
    return procSelec.empty()
        || find(procSelec.cbegin(), procSelec.cend(), proc_id) != procSelec.cend();
}

void runner::run(std::function<void(runner&)> func, const string& proc_id)
{
    if (proc_id.empty() || test_proc(proc_id))
    {
        func(*this);
    }
}

void runner::runAskRetry(const function<void(runner&)>& func, const string& proc_id)
{
    if (proc_id.empty() || test_proc(proc_id))
    {
        bool rerun = false;
        do
        {
            func(*this);
            output() << "Rerun ? (Y or N) ";
            string cont;
            input() >> cont;
            rerun = cont[0] == 'y' || cont[0] == 'Y';
            output() << endl;
        } while (rerun);
    }
}
};
