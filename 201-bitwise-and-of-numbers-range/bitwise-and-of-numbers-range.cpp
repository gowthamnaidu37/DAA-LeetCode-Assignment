class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            // Remove the rightmost bit of `right` until `left == right`
            right = right & (right - 1);
        }
        return left & right;
    }
};
