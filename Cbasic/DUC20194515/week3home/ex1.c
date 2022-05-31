#include<stdio.h>
int main(int argc, char *argv[]){
  int a,count=0;
  if(argc != 3){
    printf("ERROR SYNTAX\n");
    printf("TRUE: name <file1> <file2>\n");
  }
  FILE *f1,*f2;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"w");
  if(f1 == NULL || f2 == NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  while((a= fgetc(f1)) != EOF){
    fputc(a, f2);
    putchar(a);
    if(a=='\n'){
      printf("\n");
      count ++;
    }
  }
  printf("The number line is %d\n",count);
  return 0;
}
