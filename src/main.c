#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int strings_equal(const char *str1,  const char *str2)
{
  while(*str1 != '\0' && *str2 != '\0')
    {
      if(*str1 != *str2)
	{
	  return 0;
	}
      str1++;
      str2++;
    }
  return(*str1 == *str2);
}


int main()
{
  List *history = init_history();
  char input[100];
  

  while(1)
    {
      printf("Welcome, options are:\n");
      printf("1. To tokenize a sentence.\n");
      printf("2. To view hsitory.\n");
      printf("3. To quit.\n");
      printf("Enter your answer: ");

      int choice;
      scanf("%d", &choice);
      getchar();

      switch(choice)
	{
	case 1:
	  printf("Enter a sentence: ");
	  fgets(input, sizeof(input), stdin);

	  for(int i =0; input[i] != '\0'; i++)
	    {
	      if(input[i] == '\n')
		{
		  input[i] = '\0';
		  break;
		}
	    }

	  char **tokens = tokenize(input);
	  printf("Tokens:\n");
	  print_tokens(tokens);

	  add_history(history, input);
	  break;

	case 2:
	  printf("History:\n");
	  print_history(history);
	  break;

	case 3:
	  free_history(history);
	  return 0;

	default:
	  printf("Invalid choice. Please select a valid option.\n");
	  break;
	}
    }
  
  return 0;
}
