#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"


int main(int argc, char* argv[])
{
  MY_STRING hMy_string=NULL;
  FILE* fp;
  int c;

  hMy_string=my_string_init_default();
  fp=fopen("simple.txt", "r");

  while(my_string_extraction(hMy_string, fp))
    {
      my_string_insertion(hMy_string,stdout);
      printf("\n");
      c=fgetc(fp);
      if(c==' ')
	{
	  printf("Found a space after the string\n");
	}
      if(c==EOF)
	{
	  break;
	}
    }

  my_string_destroy(&hMy_string);

  fclose(fp);

  return 0;
  
}
