
                           https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
/*
QUESTION:-
You are given an array 'A' of size 'N' and an integer 'K'. You need to print the length of the longest subarray of array 'A' whose sum = 'K'.
Example:
Input: 'N' = 7 'K' = 3
'A' = [1, 2, 3, 1, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = '3' are:
[1, 2], [3], [1, 1, 1], [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.
*/

/*
APPROACH:-
-> Use sliding window approach using two pointers start and end
-> Run a loop to traverse the entire array add from end and subtract from start when sum>k
-> If sum==k then, update the ans now, window size = end-start+1
*/


// BRUTE FORCE 

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++)
          {
            int sum=0;
             for(int j=i;j<arr.size();j++)
               {
                 sum=sum+arr[j];
                 if(sum==k)
                  {
                      maxx=max( j-i+1,maxx);
                  }
               }
          }
          return maxx==INT_MIN?0:maxx;
    }
};


// OPTIMISED

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int K) {
        // code here
    unordered_map<int, int> prefixMap;  // stores prefixSum → first index
    int prefixSum = 0;                  // current cumulative sum
    int maxLength = 0;                  // stores maximum length found

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i]; // add current element to prefix sum

        // Case 1: If prefixSum itself equals K, subarray starts from 0
        if (prefixSum == K)
            maxLength = i + 1;

        // Case 2: If (prefixSum - K) exists, we found a subarray with sum K
        if (prefixMap.find(prefixSum - K) != prefixMap.end()) {
            int length = i - prefixMap[prefixSum - K];
            maxLength = max(maxLength, length);
        }

        // Case 3: Store prefixSum if it's not already stored
        if (prefixMap.find(prefixSum) == prefixMap.end())
            prefixMap[prefixSum] = i;
    }
    return maxLength;

    }
};






// CODE:-
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int start = 0;
    int ans = 0;
    long long sum = 0;
    int n = a.size();

    for (int end = 0; end < n; end++)
    {
        sum += a[end];
        while (sum > k)
        {
            sum -= a[start];
            start++;
        }
        if (sum == k)
        {
            ans = max(ans, end - start + 1);
        }
    }
    return ans;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)