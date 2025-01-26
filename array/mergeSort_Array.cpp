#include<bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int> &arr1, const vector<int> &arr2)                  //this take O(m+n)
{
    int i=0,j=0;
    vector<int> result;
    while(i<arr1.size() && j<arr2.size())
    {   
        if(arr1[i]<=arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
    }
        else
        {
            
            
            result.push_back(arr2[j]);
            j++;
        }
    }
    if(i>=arr1.size())
    {
        while(j<arr2.size())
        {
            result.push_back(arr2[j]);
            j++;
        }
    }
    else
    {
        while(i<arr1.size())
        {
            result.push_back(arr1[i]);
            i++;
        }
    }
    return result;
}


vector<int> sortArray(vector<int> &arr, int start, int end) {                          //o(nlogn)
    // Base case: single element is already sorted
    if (start == end) {
        return {arr[start]};
    }
    int mid = (start + end) / 2;

    // Recursively sort the left and right halves
    vector<int> left = sortArray(arr, start, mid);
    vector<int> right = sortArray(arr, mid + 1, end);

    return merge(left, right);
}




void print_array(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

#ifndef USE_UNION_MAIN                   //#ifndef (if not defined) main function then use this main function  t

int main()
{
    vector<int> arr1={2,4,1,9,3,12,0,5,9,2,4,5};

    print_array(arr1);
    cout << "Sorted Array: ";
    print_array(sortArray(arr1,0,arr1.size()-1));   

    return 0;
}
#endif