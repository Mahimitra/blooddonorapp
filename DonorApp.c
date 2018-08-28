

/**BLOOD DONOR DATABASE**/

#include "stdio.h"
#include "conio.h"
#include <string.h>
#include <graphics.h>
#include <dos.h>



FILE *fp;
long int size;
struct donor
{
char name[30];
int age;int bloodgroup;
char address[30];
char phn[11];

int  gender;
char email[25];

};
struct donor b; //Declaration of Structures


void putdonor();   //Store the Data in File
void display();   //Display Data
void donorbybloodgroup();
void donorbymobile();
void donorbyemail();
void menu();       //Display Menu




void main()
{
int i;
i=1;
size=sizeof(b);     //Finding the size of strucutre

clrscr();
while(i<=7)
{
printf("\n\n\n\n\n\n\n\n\t\t\t\t Initializing");
if(i<7)
{
delay(500);
clrscr();
delay(450);
 }
 i++;
 }
 
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);

clrscr();
menu();
getch();

}



void putdonor()
{
char a;
clrscr();
fp=fopen("BDONOR.DAT","wb+");    //Opening a Binary File
if(fp==NULL)
{
puts("Cannot Open File");
exit(0);
}
fseek(fp,0,SEEK_END);       //Putting the Pointer at the end of the File
do
{
clrscr();
fflush(stdin);
printf("\n\t Enter Name :- ");
gets(b.name);

 l:{
printf("\n\tEnter Your Age :- ");
scanf("%d",&b.age);
}
if(b.age <18){printf("Sorry....You can't become Donor.Minimun age requirement is 18.'");
goto l;
}
}
fflush(stdin);

printf("\n\t Enter address  :- ");
fflush(stdin);
gets(b.address);


printf("\n\t Enter Blood group :- 1.O-positive 2.O Negative 3.B-positive 4.B-negative");
gets(b.bloodgroup);
printf("\n\t Enter your 10 Digit Mobile Number :- ");
scanf("%s",b.phn);
fflush(stdin);
printf("\n\t Enter your Email id :-");
scanf("%s",b.email);
printf("\n\t gender  : 1.Male 2.Female :-");
scanf("%s",b.gender);
fwrite(&b,size,1,fp);

printf("\n\tDo You want to add another data\n Enter (Y \\ N)");
fflush(stdin);
scanf("%c",&a);
}while(a=='Y'||a=='y');
fclose(fp);		 //Closing the File
clrscr();
menu();
}



void donorbybloodgroup()
{
int bld;
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the Blood Group :  \n 1.O-positive 2.O Negative 3.B-positive 4.B-negative");
scanf("%d",bld);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(strcmp(b.bloodgrp,bld)==0)      //Mathching the Bloodgroup required with the one's present in Database
{
clrscr();
String x,y;
	switch(b.bloodgroup){
		
		case 1: x="O-Positive";
				break;
		case 2: x="O-Negative";
				break;
		case 3: x="B-positive";
				break;
		case 4: x="B-negative";
				break;
		
		
		
		
	}
	switch(b.gender){
		
		case 1: y="Male";
				break;
		case 2: y="Female";
				break;
	
			
	}
	printf("\n\tName: %s \n\\n\tAge: %d \n\tAddress : %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\t Gender:\n\n",b.name,b.age,b.address,b.phn,b.email,x,y);

printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}



void menu()
{
int choice;
clrscr();
printf("\n\n\t\t\t\tBLOOD DONOR DATABASE \n\n\n");
printf("\t1 Add a new entry\n\n");
printf("\t2 Search by Blood Group \n\n");
printf("\t3 Search by phone \n\n");
printf("\t4 Search by email \n\n");

printf("\t5 Display Donor details");
printf("\t6 Exit the program \n\n");
printf("\tYour Choice: ");



scanf("%d",&choice);
switch(choice)
{
case 1 : putdonor();
	 break;

case 2:  donorbybloodgroup();
	 break;

case 3:  donorbymobile();
	 break;

case 4:  donorbyemail();
	 break;

case 5:  display();
		break;

case 6:  exit();

default: clrscr();
	 printf("\n\n\t\tYou have entered wrong choice.....!!!");
	 delay(4000);
	 menu();

}
}





void donorbyemail()
{
char email[30];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the email  ");
scanf("%s",&email);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(b.email==email)      //Mathching the Bloodgroup required with the one's present in Database
{
	
	
String x,y;
	switch(b.bloodgroup){
		
		case 1: x="O-Positive";
				break;
		case 2: x="O-Negative";
				break;
		case 3: x="B-positive";
				break;
		case 4: x="B-negative";
				break;
		
		
		
		
	}
	switch(b.gender){
		
		case 1: y="Male";
				break;
		case 2: y="Female";
				break;
	
			
	}
printf("\n\tName: %s \n\\n\tAge: %d \n\tAddress : %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\t Gender:\n\n",b.name,b.age,b.address,b.phn,b.email,x,y);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}




void donorbymobile()
{
char city[20];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the phone number");
scanf("%s",phn);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if((strcmp(b.phn,phn))==0)      //Mathching the Bloodgroup required with the one's present in Database
{
String x,y;
	switch(b.bloodgroup){
		
		case 1: x="O-Positive";
				break;
		case 2: x="O-Negative";
				break;
		case 3: x="B-positive";
				break;
		case 4: x="B-negative";
				break;
		
		
		
		
	}
	switch(b.gender){
		
		case 1: y="Male";
				break;
		case 2: y="Female";
				break;
	
			
	}
printf("\n\tName: %s \n\\n\tAge: %d \n\tAddress : %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\t Gender:\n\n",b.name,b.age,b.address,b.phn,b.email,x,y);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}

void display()
{


clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);

rewind(fp);

while(fread(&b,size,1,fp)==1)
{

	
	
String x,y;
	switch(b.bloodgroup){
		
		case 1: x="O-Positive";
				break;
		case 2: x="O-Negative";
				break;
		case 3: x="B-positive";
				break;
		case 4: x="B-negative";
				break;
		
		
		
		
	}
	switch(b.gender){
		
		case 1: y="Male";
				break;
		case 2: y="Female";
				break;
	
			
	}
printf("\n\tName: %s \n\\n\tAge: %d \n\tAddress : %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\t Gender:\n\n",b.name,b.age,b.address,b.phn,b.email,x,y);
printf("\n");
fflush(stdin);

}
}





