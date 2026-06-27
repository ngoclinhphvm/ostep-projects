#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 1) {
    return EXIT_SUCCESS;
  }

  for (int i = 1; i < argc; i++) {
    FILE* stream = fopen(argv[i], "r");

    if (stream == NULL) {
      printf("wcat: cannot open file\n");
      return EXIT_FAILURE;
    }

    char buffer[50];

    while(fgets(buffer, sizeof(buffer), stream) != NULL) {
      printf("%s", buffer);
    }

    fclose(stream);
  }

  return EXIT_SUCCESS;
}
