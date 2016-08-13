#ifndef TADV_ITEM
#define TADV_ITEM

typedef struct itemch {
  struct itemch* next;
  char* name;
  char* desc;
  int quantity;
} ItemChain;

ItemChain* createItem(char* n);

int addItem(ItemChain** holder, ItemChain* newItem);
ItemChain* getItem(ItemChain** holder, char* n);

int setItemName(ItemChain* i, char* n);
int setItemDesc(ItemChain* i, char* n);
void setItemQuantity(ItemChain* i, int q);

#endif
