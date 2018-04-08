#include "ch1.hpp"
#include "runner.hpp"
#include "utils.hpp"
#include <algorithm>
#include <cstring>
#include <functional>
#include <map>
#include <utility>

using namespace std::placeholders;

using std::bind;
using std::endl;
using std::equal_to;
using std::find;
using std::for_each;
using std::make_unique;
using std::map;
using std::string;
using std::swap;

namespace fellowseb_sandbox_ctci
{

void ch1::run(runner& rnr)
{
    auto run1_1 = [](runner& rnr) {
        rnr.output() << "1.1 has_all_unique_chars" << endl;
        rnr.output() << "Input: ";
        string str1;
        rnr.input() >> str1;
        rnr.output() << "Result: " << (has_all_unique_chars(str1) ? "true" : "false")
                     << endl;
    };

    auto run1_1bis = [](runner& rnr) {
        rnr.output() << "1.1 (bis) has_all_unique_chars"
                     << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        rnr.output() << "Result: "
                     << (has_all_unique_chars2(str) ? "true" : "false")
                     << endl;
    };

    auto run1_2 = [](runner& rnr) {
        rnr.output() << "1.2 reverse_Cstyle_string" << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        auto chararr = make_unique<char[]>(str.length() + 1);
        auto cstr = chararr.get();
        strcpy(cstr, str.c_str());
        reverse_Cstyle_string(cstr);
        rnr.output() << "Result: " << cstr << endl;
    };

    auto run1_3 = [](runner& rnr) {
        rnr.output() << "1.3 remove_duplicate_chars" << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        remove_duplicate_chars(str);
        rnr.output() << "Result: " << str << endl;
    };

    auto run1_4 = [](runner& rnr) {
        rnr.output() << "1.4 are_anagrams" << endl
                     << "Input #1: ";
        string lstr, rstr;
        rnr.input() >> lstr;
        rnr.output() << "Input #2: ";
        rnr.input() >> rstr;
        rnr.output() << "Result: "
                     << (are_anagrams(rstr, lstr) ? "true" : "false")
                     << endl;
    };

    auto run1_5 = [](runner& rnr) {
        rnr.output() << "1.5 encode_HTML_space" << endl
                     << "Input: ";
        string str;
        rnr.input() >> str;
        rnr.output() << "Result: "
                     << encode_HTML_space(str)
                     << endl;
    };

    auto run1_8 = [](runner& rnr) {
        rnr.output() << "1.8 is_rotation" << endl
                     << "Input #1: ";
        string lstr, rstr;
        rnr.input() >> lstr;
        rnr.output() << "Input #2: ";
        rnr.input() >> rstr;
        rnr.output() << "Result: "
                     << (is_rotation(lstr, rstr) ? "true" : "false")
                     << endl;
    };

    rnr.output() << "CH1 - Arrays and Strings" << endl;
    rnr.runAskRetry(run1_1, "1.1");
    rnr.runAskRetry(run1_1bis, "1.1bis");
    rnr.runAskRetry(run1_2, "1.2");
    rnr.runAskRetry(run1_3, "1.3");
    rnr.runAskRetry(run1_4, "1.4");
    rnr.runAskRetry(run1_5, "1.5");
    rnr.runAskRetry(run1_8, "1.8");
}
bool ch1::has_all_unique_chars(const string& str)
{
    bool done[255] = { false };
    for (auto c : str)
    {
        if (done[c])
        {
            return false;
        }
        done[c] = true;
    }
    return true;
}
bool ch1::has_all_unique_chars2(const string& str)
{
    auto it = str.cbegin();
    for (; it != str.cend(); ++it)
    {
        if (find_if(it + 1,
                    str.cend(),
                    bind(equal_to<char>(), _1, *it))
            != str.cend())
        {
            return false;
        }
    }
    return true;
}
void ch1::reverse_Cstyle_string(char* str)
{
    if (str)
    {
        int length = strlen(str);
        if (length > 0)
        {
            for (int i = 0; i <= length / 2; ++i)
            {
                swap(str[i], str[length - i - 1]);
            }
        }
    }
}
void ch1::remove_duplicate_chars(string& str)
{
    auto start = str.begin();
    while (start != str.end())
    {
        auto comp = start + 1;
        int shiftCount = 0;
        while (comp != str.end())
        {
            if (*comp == *start)
            {
                shiftCount++;
            }
            else if (shiftCount)
            {
                *(comp - shiftCount) = *comp;
            }
            ++comp;
        }
        str.resize(str.length() - shiftCount);
        start++;
    }
}
bool ch1::are_anagrams(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size() == rhs.size())
    {
        map<char, unsigned short> dictionary;
        auto countChars = [&dictionary](char c) { dictionary[c]++; };
        for_each(lhs.cbegin(), lhs.cend(), countChars);
        for (char c : rhs)
        {
            auto entry = dictionary.find(c);
            if (entry == dictionary.end()
                || entry->second == 0)
            {
                return false;
            }
            --entry->second;
        }
        for (auto entryValue : dictionary)
        {
            if (entryValue.second)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
std::string ch1::encode_HTML_space(const std::string& str)
{
    string encodedString;
    encodedString.reserve(str.size());
    for (auto c : str)
    {
        if (c == ' ')
        {
            encodedString += "%20";
        }
        else
        {
            encodedString.push_back(c);
        }
    }
    return encodedString;
}
void ch1::rotate_ninety_degrees(size_t n, unsigned int* pixels[])
{
    size_t halfHeight = n / 2;

    for (int row = 0; row <= halfHeight; ++row)
    {
        for (int col = row; col < n - row; ++col)
        {
            swap(pixels[row][col], pixels[col][n - row - 1]);
            swap(pixels[row][col], pixels[n - row - 1][n - col - 1]);
            swap(pixels[row][col], pixels[n - col - 1][row]);
        }
    }
}
void ch1::zeroify_col_and_row(unsigned int* matrix[],
                              size_t m,
                              size_t n)
{
    auto column_flags = make_unique<bool[]>(false),
         row_flags = make_unique<bool[]>(false);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; i < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                column_flags[j] = row_flags[i] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; i < n; ++j)
        {
            if (column_flags[j] || row_flags[i])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
bool ch1::is_rotation(const std::string& str1,
                      const std::string& str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    return is_substring(str1, str2 + str2);
}
};
