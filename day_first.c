#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//replaceblank

char * ReplaceBlank(char *s){
    char *p=s;
    int OldLen=0;
    int blank=0;
    while(*p!='\0'){
          OldLen++;
          if(*p==' '){
            blank++;
          }
    }
    int pOld=OldLen;
    int pNew=OldLen+blank*2;
    while(pOld && pNew){
      if (s[pOld]==' '){
        s[pNew--]='0';
        s[pNew--]='2';
        s[pNew--]='%';
      }else {
        s[pNew--]=s[pOld--];
      }
    }
      return s;
}


int main(){
  char str[]="we are students";
  printf("%s ",ReplaceBlank(str));
  return 0;
}
