#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"


int main(int argc, char* argv[])
{
  int n;
  MY_STRING hMy_string1=NULL;
  MY_STRING hMy_string2=NULL;

  hMy_string1= my_string_init_c_string("hi");
  printf("The capacity of the string is %d", my_string_get_capacity(hMy_string1));
  printf("The size of the string is %d", my_string_get_size(hMy_string2));
  hMy_string2= my_string_init_c_string("hello");
  n=my_string_compare(hMy_string1, hMy_string2);
  if(n==1)
    {
      printf("The left string comes first. \n");
    }
  if(n==-1)
    {
      printf("The right string comes first. \n");
    }

  my_string_destroy(&hMy_string1);
  my_string_destroy(&hMy_string2);

  return 0;
  
}
