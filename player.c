#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "world.h"
#include "item.h"
#include "utility.h"

/**
 * Create a new Player
 * @param  n        String name of the player
 * @param  location Place location the player is at
 * @return          Newly created player, NULL if failed
 */
Player* createPlayer(char* n, Place* location) {
  if(n == NULL || location == NULL) {
    return NULL;
  }

  Player* newPlayer = malloc(sizeof(Player));
  if(newPlayer == NULL) {
    return NULL;
  }

  if(setPlayerName(newPlayer, n) == -1) {
    free(newPlayer);
    return NULL;
  }

  newPlayer->location = location;
  return newPlayer;
}

/**
 * Create a new Attribute
 * @param  n The string name of the attribute
 * @return   The newly created attribute, NULL if failed
 */
AttributeChain* createAttribute(char* n) {
  if(n == NULL) {
    return NULL;
  }

  AttributeChain* newAttribute = malloc(sizeof(AttributeChain));
  if(newAttribute == NULL) {
    return NULL;
  }

  if(setAttributeName(newAttribute, n) == -1) {
    free(newAttribute);
    return NULL;
  }
  return newAttribute;
}

/**
 * Add an attribute to a player
 * @param  p The player to add the attribute to
 * @param  a The attribute to add to the player
 * @return   1 if successful, -1 if failed
 */
int addAttribute(Player* p, AttributeChain* a) {
  if(p == NULL || a == NULL) {
    return -1;
  }

  if(p->attributes == NULL) {
    p->attributes = a;
    return 1;
  }

  AttributeChain* curAttribute = p->attributes;
  while(curAttribute->next != NULL) {
    curAttribute = curAttribute->next;
  }
  curAttribute->next = a;
  return 1;
}
/**
 * Find an attribute from a player
 * @param  p The player to search for an attribute
 * @param  n The name of the attribute to find
 * @return   The attribute found from the player, NULL if not found or failed
 */
AttributeChain* getAttribute(Player* p, char* n) {
  if(p == NULL) {
    return NULL;
  }

  if(p->attributes == NULL) {
    return NULL;
  }

  AttributeChain* curAttribute = p->attributes;
  while(curAttribute != NULL) {
    if(strcmp(curAttribute->name, n) == 0) {
      return curAttribute;
    }
    curAttribute = curAttribute->next;
  }
  return NULL;
}

int addInventoryItem(Player* p, ItemChain* i) {
  return addItem(&p->inventory, i);
}

ItemChain* getInventoryItem(Player* p, char* n) {
  return getItem(&p->inventory, n);
}

/**
 * Set the name of a player
 * @param  p The player to set the name of
 * @param  n The string to set the player's name to
 * @return   1 if successful, -1 if failed
 */
int setPlayerName(Player* p, char* n) {
  return setStr(&p->name, n);
}

/**
 * Set the location of a player
 * @param p The player to set the location of
 * @param l The location to set
 */
void setPlayerLocation(Player* p, Place* l) {
  p->location = l;
}

/**
 * Set the name of an attribute
 * @param  a Attribute to set the name of
 * @param  n The string name to set
 * @return   1 if successful, -1 if failed
 */
int setAttributeName(AttributeChain* a, char* n) {
  return setStr(&a->name, n);
}

/**
 * Set the text of an attribute
 * @param  a The attribute to set the text of
 * @param  t The string text to set
 * @return   1 if successful, -1 if failed
 */
int setAttributeTxt(AttributeChain* a, char* t) {
  return setStr(&a->valTxt, t);
}

/**
 * Set the value of an attribute
 * @param  a The attribute to set the value of
 * @param  v The int value to set
 * @return   1 if successful, -1 if failed
 */
int setAttributeVal(AttributeChain* a, int v) {
  if(a == NULL) {
    return -1;
  }
  a->val = v;
  return 1;
}
