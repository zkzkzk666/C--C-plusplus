// 输入一个带有符号位的二进制字符串，并将其转换为十进制输出
#include<stdio.h>

int main(){
    //设每次输入的字符串首位为符号位
    char str[32];
    printf("请输入一个带有符号位的二进制字符串\n");
    scanf("%31s",str);
    //当符号位为1时，表示该数是负数，增加符号
    if (str[0]=='1')
    {
        printf("-");
    }
    int x;
    //sscanf()函数是将字符串转换为纯数字
    sscanf(str,"%d",&x);
    //num为转换后的十进制数字
    int num=0;
    //a表示每次取余后相乘的数字
    int a=1;
    do
    {
        num+=(x%10*a);
        //a=1,2,4,8等
        a*=2;
        x/=10;
    }
    //当数字为负数时，最高位不能带入计算，只能算符号位
    while (str[0]=='1'?x>10:x>0);
    printf("%d",num);
    return 0;
}