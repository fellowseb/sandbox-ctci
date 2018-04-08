#include "ch1.hpp"
#include "runner.hpp"
#include <iostream>

using namespace std;
using namespace fellowseb_sandbox_ctci;

int main(int argc, char* argv[])
{
    runner r(argc, argv);
    r.run(ch1::run);
    return 0;
}
