#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int id_tracker = 1;

List *init_history()
{
  List *history = (List *)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

int str_length(const char *str)
{
  int length = 0;
  while(str[length] != '\0')
    {
      length++;
    }
  return length;
}

char *str_duplicate(const char *str)
{
  int length = str_length(str);
  char *duplicate = (char *)malloc((length + 1) * sizeof(char));
  for(int i = 0; i <= length; i++)
    {
      duplicate[i] = str[i];
    }
  return duplicate;
}

void add_history(List *list, char *str)
{
  Item *current;
  current = list->root;

  if(list->root == NULL)
    {
      list->root = (Item *)malloc(sizeof(Item));
      list->root->id = id_tracker++;
      int length = str_length(str);
      list->root->str = (char *)malloc((length + 1) * sizeof(char));

      for(int i = 0; i <=length; i++)
	{
	  list->root->str[i] = str[i];
	}

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
      int length = str_length(str);
      current->next->str = (char *)malloc((length + 1) * sizeof(char));

      for(int i = 0; i <= length; i++)
	{
	  current->next->str[i] = str[i];
	}
      
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
