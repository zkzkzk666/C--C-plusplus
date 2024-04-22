// 迭代法求一个数的平方根。迭代公式：Xn+1=(Xn+a/Xn)/2，其中 a 是输入的数字。
#include<stdio.h>
#include<math.h>
int main() 
{
	double x1, x2;
	double a;//a是要求的数
	printf("请输入一个数：");
	scanf("%lf",&a);
	x2=1.0;
	while (x2>0)
	{
		x1=x2;//进行迭代
		x2=(x1+a/x1)/2.0;//再计算
		if (fabs(x1 - x2)<0.00001) 
		 {                      
			printf("该数的平方根为：%.3f",x2);
			break;
		}
	}
	return 0 ;
}