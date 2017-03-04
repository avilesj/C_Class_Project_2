#include "invtools.h"
#include <stdio.h>

void clearScreen()
{
  printf("\033c");
}

void clear_newlines(void)
{
  int c;
  do
  {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
