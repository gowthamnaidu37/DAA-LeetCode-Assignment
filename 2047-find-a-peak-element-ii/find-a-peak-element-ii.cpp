#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxRow = 0;

            // Find the row index of the maximum element in the mid column
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check if the mid column's max element is a peak
            bool leftIsSmaller = (mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]);
            bool rightIsSmaller = (mid == n - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1]);

            if (leftIsSmaller && rightIsSmaller) {
                return {maxRow, mid};
            } else if (!leftIsSmaller) {
                right = mid - 1; // Move to the left half
            } else {
                left = mid + 1; // Move to the right half
            }
        }

        return {-1, -1}; // This line should never be reached
    }
};
