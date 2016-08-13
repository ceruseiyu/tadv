#include <string.h>
#include <stdlib.h>
#include "world.h"
#include "utility.h"

/**
 * Create a new Place
 * @param  n Name of the place
 * @return   Newly created place, NULL if failed
 */
Place* createPlace(char* n) {
  Place* newPlace = malloc(sizeof(Place));
  if(newPlace == NULL) {
    return NULL;
  }
  if(setPlaceName(newPlace, n) == -1) {
    free(newPlace);
    return NULL;
  }
  return newPlace;
}

/**
 * Create a new Path
 * @param  n Name of the path
 * @return   Newly created path, NULL if failed
 */
PathChain* createPath(char* n) {
  PathChain* newPath = malloc(sizeof(PathChain));
  if(newPath == NULL) {
    return NULL;
  }
  if(setPathName(newPath, n) == -1) {
    free(newPath);
    return NULL;
  }
  return newPath;
}

/**
 * Add a path to a place
 * @param  place Place to add a path to
 * @param  path  Path to add to a place
 * @return       1 if successful, -1 if failed
 */
int addPath(Place* place, PathChain* path) {
  if(place == NULL || path == NULL) {
    return -1;
  }

  if(place->paths == NULL) {
    place->paths = path;
    return 1;
  }

  PathChain* curPath = place->paths;
  while(curPath->next != NULL) {
    curPath = curPath->next;
  }
  curPath->next = path;
  return 1;
}

/**
 * Find a path from a place
 * @param  pl The place to find the path from
 * @param  n  the name of the path to look for
 * @return    The found path, NULL if failed or not found.
 */
PathChain* getPath(Place* pl, char* n) {
  if(pl == NULL) {
    return NULL;
  }

  if(pl->paths == NULL) {
    return NULL;
  }

  if(n == NULL) {
    return NULL;
  }

  PathChain* curPath = pl->paths;
  while(curPath != NULL) {
    if(strcmp(curPath->name, n) == 0) {
      return curPath;
    }
    curPath = curPath->next;
  }
  return NULL;
}

int addPlaceItem(Place* p, ItemChain* i) {
  return addItem(&p->inventory, i);
}

ItemChain* getPlaceItem(Place* p, char* n) {
  return getItem(&p->inventory, n);
}

/**
 * Set the name of a path
 * @param  path Path to set the name of
 * @param  n    The name to set
 * @return      1 if successful, -1 if failed
 */
int setPathName(PathChain* path, char* n) {
  return setStr(&path->name, n);
}

/**
 * Set the Entry String of a path
 * @param  path Path to set the Entry String of
 * @param  s    The string to set
 * @return      1 if successful, -1 if failed
 */
int setPathEntry(PathChain* path, char* s) {
  return setStr(&path->entryStr, s);
}

/**
 * Set the Look String of a path
 * @param  path Path to set the look string of
 * @param  s    The string to set
 * @return      1 if successful, -1 if failed
 */
int setPathLook(PathChain* path, char* s) {
  return setStr(&path->lookStr, s);
}

/**
 * Set the Place pointer of a pather
 * @param path The path to set the place pointer of
 * @param pl   The place pointer to set
 */
void setPathPlace(PathChain* path, Place* pl) {
  path->place = pl;
}

/**
 * Set the description of a place
 * @param  pl The place to set the description of
 * @param  d  String description to set
 * @return    1 if successful, -1 if failed
 */
int setPlaceDesc(Place* pl, char* d) {
  return setStr(&pl->desc, d);
}

/**
 * Set the name of a place
 * @param  pl The place to set the name of
 * @param  n  The string name to set
 * @return    1 if successful, -1 if failed
 */
int setPlaceName(Place* pl, char* n) {
  return setStr(&pl->name, n);
}
