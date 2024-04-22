/*两个乒乓球队进行比赛，各出 3 人。甲队为 A,B,C，3 人，乙队为 X,Y,Z，3 人。有人
向队员打听比赛的名单，A 说他不和 X 比，C 说他不和 X、Z 比，请编程序找出 3 
对赛手的名单*/
#include<stdio.h>

int main(){
    char yi[3]={'X','Y','Z'};
    //三重循环找甲队与乙队对抗的所有可能
    //yi[i]是A对抗的球员,yi[j]B对抗的球员,yi[k]C对抗的球员
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //去掉乙队队员相同的情况
            if (i!=j)
            {
                for (int k = 0; k < 3; k++)
                {
                    //去掉乙队队员相同的情况
                    if (i!=k&&j!=k)
                    {
                        //A不和 X 比，C 不和 X、Z 比
                        if (i!=0&&(k!=0&&k!=2))
                        {
                            printf("A---%c\n",yi[i]);
                            printf("B---%c\n",yi[j]);
                            printf("C---%c\n",yi[k]);
                        }  
                    }
                }
            }
        }  
    }
    return 0;
}