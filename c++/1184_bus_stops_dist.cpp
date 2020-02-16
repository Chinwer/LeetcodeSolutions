/*
 * 1184. Distance Between Bus Stops
 * A bus has n stops numbered from 0 to n - 1 that form a circle. We know the
 * distance between all pairs of neighboring stops where distance[i] is the
 * distance between the stops number i and (i + 1) % n.
 *
 * The bus goes along both directions i.e. clockwise and counterclockwise.
 *
 * Return the shortest distance between the given start and destination stops.
 *
 * Constraints:
 *
 * 1 <= n <= 10^4
 * distance.length == n
 * 0 <= start, destination < n
 * 0 <= distance[i] <= 10^4
 */

#include "header.h"

class Solution {
    public:
        int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
            int dist1 = 0, dist2 = 0;
            int size = distance.size();
            for (int i = start; i != destination; i = ++i % size) {
                dist1 += distance[i];
            }
            for (int i = destination; i != start; i = ++i % size) {
                dist2 += distance[i];
            }
            return min(dist1, dist2);
        }
};
