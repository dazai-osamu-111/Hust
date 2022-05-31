#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  char name[30];
  char tel[12];
  char email[30];
} address;

struct list_el{
  address addr;
  struct List_el *next;
};
typedef struct list_el node_addr;
node_addr *root, *cur, *prev;
node_addr *makenewnode(address addr){
  node_addr *new=(node_addr*)malloc(sizeof(node_addr));
  new->addr = addr;
  new->next = NULL;
  return new;
}
address readnode(){
  address tmp;
  printf("Enter name: ");
  gets(tmp.name);
  printf("Enter telephone number: ");
  gets(tmp.tel);
  printf("Enter email: ");
  gets(tmp.email);
  return tmp;
}
void displaynode(node_addr *p){
  /* display name, tel, email in columns */
  if(p==NULL){
    printf("Null pointer error\n");
    return;
  }
  printf("Name:  %s\n", (*p).addr.name);
  printf("Tel :  %s\n", (*p).addr.tel);
  printf("Email: %s\n", (*p).addr.email);
  return;
}
void inserathead(address addr){
  node_addr* new = makenewnode(addr);
  new->next = root;
  root = new;
  cur = root;
}
void insertaftercurrentpos(address addr){
  node_addr *new=makenewnode(addr);
  if(root == NULL){
    root = new;
    cur = root;
  } else{
    new->next = cur->next;
    cur->next = new;
    /* prev = cur */
    cur = cur->next;
  }
  return;
}
void insertbefore(address addr){
  node_addr *new = makenewnode(addr);
  if(root == NULL){
    root = new;
    cur = root;
    prev= NULL;
  } else {
    new->next = cur;
    if(cur == root){
      root = new;
    }
    else prev->next = new;
    cur = new;
  }
  return;
}
void traversinglist(){
  node_addr *p;
  for (p = root; p!= NULL; p=p->next){
    displaynode(p);
  }
  return;
}
void main(){
  /* root = makenewnode(); */
  address tmp = readnode();
  root = makenewnode(tmp);
  cur = root;
  displaynode(root);
  return ;
}

