#include <vector>
#include <unordered_map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int countSubMultisets(vector<int>& nums, int l, int r) {
  // Create a map to store the number of occurrences of each element in nums.
  unordered_map<int, int> occ;
  for (int num : nums) {
    occ[num]++;
  }

  // Create a vector to store the cumulative sum of the elements in nums.
  vector<int> cumSum(nums.size() + 1, 0);
  for (int i = 0; i < nums.size(); i++) {
    cumSum[i + 1] = cumSum[i] + nums[i];
  }

  // Create a table to store the number of sub-multisets with a sum within the range [l, r]
  // up to a certain index.
  vector<vector<int>> dp(nums.size() + 1, vector<int>(r + 1, 0));

  // Initialize the base cases.
  dp[0][0] = 1;

  // Iterate over the elements in nums.
  for (int i = 1; i <= nums.size(); i++) {
    // Iterate over the possible sums.
    for (int j = 0; j <= r; j++) {
      // If the current element is not greater than the current sum,
      // then we can add it to the sub-multiset.
      if (nums[i - 1] <= j) {
        // Add the number of sub-multisets with a sum of j - nums[i - 1] to the number of sub-multisets with a sum of j.
        dp[i][j] = (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]) % MOD;
      } else {
        // The number of sub-multisets with a sum of j is equal to the number of sub-multisets with a sum of j without the current element.
        dp[i][j] = dp[i - 1][j] % MOD;
      }
    }
  }

  // Return the number of sub-multisets with a sum within the range [l, r]
  // up to the last index.
  return dp[nums.size()][r] % MOD;
}

int main() {
  vector<int> nums = {1, 2, 2, 3};
  int l = 6, r = 6;
  int count = countSubMultisets(nums, l, r);
  cout << count << endl;
  return 0;
}
