#include "utils.hpp"

using std::back_inserter;
using std::copy;
using std::string;
using std::vector;

namespace fellowseb_ctci
{

vector<string> split(const string& s,
                     char delim)
{
    vector<string> elems;
    split<string>(s, delim, back_inserter(elems));
    return elems;
}
vector<int> split_ints(const string& s,
                       char delim)
{
    vector<int> elems;
    split<int>(s, delim, back_inserter(elems));
    return elems;
}
bool is_substring(const string& s1,
                  const string& s2)
{
    for (int i = 0;
         i < s2.length() && s1.length() <= s2.length() - i;
         ++i)
    {
        int j = 0;
        for (; j < s1.length(); ++j)
        {
            if (s2[i + j] != s1[j])
                break;
        }
        if (j == s1.length())
        {
            return true;
        }
    }
    return false;
}
}
