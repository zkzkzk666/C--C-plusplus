/*编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，
调用函数1/1+1/3+...+1/n */
#include<stdio.h>

//n为偶数
double Odd(int n){
    double sum=0;
    //i为2，4，6....
    for (int i = 2; i <=n; i+=2)
    {
        //把i转换为double类型
        sum+=1/(double)i;
    }
    return sum;
}
//n为奇数
double Even(int n){
    double sum=0;
    //i为1，3，5....
    for (int i = 1; i <= n; i+=2)
    {
        sum+=1/(double)i;
    }
    return sum;
}
//判断n是偶数还是奇数，并调用相应的函数
double func(int n){
    if (n%2==0)
    {
        return Odd(n);
    }
    return Even(n);
}

int main(){
    int n;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    printf("结果为：%lf",func(n));
    return 0;
}