#include<iostream>
#include <climits>
using namespace std;


void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i]<< " ";
    }
    
}

int max(int arr[], int size)
{
    int max= INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

int min(int arr[], int size)
{
    int min= INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}


int main()
{
    int size,n;

    int arr[100];

    cout<< "enter the size of array:";
    cin>> size;
    for(int i=0;i<size;i++)
    {
        cin>>n;
        arr[i]=n;
    }

    printarray(arr,size);
    cout<< "Maximum element is: "<<max(arr,size)<<endl;
    cout<<"minimum element is: "<<min(arr,size)<<endl;
}
