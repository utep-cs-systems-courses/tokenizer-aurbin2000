#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"

int id_tracker = 1;

List *init_history()
{
  List *history = (List *)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  Item *current;
  current = list->root;

  if(list->root == NULL)
    {
      list->root = (Item *)malloc(sizeof(Item));
      list->root->id = id_tracker++;
      list->root->str = strdup(str);
      list->root->next = NULL;
    }
  else
    {
      while(current->next != NULL)
	{
	  current = current->next;
	}
      current->next = (Item *)malloc(sizeof(Item));
      current->next->id = id_tracker;
      current->next->str = strdup(str);
      current->next->next = NULL;
    }
}

char *get_history(List *list, int id)
{
  Item *current = list->root;
  while(current != NULL)
    {
      if(current->id == id)
	{
	  return current->str;
	}
      current = current->next;
    }
  return NULL;
}

void print_history(List *list)
{
  Item *current = list->root;
  while(current != NULL)
    {
      printf("%d.- %s\n", current->id, current->str);
      current = current->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  while(current != NULL)
    {
      Item *temp = current;
      current = current->next;
      free(temp->str);
      free(temp);
    }
  free(list);
}
