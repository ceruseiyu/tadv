#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "world.h"
#include "player.h"
#include "command.h"

#define MAX_CMD_LEN 128

int main() {
  Place* curPlace = createPlace("Starter Room");
  setPlaceDesc(curPlace, "You arrive in a small room, there's a door to your left.");
  addPath(curPlace, createPath("leftdoor"));
  setPathLook(curPlace->paths, "A new wooden door, it's painted bright red.");
  setPathEntry(curPlace->paths, "You walk through the door, a breeze of air hits you.");
  setPathPlace(curPlace->paths, createPlace("You arrive in a large room, it's empty."));
  Player* p = createPlayer("Steve", curPlace);
  printf("Seems to be working. Beginning test game.\n");
  //while(1) {
    printf("Enter command:\n");
    char* command = malloc(MAX_CMD_LEN);
    fgets(command, MAX_CMD_LEN, stdin);
    printf("%s", command);
    if ((strlen(command)>0) && (command[strlen(command) - 1] == '\n')) {
      command[strlen(command) - 1] = '\0';
    }
    processCommand(command, p);
  //}
}
