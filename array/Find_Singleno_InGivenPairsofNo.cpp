#include<bits/stdc++.h>
using namespace std;


// Tc: o(N)  Sc: o(1)
int UniqueElement(vector<int>& array)
{
    int sum=0;
    for(int i=0; i<array.size(); i++)
    {
        sum=sum^array[i];
    }
    return sum;
}


// using MapFunction          TC: Nlogn + n/2+1         SC: N/2+1
int UniqueElement2(vector<int>& array)
{
    map<int, int > array_map;
    for(int i=0; i<array.size(); i++)
    {
        array_map[array[i]]++;
    }
    for(auto i:array_map)       // Tc: n/2+1
    {
        if(i.second==1)
            return i.first;
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
    vector<int> arr={1,2,3,2,1,4,4};
    print_array(arr);
    cout << "Unique element is: " << UniqueElement(arr) << endl;
    cout << "Unique element is: " << UniqueElement2(arr) << endl;
    return 0;
}