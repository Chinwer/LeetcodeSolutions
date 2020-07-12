/*
 * 826. Most Profit Assigning Work
 *
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job.
 *
 * Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i].
 *
 * Every worker can be assigned at most one job, but one job can be completed multiple times.
 *
 * For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.
 *
 * What is the most profit we can make?
 *
 * Notes:
 * 1 <= difficulty.length = profit.length <= 10000
 * 1 <= worker.length <= 10000
 * difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
 */

#include "header.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int size = profit.size();
        vector<vector<int>> tuples;
        // bind difficulty and profit
        for (int i = 0; i < size; i++) {
            tuples.push_back(vector<int>{ difficulty[i], profit[i] });
        }
        sort(worker.begin(), worker.end());
        // sort difficulty with profit
        sort(tuples.begin(), tuples.end(), compare);

        int i = 0, res = 0;
        int max_profit = 0;
        for (int w : worker) {
            // find the largest difficulty in tuples less than or equal to w
            while (i < size && tuples[i][0] <= w) {
                if (tuples[i][1] > max_profit) {
                    max_profit = tuples[i][1];
                }
                i++;
            }
            if (i > 0) {
                i--;
            }
            res += max_profit;
        }
        return res;
    }

    static bool compare(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
};
