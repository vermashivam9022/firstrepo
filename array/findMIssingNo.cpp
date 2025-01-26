#include<bits/stdc++.h>
using namespace std;

int FindMissingNo(vector<int> &arr,int n)
{
    int total=(n*(n+1))/2;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum=sum+arr[i];
    }
    return total-sum;
}


int FindMissingNoUsingXOR(vector<int>& arr, int n)
{
    int xor1=0, xor2=0;                                // XOR2=1^2^3^4^5;      // XOR1=1^2^4^5; 
    for(int i=0; i<n-1; i++)
    {
        xor1=xor1^arr[i];
        xor2=xor2^(i+1);
    }
    xor2=xor2^n;
    return xor1^xor2;
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
    //given the 1 to n-1 number ..we have to find which number is missing
    vector<int> arr={1,2,4,5};
    int n=5;
    print_array(arr);
    cout << "Missing no is: "<<FindMissingNo(arr,n) << endl;
    cout << "Missing no using XOR is: "<<FindMissingNoUsingXOR(arr,n) << endl;
    return 0;
}