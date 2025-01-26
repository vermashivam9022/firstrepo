#include<bits/stdc++.h>
using namespace std;

// brute force method o(n^2)
vector<int> twosum(vector<int> arr,int k)
{
    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = i + 1; j < arr.size(); j++) 
        {
            if (arr[i] + arr[j] == k) 
            {
                return {i,j};
            }
        }
    }
    return {-1,-1}; // return {-1,-1} if no pair found with given sum
}


// using hashmap   tc: o(n)  sc: o(n)

vector<int> twosum_usingHashMap(vector<int> arr,int k)
{
    unordered_map<int, int> map;                     // <elements, indices>
    for (int i = 0; i < arr.size(); i++) 
    {
        int complement = k - arr[i];               // Check if the complement is already in the map
        if (map.find(complement)!= map.end())     // If it is, we have found two elements that add up to k
        {
            return {map[complement], i};
        }
        map[arr[i]] = i;    //        // If complement is not found, add the current element and its index to the map
    }
    return {-1,-1}; // return {-1,-1} if no pair found with given sum
}


//using two pointer approach   but it work for only array have to be sorted  then take o(n) 

vector<int> twosum_usingTwoPointer(vector<int> arr,int k)
{
    int left = 0, right = arr.size() - 1;
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        if (sum == k) 
        {
            return {left, right};
        } 
        else if (sum < k) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return {-1,-1}; // return {-1,-1} if no pair found with given sum
}

void printArray(const vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr={2,6,5,8,11};
    vector<int> arr2={2,7,8,10};
    int k=8;
    printArray(arr);
    printArray(twosum(arr,k));
    printArray(twosum_usingHashMap(arr,k));
    printArray(twosum_usingTwoPointer(arr2,10));
    return 0;
}