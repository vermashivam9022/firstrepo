#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr)
{
    bool flag=true;
    for (int i = 1; i < arr.size(); i++) {
        if(arr[i]<arr[i-1])
        {
            flag=false;
        }
    }
    return flag;
}

int main()
{
    vector<int> arr={0,1,2,3,3,4,5,5,6}; //
    
    bool flag=isSorted(arr);
    flag?cout << "Given array is sorted" << endl : cout << "Given array is not sorted" << endl;
    return 0;
}