#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
  {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' && c != '\t')
    {
      return 1;
    }
  return 0;
}

char *token_start(char *str)
{
  while(*str != '\0')
    {
      if(space_char(*str))
	{
	  str = str +1;
	  continue;
	}
      return str;
    }
  return str;
}

char *token_terminator(char *token)
{
  while(*token != '\0')
    {
      if(space_char(*token))
	{
	  return token;
	}
      token = token +1;
    }
  return token;
}

int count_tokens(char *str)
{
  int count = 0;
  str = token_start(str);

  while(*str != '\0')
    {
      count = count + 1;
      str = token_terminator(str);
      str = token_start(str);
    }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *newStr = (char *)malloc((len+1) * sizeof(char));

  for(int i = 0; i < len; ++i)
    {
      newStr[i] = inStr[i];
    }
  newStr[len] = '\0';
  return newStr;
}

char **tokenize(char* str)
{
  int numofWords = count_tokens(str);
  char **tokens = malloc((numofWords + 1) * sizeof(char *));
  char *tempStr;

  for(int i = 0; i < numofWords; ++i)
    {
      str = token_start(str);
      int count = 0;
      tempStr = str;

      while(non_space_char(*tempStr) && *tempStr != '\0')
	{
	  count = count + 1;
	  tempStr = tempStr + 1;
	}
      tokens[i] = copy_str(str, count);
      str = token_terminator(str);
    }
  tokens[numofWords] = '\0';
  return tokens;
}
	
void print_tokens(char **tokens)
{
  int count = 0;
  while(*tokens)
    {
      printf("token[%d] = %s\n", count, *tokens);
      tokens++;
      count++;
    }
}

void free_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index])
    {
      free(tokens[index]);
      index++;
    }
  free(tokens);
}

int main()
{
  char userChoice[10];
  char userInput[100];
  int userContinue = 1;
  List *historyList = init_history();
  while (userContinue)
    {
      printf("Enter 'w' to write a string input, '!h' to see all history records, and '!' followed by a number to see a particular history record:\n");
      putchar('$');
      fgets(userChoice, 10, stdin);

      if(*userChoice == 'w')
	{
	  printf("Please enter a sentence:\n");
	  putchar('$');
	  fgets(userInput, 100, stdin);
	  
	  char **tokenizer = tokenize(userInput);
	  print_tokens(tokenizer);
	  free_tokens(tokenizer);
	  
	  add_history(historyList, userInput);
	}
      else if(userChoice[0] == '!')
	{
	  if(userChoice[1] == 'h')
	    {
	      print_history(historyList);
	    }
	  else if(userChoice[1] >= 48 && userChoice[1] <= 57)
	    {
	      int userNumber = userChoice[1] - '0';
	      printf("%s\n", get_history(historyList, userNumber));
	    }
	  else if(userChoice[1] == '1')
	    {
	      printf("wow");
	    }
	}
      else
	{
	  printf("You entered an invalid selection.\n");
	  userContinue = 0;
	}

      char *strPoint;
      strPoint = &userInput[0];
    }

  free_history(historyList);
  return 0;
}
