#include<stdio.h>
#include<stdlib.h>
#include "string.h"  
#include "sorted-list.h"

int compareInt(void* obj1, void* obj2){
  int first = *((int*)obj1);
  int second = *((int*)obj2);
  printf("first: %d , second: %d\n",first,second);
  if(first > second)
    return 1;
  else if(second > first)
    return -1;
  else 
    return 0;
}

int compareChar(void* obj1, void* obj2){
  char *first = (char*)obj1;
  char *second = (char*)obj2;

  if(*first > *second)
    return 1;
  else if(*second > *first)
    return -1;
  else
    return 0;
}

int compareString(void* obj1, void* obj2){
  char *first = (char*)obj1;
  char *second = (char*)obj2;
  
  int pos = 0;
  char v1;
  char v2; 

  while(pos > -1){
    v1 = first[pos];
    v2 = second[pos];
    if(v1 > 96)
      v1 = v1 - 32;
    if(v2 > 96)
      v2 = v2 - 32;
    if(v1 == '\0' && v2 == '\0')
      return 0;    
    if(v1 > v2 || v1 == '\0')
      return 1;
    else if(v2 > v1 || v2 == '\0')
      return -1;
    pos++;
  }
}

void df(void *obj){
}

int main(int argc, char** argv){
  char in, trash; 
  int xi;
  int yi;
  char xc;
  char yc;
  char *xs[30];
  char *ys[30];
  void *ptr3 = NULL;
  void *ptr4 = &yi;
  char string[10] = "";
  SortedListPtr SLint = NULL;
  do{
    printf("0 for sorted-list options, 1 for iterator options, and q to quit\n");
    scanf("%c", &in);
    scanf("%c", &trash);
    if(in == '0'){
      printf("0 to insert in list, 1 to remove from list, 2 to destroy list\n");
      scanf("%c", &in);
      scanf("%c", &trash);
      if(in == '0'){ //insert
	printf("0 for int, 1 for char, 2 for string\n");
	scanf("%c", &in);
	scanf("%c", &trash);
	if(in == '0'){ //int
	  printf("enter an int to insert\n");
	  scanf("%d", &xi);
	  scanf("%c", &trash);
	  void *ptrtest=(void*)(malloc(sizeof(int)));
	  //ptr3 = &xi;
	  memcpy(ptrtest,&xi,1);
	  if(SLint == NULL){
	    SLint = SLCreate(&compareInt, &df);
	    printf("created list, SLint\n");
	  }
	  printf("output is: %d\n", SLInsert(SLint, ptrtest));
	}
	else if(in == '1'){ //char
	  scanf("%c", &trash);
	  printf("first char\n");
	  scanf("%c", &xc);
	  scanf("%c", &in);
	  printf("second char\n");
	  scanf("%c", &yc);
	  ptr3 = &xc;
	  ptr4 = &yc;
	  printf("output is: %d\n", compareChar(ptr3, ptr4));
	  scanf("%c", &in);
	}
      }
      else if(in == '1'){ //remove
	printf("0 for int, 1 for char, 2 for string\n");
	scanf("%c", &in);
	scanf("%c", &trash);
	if(in == '0'){ //int
	  printf("enter an int to remove\n");
	  scanf("%d", &xi);
	  ptr3 = &xi;
	  printf("output is: %d\n", SLRemove(SLint, ptr3));
	}
      }
      else if(in == '2'){ //destroy
	printf("0 for int, 1 for char, 2 for string\n");
	scanf("%c\n", &in);
	if(in == '0'){ //int
	  SLDestroy(SLint);
	  printf("destroyed int list\n");
	}
      }
    }
  }while(in != 'q');
  
  return 0;
}

