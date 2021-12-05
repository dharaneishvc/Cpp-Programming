#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
void correction(char ans,char c_ans,int& mark,int& c,int& w)
{

 if((ans==tolower(c_ans))||(ans==toupper(c_ans)) )
 {cout<<"\n\nCORRECT!!!\n\n"; mark+=4;c++;}
 else
 {cout<<"\n\nINCORRECT!!!\n\n";mark--;w++;}

}
void eligibility(int gra)
{
 if((gra!=11)&&(gra!=12))
 {
   cout<<"\n\nSORRY !!! NOT ELIGIBLE ";
   cout<<"\nEnter class (11/12): ";
   cin>>gra;
   eligibility(gra);
 }

}
void line()
{
cout<<"\n\n";
for(int t=0;t<=78;t++)
cout<<char(240);
cout<<'\n';

}
void next()
{
 cout<<"\n\nPress Enter for Next Question";
 getch();
 clrscr();
 line();
}
void main()
{
 char id[30],password[8],ans[12];
 int mark=0,c=0,w=0;
 clrscr();
 line();
 cout<<"\n\t\tSAGAR INTERNATIONAL SENIOR SECONDARY SCHOOL \n";
 cout<<"\n\t\t\t\tPERUNDURAI";
 line();
 cout<<"\n\t\t\tSTUDENTS EXAMINATION PORTAL \n";
 cout<<"\nEnter user ID : ";
 gets(id);
 if(!((strcmp(strupr(id),"dharaneishvc")==0)||(strcmp(strlwr(id),"dharaneishvc")==0)))
 {cout<<"\nINCORRECT USER NAME!!!\nPress any key to exit";getch();exit(0);   }

 cout<<"\nEnter Password(case sensitive) : ";
 for(int i=0;i<8;i++)
 {
   password[i]=getch();
   cout<<"*";
 }

  if(!((strcmp(password,"28102002")==0)))
 {cout<<"\nINCORRECT PASSWORD!!!\nPress any key to exit";}
 else

 {
 clrscr();int gra; char name[30];
 cout<<"\nWELCOME TO QUIZ ";
 cout<<"\nEnter your name: ";gets(name);
 cout<<"\nEnter your class(11/12): ";cin>>gra;
 eligibility(gra);

 clrscr();
 cout<<"\nHI "<<name;
 cout<<"\n\nTOTAL NO OF QUESTIONS: 10\nMAXIMUM MARKS: 40\nTIME PERIOD: 10 minutes\n";
 cout<<"\n\n____________________________General Instructions_______________________________\n1.All Questions are compulsory.\n2.All Questions are Single correct answer type Questions.\n3.Question Once Answered cannot be changed.\n4.You cannot unattempt any Question.\n5.Any wrong responses will be considered as Incorrect only.\n________________________________ALL THE BEST___________________________________ ";
 cout<<"\n\n\nPRESS ENTER TO START TEST ";
 getch();
 clrscr();
Q1:
 {
 line();
 cout<<"\n 1.In which of the years did India got WorldCup?\nA.1983,2007\nB.1987,2011\nC.1983,2011\nD.1961,2001 ";
 cout<<"\nEnter your Answer:";cin>>ans[0];
 correction(ans[0],'C',mark,c,w);
 next();
Q2:
 {
  cout<<"\n 2.Which is the largest ocean in earth?\nA.Pacific\nB.Atlantic\nC.Indian\nD.Antartic";
  cout<<"\nEnter your Answer:";cin>>ans[1];
  correction(ans[1],'A',mark,c,w);
  next();
 }
Q3:
 {
  cout<<"\n 3.Which is the only even prime Number?\nA.0\nB.2\nC.1\nD.4";
  cout<<"\nEnter your Answer:";cin>>ans[2];
  correction(ans[2],'B',mark,c,w);
  next();
 }
Q4:
 {
  cout<<"\n 4.When is Pakistan's Independence Day celebrated?\nA.August 15\nB.August 14\nC.January 26\nD.January 25";
  cout<<"\nEnter your Answer:";cin>>ans[3];
  correction(ans[3],'B',mark,c,w);
  next();
 }
 Q5:
 {
  cout<<"\n 5.What is the height of Mount Everest?(in metres)\nA.4484m\nB.8848m\nC.7888m\nD.8000m";
  cout<<"\nEnter your Answer:";cin>>ans[4];
  correction(ans[4],'B',mark,c,w);
  next(); }
Q6:
 {
  cout<<"\n 6.What is the National Game of Bangladesh\nA.Hockey\nB.Cricket\nC.Kho-Kho\nD.Kabaddi";
  cout<<"\nEnter your Answer:";cin>>ans[5];
  correction(ans[5],'D',mark,c,w);
  next();
}

Q7:
{
  cout<<"\n 7.Which of the following Country is not a part of SAARC?\nA.India\nB.Pakistan\nC.China\nD.Srilanka";
  cout<<"\nEnter your Answer:";cin>>ans[6];
  correction(ans[0],'C',mark,c,w);
  next();
}

Q8:
{
  cout<<"\n 8.Which of the following country's cricket team got the ICCI World Cup in 2015?\nA.Australia\nB.India\nC.Newzeland\nD.Pakistan";
  cout<<"\nEnter your Answer:";cin>>ans[7];
  correction(ans[7],'A',mark,c,w);
  next();
}

Q9:
{
  cout<<"\n 9.Which of the following IPL team won the first IPL T20 in 2008?\nA.Chennai Super Kings\nB.Mumbai Indians\nC.Pune Warriors India\nD.Rajastan Royals";
  cout<<"\nEnter your Answer:";cin>>ans[8];
  correction(ans[8],'D',mark,c,w);
  next();
}

Q10:
 {
  cout<<"\n 10.What is the capital of Japan?\nA.Tokyo\nB.Chennai\nC.New Delhi\nD.Washington DC";
  cout<<"\nEnter your Answer:";cin>>ans[9];
  correction(ans[9],'A',mark,c,w);
  cout<<"\n\n\n Press Enter for Results ";
  getch();
 }
 clrscr();
 line();
  cout<<"\n\t\t\t\t___RESULT___\n\n";
 cout<<"\n\nNo of correct answers is "<<c;
 cout<<"\nNo of wrong answers is "<<w;
 cout<<"\n\n\n";
 if(mark>30)
 cout<<"\nCONGRATULATIONS!!!";
 else if(mark>20)
 cout<<"\nGOOD!!!";
 else if(mark>10)
 cout<<"\nNOT BAD!!!";
 else if(mark>0)
 cout<<"\nIMPROVE NEXT TIME!!!";
 else if(mark==0)
 cout<<"\nSORRY!!!";
 cout<<"\nTOTAL MARKS OUT OF 40 IS "<<mark;
 cout<<"\n\n(For every correct answer +4 will be awarded &\n -1 will be deducted for every Wrong Answer)\n\n";

 }
 }
 getch();
}

