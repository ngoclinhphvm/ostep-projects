#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int main(int argc, char* argv[]) {
  FILE* stream;
  char* searchterm;
  char* line = NULL;
  size_t len = 0;
  ssize_t nread;
 
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(EXIT_FAILURE);
  }

  searchterm = argv[1];

  if (argc == 2) {
    while((nread = getline(&line, &len, stdin)) != -1) {
      if (strstr(line, searchterm) != NULL) {
        printf("%s", line);
      }
    }
  } else {
    for (int i = 2; i < argc; i++) {
      stream = fopen(argv[i], "r");
      if (stream == NULL) {
        printf("wgrep: cannot open file\n");
        free(line);
        exit(EXIT_FAILURE);
      }
      while((nread = getline(&line, &len, stream)) != -1){
        if (strstr(line, searchterm) != NULL) {
          printf("%s", line);
        }
      }
      fclose(stream);
    }
  }
  
  free(line);
  exit(EXIT_SUCCESS);
}
