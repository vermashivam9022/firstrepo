#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int>& arr,int k)                    //o(n^2)
{
    k=k%arr.size();
    
    for (int i = 0; i < k; i++) {

        int j=arr[0];
        for (int i = 1; i < arr.size(); i++) {
            arr[i-1]=arr[i];
        }
        arr[arr.size()-1]=j;
    }
}


// solution2   which take o(n+k)  but take o(k) space
void rotateArray2(vector<int>& arr,int k) 
{
    int size=arr.size();
    k=k%size;
    vector<int> s;
    for (int i = 0; i < k; i++) {                       //o(k)
        s.push_back(arr[i]);
    }
    for (int i = k; i < size; i++) {                      //o(n-k)
        arr[i-k]=arr[i];
    }
    for (int i = size-k; i < size; i++) {                //o(n-(n-k)) --> o(k)
        arr[i]=s[i-(size-k)];
    }
}

//optimal solution   // o(n)  and space o(1)
void rotateArray_optimal(vector<int>& arr,int k)                    // o(n)
{
    k=k%arr.size();
// reverse is in build function in <algorithm>  which has O(n) TC  reverse[start, end)
    reverse(arr.begin(), arr.begin()+k);     // rotate first 0 to k-1 element
    reverse(arr.begin()+k, arr.end());       //rotate next k to n-1 element
    reverse(arr.begin(), arr.end());        //rotate whole array
}


// if if are not using inbuild reverse then this function can be used   o(n)
void reverse_new(vector<int>& arr)
{
    int start=0;
    int end=arr.size()-1;
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
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
    vector<int> arr={1 ,2 ,3 ,4 ,5};
    int k=2;
    print_array(arr);
    rotateArray_optimal(arr,k);
    print_array(arr);
    return 0;
}