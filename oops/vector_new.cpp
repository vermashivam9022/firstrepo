#include<bits/stdc++.h>
using namespace std;

class Vector{
    public:
    int size;
    int capacity;
    int *arr;

    Vector(){
        size=0;
        capacity=1;
        arr=new int[capacity];
    }

    void push_back(int value){
        if(size==capacity){
            capacity*=2;
            int *new_arr=new int[capacity];
            for(int i=0;i<size;i++){
                new_arr[i]=arr[i];
            }
            delete[] arr;
            arr=new_arr;
        }
        arr[size]=value;
        size++;
    }

    void get(int value){
        if(value<0 || value>=size){
            cout<<"Invalid index"<<endl;
            return;
        }
        cout<<"AT pos "<< value <<":" <<arr[value]<<endl;
    }

    void pop_back(){
        if(size==0)
        {
            cout<<"Vector is empty"<<endl;
            return;
        }
        size--;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"//size: "<<size<< " capacity:"<< capacity<<endl;
    }
};


int main()
{
    //your code here
    Vector v;
    v.push_back(1);
    v.print();

    v.push_back(2);
    v.print();

    v.push_back(3);
    v.print();

    v.push_back(4);
    v.print();


    v.get(3); 
    v.pop_back(); 
    v.print(); 
    v.get(1); 

    return 0;
}