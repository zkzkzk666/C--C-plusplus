// 对10个数进行排序，使用快速排序算法
#include<stdio.h>

//用第一个元素将待排序序列划分成左右两个部分，返回排序后low的位置，即枢轴的位置
int partition(int arr[],int low,int high){
    //让待排序序列中的第一个元素成为基准
    int pivot=arr[low];
    //low=high代表一次划分完成
    while (low<high)
    {
        //从待排序序列的右边往左找
        //找到一个比基准小的元素，循环就结束
        while (low<high&&pivot<=arr[high])
        {
            high--;
        }
        //让比基准小的元素移动到左边
        arr[low]=arr[high];
        //从待排序序列的左边往右找
        //找到一个比基准大的元素，循环就结束
        while (low<high&&pivot>=arr[low])
        {
            low++;
        }
        //让比基准大的元素移动到右边
        arr[high]=arr[low];
    }
    //让基准元素成为枢轴，此时，枢轴左边都是比它小的元素，枢轴右边都是比它大的元素
    arr[low]=pivot;
    //返回枢轴
    return low;
}


//快速排序
//在区间中挑选第一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序
//对于这两个区间就可以采用递归调用方式再次进行排序
void quick_sort(int arr[],int low,int high){
    //low=high代表一趟排序完成
    if (low<high)
    {
        //pivot作为划分左右两个区间的枢轴，即左子表 枢轴 右子表
        int pivot=partition(arr,low,high);
        //划分左子表
        quick_sort(arr,low,pivot-1);
        //划分右子表
        quick_sort(arr,pivot+1,high);
    }
}

int main(){
    int arr[10]={1,7,4,8,6,3,9,2,5,10};
    printf("排序前：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    quick_sort(arr,0,9);
    printf("\n排序后：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}