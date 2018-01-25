#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]){
  printf("\nProgram wypisuje na ekran dane z pliku\n");
  printf("-b duze litery, -l male litery\n");

  if (argc < 2){
      printf("Nie podano nazwy pliku!!\n");
      return -1;
    }

  FILE *f=fopen(argv[1], "r");
  int currentChar;
  char error[256] = { 0 };
  if (f == NULL)
    {
      printf("Unable to open file %s\n", argv[1]);
      perror(error); //prosty komunikat o bledzie
      printf("Error: %s\n", error);
      return -1;
    }
  printf("Successfully opened file %s\n\n", argv[1]);


  while (!feof(f)) {
    if ((currentChar = getc(f)) == EOF) // read char into int variable
    {
      break;
    }

    if ((argv[2]) && (!strcmp(argv[2], "-b"))) {
      if ((currentChar <= 122) && (currentChar >= 97)){
	currentChar -= 32;
      }
    } else  if ((argv[2]) && (!strcmp(argv[2], "-l"))) {
      if ((currentChar <= 90) && (currentChar >= 65)) {
	currentChar += 32;
      }
    }
    putc(currentChar, stdout);  // print char to console
  }

  fclose(f);

  printf("Successfully reached the end of the program\n");
  return 0;
}
