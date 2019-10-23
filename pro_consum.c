#include<stdio.h>
#define BUFFER_SIZE 10

int insert_to_buffer(int ptr,int buff[BUFFER_SIZE],int item)
{
  ptr++;
  if(ptr<=BUFFER_SIZE)
  {
   buff[ptr]=item;
  }
  else
  {
   printf("buffer is full\n");
  }
  return ptr;
}

void display(int ptr,int buff[BUFFER_SIZE])
{
  int i;
  if(ptr==0)
  {
   printf("buffer is empty\n");
  }
  for(i=ptr;i>0;i--)
  {
   printf("%d  ",buff[i]);
  }
  printf("\n");
}

int remove_from_buffer(int ptr,int buff[BUFFER_SIZE])
{
  int c;
  if(ptr>0)
  {
   c=buff[ptr];
   printf("Item removed is %d",c);
   buff[ptr]=0;
   ptr--;
  }
  else
  {
   printf("buffer is empty\n");
  }
  return ptr;
}


int main()
{
 int ch,item,buff[BUFFER_SIZE],ptr=0;
 printf("Enter\n 1.TO PRODUCE ITEM\n 2.TO CONSUME AN ITEM\n 3.DISPLAY ITEMS IN BUFFER\n 4.PRODUCER   PROCESS USING SHARED MEMORY\n 5.CONSUMER PROCESS USING SHARED MEMORY\n 6.EXIT\n");
 for(;;)
{
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:printf("Enter the item to be inserted\n");
          scanf("%d",&item);
          ptr=insert_to_buffer(ptr,buff,item);
          break;

   case 2:ptr=remove_from_buffer(ptr,buff);
          break;
   
   case 3:display(ptr,buff);
          break;
 }
}
 return 0;
}
