#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define  MAX 200
#include<stdio_ext.h>
typedef struct{
  int ngay;
  int thang;
  int nam;
} ngaythang;
typedef struct{
  ngaythang day;
  char thoitiet[MAX];
  char nhietdo[10];
  char dacdiem[MAX];
} nhatki;
typedef nhatki element;

void swap(element *a, element *b){
  element temp;
  temp=*a;
  *a= *b;
  *b=temp;
  return;
}

void randomarray(element a[], int n){
  srand (time(NULL));
  for(int i=n-1; i>0; i--){
    int j=rand() %(i+1);
    swap(&a[i], &a[j]);
  }
}
void printrandom(element a[],int n){
  int i;
  for(i=0;i<n;i++){
      printf("Ngay %d/%d/%d, %s, %s do\n%s\n",a[i].day.ngay,a[i].day.thang,a[i].day.nam, a[i].thoitiet,a[i].nhietdo, a[i].dacdiem);
  }
  return;
}
int compare(nhatki a, nhatki b){
  if(a.day.nam<b.day.nam){
    return -1;
  } else{
    if(a.day.nam>b.day.nam){
      return 1;
    } else{
      if(a.day.thang<b.day.thang) return -1;
      else{
	if(a.day.thang>b.day.thang) return 1;
	else{
	  if(a.day.ngay<b.day.ngay) return -1;
	  else{
	    if(a.day.ngay>b.day.ngay) return 1;
	    else return 0;
	  }
	}
      }
    }
  }
}
#include "GenBSTreehw2.h"
int main(){
  int count=0,i;
  treetype T,tmp;
  char  x,x1;
  FILE *fptr;
  nhatki a,b,*arr;
  do{
    printf("1. Nap noi dung\n"
	   "2. Noi dung nhat ki\n"
	   "3. Them/ sua\n"
	   "4. Viet nhat ki o dang doan van\n"
	   "5. In ra toan bo nhat ki theo thu tu ngau nhien\n"
	   "6. Thoat\n"
	   "Ban chon: ");
    scanf("%c", &x);
    __fpurge(stdin);
    switch(x){
    case '1':
      makenulltree(&T);
      fptr=fopen("MyDiary.txt","r+");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      while(fscanf(fptr,"%d%*c%d%*c%d%*c%[^0123456789]%s%*c%[^\n]%*c",&a.day.ngay,&a.day.thang,&a.day.nam,a.thoitiet, a.nhietdo, a.dacdiem) !=EOF){
	insertnode(a, &T);
      }
      fclose(fptr);
      printf("Done\n");
      break;
    case '2':
      inorderprint(T);
      break;
    case '3':
      printf("Nhap ngay/thang/nam: ");
      scanf("%d/%d/%d", &b.day.ngay,&b.day.thang,&b.day.nam);
      tmp=search(b, T);
      if(tmp==NULL){
	printf("Ngay nay khong co trong nhat ki\n");
	printf("Nhap thong tin cho ngay\n");
	__fpurge(stdin);
	printf("Thoi tiet: ");
	gets(b.thoitiet);
	printf("Nhiet do: ");
	gets(b.nhietdo);
	printf("Noi dung: ");
	gets(b.dacdiem);
	insertnode(b, &T);
	printf("Da them vao cay\n");
      } else{
	__fpurge(stdin);
	printf("Da tim thay ngay, ban co muon chinh sua no khong(y/n)\n");
	scanf("%c", &x1);
	
	if(x1=='y'){
	  __fpurge(stdin);
	  printf("Thoi tiet: ");
	  gets(tmp->key.thoitiet);
	  printf("Nhiet do: ");
	  gets(tmp->key.nhietdo);
	  printf("Noi dung: ");
	  gets(tmp->key.dacdiem);
	} 
      }
      inorderprint(T);
      break;
    case '4':
      printf("\t");
      intheodoanvan(T);
      printf("\n");
      fptr=fopen("MyDiary.txt","r+");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      while(fscanf(fptr,"%d%*c%d%*c%d%*c%[^0123456789]%s%*c%[^\n]%*c",&a.day.ngay,&a.day.thang,&a.day.nam,a.thoitiet, a.nhietdo, a.dacdiem) !=EOF){
	count++;
	insertnode(a, &T);
      }
      arr=(nhatki*)malloc(count * sizeof(nhatki));
      if(fseek(fptr, 0, SEEK_SET) !=0){
	printf("Fseek failed\n");
	return 1;
      }
      i=0;
      while(fscanf(fptr,"%d%*c%d%*c%d%*c%[^0123456789]%s%*c%[^\n]%*c",&arr[i].day.ngay,&arr[i].day.thang,&arr[i].day.nam,arr[i].thoitiet, arr[i].nhietdo, arr[i].dacdiem) !=EOF){
	i++;
      }
      fclose(fptr);
      break;
    case '5':
      randomarray(arr, count);
      printrandom(arr, count);
      break;
    default:
      break;
    }
  } while(x!= '6');
  freetree(&T);
  return 0;
}
