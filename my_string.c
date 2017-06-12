#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"

struct object
{
  int size;
  int capacity;
  char* data;
};
typedef struct object Object;

MY_STRING my_string_init_default(void)
{
  Object* pObject;
  pObject= (Object*) malloc(sizeof(Object));

  if(pObject != NULL)
    {
      pObject -> size= 0;
      pObject -> capacity= 1;
      pObject -> data= (char*)malloc(sizeof(char)*pObject->capacity);
      if(pObject->data==NULL)
	{
	  free(pObject);
	  pObject=NULL;
	}
    }
  

  return (MY_STRING)pObject;
}

Status my_string_destroy(MY_STRING* phMy_string)
{
  Object* pObject;
  pObject= (Object*) *phMy_string;

  free(pObject->data);
  free(pObject);
  *phMy_string=NULL;
  return SUCCESS;

}

MY_STRING my_string_init_c_string(const char* c_string)
{
  Object* pObject;
  pObject= (Object*) malloc(sizeof(Object));

  if(pObject != NULL)
    {
      pObject -> size= 0;
      pObject -> capacity= sizeof(c_string);
      pObject -> data= (char*)malloc(sizeof(char)*pObject->capacity);
      if(pObject->data==NULL)
	{
	  free(pObject);
	  pObject=NULL;
	}
    }
  

  return (MY_STRING)pObject;

}

int my_string_get_capacity(MY_STRING hMy_string)
{
  Object* pObject= (Object*)hMy_string;
  return pObject->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  Object* pObject= (Object*)hMy_string;
 
  return pObject->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  Object* pLeft= (Object*)hLeft_string;
  Object* pRight= (Object*)hRight_string;
  int i=0;
  while((pLeft->data[i])==(pRight->data[i]))
    {
      i++;
    }
  if((pLeft->data[i])>(pRight->data[i]))
    {
      return 1;
    }
  if((pRight->data[i])>(pLeft->data[i]))
    {
      return -1;
    }
  return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  Object* string= (Object*)hMy_string;
  
  int i;
  string->size=0;
  fscanf(fp, "%s", string->data);

  for(i=0; string->data[i] != '\0';i++)
    {
      string->size++;
    }
 
  
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  Object* string= (Object*)hMy_string;

  printf("%s", string->data);

  return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  Object* string= (Object*)hMy_string;
  char* temp;
  int i;

  if(string->size >= string->capacity)
    {
      temp= (char*)malloc(sizeof(char)* string->capacity*2);
      if (temp==NULL)
	{
	  return FAILURE;
	}
      for (i=0; i< string->size; i++)
	{
	  temp[i]= string->data[i];
	}
      free(string->data);
      string->data= temp;
      string->capacity *=2;
    }

  string->data[string->size] = item;
  string->size++;

  printf("The data is: %s \n And the capacity is %d\n", string->data, string->capacity);
  return SUCCESS;
      
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  Object* string= (Object*)hMy_string;

  if(string->size == 0)
    {
      return FAILURE;
    }

  string->size--;
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  Object* string= (Object*)hMy_string;

  if(index >= string->size)
    {
      printf("Out of bounds\n");
      return NULL;
    }

  return &(string->data[index]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  Object* string= (Object*)hResult;
  Object* string2= (Object*)hAppend;
  char* temp;
  int i;
  
  if(string->capacity < (string->size + string2->size))
    {
      printf("Not enough space!\n");
      return FAILURE;
    }

   temp= (char*)malloc(sizeof(char)* string->capacity*2);
      if (temp==NULL)
	{
	  return FAILURE;
	}
      for (i=0; i< string->size; i++)
	{
	  temp[i]= string->data[i];
	}
      
      int n=0;
      while(i<=string->capacity)
	{
	  temp[i]= string2->data[n];
	  i++;
	  n++;
	  string->size++;
	}
      free(string->data);
      string->capacity *=2;
      string->data= temp;
      
      

      printf("The connected string is: %s\n", string->data);

      return SUCCESS;
      
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  Object* string= (Object*)hMy_string;

  return (Boolean) (string->size == 0);
}
