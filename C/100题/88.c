// 将一个数组逆序输出，使用指针数组操作
#include<stdio.h>

//将一个数组逆序输出
void reverse(int *arr,int len){
    //头指针
    int *start=arr;
    //尾指针
    int *end=arr+len-1;
    //通过交换数组中前后所有的数，来使数组逆序
    while (start<end)
    {
        //交换数组中前后的两个数
        int temp;
        temp=*start;
        *start=*end;
        *end=temp;
        //指针移动，继续交换数组中其他数
        start++;
        end--;
    }
}


int main(){
    int arr[]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("逆序前数组：\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    reverse(arr,len);
    printf("\n逆序后数组：\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}