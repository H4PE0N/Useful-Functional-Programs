
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "test-program.h"

int main(int count, char* arguments[])
{
  char* string = arguments[1];
  int length = strlen(string);

  char* reversed = reverse_string_variable(string, length);

  printf("%s REVERSED: %s\n", string, reversed);

  return 0;
}

char* reverse_string_variable(char* string, int length)
{
  char* reversed = malloc(sizeof(char) * length);
  for(int index = 0; index < length; index = index + 1)
  {
    *(reversed + index) = *(string + (length-index-1));
  }
  return reversed;
}
