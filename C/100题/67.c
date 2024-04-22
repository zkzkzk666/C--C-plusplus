/*从键盘输入一个正整数，判断他们是否是回文数，所谓回文数，是指正数和反数都一样
例如 123321 是回文数*/
#include<stdio.h>
//这个数的最大长度
#define N 10
int main(){
    //length是这个数的长度
    int num,length=0;
    printf("请输入一个正整数:");
    scanf("%d",&num);
    //创建数组存储这个数的每一位
    int arr[N];
    //循环把数组的每一位存入数组中，并求得这个数的长度
    do
    {
        arr[length]=num%10;
        num/=10;
        length++;
    } while (num>0);
    //判断是否为回文数的标志，1为非回文数，0为回文数
    int flag=0;
    for (int j = 0; j < (length/2)+1; j++)
    {
        //比较的两个数是正整数的每个位数上相对称的数
        if (arr[j]!=arr[length-j-1])
        {
            //当前后不相等时不是回文数，flag设为1
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("是回文数");
    }
    else{
        printf("不是回文数");
    }
    return 0;
}