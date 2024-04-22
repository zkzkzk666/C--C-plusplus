// 将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
#include<stdio.h>
//定义全局变量，使i可以作用于函数的递归调用中
int i=2;

void func(int num){
    //递归结束条件，当这个数除以最后一个它的因子时，即num/i就等于1
    //num%i就是判断i是否为这个数的因子
    if (num/i<=1&&num%i==0)
    {
        printf("%d",i);
        return;
    }
    //i是因子但不是最后一个时，就要输出，并且递归调用自己
    //相当于求得因子后，把自己除以因子，除以因子的这个结果要继续求它的因子，即递归调用
    if (num%i==0)
    {
        printf("%d*",i);
        func(num/i);
    }
    //不是因子时，i递增，并递归调用再次寻找因子
    else{
        i++;
        func(num);
    }
}

int main(){
    int num;
    scanf("%d",&num);
    func(num);
    return 0;
}