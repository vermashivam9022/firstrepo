#include<bits/stdc++.h>
using namespace std;

void moveZeroToEnd(vector<int>& arr)
{
    int n=arr.size();
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            //swap(arr[i],arr[j]);   this also work but this is inbuilt library function
            int temp=arr[i];
            arr[i]=arr[j];  
            arr[j]=temp;
            j++;
        }
    }
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
    print_array(arr);
    moveZeroToEnd(arr);
    print_array(arr);
    return 0;
}