/*
 * 204. Count Primes
 *
 * Count the number of prime numbers less than a non-negative number, n.
 */

#include "header.h"

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<int> is_prime(n, 1);
        for (int i = 2; i * i < n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return accumulate(is_prime.begin() + 2, is_prime.end(), 0);
    }
};