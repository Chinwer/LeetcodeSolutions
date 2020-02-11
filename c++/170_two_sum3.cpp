/*
 * 170. Two Sum III - Data structure design
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 *      add - Add the number to an internal data structure.
 *     find - Find if there exists any pair of numbers which sum is equal to the value
 */

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class TwoSum {
private:
    map<int, int> dict;

public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        dict[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it : dict) {
            if ((it.first << 2) == value) {
                if (it.second >= 2) {
                    return true;
                }
            } else {
                if (dict.count(value - it.first)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
