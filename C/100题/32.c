// 已知 XYZ+YZZ=532,其中 X,Y 和 Z 为数字，编写程序求出 X,Y 和 Z 的值

#include<stdio.h>

int main(){
    for (int X = 1; X < 10; X++)
    {
        for (int Y = 1; Y < 10; Y++)
        {
            for (int Z = 0; Z < 10; Z++)
            {
                if ((X*100+Y*10+Z+Y*100+Z*10+Z)==532)
                {
                    printf("X=%d\n",X);
                    printf("Y=%d\n",Y);
                    printf("Z=%d\n",Z);
                }
            }
        }
    }
    return 0;
}