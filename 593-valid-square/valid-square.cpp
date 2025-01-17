#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // Function to calculate the squared distance between two points
        auto distanceSquared = [](vector<int>& a, vector<int>& b) {
            return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
        };

        // Store all squared distances between the points in a vector
        vector<int> distances = {
            distanceSquared(p1, p2),
            distanceSquared(p1, p3),
            distanceSquared(p1, p4),
            distanceSquared(p2, p3),
            distanceSquared(p2, p4),
            distanceSquared(p3, p4)
        };

        // Sort the distances
        sort(distances.begin(), distances.end());

        // A valid square must have:
        // - Four equal sides (smallest 4 distances are the same)
        // - Two equal diagonals (largest 2 distances are the same and greater than the sides)
        return distances[0] > 0 &&
               distances[0] == distances[1] &&
               distances[1] == distances[2] &&
               distances[2] == distances[3] &&
               distances[4] == distances[5];
    }
};
