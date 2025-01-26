#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


// time complexity  m logn + n lonn + m+ n    ,  space complexity o(m+n) for set and o(m+n) for vector o/p
vector<int> unionOfArray1(const vector<int> &arr1,const vector<int> &arr2)
{
    vector<int> result;
    set<int> set;
    for(int i:arr1)
    {
        set.insert(i);                    //insert operation take log n time
    }
    for(int i:arr2)
    {
        set.insert(i);
    }
    for(int i:set)
    {
        result.push_back(i);
    }
    return result;
}
//********************************************************************* */

// this take o(m+n) times
vector<int> unionOfArray2(const vector<int> &arr1, const vector<int> &arr2)
{
    int i=0,j=0;
    vector<int> result;
    while(i<arr1.size() && j<arr2.size())
    {   
        if(arr1[i]<=arr2[j])
        {
            if(result.empty()|| arr1[i]!=result.back())    //check that element is not present in result or result array is empty
                result.push_back(arr1[i]);
                i++;
        }
        else
        {
            if(result.empty()||arr2[j]!=result.back())
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
    vector<int> arr1={1,2,2,3,5,9,10,11};
    vector<int> arr2={1,4,6,7,8,13,14};
    print_array(arr1);
    print_array(arr2);
    
   cout << "Union of two sorted array is :";
   print_array(unionOfArray1(arr1,arr2));
   cout << "Union of two sorted array is :";
   print_array(unionOfArray2(arr1,arr2));

   return 0;
}