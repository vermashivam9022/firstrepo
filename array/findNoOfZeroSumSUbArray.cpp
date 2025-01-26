#include<bits/stdc++.h>
using namespace std;

   /*logic 
index:            0 1  2 3 4   5   6   7  8 9 10 11
array:            6 4 -5 1 8   3   2 -10 -4 0 4 - 9 
prefixsum:        6 10 5 6 14  17  19  9  5  5 9  0


index: 0 1  2  3  4  5 
array: 0 0  5  5  0  0
presum:0 0 10 10 10 10

 if  prefixsum is repeated that means from first value to repeated value sum become 0  eg, 6 4 -5 1  here  sum become 0
   */  

  // o(n)
int countZeroSumSubArray(const vector<int>& arr)
{
    unordered_map<int, int> prefixSum;            //  value , count
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == 0) {                              // edge case  if sum become 0 then increase count
            count++;
        }
        if (prefixSum.find(sum)!=prefixSum.end()) {         // if sum is present in map then increase count by no of time present
            count += prefixSum[sum];
        }
        prefixSum[sum]++;                     // already add prefixsum and increment count
    }
    return count;
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
    vector<int> arr={6,4,-5,1,8,3,2,-10,-4,0,4,-9};  
    vector<int> arr1={0,0,5,5,0,0};
    printArray(arr1);          
    cout<<"Count of zero sum subarrays: "<<countZeroSumSubArray(arr1)<<endl;

    return 0;
}