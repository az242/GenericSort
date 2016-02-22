#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"

/*
 * SLCreate creates a new, empty, 'SortedList'.
 *
 * SLCreate's parameters will be a comparator (cf) and destructor (df) function.
 *   Both the comparator and destructor functions will be defined by the user as per
 *     the prototypes above.
 *   Both functions must be stored in the SortedList struct.
 * 
 * SLCreate must return NULL if it does not succeed, and a non-NULL SortedListPtr
 *   on success.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
  SortedListPtr temp = NULL;
  temp = (struct SortedList *)malloc( 1 * sizeof(struct SortedList));
  temp->next = NULL;
  temp->prev = NULL;
  temp->data = NULL;
  temp->references = 0;
  temp->compare = cf;
  temp->destruct = df;
  return temp;
}

/*
 * SLDestroy destroys a SortedList, freeing all dynamically-allocated memory.
 */
void SLDestroy(SortedListPtr list){
  if(list != NULL && list->next != NULL)
    SLDestroy(list->next);
  free(list);
}

//===0.2: List Insert/Remove

/*
 * SLInsert inserts a given data item 'newObj' into a SortedList while maintaining the
 *   order and uniqueness of list items.
 * SLInsert should return 1 if 'newObj' is not equal to any other items in the list and
 *   was successfully inserted.
 * SLInsert should return 0 if 'newObj' is equal to an item already in the list or it was
 *   not successfully inserted
 *
 * Data item equality should be tested with the user's comparator function *
 */

int SLInsert(SortedListPtr list, void *newObj){
  if(list == NULL)
    return 0;
  if(list->data == NULL){ //if new list
    list->data = newObj;
    return 1;
  }
  else if(list->compare(newObj, list->data) == 0){ //if object already inserted
    return 0;
  }
  else if(list->compare(newObj, list->data) == 1){ //if object is greater than current object
    if(list->prev == NULL){ //insert at beginning of list
      SortedListPtr temp = SLCreate(list->compare, list->destruct);
      temp->next = list;
      list->prev = temp;
      temp->data = newObj;
      return 1;
    }
    else if(list->compare(newObj, list->prev->data) == -1){ //insert before current object
      SortedListPtr temp = SLCreate(list->compare, list->destruct); 
      temp->next = list;
      temp->prev = list->prev;
      list->prev->next = temp;
      list->prev = temp;
      temp->data = newObj;
      return 1;
    }
    else //continue looking backwards
      return(SLInsert(list->prev, newObj));
  }
  else if(list->compare(newObj, list->data) == -1){ //if object is less than current object
    if(list->next == NULL){ //insert at end of list
      SortedListPtr temp = SLCreate(list->compare, list->destruct);
      temp->prev = list;
      list->next = temp;
      temp->data = newObj;
      return 1;
    }
    else if(list->compare(newObj, list->next->data) == 1){ //insert before next object
      SortedListPtr temp = SLCreate(list->compare, list->destruct);
      temp->prev = list;
      temp->next = list->next;
      list->next->prev = temp;
      list->next = temp;
      temp->data = newObj;
      return 1;
    }
    else //continue looking forwards
      return(SLInsert(list->next, newObj));
  }
  return 0;
}

/*
 * SLRemove should remove 'newObj' from the SortedList in a manner that
 *   maintains list order.
 *
 * SLRemove must not modify the data item pointed to by 'newObj'.
 *
 * SLRemove should return 1 on success, and 0 on failure.
 */

int SLRemove(SortedListPtr list, void *newObj){
  if(list == NULL)
    return 0;
  if(list->data == NULL){ //if new list
    return 0;
  }
  else if(list->compare(newObj, list->data) == 0){ //if object already inserted
    if(list->prev == NULL){ //no object before
      list->next->prev = NULL;
    }
    else if(list->next == NULL){
      list->prev->next = NULL;
    }
    else{
      list->next->prev = list->prev;
      list->prev->next = list->next;
    }
    list->destruct(list);
    return 1;
  }
  else if(list->compare(newObj, list->data) == -1){ //if object is less than current object continue looking backwards
    if(list->prev == NULL)
      return 0;
    return(SLRemove(list->prev, newObj));
  }
  else if(list->compare(newObj, list->data) == 1){ //if object is greater than current object continue looking forwards
    if(list->next == NULL)
      return 0;
    return(SLRemove(list->next, newObj));
  }
  return 0;
}

/*
 * SLCreateIterator creates a SortedListIterator for the SortedList pointed to by 'list'.
 *
 * SLCreateIterator should return a non-NULL SortedListIteratorPtr on success.
 * SLCreateIterator should return a NULL SortedListIteratorPtr if it could not
 *  construct a SortedListIterator, or if the SortedListPtr parameter 'list' is NULL.
 */

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  SortedListIteratorPtr temp = NULL;
  temp = (struct SortedListIterator *)malloc( 1 * sizeof(struct SortedListIterator));
  temp->Itptr = list;
  return temp;
}


/*
 * SLDestroyIterator destroys a SortedListIterator pointed to by parameter 'iter'.
 *
 * SLDestroyIterator should destroy the SortedListIterator, but should NOT
 *  affect the list used to create the SortedListIterator in any way.
 */

void SLDestroyIterator(SortedListIteratorPtr iter){
  free(iter);
}

//===1.2: SortedList Iterator Get/Next Operations

/*
 * SLNextItem returns a pointer to the data associated with the
 *  next item in the SortedListIterator's list
 *
 * SLNextItem should return a NULL if all of iter's elements have
 *  been iterated through.
 *
 * NB: Be sure to check the length of the list that SortedListIterator holds
 *         before attempting to access and return an item from it.
 *         If an item is removed from the list, making it shorter, be careful not
 *         to try to read and return an item off the end of the list.
 */

void * SLNextItem(SortedListIteratorPtr iter){
  if(iter == NULL || iter->Itptr == NULL || iter->Itptr->next == NULL)
    return NULL;
  iter->Itptr = iter->Itptr->next;
  return iter->Itptr->data;
}

/*
 * SLGetItem should return a pointer to the current data item
 *   The current data item is the item that was most recently returned by SLNextItem
 *   SLGetItem should not alter the data item that SortedListIterator currently refers to
 *
 * SLGetItem should return a NULL pointer if the SortedListIterator has been advanced
 *  all the way through its list.
 *
 * NB: Be sure to check the length of the list that SortedListIterator holds
 *         before attempting to access and return an item from it.
 *         If an items are removed from the list, making it shorter, be careful not
 *         to try to read and return an item off the end of the list.
 */

void * SLGetItem( SortedListIteratorPtr iter ){
  if(iter == NULL || iter->Itptr == NULL)
    return NULL;
  return iter->Itptr->data;
}
