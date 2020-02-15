/*
 * 1086. High Five
 * Given a list of scores of different students, return the average score of
 * each student's top five scores in the order of each student's id.
 *
 * Each entry items[i] has items[i][0] the student's id, and items[i][1] the
 * student's score.  The average score is calculated using integer division.
 *
 * Note:
 *
 * 1 <= items.length <= 1000
 * items[i].length == 2
 * The IDs of the students is between 1 to 1000
 * The score of the students is between 1 to 100
 * For each student, there are at least 5 scores
 */

#include "header.h"

class Solution {
    private:
        map<int, multiset<int>> _records;

    public:
        vector<vector<int>> highFive(vector<vector<int>>& items) {
            for (vector<int> item : items) {
                multiset<int> &record = _records[item[0]];
                if (record.size() < 5) {
                    record.emplace(item[1]);
                } else if (*record.begin() < item[1]) {
                    record.erase(record.begin());
                    record.emplace(item[1]);
                }
            }

            vector<vector<int>> res;
            for (auto r : _records) {
                int avg = 0;
                for (int num : r.second) {
                    avg += num;
                }
                avg /= 5;
                res.push_back(vector<int>{ r.first, avg });
            }

            return res;
        }
};
