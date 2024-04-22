/* 有一篇文章，共有 3 行文字，每行有 80 个字符。要求分别统计出其中英文大写字母、
小写字母、数字、空格以及其他字符的个数*/

#include<stdio.h>
int main(){
    //创建一篇这样的文章到二维字符数组中
    char str[3][80] = {
        "The Quick Brown Fox Jumps Over 123 Lazy Dogs. A Test Sentence for Char Count.",
        "In This Line, We Have 4567 Numbers Mixed with Special Characters and Spaces.",
        "How Many UPPERCASE Letters, lowercase letters, 789 Numbers, and %* Punctuation."
    };
    //定义所求的结果
    int bigLetter=0,littleLetter=0,number=0,blank=0,another=0;
    //遍历所有字符求解
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            //判断字符所属类别
            int c=str[i][j];
            if (c>='A'&&c<='Z')
            {
                bigLetter++;
            }
            else if (c>='a'&&c<='z')
            {
                littleLetter++;
            }
            else if (c==' ')
            {
                blank++;
            }
            else if (c>='0'&&c<='9')
            {
                number++;
            }
            else{
                another++;
            }
        }
    }
    printf("大写字母个数：%d\n小写字母个数：%d\n数字个数：%d\n空格个数：%d\n其他字符个数：%d",bigLetter,littleLetter,number,blank,another);
    return 0;
}