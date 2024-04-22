#include<stdio.h>

//希尔排序，从小到大
//参数：arr[]表示待排序数组，len表示该数组长度
void shell_sort(int arr[],int len){
    //d表示增量
    //tmp保存待排序那个数的值
    //arr[i]表示待排序的那个数
    //arr[j]用来移动数据
    int i,j,d,temp;
    //初始时增量d为元素个数的一半，缩小增量d，直到d=1为止
    for (d =len/2; d>=1; d/=2)
    {
        //默认第d个数，即arr[0]是已经排序好的，所以i从d开始遍历
        for (i = d; i <=len; i++)
        {
            //如果待排序的数大于等于它之前已经排序好的序列，就不用做任何处理，如果小于的话就应该做以下处理，也就是我们熟悉的直接插入排序
            if (arr[i]<arr[i-d])
            {
                //用tmp保存数值，防止被移动过来的数覆盖
                temp=arr[i];
                //j=i-d,就是从待排序数前面相隔为d的那个数开始移动，如果比待排序数大，就往后移动，然后j-=d,从后往前遍历已经排序好的序列，直到小于或者等于待排序的数
                //如果j=0,就说明待排序的数是当前已经排序好的序列里最小的数，所以要把arr[j+d]的位置让给待排序数
                for ( j = i-d; j >=0&&arr[j]>temp; j-=d)
                {
                    arr[j+d]=arr[j];
                }
                arr[j+d]=temp;
            }
        }
    }
}

int main(){
    int arr[10]={3,2,1,7,5,9,8,4,10,6};
    shell_sort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}