#include<stdio.h>

int main(){
    int n=0;
    printf("��������������:");
    scanf("%d",&n);
    int arr[n][n];
    //�������
    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            scanf("%d",&(arr[i][j]));
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
    //��ӡ����
    printf("�þ���Ϊ:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
    //���þ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        } 
    }
    //��ӡ����
    printf("���ú����Ϊ:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
    return 0;
}
