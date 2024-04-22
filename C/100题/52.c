// 现有一有序数组，要求输入一个数后，按原来排序的规律将他插入数组中
#include<stdio.h>

int main()
{
    //升序排列
    int arr[100]={2,4,6,8,10};
    //数组中元素的个数
    int length=5;
    printf("有序数组为\n");
    for (int i = 0; i <length; i++)
    {
        printf("%d ",arr[i]);
    }
    int num;
    printf("\n请输入你想插入的数：");
    scanf("%d",&num);
    //判断num是否处于数组中间(不在数组尾)
    int flag=0;
    for (int i = 0; i < length; i++)
    {
        //当num比数组中某个数小时，先把这个数及之后的数往后移动一位，再把num插入到这个数的位置
        if (num<=arr[i])
        {
            for (int j = length; j >i; j--)
            {
                arr[j]=arr[j-1];
            }
            arr[i]=num;
            //说明num在数组中间
            flag=1;
            break;
        }
    }
    //当这个数比数组中的数都大时，把这个数放在数组尾部
    if (flag==0)
    {
        arr[length]=num;
    }
    printf("插入后该数组为\n");
    for (int i = 0; i <length+1; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
