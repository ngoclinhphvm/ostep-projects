#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]){
  if (argc == 1) {
    printf("wunzip: file1 [file2 ...]\n"); 
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    FILE* stream = fopen(argv[i], "r");
    
    if (stream == NULL) { 
      printf("wunzip: cannot open file\n");
      exit(EXIT_FAILURE);
    }

    int count;
    char c; 

    while ((fread(&count, sizeof(int), 1, stream) == 1)
    && (fread(&c, sizeof(char), 1, stream) == 1)) {
      for (int i = 0; i < count; i++) {
        fwrite(&c, sizeof(char), 1, stdout);
      }
    }

    fclose(stream);
  }
 return EXIT_SUCCESS;
}
