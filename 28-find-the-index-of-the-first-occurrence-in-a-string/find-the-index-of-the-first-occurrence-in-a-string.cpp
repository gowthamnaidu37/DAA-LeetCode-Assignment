class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        // If needle is empty, return 0 (per problem definition)
        if (n == 0) return 0;

        // Iterate through haystack and check for needle
        for (int i = 0; i <= m - n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i; // Return the starting index of the first occurrence
            }
        }

        // If needle is not found, return -1
        return -1;
    }
};
