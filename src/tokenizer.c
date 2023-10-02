#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  return(c == ' ' || c == '\t');
}

int non_space_char(char c)
{
  return !space_char(c);
}

char *token_start(char *str)
{
  while(space_char(*str))
    {
      str++;
    }
  return str;
}

char *token_terminator(char *token)
{
  while(non_space_char(*token))
    {
      token++;
    }
  return token;
}

int count_tokens(char *str)
{
  int count = 0;
  int in_token = 0;

  while(*str)
    {
      if(space_char(*str))
	{
	  in_token = 0;
	}
      else if(!in_token)
	{
	  in_token = 1;
	  count++;
	}
      
      str++;
    }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *copy = (char *)malloc((len+1) * sizeof(char));
  for(short i = 0; i < len; i++)
    {
      copy[i] = inStr[i];
    }
  copy[len] = '\0';
  return copy;
}

char **tokenize(char* str)
{
  int count = count_tokens(str);
  char **tokens = (char **)malloc((count+1) * sizeof(char *));
  char *token_start_ptr, *token_end_ptr;
  int token_index = 0;

  while(*str)
    {
      token_start_ptr = token_start(str);
      token_end_ptr = token_terminator(token_start_ptr);

      if(token_start_ptr != token_end_ptr)
	{
	  tokens[token_index++] = copy_str(token_start_ptr, token_end_ptr - token_start_ptr);
	}

      str = token_end_ptr;
    }

  tokens[token_index] = NULL;
  return tokens;
}
	
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i])
    {
      printf("Token[%d]: %s\n", i, tokens[i]);
      i++;
    }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i])
    {
      free(tokens[i]);
      i++;
    }
  free(tokens);
}
