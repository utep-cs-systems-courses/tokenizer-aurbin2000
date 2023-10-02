#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  List *history = init_history();
  char input[100];
  

  while(1)
    {
      printf("Welcome, options are:\n");
      printf("1. Tokenize a sentence.\n");
      printf("2. View hsitory.\n");
      printf("3. Quit.\n");
      printf("Enter your answer: ");

      int choice;
      scanf("%d", &choice);
      getchar();

      switch(choice)
	{
	case 1:
	  printf("Enter a sentence: ");
	  fgets(input, sizeof(input), stdin);

	  int i;
	  for(i = 0; input[i] != '\0'; i++)
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

	  free_tokens(tokens);
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
