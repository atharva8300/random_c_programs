#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *fs1, *fs2, *ft;

  char ch; //file1[20], file2[20], file3[20];
/*
  printf("Enter name of first file\n");
  gets(file1);

  printf("Enter name of second file\n");
  gets(file2);

  printf("Enter name of file which will store contents of the two files\n");
  gets(file3);
*/
  fs1 = fopen("text1.txt", "r");
  fs2 = fopen("text2.txt", "r");
  ft = fopen("text3.txt","w");
  if (fs1 == NULL || fs2 == NULL)
  {
    perror("Error ");
    printf("Press any key to exit...\n");
    exit(EXIT_FAILURE);
  }
  while ((ch = fgetc(fs1)) != EOF)
    fputc(ch,ft);

  while ((ch = fgetc(fs2)) != EOF)
    fputc(ch,ft);

  printf("The two files were merged into  file3 successfully.\n");

  fclose(fs1);
  fclose(fs2);
  fclose(ft);

  return 0;
}

