#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <functional>
#include <istream>
#include <memory>
#include <ostream>
#include <sstream>
#include <vector>

namespace fellowseb_ctci
{
class runner
{
public:
    runner(int argc, char* argv[]);

    void run(std::function<void(runner&)> func,
             const std::string& procid = "");
    void runAskRetry(const std::function<void(runner&)>& func,
                     const std::string& procid = "");
    std::ostream& output();
    std::istream& input();

private:
    void read_params(int argc, char* argv[]);
    bool test_proc(const std::string& proc_id);

    std::vector<std::string> procSelec;
    std::unique_ptr<std::stringstream> in;
    std::unique_ptr<std::ostream> out;
};
};
#endif //RUNNER_HPP
