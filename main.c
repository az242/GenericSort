#include<stdio.h>
#include<stdlib.h>
#include "string.h"  
#include "sorted-list.h"

int compareInt(void* obj1, void* obj2){
  int first = *((int*)obj1);
  int second = *((int*)obj2);
  if(first > second)
    return 1;
  else if(second > first)
    return -1;
  else 
    return 0;
}

int compareChar(void* obj1, void* obj2){
  char first = *((char*)obj1);
  char second = *((char*)obj2);

  if(first > second)
    return 1;
  else if(second > first)
    return -1;
  else
    return 0;
}

int compareFloat(void* obj1, void* obj2){
  float first = *((float*)obj1);
  float second = *((float*)obj2);
  
  if(first < second)
    return -1;
  else if(first > second)
    return 1;
  else
    return 0;
}

int compareString(void* obj1, void* obj2){
  if(strcmp(obj1,obj2)<0){
    return -1;
  }else if(strcmp(obj1,obj2)>0){
    return 1;
  }else{
    return 0; 
  }
}

void df(void *obj){
}

int main(int argc, char** argv){
  char in, trash; 
  int xi;
  char xc;
  float xf;
  char *xs[30];
  void *ptr3 = NULL;
  SortedListPtr SLint = NULL;
  SortedListPtr SLchar = NULL;
  SortedListPtr SLstring = NULL;
  SortedListPtr SLfloat = NULL;
  SortedListIteratorPtr Itint = NULL;
  SortedListIteratorPtr Itchar = NULL;
  SortedListIteratorPtr Itstring = NULL;
  SortedListIteratorPtr Itfloat = NULL;
  do{
    printf("0 for sorted-list options, 1 for iterator options, and q to quit\n");
    scanf("%c", &in);
    scanf("%c", &trash);
    if(in == '0'){
      printf("0 to insert in list, 1 to remove from list, 2 to destroy list\n");
      scanf("%c", &in);
      scanf("%c", &trash);
      if(in == '0'){ //insert
	printf("0 for int, 1 for char, 2 for string, 3 for float\n");
	scanf("%c", &in);
	scanf("%c", &trash);
	if(in == '0'){ //int
	  printf("enter an int to insert\n");
	  scanf("%d", &xi);
	  scanf("%c", &trash);
	  void *ptrtest=(void*)(malloc(sizeof(int)));
	  memcpy(ptrtest, &xi, 1);
	  if(SLint == NULL){
	    SLint = SLCreate(&compareInt, &df);
	    printf("created list, SLint\n");
	  }
	  printf("output is: %d\n", SLInsert(SLint, ptrtest));
	}
	else if(in == '1'){ //char
	  printf("enter a char to insert\n");
	  scanf("%c", &xc);
	  scanf("%c", &trash);
	  void *ptr = (void*)(malloc(sizeof(char)));
	  memcpy(ptr, &xc, 1);
	  if(SLchar == NULL){
	    SLchar = SLCreate(&compareChar, &df);
	    printf("created list, SLchar\n");
	  }
	  printf("output is: %d\n", SLInsert(SLchar, ptr));
	}
	else if(in == '2'){ //string
          printf("enter a string to insert\n");
          scanf("%s",(char*) xs);
          scanf("%c", &trash);
          void *ptr = (void*)(malloc(sizeof(char[30])));
          memcpy(ptr, &xs, 30);
          if(SLstring == NULL){
            SLstring = SLCreate(&compareString, &df);
            printf("created list, SLstring\n");
          }
          printf("output is: %d\n", SLInsert(SLstring, ptr));
        }
	else if(in == '3'){ //float
	  printf("enter a char to insert\n");
          scanf("%f", &xf);
          scanf("%c", &trash);
          void *ptr = (void*)(malloc(sizeof(float)));
          memcpy(ptr, &xf, 30);
          if(SLfloat == NULL){
            SLfloat = SLCreate(&compareFloat, &df);
            printf("created list, SLfloat\n");
          }
          printf("output is: %d\n", SLInsert(SLfloat, ptr));
        }
      }
      else if(in == '1'){ //remove
	printf("0 for int, 1 for char, 2 for string, 3 for float\n");
	scanf("%c", &in);
	scanf("%c", &trash);
	if(in == '0'){ //int
	  printf("enter an int to remove\n");
	  scanf("%d", &xi);
	  scanf("%c", &trash);
	  ptr3 = &xi;
	  printf("output is: %d\n", SLRemove(SLint, ptr3));
	}
	if(in == '1'){ //char
          printf("enter a char to remove\n");
          scanf("%c", &xc);
	  scanf("%c", &trash);
          ptr3 = &xc;
          printf("output is: %d\n", SLRemove(SLchar, ptr3));
        }
	if(in == '2'){ //string
          printf("enter a string to remove\n");
          scanf("%s", (char*)xs);
          scanf("%c", &trash);
          ptr3 = &xs;
          printf("output is: %d\n", SLRemove(SLstring, ptr3));
        }
	if(in == '3'){ //float
          printf("enter a float to remove\n");
          scanf("%f", &xf);
          scanf("%c", &trash);
          ptr3 = &xf;
          printf("output is: %d\n", SLRemove(SLfloat, ptr3));
        }
      }
      else if(in == '2'){ //destroy
	printf("0 for int, 1 for char, 2 for string, 3 for float\n");
	scanf("%c", &in);
	scanf("%c",&trash);
	if(in == '0'){ //int
	  SLDestroy(SLint);
	  printf("destroyed int list\n");
	}
	if(in == '1'){ //char
          SLDestroy(SLchar);
          printf("destroyed char list\n");
        }
	if(in == '2'){ //string
	  SLDestroy(SLstring);
	  printf("destroyed string list\n");
	}
	if(in == '3'){ //float
          SLDestroy(SLfloat);
          printf("destroyed float list\n");
        }
      }
    }
    else if(in == '1'){ //iterators
      printf("0 to create iterator, 1 to getdata from iterator, 2 to iterate iterator, 3 to destroy iterator\n");
      scanf("%c", &in);
      scanf("%c", &trash);
      if(in == '0'){ //create
	printf("0 for int iterator, 1 for char iterator, 2 for string iterator, 3 for float iterator\n");
	scanf("%c", &in);
	scanf("%c", &trash);
	if(in == '0'){ // int
	  Itint = SLCreateIterator(SLint);
	  printf("made Iterator It_int\n"); 
 	}
	else if(in == '1'){ //char
	  Itchar = SLCreateIterator(SLchar);
	  printf("made Iterator It_char\n");
	}
	else if(in == '2'){ //string
          Itstring = SLCreateIterator(SLstring);
          printf("made Iterator It_string\n");
        }
	else if(in == '3'){ //float
          Itfloat = SLCreateIterator(SLfloat);
          printf("made Iterator It_float\n");
        }
	
      }
      else if(in == '1'){ //getdata
	printf("0 for int iterator, 1 for char iterator, 2 for string iterator, 3 for float iterator\n");
        scanf("%c", &in);
        scanf("%c", &trash);
        if(in == '0'){ // int
          void *ptr = (void*)(malloc(sizeof(int)));
	  ptr = SLGetItem(Itint);
	  if(ptr == NULL)
	    printf("NULL\n");
	  else 
	    printf("item: %d\n", *((int*)(ptr)));
        }
	if(in == '1'){ //char
	  void *ptr = (void*)(malloc(sizeof(char)));
	  ptr = SLGetItem(Itchar);
	  if(ptr == NULL)
	    printf("NULL\n");
	  else
	    printf("item: %c\n", *((char*)(ptr)));
	}
	if(in == '2'){ //string
          void *ptr = (void*)(malloc(sizeof(char[30])));
          ptr = SLGetItem(Itstring);
          if(ptr == NULL)
            printf("NULL\n");
          else
            printf("item: %s\n", (char*)(ptr));
        }
	if(in == '3'){ //float
          void *ptr = (void*)(malloc(sizeof(float)));
          ptr = SLGetItem(Itfloat);
          if(ptr == NULL)
            printf("NULL\n");
          else
            printf("item: %.9f\n", *((float*)(ptr)));
        }
      }
      else if(in == '2'){ //get next data
        printf("0 for int iterator, 1 for char iterator, 2 for string iterator, 3 for float iterator\n");
        scanf("%c", &in);
        scanf("%c", &trash);
        if(in == '0'){ // int
          void *ptr = (void*)(malloc(sizeof(int)));
          ptr = SLNextItem(Itint);
	  if(ptr == NULL)
	    printf("NULL\n");
	  else
	    printf("item: %d\n", *((int*)(ptr)));
        }
	if(in == '1'){ //char
	  void *ptr = (void*)(malloc(sizeof(char)));
	  ptr = SLNextItem(Itchar);
	  if(ptr == NULL)
	    printf("NULL\n");
	  else
	    printf("item: %c\n", *((char*)(ptr)));
	}
	if(in == '2'){ //string
          void *ptr = (void*)(malloc(sizeof(char[30])));
          ptr = SLNextItem(Itstring);
          if(ptr == NULL)
            printf("NULL\n");
          else
            printf("item: %s\n", (char*)(ptr));
        }
	if(in == '3'){ //float
          void *ptr = (void*)(malloc(sizeof(float)));
          ptr = SLNextItem(Itfloat);
          if(ptr == NULL)
            printf("NULL\n");
          else
            printf("item: %.9f\n", *((float*)(ptr)));
        }
      }
      else if(in == '3'){ //destroy
	printf("0 for int iterator, 1 for char iterator, 2 for string iterator, 3 for float iterator\n");
	scanf("%c", &in);
        scanf("%c", &trash);
	if(in == '0'){ // int
	  SLDestroyIterator(Itint);
	  printf("It_int destroyed");
	}
	if(in == '1'){ //char
	  SLDestroyIterator(Itchar);
	  printf("It_char destroyed");
	}
	if(in == '2'){ //string
          SLDestroyIterator(Itstring);
          printf("It_string destroyed");
        }
	if(in == '3'){ //float
          SLDestroyIterator(Itfloat);
          printf("It_float destroyed");
        }
      }
    }
  }while(in != 'q');
  
  return 0;
}
