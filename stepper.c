#include<LPC214X.H>

#define O1 0X000000E0
#define O2 0X000000D0

#define I1 0x0000000E

#define CLR 0x000000F0

unsigned int CLOCK[4]      = {0x00330000,0x00990000,0x00CC0000,0x00660000};
unsigned int ANTI_CLOCK[4] = {0x00660000,0x00CC0000,0x00990000,0x00330000};

char scan (int);
void delay(int);

int main(void){  
  IO0DIR = 0X00FF00F0;
  while(1)
    {
         unsigned char I;
         IO0CLR = CLR;
         IO0SET = O1;	
    
   while(scan(I1))					       //S1
	    {		 
		  for(I=0;I<4;I++)
		     {
               IO0SET |= CLOCK[I];			   
		       IO0CLR |= ~CLOCK[I];
               delay(5);
			 }		   		    
		}	
    
    IO0CLR = CLR;
    IO0SET = O2;
    while(scan(I1))                        //S2
	    { 		 
		  for(I=0;I<4;I++)
		     {
               IO0SET |= ANTI_CLOCK[I];			   
		       IO0CLR |= ~ANTI_CLOCK[I];
               delay(5);
			 }		  	 	
		}
    
    IO0CLR = CLR;
 			  
    }
 }

char scan(int keystatus)		  /* scanning a a key	*/
  {
    while((IO0PIN & 0X0000000F)==keystatus)
	  {
	       return(1);
	  }
	       return(0);
   }

void delay(int n)	  			/* generates one milisecond delay  */
  {
   int i,j;
   for (i=1; i<=n; i++)
   for(j=0; j<=10000; j++);
   }
