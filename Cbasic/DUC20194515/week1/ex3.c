#include<stdio.h>
#include<string.h>
#define MAX 1000
int main(){
  char s[MAX],name[MAX];
  int i;
  printf("Nhap ho va ten:");
  fgets(s,sizeof(s), stdin);
  for(i=strlen(s);s[i] != ' ';--i){
    strcpy(name,s[i-1]);
  }
   printf("%s",name);
  return 0;
}

