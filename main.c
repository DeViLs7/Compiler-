#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 int akeyword(char strin[]){
 char keyword[15][10]={"int","float","string","if","else","case","long"};
 int i=0,flag=0;
 for (i=0;i<32;++i){
    if(strcmp(keyword[i],strin)==0){
        flag=1;
    }
 }
 return flag;
 }
int main()
{
 char ch ,strin[10] , operators[10] ="+-*/%^=";
  FILE *fo;
  int i,j=0;
  fo =fopen("salah.txt","r");
  if (fo==NULL)
      {
        printf("the input is error\n");
        exit(0);
      }
  while ((ch=fgetc(fo))!=EOF){
    for (i=0;i<6;i++){
        if (ch == operators[i])
            printf("The word '%c' is Operator \n ",ch);
    }
    if (isalnum(ch)){
        strin[j++]=ch;}

    else if ((ch == ' '|| ch == '\n') && (j != 0))
    {
         strin[j] = '\0';
                   j = 0;
        if (akeyword(strin)==1)
            printf("This is '%s' keyword  \n", strin);
        else
            printf("This is '%s'  indentifier  \n", strin);
    }
  }
    return 0;
}
