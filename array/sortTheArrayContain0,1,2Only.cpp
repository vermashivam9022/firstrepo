#include<bits/stdc++.h>
using namespace std;

//brute force method   //o(2n) 
void sortArray(vector<int>& nums)
{
    int count[3]={0};
    for(int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }
    for (int i = 0; i < count[0]; i++) {
        nums[i] = 0;
    }
    for (int i =count[0]; i < (count[0]+count[1]); i++) {
        nums[i] = 1;
    }
    for (int i = (count[0]+count[1]); i < nums.size(); i++) {
        nums[i] = 2;
    }
   
}


//utch National Flag Algorithm     o(N) time  sc: o(1)
//D                                         0 to low-1     low to mid-1    mid to high     high+1 to n-1
//                                          0   0    0      1   1   1      0 1 2 0 1      2 2 2 2 2

// mid to high is our array which have to sort

/*

0 to low-1   -> 0
low to mid-1   -> 1
mid to high    unsorted array
high+1 to n-1   -> 2
*/

void sortArray2(vector<int>& nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if(nums[mid]==0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
            mid++;
        else if(nums[mid]==2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
void printArray(const vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={0,1,2,0,1,1,0,2,2,0,1,2,0};
    printArray(arr);
    sortArray2(arr);
    printArray(arr);
    return 0;
}