#include<iostream>
using namespace std;

int main(){
    int a[5]={3,1,7,5,4};
    int length=sizeof(a)/sizeof(int);
    //冒泡排序
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
    //排序后
    for (int k = 0; k < length; k++)
    {
        cout<<a[k]<<" ";
    }
    return 0;
}