/*
 * 983. Minimum Cost For Tickets
 *
 * In a country popular for train travel, you have planned some
 * train travelling one year in advance.  The days of the year
 * that you will travel is given as an array days.
 * Each day is an integer from 1 to 365.
 *
 * Train tickets are sold in 3 different ways:
 *
 * a 1-day pass is sold for costs[0] dollars;
 * a 7-day pass is sold for costs[1] dollars;
 * a 30-day pass is sold for costs[2] dollars.
 * The passes allow that many days of consecutive travel.
 * For example, if we get a 7-day pass on day 2, then we can
 * travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
 *
 * Return the minimum number of dollars you need to travel every
 * day in the given list of days.
 *
 * Note:
 *
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 */

#include "header.h"

class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            // return solution1(days, costs);
            return solution2(days, costs);
        }

        int solution2(vector<int>& days, vector<int>& costs) {
            int n = days.size();
            vector<int> dp(n, INT_MAX);
            vector<int> durations = { 1, 7, 30 };
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    int k = i;
                    while (k < n && days[k] < days[i] + durations[j]) {
                        k++;
                    }
                    if (k >= n) {
                        dp[i] = min(dp[i], costs[j]);
                    } else {
                        dp[i] = min(dp[i], costs[j] + dp[k]);
                    }
                }
            }
            return dp[0];
        }

        int solution1(vector<int>& days, vector<int>& costs) {
            vector<int> dp(366, 0);
            vector<int> tickets = { 1, 7, 30 };
            set<int> days_set(days.begin(), days.end());
            for (int i = 364; i >= 0; i--) {
                if (!days_set.count(i)) {
                    dp[i] = dp[i + 1];
                } else {
                    for (int j = 0; j < 3; j++) {
                        if (i + tickets[j] > 365) {
                            break;
                        }
                        if (dp[i] == 0) {
                            dp[i] = costs[j] + dp[i + tickets[j]];
                        } else {
                            dp[i] = min(dp[i], costs[j] + dp[i + tickets[j]]);
                        }
                    }
                }
            }
            return dp[0];
        }
};
