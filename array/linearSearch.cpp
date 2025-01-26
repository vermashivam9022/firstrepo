#include<bits/stdc++.h>
using namespace std;


int linearSearch(const vector<int>& a,int k)
{
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    return -1; // return -1 if element is not found in the array
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
    vector<int> arr={1, 5, 0, 8, 0 ,9, 10};
    int k=0;
    print_array(arr);
    cout << k<<" is present at " << linearSearch(arr,k) << endl;
    return 0;
}