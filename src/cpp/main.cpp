#include "ch1.hpp"
#include "ch2.hpp"
#include "runner.hpp"
#include <iostream>

using namespace std;
using namespace fellowseb_ctci;

int main(int argc, char* argv[])
{
    runner r(argc, argv);
    //r.run(ch1::run);
    r.run(ch2::run);
    return 0;
}
