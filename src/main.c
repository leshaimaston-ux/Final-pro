#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 27

void warning()
{printf("Warning: temperature outside of range\n");
	gpioInitialise();
	gpioSetMode(PIN,PI_OUTPUT);
	gpioWrite(PIN,1); //LED ON

}


int main()
{
int temp;
int choice;
int cnt=0;
float avg=0;
int div=0;
while(1)
{printf("Input the temperature (must be within 68-76) \n");
scanf("%d", &temp);
getchar();
avg+=temp;
div++;
while(temp>77||temp<67)
{warning();	
printf("Input correct temperature\n");
scanf("%d", &temp);
getchar();
cnt++;
div++;
}
if(cnt>0)
{gpioWrite(PIN,0); // LED OFF
gpioTerminate();}
printf("Would you like to continue (0 to exit, 1 to continue)\n");
scanf("%d", &choice);
getchar();
if(choice==0)
break;}

printf("Temperature accepted\n");
printf("temperature average %.2f" ,avg/div);
	
	return 0;}
