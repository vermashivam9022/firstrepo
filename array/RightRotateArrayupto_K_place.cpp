#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void RightrotateArray_optimal(vector<int>& arr,int k)                    // o(n)
{
    int n=arr.size();
    k=k%n;
// reverse is in build function in <algorithm>  which has O(n) TC  reverse[start, end)
    reverse(arr.begin(), arr.begin()+n-k);     // rotate first n-k element
    reverse(arr.begin()+n-k, arr.end());       //rotate next n-k to n-1 element
    reverse(arr.begin(), arr.end());        //rotate whole array
}

//1 2  3 4 5   for k=2
//  4 5 1 2 3

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
    vector<int> arr={1 ,2 ,3 ,4 ,5};
    int k=3;
    print_array(arr);
    RightrotateArray_optimal(arr,k);
    print_array(arr);
    return 0;
}