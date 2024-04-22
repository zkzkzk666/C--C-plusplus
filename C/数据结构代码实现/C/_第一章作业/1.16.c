//自大到小依次输出顺序读入的三个数字X，Y，Z
#include <stdio.h>
int main(){
    int X,Y,Z,temp;
    printf("输入三个整数");
    scanf("%d %d %d",&X,&Y,&Z);
    if (X<Y)
    {
        //让X,Y互换
        temp=X;
        X=Y;
        Y=temp;
    }
    //交换后再继续比较
    if (Y<Z)
    {
        //让Z,Y互换
        temp=Z;
        Z=Y;
        Y=temp;
        if (X<Y)
        {
            //让X,Y互换
            Y=X;
            X=temp;
        }
    }
    printf("%d %d %d",X,Y,Z);
    return 0;
}