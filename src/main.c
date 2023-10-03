#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char inputString[100];
  putchar('$');
  fgets(inputString, 100, stdin);
  printf(inputString, "\n");
  
  return 0;
}
