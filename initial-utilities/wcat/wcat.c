#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]) {
  if (argc == 1) {
    return 0;
  }

  for (int i = 1; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
      exit(1);
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      printf("%s", buffer);
    }
  }

  return EXIT_SUCCESS;
}
