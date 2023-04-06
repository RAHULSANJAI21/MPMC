#include <AT89S52.h>
#define FOSC 11059200
#define TCLK FOSC/12
#define SCLK TCLK/32

#define TRIG P1_7
#define ECHO P1_6
#define DATABUS P2
#define RS P1_0
#define RW P1_1
#define EN P1_2
#include<LCD.h>
void baud_rate(int);
void send_byte(char);
void send_msg(char*);
void wait (char);
int get_distance(void);

const char ASCII[11]="0123456789";
void wait (char);
void main()
{
char dist,hun,ten,one;
 baud_rate(9600);
 lcd_init();
 while(1)
 {
 lcd_cmd(0x01);
  
  dist=get_distance();
  one=(dist%10);
  dist= dist/10;
  ten = dist%10;
  hun=(dist/10);
  send_msg("Distance = ");
  send_byte(ASCII[hun]);
  send_byte(ASCII[ten]);
  send_byte(ASCII[one]);
  send_msg(" Cm\n\n");
  lcd_data(ASCII[hun]);
  lcd_data(ASCII[ten]);
  lcd_data(ASCII[one]);
  lcd_print(" Cm");
  wait(500);
 }
}

void baud_rate(int baud)
{
 char b;
 SCON=0X50;
 TMOD=(TMOD&0X0F)|0x20;
 b=(0xFF-(SCLK/baud))+1;
 TH1=b;
 TL1=b;
 TR1=1;
}

void send_byte(char m)
{
 SBUF=m;
 while(TI==0)
 {}
 TI=0;
}

void send_msg(char *m)
{
 while(*m!=0)
 {
  SBUF=*m;
  *m++;
  while(TI==0)
  {}
  TI=0;
 }
}

int get_distance(void)
{
 int ultra_dist;
 char ultra_q;
 TRIG=0;
 ECHO=1;
 TR0=0;
 TMOD=(TMOD&0xF0)|(0x01);
 TH0=0x00;
 TL0=0x00;

 TRIG=1;
 for(ultra_q=0;ultra_q<10;ultra_q++)
 {}
 TRIG=0;
 
 while(ECHO==0)
 {
 }
 TR0=1;
 while(ECHO==1)
 {
 }
 TR0=0;
 ultra_dist=((TH0*256)+TL0)/54;
 return ultra_dist;
}
void wait (char d)
{
 char i;
 int j;
 for(i=0;i<d;i++)
 {
  for(j=0;j<1275;j++)
  {}
 }
}
