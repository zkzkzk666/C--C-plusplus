#include<iostream>
using namespace std;

int main(){
    int a1[10];
    int a2[10]={0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i <10; i++)
    {
        cout<<a2[i]<<endl;
    }
    int a3[]={1,2,3,4,5};
    for (int j = 0; j <5; j++)
    {
        cout<<a3[j]<<endl;
    }
    return 0;
}