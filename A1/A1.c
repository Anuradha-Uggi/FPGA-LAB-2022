/*
Name:Anuradha uggi
I'D:EE21RESCH01008
Course:FPGA Lab course
Assignment:01
*/

#include<stdio.h>
main()
{

//declare variables
  int p,q,r,s;
  printf("Code starts here...\n");
  printf("enter possible boolean combinations pqrs:\n");
//user inputs for above variables
  scanf("%d%d%d%d",&p,&q,&r,&s);
//NAND logic function declaration
// 1-input NAND logic
  int NAND1(int p)
  {
     int y=!p;
     return y;
  }
//2-inputs NAND logic
  int NAND2(int p,int q)
  {
      int y=!(p&q);
      return y;
  }
//4-input NAND logic
  int NAND4(int p,int q,int r,int s)
  {
      int y=!(p&q&r&s);
      return y;
  }
  
 //reduced k-map logic
 int F(int p,int q,int r,int s)
 {
      int a,b,c,d;
      a=NAND2(NAND1(p),NAND1(q));
      b=NAND2(NAND1(s),r);
      c=NAND2(NAND1(p),s);
      d=NAND2(q,r);
      int f=NAND4(a,b,c,d);
      return f;
 }
 //printing output
 printf("\noutput:%d",F(p,q,r,s));
 //ALL POSSIBLE COMBINATIONS
 //decimal to 4-bit binary conversion
 char * convert(int dec, char *output) {
    output[4] = '\0';
    output[3] = (dec & 1) + '0';
    output[2] = ((dec >> 1) & 1) + '0';
    output[1] = ((dec >> 2) & 1) + '0';
    output[0] = ((dec >> 3) & 1) + '0';
    return output;
   }
 char binary[5];
 int input[16];
 for(int i=0;i<16;i++)
 {
   input[i]=i;
 }
 //truth table for the reduced logic
 printf("\nTRUTH TABLE:\n");
 printf("\n");
 for(int i=0;i<16;i++)
 {
   convert(input[i], binary);
   int m=binary[0]-48,n=binary[1]-48,o=binary[2]-48,p=binary[3]-48;
   printf("\t input:%s \t output:%d", binary,F(m,n,o,p));
   printf("\n");
   
 }
}
