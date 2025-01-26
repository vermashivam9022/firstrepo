#include<bits/stdc++.h>
using namespace std;

//brute for METHOD   O(N^2)
int majorityElement1(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=0; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                if(count>n/2)
                {
                    return arr[i];
                }
            }
        }
    }
    return -1;
}

// MORE EFFICIENT METHOD using hash map O(N)  sc: o(N)
int majorityElement2(vector<int>& arr)
{
    unordered_map<int, int> map;
    for(int i=0; i<arr.size(); i++)
    {
        map[arr[i]]++;
        if(map[arr[i]]>arr.size()/2)  // // Check if the current element's count is more than n/2
        {
            return arr[i];
        }
    }
    return -1;
}


//moore's voting algorithm  tc: o(n)  sc: o(1)  optimal solution
int majorityElement3(vector<int>& arr)
{
    int count = 0;
    int element;
    for (int i = 0; i < arr.size(); i++)
    {
        if(count == 0)
        {
            element = arr[i];
            count = 1;
        }
        else if(arr[i] == element)
            count++;
        else
            count--;
    }
    count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i] == element)
        {
            count++;
            if(count > arr.size()/2)
                return element;
        }
    }
    return -1;
}

void print_array(const vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr={1,2,3,1,2,3,1,3,1,1,1,2,1,12,1};
    vector<int> arr1 = {3, 3, 4, 2, 3, 3, 3}; 
    vector<int> arr2 = {1, 2, 3, 4, 5, 6}; 
    vector<int> arr3 = {7};

    print_array(arr1);
    cout<<"Majority Element is: "<<majorityElement3(arr1)<<endl;

    print_array(arr2);
    cout<<"Majority Element is: "<<majorityElement3(arr2)<<endl;

    print_array(arr3);
    cout<<"Majority Element is: "<<majorityElement3(arr3)<<endl;
    
    return 0;
}