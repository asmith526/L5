#include<stdio.h>
#include"unit_test.h"


int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int)=
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,
      test_get_capacity_on_init_default,
      test_my_string_at,
      test_my_string_empty,
      test_my_string_push_back,
      test_my_string_pop_back,
      test_my_string_concat,
      test_my_string_extraction,
      test_my_string_init_c_string,
      test_my_string_compare,
      test_get_capacity_returns_1,
      test_destroy,
      test_c_string_size,
      test_c_string_capacity,
      test_my_string_insertion,
      test_push_capacity,
      test_push_size,
      test_push_data,
      test_pop_empty,
      test_not_empty
    };

  int number_of_functions= sizeof(tests)/sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count=0;
  int failure_count=0;

  for(i=0;i<number_of_functions;i++)
    {
      if(tests[i](buffer,500)==FAILURE)
	{
	  printf("FAILED: Test %d failed\n", i);
	  printf("\t%s\n", buffer);
	  failure_count++;
	}

       if(tests[i](buffer,500)==SUCCESS)
	{
	  printf("SUCCESS: Test %d succeeded\n", i);
	  printf("\t%s\n", buffer);
	  success_count++;
	}
    }

  printf("Success count: %d", success_count);
  printf("Failure count: %d", failure_count);

  return 0;
}
