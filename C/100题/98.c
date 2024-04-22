/*某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规
则如下：每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位
交换，第二位和第三位交换。请输入四位整数，输出加密后的结果。*/ 
#include<stdio.h>

void encryption(int num){
    //代表千位，百位，十位，个位
    int a,b,c,d;
    a=(num/1000+5)%10;
    b=(num/100%10+5)%10;
    c=(num/10%10+5)%10;
    d=(num%10+5)%10;
    printf("加密后结果为：%d%d%d%d",d,c,b,a);
}

int main(){
    int num;
    printf("请输入一个四位的整数：");
    scanf("%d",&num);
    encryption(num);
    return 0;
}