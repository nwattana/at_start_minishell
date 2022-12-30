# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_terminal.h"

int main() 
{
  char* input;
  
  input = readline(PROMPT_MESSAGE);
  while (input)
  {
    input = readline(PROMPT_MESSAGE);
    printf("> %s\n", input);
    if (input == NULL)
      return (0);
	add_history(input);
	
	free(input);
  }
}

