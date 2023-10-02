#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *history = (List *)malloc(sizeof(List));
  if(history)
    {
      history->root = NULL;
    }
  return history;
}

void add_history(List *list, char *str)
{
  if(!list)
    {
      return;
    }
  
  Item *current = list->root;

  if(!list->root)
    {
      list->root = (Item *)malloc(sizeof(Item));
      if(list->root)
	{
	  list->root->id = 1;
	  int length = 0;
	  while(str[length] != '\0')
	    {
	      length++;
	    }
	  list->root->str = (char *)malloc((length + 1) * sizeof(char));
	  
	  if(list->root->str)
	    {
	      for(int i = 0; i<= length; i++)
		{
		  list->root->str[i] = str[i];
		}
	      list->root->next = NULL;
	    }
	  else
	    {
	      free(list->root);
	      list->root = NULL;
	    }
	}
    }
  else
    {
      while(current->next)
	{
	  current = current->next;
	}
      current->next = (Item *)malloc(sizeof(Item));
      if(current->next)
	{
	  current->next->id = current->id + 1;
	  int length = 0;
	  while(str[length] != '\0')
	    {
	      length++;
	    }
	  current->next->str = (char *)malloc((length + 1) * sizeof(char));

	  if(current->next->str)
	    {
	      for(int i = 0; i<= length; i++)
		{
		  current->next->str[i] = str[i];
		}
	      current->next->next = NULL;
	    }
	  else
	    {
	      free(current->next);
	      current->next=NULL;
	    }
	}
    }
}

char *get_history(List *list, int id)
{
  if(!list)
    {
      return NULL;
    }
  
  Item *current = list->root;
  while(current)
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
  if(!list)
    {
      return;
    }
  
  Item *current = list->root;
  while(current)
    {
      printf("%d.- %s\n", current->id, current->str);
      current = current->next;
    }
}

void free_history(List *list)
{
  if(!list)
    {
      return;
    }
  
  Item *current = list->root;
  while(current)
    {
      Item *temp = current;
      current = current->next;
      free(temp->str);
      free(temp);
    }
  free(list);
}
