#include<bits/stdc++.h>
#define USE_UNION_MAIN              //  if main is not define then use main function from sorting_Array.cpp
#include "sorting_Array.cpp"      // to inclde own definr sorting function using sorting_Array.cpp file

using namespace std;


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



int main()
{
    vector<int> arr1={2,4,1,9,3,12,0,5};
    vector<int> arr2={5,8,6,7,10,13,11};

    print_array(arr1);     //print_array function define in sorting_Array.cpp
    print_array(arr2);

    /*Sorting the array  using inbuilt sort*/ 

    // sort(arr1.begin(), arr1.end());            //TC: o(nlogn)    SC:  o(logn)
    // sort(arr2.begin(), arr2.end());             //TC: o(nlogn)    SC:  o(logn)


    //sorting the array using own define sortArray functions in sorting_Array.cpp file which is include in header file
    arr1=sortArray(arr1,0,arr1.size()-1); 
    arr2=sortArray(arr2,0,arr2.size()-1);           
    
    cout << "Union of two Unsorted array using Union_Function :";
    print_array(unionOfArray2(arr1,arr2));              // O(M+N)

    cout << "Union of two Unsorted array using Merge Function :";
    print_array(merge(arr1,arr2));   


    
    return 0;
}