#include<stdio.h>
#define BUFFER_SIZE 11

int insert_to_buffer(int in,int buff[BUFFER_SIZE],int item)
{
  in++;
  if(in<=BUFFER_SIZE)
  {
   buff[in]=item;
  }
  else
  {
   printf("buffer is full\n");
  }
  return in;
}

void display(int out,int buff[BUFFER_SIZE],int in)
{
  int i;
  if(in==0)
  {
   printf("buffer is empty\n");
  }
  for(i=1;i<BUFFER_SIZE;i++)
  {
   printf("%d  ",buff[i]);
  }
  printf("\n");
}

int remove_from_buffer(int in,int buff[BUFFER_SIZE])
{
  int c;
  if(in>0)
  {
   c=buff[in];
   printf("Item removed is %d",c);
   buff[in]=0;
   in--;
  }
  else
  {
   printf("buffer is empty\n");
  }
  return in;
}

int produce(int ptr,int buff[BUFFER_SIZE],int item,int out)
{
 int in;
 in=ptr;
 if(((in+1)%BUFFER_SIZE)==out)
  {
   printf("BUFFER IS FULL\n");
   return in;
  }
 while(((in+1)%BUFFER_SIZE)!=out)
 {
   buff[in]=item;
   in=(in+1)%BUFFER_SIZE;
 }
 buff[BUFFER_SIZE-1]=item;
 printf("Items are produced by the buffer\n");
 return in;
}

int consume(int in,int buff[BUFFER_SIZE],int out)
{
 int item_consumed;
 if(in==out)
  {
   printf("NO ITEMS TO CONSUME\n");
   return out;
  }
 while(in!=out)
 {
  item_consumed=buff[out];
  buff[out]=0;
  out=(out+1)%BUFFER_SIZE;
 }
 buff[BUFFER_SIZE-1]=0;
 printf("All the items are consumed by the consumer\n");
 return out;
}
int main()
{
 int ch,item,buff[BUFFER_SIZE]={0},in=1,out=0;
 printf(" 1.TO PRODUCE ITEM\n 2.TO CONSUME AN ITEM\n 3.DISPLAY ITEMS IN BUFFER\n 4.PRODUCER   PROCESS USING SHARED MEMORY\n 5.CONSUMER PROCESS USING SHARED MEMORY\n 6.EXIT\n");
 for(;;)
{
 printf("Enter your choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:printf("Enter the item to be inserted\n");
          scanf("%d",&item);
          in=insert_to_buffer(in,buff,item);
          break;

   case 2:in=remove_from_buffer(in,buff);
          break;
   
   case 3:display(out,buff,in);
          break;
  
   case 4:printf("Enter the item to be produced by producer\n");
          scanf("%d",&item);
          in=produce(in,buff,item,out);
          break;

   case 5:out=consume(in,buff,out);
          break;
   
   default:exit(0);
 }
}
 return 0;
}
