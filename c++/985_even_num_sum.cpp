/*
 * 985. Sum of Even Numbers After Queries
 * We have an array A of integers, and an array queries of queries.
 *
 * For the i-th query val = queries[i][0], index = queries[i][1], we add val to
 * A[index].  Then, the answer to the i-th query is the sum of the even values
 * of A.
 *
 * (Here, the given index = queries[i][1] is a 0-based index, and each query
 * permanently modifies the array A.)
 *
 * Return the answer to all queries.  Your answer array should
 * have answer[i] as the answer to the i-th query.
 *
 * Note:
 *
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * 1 <= queries.length <= 10000
 * -10000 <= queries[i][0] <= 10000
 * 0 <= queries[i][1] < A.length
 */

#include "header.h"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        int size = A.size();
        vector<int> res;

        for (int a : A) {
            sum += a % 2 ? 0 : a;
        }

        for (vector<int> query : queries) {
            int idx = query[1], val = query[0];
            if (!(A[idx] % 2)) {
                sum -= A[idx];
            }
            A[idx] += val;
            if (!(A[idx] % 2)) {
                sum += A[idx];
            }
            res.push_back(sum);
        }
        return res;
    }
};
