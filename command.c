#include <stdio.h>
#include <string.h>
#include "player.h"
/**
 * Print all attributes of a player in a list
 * @param p The player to list the attributes of
 */
void listAttributes(Player* p) {
  if(p == NULL) {
    printf("No player to list attributes of!\n");
    return;
  }

  printf("========================================\n");
  printf("Name: %s\n", p->name);
  printf("Location: %s\n", p->location->name);
  printf("========================================\n");

  if(p->attributes == NULL) {
    printf("No attributes to list!\n");
    return;
  }

  AttributeChain* curAttribute = p->attributes;
  while(curAttribute != NULL) {
    if(curAttribute->valTxt == NULL) {
      printf("%s: %d\n", curAttribute->name, curAttribute->val);
    } else{
      printf("%s: %s\n", curAttribute->name, curAttribute->valTxt);
    }
    curAttribute = curAttribute->next;
  }
  printf("========================================\n");
}

/**
 * Move a player along a path
 * @param p        The player to move
 * @param pathName String name of the path to move along
 */
void goPlace(Player* p, char* pathName) {
  if(p == NULL) {
    printf("No player to get paths for!\n");
    return;
  }

  PathChain* path = getPath(p->location, pathName);
  if(path == NULL) {
    printf("Path %s not found!\n", pathName);
    return;
  }

  setPlayerLocation(p, path->place);
  if(path->entryStr == NULL) {
    printf("Entering %s...\n", pathName);
  } else {
    printf("%s\n", path->entryStr);
  }

  if(p->location->desc == NULL) {
    printf("Nothing appears to be here...\n");
  } else{
    printf("%s\n", p->location->desc);
  }
}

void listPaths(Player* p) {
  if(p == NULL) {
    printf("No player to list paths for!\n");
    return;
  }

  printf("========================================\n");
  if(p->location->paths == NULL) {
    printf("No paths found!\n");
    return;
  }

  printf("Available paths:\n");
  PathChain* curPath = p->location->paths;
  while(curPath != NULL) {
    printf("%s\n", curPath->name);
    curPath = curPath->next;
  }
  printf("========================================\n");
}

void look(Player* p) {
  if(p == NULL) {
    printf("No player to look around with!");
    return;
  }


}

void processCommand(char* c, Player* p) {
  if(c == NULL) {
    printf("Error! NULL command received!\n");
  }
  char* word = strtok(c," ");
  printf("%s\n", word);
  if(strcmp(word, "list") == 0) {
    word = strtok(NULL, " ");
    if(strcmp(word, "paths") == 0) {
      listPaths(p);
      return;
    }

    if(strcmp(word, "attributes") == 0) {
      listAttributes(p);
      return;
    }

    printf("List command not recognised!\n");
    return;
  }

  if(strcmp(word, "go") == 0) {
    word = strtok(NULL, " ");
    printf("%s\n", word);
    goPlace(p, word);
    return;
  }

  printf("Command not recognised!\n");
}
