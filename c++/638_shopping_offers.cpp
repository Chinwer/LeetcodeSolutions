/*
 * 638. Shopping Offers
 *
 *
 * In LeetCode Store, there are some kinds of items to sell. Each item has a price.
 *
 * However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
 *
 * You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
 *
 * Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
 *
 * You could use any of special offers as many times as you want.
 *
 * Note:
 * There are at most 6 kinds of items, 100 special offers.
 * For each item, you need to buy at most 6 of them.
 * You are not allowed to buy more items than you want, even if that would lower the overall price.
 */

#include "header.h"

class Solution {
    private:
        map<vector<int>, int> memo;

    public:
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
            return dfs(price, special, needs);
        }

        int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
            if (memo.count(needs)) {
                return memo[needs];
            }
            int j, res = sum(price, needs);
            int n = special.size(), nums = needs.size();

            for (vector<int> &sp : special) {
                vector<int> new_needs(needs);
                for (j = 0; j < nums; j++) {
                    int diff = needs[j] - sp[j];
                    if (diff < 0) {
                        break;
                    }
                    new_needs[j] = diff;
                }
                if (j == nums) {
                    res = min(res, sp[j] + dfs(price, special, new_needs));
                }
            }
            memo[needs] = res;
            return res;
        }

        int sum(vector<int> &price, vector<int> &needs) {
            int sum = 0, n = price.size();
            for (int i = 0; i < n; i++) {
                sum += price[i] * needs[i];
            }
            return sum;
        }
};
