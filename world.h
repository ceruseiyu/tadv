#ifndef TADV_WORLD
#define TADV_WORLD
#include "item.h"

typedef struct pachain {
  struct pachain* next;
  char* name;
  char* entryStr;
  char* lookStr;
  struct pl* place;
} PathChain;

typedef struct pl {
  PathChain* paths;
  char* name;
  char* desc;
  ItemChain* inventory;
} Place;

Place* createPlace(char* n);
PathChain* createPath(char* n);

int addPath(Place* place, PathChain* path);
PathChain* getPath(Place* pl, char* n);

int addPlaceItem(Place* p, ItemChain* i);
ItemChain* getPlaceItem(Place* p, char* n);

int setPathName(PathChain* path, char* n);
int setPathEntry(PathChain* path, char* s);
int setPathLook(PathChain* path, char* s);
void setPathPlace(PathChain* path, Place* pl);

int setPlaceDesc(Place* pl, char* d);
int setPlaceName(Place* pl, char* n);
#endif
