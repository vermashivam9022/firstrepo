#include<bits/stdc++.h>
using namespace std;


int maximum(vector<int> &arr)
{
    int max=arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
int main()
{
    vector<int> arr={0,7,2,4,9,10,10}; //
    
    int max=maximum(arr);
    cout << "Max: "<< max << endl;
    return 0;
}