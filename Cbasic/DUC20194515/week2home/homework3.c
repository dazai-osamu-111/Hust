#include<stdio.h>
int main(int argc, char *argv[]){
  FILE *fptr1,*fptr2;
  int c;
  if(argc != 3){
    printf("ERROR SYNTAX\n");
    printf("TRUE SYNTAX: apd <file1> <file2>\n");
    return 1;
  }
  if((fptr1 = fopen(argv[1],"a")) == NULL){
    printf("Cannot open %s.\n",argv[1]);
    return 1;
  }
  if((fptr2 = fopen(argv[2],"r")) == NULL){
    printf("Can not open %s.\n",argv[2]);
    return 1;
  }
  while((c=fgetc(fptr2)) != EOF){
    fputc(c,fptr1);
    putchar(c);
  }
  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
