// 求多项式：1 – 1/2 + 1/3 – 1/4 + … + 1/99 – 1/100 的值。
#include<stdio.h>
double func(int num){
    double result=0;
    for (int i = 0; i < num; i++)
    {   
        //确定多项式的正负号
        if (i%2==0)
        {   
            //用1.0来让结果转换为double类型
            result+=1.0/(i+1);
        }
        else{
            result-=1.0/(i+1);
        }
    }
    return result;
}

int main(){
    //保留16位小数
    printf("结果为%.16f",func(100));
    return 0;
}