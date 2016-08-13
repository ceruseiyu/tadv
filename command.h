#ifndef TADV_COMMAND
#define TADV_COMMAND
#include "player.h"

void listAttributes(Player* p);
void listPaths(Player* p);

void goPlace(Player* p, char* pathName);

void processCommand(char* c, Player* p);
#endif
