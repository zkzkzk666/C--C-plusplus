//����ʮ�����������������֡�
#include<stdio.h>

int main(){
    int max=0,num;
    for (int i = 0; i < 10; i++)
    {
        printf("�������%d����\n",i+1);
        scanf("%d",&num);
        if (num>=max)
        {
            max=num;
        }
    }
    printf("����������Ϊ%d",max);
    return 0;
}
