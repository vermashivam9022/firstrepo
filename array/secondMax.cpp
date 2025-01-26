#include<bits/stdc++.h>
using namespace std;

void secondMax(vector<int> &arr)
{
    int max=arr[0],secondMax=INT_MIN;
    for(int i = 0; i < arr.size();i++)
    {
        if(arr[i]>max)
        {
            secondMax=max;
            max=arr[i];
        }
        else if(arr[i]<max && arr[i]>secondMax)
        {
            secondMax=arr[i];
        }
    }
    cout << "Max: "<<max << endl;
    cout << "second max: "<<secondMax << endl;

}
int main()
{
    vector<int> arr={0,7,2,4,9,10,10}; //
    
    secondMax(arr);
   

    return 0;
}