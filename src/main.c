#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history();
  char input[100];

  while(1)
    {
      printf("Enter a sentence: ");
      fgets(input, sizeof(input), stdin);

      input[strcspn(input, "\n")] = '\0';

      if(strcmp(input, "q") == 0)
	{
	  break;
	}

      char **tokens = tokenize(input);
      printf("Tokens:\n");
      print_tokens(tokens);

      add_history(history, input);
      printf("History:\n");
      print_history(history);

      free_tokens(tokens);
    }

  free_history(history);

  return 0;
}
