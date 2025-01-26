#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/* this take o(n^2) time 

int max_subarraysum(vector<int> nums)
{
    int max_sum=INT_MIN;
    int size=nums.size();
    for (int start = 0; start < size; start++) {
        int curr_sum=0;
        for (int end = start; end < size; end++) {
            curr_sum=curr_sum+nums[end];
            max_sum=max(max_sum,curr_sum);
        }
    }
    return max_sum;
}
*/


// this take o(n) kadanes' Algorithm
int max_subarraysum(vector<int> nums)
{
    int max_sum=INT_MIN;
    int size=nums.size();
    int curr_sum=0;
    for (int i = 0; i < size; i++) {
        curr_sum=curr_sum+nums[i];
        max_sum=max(max_sum,curr_sum);
        if(curr_sum<0)
        {
            curr_sum=0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> nums={10,2,-1,4,-2,-3};

    cout << max_subarraysum(nums) << endl;


    return 0;
}