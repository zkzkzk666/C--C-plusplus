// 把两个升序数组合并成一个升序数组
#include<stdio.h>
//单个数组的长度
#define N 5

int main(){
    int arr1[N]={1,4,7,8,9};
    int arr2[N]={2,3,6,9,10};
    //创建合并后数组
    int arr3[2*N];
    //j为arr1的指针，k为arr2的指针
    int j=0,k=0;
    printf("合并后数组为\n");
    for (int i = 0; i < 2*N; i++)
    {
        //如果两个数组都没有全部合并进arr3
        if (i<N&&j<N)
        {
            //arr2小于arr1，arr2里的那个数进入arr3
            if (arr1[j]>=arr2[k])
            {
                arr3[i]=arr2[k];
                k++;
            }
            //arr1小于arr2，arr1里的那个数进入arr3
            else{
                arr3[i]=arr1[j];
                j++;
            }
        }
        //k=N的话，就是arr2里的所有元素都进入arr3中了，此时把arr1中所有元素加入到arr3中即可
        else if (j<N)
        {
            arr3[i]=arr1[j];
            j++;        
        }
        //j=N的话，就是arr1里的所有元素都进入arr3中了，此时把arr2中所有元素加入到arr3中即可
        else if (k<N)
        {
            arr3[i]=arr2[k];
            k++;
        }
        printf("%d ",arr3[i]);
    }
    return 0;
}