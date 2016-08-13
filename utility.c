#include <stdlib.h>
#include <string.h>

/**
 * Set a string to a new string
 * @param  str    Pointer to string to set
 * @param  newStr Pointer to text to set to str
 * @return        1 if successful, -1 if failed
 */
int setStr(char** str, char* newStr){
  if(newStr == NULL) {
    return -1;
  }

  if(*str != NULL) {
    free(str);
  }

  *str = malloc(strlen(newStr));
  if(*str == NULL) {
    return -1;
  }

  strcpy(*str, newStr);
  return 1;
}
