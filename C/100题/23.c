// 用二分法求 2x^3-4x^2+3x-6=0 方程在（-10，10）之间的根

#include<stdio.h>
#include<math.h>

int main(){
    //x1,x2表示二分法中所求根的区间
    double x1=-10;
    double x2=10;
    //mid表示每个区间的中点，也是最终所求的根
    double t1,t2,t3,mid;
    mid=(x1+x2)/2;
    //将mid带入到方程中所求得的t1就是判断mid与实际根相差的精度
    t1=2*mid*mid*mid-4*mid*mid+3*mid-6;
    while (fabs(t1)>=1e-6)
    {
        //t2为f(x1),t3为f(x2)
        t2=2*x1*x1*x1-4*x1*x1+3*x1-6;
        t3=2*x2*x2*x2-4*x2*x2+3*x2-6;
        //方程的根存在于t2*t3<0的区间,方程根的存在性定理
        if (t1*t2>0)
        {
            x1=mid;
        }
        else{
            x2=mid;
        }
        mid=(x1+x2)/2;
        t1=2*mid*mid*mid-4*mid*mid+3*mid-6;
    }
    printf("%.4f",mid);
    return 0;
}