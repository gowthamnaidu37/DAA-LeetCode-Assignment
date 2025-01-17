#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert numbers to strings
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        // Custom comparator to sort strings in the desired order
        sort(numStrs.begin(), numStrs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // If the largest number is "0", the result is "0" (all zeros in the input)
        if (numStrs[0] == "0") return "0";

        // Concatenate all numbers to form the result
        string result;
        for (const string& numStr : numStrs) {
            result += numStr;
        }

        return result;
    }
};
