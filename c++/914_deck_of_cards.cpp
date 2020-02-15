/*
 * 914. X of a Kind in a Deck of Cards
 * In a deck of cards, each card has an integer written on it.
 *
 * Return true if and only if you can choose X >= 2 such that it is possible to
 * split the entire deck into 1 or more groups of cards, where:
 *
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 *
 * Constraints:
 *
 * 1 <= deck.length <= 10^4
 * 0 <= deck[i] < 10^4
 */

#include "header.h"

class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            if (deck.size() < 2) {
                return false;
            }

            map<int, int> cnt;
            for (int card : deck) {
                cnt[card]++;
            }
            auto it = cnt.begin();
            int x = it->second;
            while (++it != cnt.end()) {
                x = gcd(x, it->second);
                if (x == 1) {
                    return false;
                }
            }
            return true;
        }

        int gcd(int x, int y) {
            while (y > 0) {
                int r = x % y;
                x = y;
                y = r;
            }
            return x;
        }
};
