#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "utility.h"

ItemChain* createItem(char* n) {
  if(n == NULL) {
    return NULL;
  }

  ItemChain* newItem = malloc(sizeof(ItemChain));
  if(newItem == NULL) {
    return NULL;
  }

  if(setItemName(newItem, n) == -1) {
    free(newItem);
    return NULL;
  }

  return newItem;
}

int addItem(ItemChain** holder, ItemChain* newItem) {
  if(newItem == NULL) {
    return -1;
  }

  if(*holder == NULL) {
    *holder = newItem;
    return 1;
  }

  ItemChain* curItem = *holder;
  while(curItem->next != NULL) {
    curItem = curItem->next;
  }

  curItem->next = newItem;
  return 1;
}

ItemChain* getItem(ItemChain** holder, char* n) {
  if(*holder == NULL) {
    return NULL;
  }

  if(n == NULL) {
    return NULL;
  }

  ItemChain* curItem = *holder;
  while(curItem != NULL) {
    if(strcmp(curItem->name, n) == 0) {
      return curItem;
    }
    curItem = curItem->next;
  }
  return NULL;
}

int setItemName(ItemChain* i, char* n) {
  return setStr(&i->name, n);
}

int setItemDesc(ItemChain* i, char* n) {
  return setStr(&i->desc, n);
}

void setItemQuantity(ItemChain* i, int q) {
  i->quantity = q;
}
