#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"


int main(int argc, char* argv[])
{
  MY_STRING hMy_string=NULL;
  FILE* fp;
  int c;

  hMy_string=my_string_init_default();
  fp=fopen("dictionary.txt", "r");

  while(my_string_extraction(hMy_string, fp))
    {
     if(my_string_get_size(hMy_string)==29)
     	{
	  my_string_insertion(hMy_string,stdout);
	  printf("\n");
	  printf("%d\n",(my_string_get_size(hMy_string)));
       	}
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
