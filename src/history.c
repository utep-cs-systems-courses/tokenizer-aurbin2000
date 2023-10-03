#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *stringHistory = malloc(sizeof(List*));
  stringHistory -> root = NULL;
  return stringHistory;
}

void add_history(List *list, char *str)
{
  int len;
  for(len = 0; str[len] != '\0'; len++)
    {}

  char *newStr = copy_str(str, len);
  int count = 1;
  Item *current = list -> root;

  if(current == NULL)
    {
      current = malloc(sizeof(Item));
      current -> id = 0;
      current -> str = newStr;
      current -> next = NULL;
      list -> root = current;
      return;
    }

  while(current -> next != NULL)
    {
      count++;
      current = current -> next;
    }

  current -> next = malloc(sizeof(Item));
  current -> next -> id = count;
  current -> next -> str = newStr;
  current -> next -> next =  NULL;

}

char *get_history(List *list, int id)
{
  Item *current = list -> root;
  while(current != NULL)
    {
      if(current -> id == id)
	{
	  return current -> str;
	}
      current = current -> next;
    }
  return "";
}

void print_history(List *list)
{
  Item *current = list -> root;
  while(current != NULL)
    {
      printf("%d.- %s\n", current -> id, current -> str);
      current = current -> next;
    }
}

void free_history(List *list)
{
  Item *current = list -> root;
  Item *deleted = current;
  
  while(current != NULL)
    {
      deleted = current;
      current = current -> next;
      free(deleted);
    }
  free(list);
}
