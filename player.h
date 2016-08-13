#ifndef TADV_PLAYER
#define TADV_PLAYER
#include "world.h"
#include "item.h"

typedef struct plyr {
  char* name;
  Place* location;
  struct attch* attributes;
  ItemChain* inventory;
} Player;

typedef struct attch {
  struct attch* next;
  char* name;
  char* valTxt;
  int val;
} AttributeChain;

Player* createPlayer(char* n, Place* location);
AttributeChain* createAttribute(char* n);

int addAttribute(Player* p, AttributeChain* a);
AttributeChain* getAttribute(Player* p, char* n);

int addInventoryItem(Player* p, ItemChain* i);
ItemChain* getInventoryItem(Player* p, char* n);

int setPlayerName(Player* p, char* n);
void setPlayerLocation(Player* p, Place* l);

int setAttributeName(AttributeChain* a, char* n);
int setAttributeTxt(AttributeChain* a, char* t);
int setAttributeVal(AttributeChain* a, int v);

#endif
