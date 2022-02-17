
#include <Arduino.h>
#define P 2
#define Q 3
#define R 4
#define S 5

// variable declaration
int p,q,r,s,kmap_logic,NAND_logic;

//1-input NAND logic
int NAND1(int p)
{ 
	int y=!p;
	return y;
}
//2 input NAND logic
int NAND2(int p,int q)
{
	int y=!(p && q);
	return y;
}
//4 input NAND logic
int NAND4(int p,int q,int r,int s)
{
        int y=!(p && q && r && s);
        return y;
}

//reduced kmap logic
int NAND_logic_F(int p,int q,int r,int s)
{
	int a,b,c,d;
	a=NAND2(NAND1(p),NAND1(q));
	b=NAND2(NAND1(s),r);
	c=NAND2(NAND1(p),s);
	d=NAND2(q,r);
	int f=NAND4(a,b,c,d);
	return f;
}
int K_map(int p,int q,int r,int s)
{
	int f=(!p && !q) || (r && !s) || (!p && s) || (q && r);

	return f;
}
void setup()
{
	//IO pins
	pinMode(LED_BUILTIN,OUTPUT);
	pinMode(P,INPUT);
	pinMode(Q,INPUT);
	pinMode(R,INPUT);
	pinMode(S,INPUT);
}
void loop()
{
	//logic implementation
	p=digitalRead(P);
	q=digitalRead(Q);
	r=digitalRead(R);
	s=digitalRead(S);

	kmap_logic=K_map(p,q,r,s);
	NAND_logic=NAND_logic_F(p,q,r,s);

	if(kmap_logic==NAND_logic)
	
		digitalWrite(LED_BUILTIN,HIGH);
	else
		digitalWrite(LED_BUILTIN,LOW);

}
