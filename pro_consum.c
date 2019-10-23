#include<stdio.h>
#define BUFFER_SIZE 11


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
 int ch,item,buff[BUFFER_SIZE]={0},in=1,out=0,c=1;
 printf(" 1.PRODUCER PROCESS USING SHARED MEMORY\n 2.CONSUMER PROCESS USING SHARED MEMORY\n 3.DISPLAY ITEMS IN BUFFER\n 4.EXIT\n");  
 while(c==1)
{
 printf("Enter your choice\n");
 scanf("%d",&ch);
 printf("Entered choice is %d\n",ch);

 switch(ch)
 {
   
   case 3:display(out,buff,in);
          goto label;
   

   case 1:printf("Enter the item to be produced by producer\n");
          scanf("%d",&item);
          in=produce(in,buff,item,out);
          printf("Items produced by buffer is %d\n",item);
          goto label;


   case 2:out=consume(in,buff,out);
          goto label;


   default:exit(0);

 label:
     printf("Enter 1 to continue 0 to exit\n");
     scanf("%d",&c);
     printf("Entered value is %d\n",c);
     break;
 }
}
 return 0;
}
