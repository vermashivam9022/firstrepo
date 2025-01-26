#include<bits/stdc++.h>
using namespace std;


//  o(n^3)
int longestSubarrayWithSumK1(vector<int> &arr,int sum)
{
    int max1=0;
    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = i; j < arr.size(); j++)
        {
           int sum1=0,count=0;
           for (int k = i; k <=j; k++) {
               sum1+=arr[k];
               count++;
           }
           if(sum1==sum)
           {
             max1=max(max1,count);
           }
        }
    }
    return max1;

}

// o(n^2)
int longestSubarrayWithSumK2(vector<int> &arr,int sum)
{
    int max1=0;

    for (int i = 0; i < arr.size(); i++) 
    {   int sum1=0,count=0;
        for (int j = i; j < arr.size(); j++)
        {
           sum1=sum1+arr[j];
           count++;
           if(sum1==sum)
           {
             max1=max(max1,count);
           }
        }
    }
    return max1;

}

// two pointer approach(sliding window method) only for 0 and positive number with tc: o(n)( and sc:o(1))
int longestSubarrayWithSumK3(const vector<int>& nums, int k) {
    int start = 0, current_sum = 0, max_length = 0;

    for (int end = 0; end < nums.size(); ++end) {
        // Add current element to the window
        current_sum += nums[end];

        // Shrink the window from the start if sum exceeds k
        while (current_sum > k && start <= end) {
            current_sum -= nums[start];
            start++;
        }

        // Check if we have found a subarray with sum exactly k
        if (current_sum == k) {
            max_length = max(max_length, end - start + 1);
        }
    }

    return max_length;
}


// longestsubarrayCount with sum k with hash map using prefix sum matcxh
//this will work for both negative and positive numbers  tc: o(n) and space o(n)
int longestSubarrayWithSumK4(const vector<int>& arr, int k) 
{
    int curr_sum=0;
    int max_len=0;
    unordered_map<int, int> prefix_sum;    // To store (prefix_sum, earliest index)

    for (int i = 0; i < arr.size(); i++) {
        
        curr_sum+=arr[i];

        if(curr_sum==k)
        {
            max_len=max(max_len,i+1);
        }
 // Check if (current_sum - k) exists in the map
        if(prefix_sum.find(curr_sum-i)!=prefix_sum.end())
            max_len=max(max_len,i-(curr_sum-i)+1);
        
  // Only add the current_sum to the map if it hasn't been seen before
// This ensures we store the earliest index for each prefix_sum
        if(prefix_sum.find(curr_sum)==prefix_sum.end())
        {
            prefix_sum[curr_sum]=i;
        }   
    }
    return max_len;
}

void printArray(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={1,2,2,1,1,1,1,4,2,3};
    int sum=5
    ;
    printArray(arr);
    cout << "Length of longest subarray with count of " << sum <<": " << longestSubarrayWithSumK1(arr,sum) << endl;
    cout << "Length of longest subarray with count of " << sum <<": " << longestSubarrayWithSumK2(arr,sum) << endl;
    cout << "Length of longest subarray with count of " << sum <<": " << longestSubarrayWithSumK3(arr,sum) << endl;
    cout << "Length of longest subarray with count of " << sum <<": " << longestSubarrayWithSumK4(arr,sum) << endl;



    return 0;
}

/*
Approach  1
Sliding Window Technique: The sliding window works well for non-negative numbers. With this approach:

Use two pointers, start and end, which represent the current window.
As end pointer moves, add the current element to current_sum.
If current_sum exceeds  𝑘
k, move start to the right, adjusting current_sum accordingly.
If current_sum equals 𝑘
k, update max_length with the length of the current window.
Handling Negative Numbers: If the array has negative numbers, a sliding window
technique with fixed adjustments may not work efficiently. For such cases, using a hashmap approach is recommended. 
Below is the sliding window solution for positive numbers.




To solve for the longest subarray with a sum of 
𝑘
k using a hash map, we can take advantage of prefix sums. This approach handles both positive and negative numbers, 
which the sliding window method struggles with.

Approach 2
Prefix Sum and Hash Map:

Maintain a current_sum as you iterate over the array, where current_sum is the sum of elements from the beginning of 
the array to the current position.
Use a hash map to store each current_sum and the earliest index at which it appears.
For each element:
Calculate the current_sum up to that point.
If current_sum == k, update max_length because this indicates a subarray from the start to the current index with the 
sum 
𝑘
k.
Check if (current_sum - k) exists in the hash map. If it does, this means there’s a subarray with sum 
𝑘
k from the index right after where (current_sum - k) first occurred to the current index.
If current_sum is not already in the hash map, store it with the current index (to maintain the earliest index for 
that sum).
Result: The length of the longest subarray with sum 
𝑘
k is stored in max_length.
*/