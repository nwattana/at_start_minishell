
# include <readline/readline.h>
# include <readline/history.h>

int main() {
  char* input = readline("Enter your command: ");
  printf("You entered: %s\n", input);

  while (input)
  {
    input = readline("Enter your command: ");
    printf("You entered: %s\n", input);
    if (input == NULL)
      return (0);
  }
}
