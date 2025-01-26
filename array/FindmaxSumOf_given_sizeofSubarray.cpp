#include<bits/stdc++.h>
using namespace std;

int MaxSumInGivenSizeSubarray(vector<int> arr, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxSum = sum;
    for(int i = k; i < arr.size();i++) 
    {   
        sum = sum - arr[i-k] + arr[i];
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}
int main()
{
    vector<int> arr={1,2,3,7,1,3,1,8};
    int k=4;
    cout << "Max sum with "<<k<< "size subarray is " << MaxSumInGivenSizeSubarray(arr,k)<< endl;

    return 0;
}