#include<bits/stdc++.h>
using namespace std;

int maxConsectiveOnes(vector<int>& a)
{
    int max_count = 0, count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            count++;
            max_count = max(max_count, count);
        } 
        else 
            count = 0;
    }
    return max_count;
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
    vector<int> arr={1,1,0,1,1,1,0,1,1,0,1};
    print_array(arr);
    cout << "Maximum consecutive ones are: " << maxConsectiveOnes(arr) << endl;
    return 0;
}