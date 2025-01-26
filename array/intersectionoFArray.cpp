#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> arr1, vector<int> arr2)
{
    int i=0,j=0;
    vector<int> result;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr2[j]<arr1[i])
            j++;
        else
        if(arr1[i]==arr2[j])
        {
            if(result.empty() || arr1[i]!=result.back())
                result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return result;
}

void printArray(const vector<int>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr1={6,20,20,34};
    vector<int> arr2={4,5,6,8,20,34};
    printArray(arr1);
    printArray(arr2);
    cout<<"Intersect5ion of two Array is: ";
    printArray(intersection(arr1,arr2));

    return 0;
}