/*从文件 D://test.txt 读取字符串，将字符串中所有的大写字母改为小写字母并写回
到源文件中*/
#include<stdio.h>

//将字符串中所有的大写字母改为小写字母
void func(char *buff){
    while (*buff!='\0')
    {
        if (*buff>='A'&&*buff<='Z')
        {
            *buff+=('a'-'A');     
        }
        buff++;
    }
}

int main(){
    //创建指向读取文件的指针，先设置为NULL，避免野指针情况
    FILE *fp=NULL;
    //读取的字符串存放的位置
    char buff[255];
    //打开文件，以读写的方式
    fp=fopen("D:/test.txt","r+");
    //预防打开文件失败的情况
    if (fp==NULL)
    {
        printf("读取文件失败\n");
        return 0;
    }
    //预防读取字符串失败的情况
    //fget()读取所有字符
    if (fgets(buff, sizeof(buff), fp) == NULL) {
        printf("读取字符串失败\n");
        fclose(fp);
        return 0;
    }
    printf("%s\n",buff);
    func(buff);
    printf("%s\n",buff);
    // 将文件指针移到文件开头
    fseek(fp, 0, SEEK_SET);
    //把字符串写入文件
    fprintf(fp,buff);
    //关闭文件
    fclose(fp);
    return 0;
}