#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace fellowseb_ctci
{
template <typename T, typename Out>
void split(const std::string& s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        std::stringstream iss;
        iss.clear();
        iss.str(item);
        copy(std::istream_iterator<T>(iss), std::istream_iterator<T>(), result);
    }
}

std::vector<std::string> split(const std::string& s,
                               char delim);

std::vector<int> split_ints(const std::string& s,
                            char delim);

bool is_substring(const std::string& s1,
                  const std::string& s2);
}
#endif //UTILS_HPP
