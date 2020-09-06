/*
 * 802. Find Eventual Safe States
 *
 * In a directed graph, we start at some node and every turn, walk along
 * a directed edge of the graph.  If we reach a node that is terminal
 * (that is, it has no outgoing directed edges), we stop.
 *
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node.  More specifically, there exists
 * a natural number K so that for any choice of where to walk, we must
 * have stopped at a terminal node in less than K steps.
 *
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 *
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is
 * the length of graph.  The graph is given in the following form:
 * graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
 *
 * Note:
 *
 * - graph will have length at most 10000.
 * - The number of edges in the graph will not exceed 32000.
 * - Each graph[i] will be a sorted list of different integers,
 *   chosen within the range [0, graph.length - 1].
 */

#include "header.h"

class Solution {
private:
    vector<vector<int>> g;

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // return topological_sorting(graph);

        g = graph;
        int n = g.size();
        vector<int> safe(n, 0);
        for (int i = 0; i < n; i++) {
            dfs(i, safe);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }

    void dfs(int i, vector<int> &safe) {
        if (safe[i] != 0) {
            return;
        }
        // mark i as dangerous node
        safe[i] = -1;
        for (int j : g[i]) {
            if (safe[j] == -1) {
                return;
            }
            dfs(j, safe);
            if (safe[j] == -1) {
                return;
            }
        }
        // mark i as safe node
        safe[i] = 1;
    }

    vector<int> topological_sorting(vector<vector<int>> &graph) {
        int n = graph.size();
        queue<int> queue;  // vertices with zero output degree
        vector<vector<int>> table(n, vector<int>(0));
        vector<int> safe(n, 0), degree(n, 0);

        // build reversed graph
        for (int i = 0; i < n; i++) {
            int m = graph[i].size();
            degree[i] = m;
            if (!m) {
                safe[i] = 1;
                queue.push(i);
            }
            for (int j : graph[i]) {
                table[j].push_back(i);
            }
        }

        // topological sorting
        while (!queue.empty()) {
            int i = queue.front();
            queue.pop();
            for (int j : table[i]) {
                degree[j]--;
                if (degree[j] == 0) {
                    queue.push(j);
                    safe[j] = 1;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};