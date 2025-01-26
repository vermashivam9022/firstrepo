#include<bits/stdc++.h>
using namespace std;

// brute force method o(n^2)
int maxSubArray(vector<int>& arr)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        int current_sum = 0;
        for (int j = i; j < arr.size(); j++) {
            current_sum += arr[j];
            max_sum = max(current_sum,max_sum);
        }
    }
    return max_sum;
}

// this function also print subarray and also print sum of subarray  o(n^2)
void maxSubArrayprint(vector<int>& arr)
{
    int max_sum[3] = {INT_MIN,-1,-1};
    for (int i = 0; i < arr.size(); i++) {
        int current_sum = 0;
        for (int j = i; j < arr.size(); j++) {
            current_sum += arr[j];
            if(current_sum > max_sum[0]) 
            {
                max_sum[2] = j;
                max_sum[1] = i;
                max_sum[0] = current_sum;
            }
        }
    }
    cout << "Subarray: ";
    for (int i = max_sum[1]; i <=max_sum[2]; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<< "Max Sum of subArray: " <<max_sum[0]<<endl<<endl;
}


//kadans Algorithms tc: o(N)    optimal Algorithm
int maxSubArrayUsingKadans(vector<int>& arr)
{
    int max_sum=INT_MIN;
    int current_sum=0;
    for (int i = 0; i < arr.size(); i++) {
        current_sum+=arr[i];
        max_sum=max(max_sum,current_sum);
        if(current_sum<0)
        {
            current_sum=0;
        }
    }
    return max_sum;
}


//to print subarray using kadans
void maxSubArrayPrintUsingKadans(vector<int>& arr)
{
    int max_sum=INT_MIN;
    int first=0,last=0,start=0;
    int current_sum=0;
    for (int i = 0; i < arr.size(); i++) {
        current_sum+=arr[i];
        if(current_sum>max_sum) 
        {
            max_sum=current_sum;
            first=start;
            last=i;

        }
        if(current_sum<0)
        {
            current_sum=0;
            start=i+1;  // update start index to next element of current subarray
        }
    }
    cout << "Subarray: ";
    for (int i = start; i <=last; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<< "Max Sum of subArray: " <<max_sum<<endl<<endl;
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
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Expected output: 6 (subarray [4, -1, 2, 1])

    vector<int> arr2 = {-4, -2, -3, -4, -1}; // Expected output: -1 (subarray [-1])

    vector<int> arr3 = {5, -9, 6, -2, 3}; // Expected output: 7 (subarray [6, -2, 3])

    print_array(arr1);
    maxSubArrayprint(arr1);

    print_array(arr2);
    cout<< "Max Sum of subArray: " <<maxSubArrayUsingKadans(arr2)<<endl<<endl;

    print_array(arr3);
    cout<< "Max Sum of subArray: " <<maxSubArrayUsingKadans(arr3)<<endl<<endl;

    print_array(arr3);
    maxSubArrayprint(arr3);

    print_array(arr1);
    maxSubArrayPrintUsingKadans(arr1);
    return 0;
}