#include<iostream>
using namespace std;

int main(){
    //二维数组的定义
    //1
    int a1[2][2];
    a1[0][0]=1;
    cout<<a1[0][0]<<endl;
    //2
    int a2[2][3]={
        {1,2,3},
        {4,5,6}
    };
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<a2[i][j]<<" ";
        }
    }
    cout<<endl;
    //3
    int a3[2][3]={1,2,3,4,5,6};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<a3[i][j]<<" ";
        }
    }
    cout<<endl;

    //4
    int a4[][3]={1,2,3,4,5,6};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<a4[i][j]<<" ";
        }
    }
    cout<<endl;
    return 0;
}