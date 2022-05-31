#include<stdio.h>
#include "DirectedGraph.h"

int main(){
  int x, m, n, i, v1, v2, x3;
  int  output[30];
  double weight;
  Graph G = createGraph();
  JRB node1, node2, node;
  FILE *fin;
  do{
    printf("1. Doc ban do thanh tri.\n"
	   "2. In ra danh sach ke moi thanh tri.\n"
	   "3. Dua ra danh sach thanh tri theo yeu cau.\n"
	   "4. Tim duong di ngan nhat.\n"
	   "5. Tim duong di bo ngan nhat.\n"
	   "6. thoat\n"
	   "Ban chon? ");
    scanf("%d", &x);
    switch(x){
    case 1:
      fin = fopen("dothi.txt", "r+");
      if(fin == NULL){
	printf("Khong the moi file.\n");
	return 1;
      }
      fscanf(fin, "%d%d", &m, &n);
      for(i = 0;i<n;i++){
	fscanf(fin, "%d%d%lf", &v1, &v2, &weight);
	//printf("%d\t%d\t%lf\n", v1, v2, weight);
	addVertex(G, v1, "1");
	addVertex(G, v2, "1");
	//printf("%d %d\n", v1, v2);
	addEdge(G, v1, v2, weight);
	addEdge(G, v2, v1, weight);
      }
      printf("%-3c", ' ');
      jrb_traverse(node1, G.edges){
	printf("%-3d", (int)jval_i(node1->key));
      }
      printf("\n");
      jrb_traverse(node1, G.edges){
	printf("%-3d", (int)jval_i(node1->key));
	jrb_traverse(node2, G.vertices){
	  node = jrb_find_int((JRB)jval_v(node1->val), jval_i(node2->key));
	  if(!node) printf("%-3c",'0' );
	  else{
	    printf("%-3d", (int)getEdgeValue(G, jval_i(node1->key), jval_i(node2->key)));
	  }
	}
	printf("\n");
	}
      
      break;
    case 2:
      jrb_traverse(node, G.edges){
	n = outdegree(G, jval_i(node->key), output);
	printf("Castle %d: ", jval_i(node->key));
	for(i=0;i<n;i++){
	  printf("%d ", output[i]);
	}
	printf("\n");
      }
      break;
    case 3:
      do{
	printf("1. Danh sach thanh tri chi co the den tu 1 thanh tri khac bang cach di bo.\n");
	printf("2. Danh sach thanh tri co nhieu duong di noi truc tiep tu 1 thanh tri khac den no nhat.\n"
	       "3.Thoat\n"
	       "ban chon? ");
	scanf("%d", &x3);
	switch(x3){
	case 1:
	  
	  break;
	case 2:
	  break;
	case 3:
	  break;
	default: break;
	}
      } while(x3 != 3);
      break;
    case 4: break;
    case 5: break;
    case 6: break;
    default: break;
    }
  }while(x != 6);
  dropGraph(G);
  return 0;
}
