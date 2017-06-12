#include<string.h>
#include"my_string.h"



Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  if(hString==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_init_default_returns_nonNULL\n",length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString=NULL;
  Status status;

  hString=my_string_init_default();

  if(my_string_get_size(hString)!=0)
    {
      status = FAILURE;
      printf("Expected size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer,  "Did not= test_get_size_on_init_default_returns_0\n", length);
    }
    else
      {
	status = SUCCESS;
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
      }

    my_string_destory(&hString);
    return status;
    
}

Status test_get_capacity_on_init_default(char* buffer, int length)
{
  MY_STRING hString=NULL;
  Status status;

  hString=my_string_init_default();

  if(my_string_get_capacity(hString)==0)
    {
      status = FAILURE;
      printf("Expected capacity of !0 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer,  "Did not= test_get_capacity_on_init_default\n", length);
    }
    else
      {
	status = SUCCESS;
	strncpy(buffer, "test_get_capacity_on_init_default\n", length);
      }

    my_string_destory(&hString);
    return status;
    
}

Status test_my_string_at(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  char* c= my_string_at(hString, 0);

  if(c==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_at FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_at\n",length);
      return SUCCESS;
    }
}

Status test_my_string_empty(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  Boolean c= my_string_empty(hString);

  if(c==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_empty FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_empty\n",length);
      return SUCCESS;
    }
}
    
Status test_my_string_push_back(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';

  hString= my_string_init_default();

  Status status= my_string_push_back(hString, item);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_push FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_push \n",length);
      return SUCCESS;
    }
}


Status test_my_string_pop_back(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';

  hString= my_string_init_default();

  my_string_push_back(hString, item);

  Status status= my_string_pop_back(hString);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_pop FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_pop \n",length);
      return SUCCESS;
    }
}

Status test_my_string_concat(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';

  hString= my_string_init_default();

  my_string_push_back(hString, item);

  MY_STRING hString2= NULL;

  hString2= my_string_init_default();

  my_string_push_back(hString2, item);

  Status status=  my_string_concat(hString, hString2);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_concat FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_concat \n",length);
      return SUCCESS;
    }
}

 Status test_my_string_extraction(char* buffer, int length)
{
  MY_STRING hString= NULL;
  FILE* fp;
  int c;

  hString= my_string_init_default();
  fp=fopen("dictionary.txt", "r");
  Status status= my_string_extraction(hString, fp);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_extraction FAILURE\n", length);
      fclose(fp);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_extraction \n",length);
      fclose(fp);
      return SUCCESS;
    }
}


Status test_my_string_init_c_string(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  hString= my_string_init_c_string("hi");

  if(hString==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_init_c_string FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_init_c_string\n",length);
      return SUCCESS;
    }
}


Status test_my_string_compare(char* buffer, int length)
{
  MY_STRING hString= NULL;
  MY_STRING hString2= NULL;
  int n;

  hString= my_string_init_default();
  hString2= my_string_init_default();

  hString= my_string_init_c_string("hi");
  hString2= my_string_init_c_string("hello");

  n=my_string_compare(hString, hString2);

  if(n==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_compare FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_compare\n",length);
      return SUCCESS;
    }
}
Status test_get_capacity_returns_1(char* buffer, int length)
{
  MY_STRING hString=NULL;
  Status status;

  hString=my_string_init_default();

  if(my_string_get_capacity(hString)!=1)
    {
      status = FAILURE;
      printf("Expected capacity of 1 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer,  "Did not= test_get_capacity_returns_1\n", length);
    }
    else
      {
	status = SUCCESS;
	strncpy(buffer, "test_get_capacity_returns_1\n", length);
      }

    my_string_destory(&hString);
    return status;
    
}

Status test_destroy(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  Status status= my_string_destory(&hString);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_destroy\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_destory\n",length);
      return SUCCESS;
    }
}

Status test_c_string_size(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  hString= my_string_init_c_string("hi");

  if(my_string_get_size(hString)!=0)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_c_string_size FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_c_string_size \n",length);
      return SUCCESS;
    }
}
Status test_c_string_capacity(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  hString= my_string_init_c_string("hi");

  if(my_string_get_capacity(hString)==0)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_c_string_capacity FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_c_string_capacity \n",length);
      return SUCCESS;
    }
}

 Status test_my_string_insertion(char* buffer, int length)
{
  MY_STRING hString= NULL;
  FILE* fp;

  hString= my_string_init_default();
  fp=fopen("dictionary.txt", "r");
  Status status= my_string_extraction(hString, fp);

  if(status==FAILURE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_my_string_insertion FAILURE\n", length);
      fclose(fp);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_my_string_insertion \n",length);
      fclose(fp);
      return SUCCESS;
    }
}
Status test_push_capacity(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';
  int capacity1;
  int capacity2;

  hString= my_string_init_default();

  my_string_push_back(hString, item);
  capacity1= my_string_get_capacity(hString);
  my_string_push_back(hString, item);
  capacity2=my_string_get_capacity(hString);

  if(capacity1>capacity2)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_push_capacity FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_push_capacity \n",length);
      return SUCCESS;
    }
}
Status test_push_size(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';
  int size1;
  int size2;

  hString= my_string_init_default();

  my_string_push_back(hString, item);
  size1= my_string_get_size(hString);
  my_string_push_back(hString, item);
  size2=my_string_get_size(hString);

  if(size1>size2)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_push_size FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_push_size \n",length);
      return SUCCESS;
    }
}
Status test_push_data(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';

  hString= my_string_init_default();

  my_string_push_back(hString, item);

  if(hString==NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_push_data \n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_push_data \n",length);
      return SUCCESS;
    }
}
Status test_pop_empty(char* buffer, int length)
{
  MY_STRING hString= NULL;

  hString= my_string_init_default();

  Status status=my_string_pop_back(hString);

  if(status==SUCCESS)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_pop_empty \n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_pop_empty \n",length);
      return SUCCESS;
    }
}

Status test_not_empty(char* buffer, int length)
{
  MY_STRING hString= NULL;

  char item= 'r';

  hString= my_string_init_default();
  my_string_push_back(hString, item);

  Boolean c= my_string_empty(hString);

  if(c==FALSE)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_not_empty FAILURE\n", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\test_not_empty\n",length);
      return SUCCESS;
    }
}
