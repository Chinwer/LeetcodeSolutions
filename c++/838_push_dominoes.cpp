/*
 * 838. Push Dominoes
 * There are N dominoes in a line, and we place each domino
 * vertically upright.
 *
 * In the beginning, we simultaneously push some of the dominoes
 * either to the left or to the right.
 *
 * After each second, each domino that is falling to the left
 * pushes the adjacent domino on the left.
 *
 * Similarly, the dominoes falling to the right push their
 * adjacent dominoes standing on the right.
 *
 * When a vertical domino has dominoes falling on it from both
 * sides, it stays still due to the balance of the forces.
 *
 * For the purposes of this question, we will consider that a falling
 * domino expends no additional force to a falling or already fallen domino.
 *
 * Given a string "S" representing the initial state. S[i] = 'L',
 * if the i-th domino has been pushed to the left; S[i] = 'R',
 * if the i-th domino has been pushed to the right; S[i] = '.',
 * if the i-th domino has not been pushed.
 *
 * Return a string representing the final state. 
 *
 * Note:
 *
 * 0 <= N <= 10^5
 * String dominoes contains only 'L', 'R' and '.'
 */

#include "header.h"

class Solution {
    public:
        string pushDominoes(string dominoes) {
            // original(dominoes);
            return optimized(dominoes);
        }

        string optimized(string &dominoes) {
            int n = dominoes.length();
            vector<int> forces(n);

            int force = 0;
            for (int i = 0; i < n; i++) {
                switch (dominoes[i]) {
                    case 'R':
                        force = n;
                        break;
                    case 'L':
                        force = 0;
                        break;
                    default:
                        force = max(force - 1, 0);
                        break;
                }
                forces[i] += force;
            }

            force = 0;
            for (int i = n - 1; i >= 0; i--) {
                switch (dominoes[i]) {
                    case 'L':
                        force = n;
                        break;
                    case 'R':
                        force = 0;
                        break;
                    default:
                        force = max(force - 1, 0);
                        break;
                }
                forces[i] -= force;
            }

            for (int i = 0; i < n; i++) {
                dominoes[i] = forces[i] > 0 ? 'R' : forces[i] < 0 ? 'L' : '.';
            }
            return dominoes;
        }

        string original(string &dominoes) {
            // All dominoes will stop falling
            // after at most n - 1 seconds
            int n = dominoes.length();
            for (int j = 0; j < n; j++) {
                bool changed = false;
                string pre = dominoes;
                for (int i = 0; i < n; i++) {
                    if (pre[i] != '.') {
                        continue;
                    }
                    bool l = i > 0 && pre[i - 1] == 'R';
                    bool r = i < n - 1 && pre[i + 1] == 'L';
                    if (l && r) {
                        continue;
                    }
                    if (l) {
                        changed = true;
                        dominoes[i] = 'R';
                    }
                    if (r) {
                        changed = true;
                        dominoes[i] = 'L';
                    }
                }
                if (!changed) {
                    break;
                }
            }
            return dominoes;
        }
};
