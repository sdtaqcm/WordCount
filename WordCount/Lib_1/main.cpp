#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
int readline(char str[]){
    int i,c;
    for(i=0;i<MAXLEN-1&&(c=getchar())!=EOF&&c!='\n';++i){
        str[i]=c;
    }
    str[i]='\0';
    return i;
}

int Word(){
        char a[10000];
        int i;
        FILE *fp;
        char file[MAXLEN];
        int len;
//        printf("读取当前目录下的文本文件，请输入文件名：\n");
        len=readline(file)>0;
        if((fp=fopen(file,"rt"))==NULL){
            printf("文件打开错误\n");
            exit(0);
        }
        for(i = 0; !feof(fp); i++)
            fscanf(fp, "%c", &a[i]);
        
        fclose(fp);
     
    int num=0;
    
    for(i=0;a[i]!='\0';i++) //这里应该检查到度串尾,字符知串结束符是'\0'
    {
            if ( (a[i] >='a' && a[i] <='z') || (a[i] >='A' && a[i] <='Z') ) //如果是字母内，则一直找到非字母（分隔符:符号，空格等容）
            {
                do {
                    i++ ;
                } while ( (a[i] >='a' && a[i] <='z') || (a[i] >='A' && a[i] <='Z') );
            //记录一个单词
                num++;
            }
    }
    return num;
    
}

int charcount1()//字符的统计
{
    FILE *fp;
    char ch,file[10000];
    int len;
    int n=0;
//    printf("读取当前目录下的文本文件，请输入文件名：\n");
    len=readline(file)>0;
    if((fp=fopen(file,"rt"))==NULL){
        printf("文件打开错误\n");
        exit(0);
    }
    
    do{
       ch = fgetc(fp);
       if( feof(fp) )
       {
           break ;
       }
       if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z'))
           n++;
    }while(1);
    
    
    fclose(fp);
    return n;
}


int main(void){
    int counts=0; //统计单词数
    int count_c=0;//统计字符数
    char temp;
    scanf("%c",&temp);
    if(temp=='w'){
        char aaa;
        scanf("%c",&aaa);
        counts=Word(); //统计单词数
        printf("单词数：%d\n",counts);
    }
    else if(temp=='c'){
        char aaa;
        scanf("%c",&aaa);
        count_c=charcount1();
        printf("字符数：%d\n",count_c);
    }
    else
        printf("您输入的格式有误\n");
    
    
    
    return 1;
}

 
