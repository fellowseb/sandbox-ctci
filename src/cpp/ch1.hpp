#ifndef CH1_HPP
#define CH1_HPP

#include <istream>
#include <ostream>
#include <string>

namespace fellowseb_ctci
{

class runner;
/**
 * Chapter 1 | Arrays and Strings
 **/
namespace ch1
{
    void run(fellowseb_ctci::runner& rnr);
    /**
     * 1.1
     * Implement an algorithm to determine if a string has
     * all unique characters.
     * What if you can not use additional data structures ?
     **/
    bool has_all_unique_chars(const std::string& str);
    bool has_all_unique_chars2(const std::string& str);
    /**
     * 1.2
     * Write code to reverse a C-style String.
     **/
    void reverse_Cstyle_string(char* str);
    /**
     * 1.3
     * Write code to remove the duplicate characters
     * in a string without using additional buffer.
     **/
    void remove_duplicate_chars(std::string& str);
    /**
     * 1.4
     * Write a metod to decide if two strings are
     * anagrams or not.
     **/
    bool are_anagrams(const std::string& lhs,
                      const std::string& rhs);
    /**
     * 1.5
     * Write a method to replace all spaces in a
     * string with '%20'.
     **/
    std::string encode_HTML_space(const std::string& str);
    /**
     * 1.6
     * Given an image reprensented by an NxM matrix,
     * where each pixel in the image is 4 bytes,
     * write a method to rotate the image by 90 degrees.
     * Can you do this in place ?
     **/
    void rotate_ninety_degrees(size_t n,
                               unsigned int* pixels[]);
    /**
     * 1.7
     * Write an algorithm such that if an element in an MxN
     * matrix is 0, its entire row and column is set to 0.
     **/
    void zeroify_col_and_row(unsigned int* matrix[],
                             size_t n,
                             size_t m);
    /**
     * 1.8
     * Assume you have a method isSubstring.
     * Given two strings s1 and s2, write code to check if
     * s2 is a rotation of s1 using only one call to isSubstring.
     **/
    bool is_rotation(const std::string& str1,
                     const std::string& str2);
}; // namespace ch1
}; // namespace fellowseb_ctci

#endif // CH1_HPP
