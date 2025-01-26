#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //if onl positive repeation store then find unique value
    int a[]={1,2,9,3,3,2,4,1,4,5,5};
    
    int res=0;
    for(int i=0;i<11;i++)
    {
        res=res^a[i];
    }
    cout << res << endl;

    // if positve and negative value strore then find unique value
    int b[]={1,-1,2,-2,3};
    int res1=0;
    for(int i = 0; i < 5; i++) {
        res1=res1+b[i];
    }
    cout << res1 << endl;
    
    return 0;
}