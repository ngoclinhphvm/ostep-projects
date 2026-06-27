#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]){
  FILE* stream;

  if (argc == 1) {
    printf("wzip: file1 [file2 ...]\n"); 
    exit(EXIT_FAILURE);
  }

  int c;
  char cur;
  int count = 0;

  for (int i = 1; i < argc; i++) {
    stream = fopen(argv[i], "r");
    
    if (stream == NULL) { 
      printf("wzip: cannot open file");
      exit(EXIT_FAILURE);
    }

    while ((c = fgetc(stream)) != EOF) {
      if (count == 0) {
        cur = (char)c;
        count++;
      } else if ((char)c == cur) {
        count++;
      } else {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&cur, sizeof(char), 1, stdout);

        cur = (char)c;
        count = 1;
      }
    }
  }

  if (count) {
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&cur, sizeof(char), 1, stdout);
  }

  fclose(stream);
  fclose(stdout);

  return EXIT_SUCCESS;
}
