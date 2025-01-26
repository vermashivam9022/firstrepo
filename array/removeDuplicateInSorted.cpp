#include<bits/stdc++.h>
using namespace std;

//  TC: o(n)  SC: o(n)
void removeDuplicates(vector<int> &arr)
{
    unordered_set<int> s;
    vector<int> arr2;
    for(int i:arr)
    {
        if(s.find(i)==s.end())
        {
            s.insert(i);
            arr2.push_back(i);
        }
    }
    arr=arr2;
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
    vector<int> arr={1,2,2,3,3,4,5,5,6,6,6};
    print_array(arr);
    removeDuplicates(arr);
    print_array(arr);
    
    return 0;
}