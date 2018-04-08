#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace fellowseb_sandbox_ctci
{
template <typename Out>
void split(const std::string& s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string& s,
                               char delim);

bool is_substring(const std::string& s1,
                  const std::string& s2);
}
#endif //UTILS_HPP
