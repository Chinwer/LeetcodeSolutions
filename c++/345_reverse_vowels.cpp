/*
 * 345. Reverse Vowels of a String
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        string reverseVowels(string s) {
            if (s.empty()) {
                return s;
            }
            int l = 0, r = s.length() - 1;
            while (l < r) {
                while (l < r && !is_vowel(s[l])) {
                    l++;
                }
                while (l < r && !is_vowel(s[r])) {
                    r--;
                }
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            }
            return s;
        }

        bool is_vowel(char c) {
            return c == 'a' || c == 'A'
                || c == 'e' || c == 'E'
                || c == 'i' || c == 'I'
                || c == 'o' || c == 'O'
                || c == 'u' || c == 'U';
        }
};
