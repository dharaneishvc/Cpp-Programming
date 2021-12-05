
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void check(int& a)
{
 switch(a)
 {
 case(0):break;
 case(1):break;
 case(2):break;
 case(3):break;
 case(4):break;
 case(5):break;
 case(6):break;
 default:cout<<"\n INVLID INPUT!!!! WILL BE CONSIDERED AS ZERO ";a=0;break;
 }
}
void line()
{
for(int x=0;x<79;x++)
{
cout<<char(216);
}
}
void open()
{
cout<<"\n\n";line();cout<<"\n\t\t\t\tCRICKET GAME \nOVERS:5\t\t\t\t\t\t\t\t  WICKETS:3\n\n";line();cout<<"\n";
}
class cricket
{
 public:
 int score_man,score_comp,wic_man,wic_comp,man[5][6],comp[5][6];
 void bating();
 void bowling();

};
void cricket::bating()
 {
   int temp;
   cout<<'\n';line();
   cout<<"\n\n\t\t\t *******BATING******\n";
   for(int i=0;i<5;i++)
   {
    cout<<"\n\n_____________________________________OVER "<<i+1<<"____________________________________\n";
    for(int j=0;j<6;j++)
    {
    cout<<"\n\nBALL "<<j+1;
    cout<<"\nEnter :";cin>>man[i][j];
    check(man[i][j]);
    temp=random(6)+1;
    cout<<"Bowling :"<<temp;
    if(temp==man[i][j])
    {cout<<"\nWICKET";wic_man++;}
    else
    {score_man+=man[i][j];}
    if(wic_man==3)
    {cout<<"\nALL OUT!!!"; goto END;}
   }
   }
  END:
  cout<<"\n\nTOTAL SCORE = "<<score_man<<" WICKETS LOST "<<wic_man ;
 }


void cricket::bowling()
 {
   int temp;
   cout<<'\n';line();
   cout<<"\n\n\t\t\t ******BOWLING******\n";
   for(int i=0;i<5;i++)
   {
    cout<<"\n\n_____________________________________OVER "<<i+1<<"____________________________________\n";
    for(int j=0;j<6;j++)
    {
    cout<<"\n\nBALL "<<j+1;
    cout<<"\nEnter :";cin>>temp;
    check(temp);
    comp[i][j]=random(7);
    cout<<"Bating :"<<comp[i][j];
    if(temp==comp[i][j])
    {cout<<"\nWICKET";wic_comp++;}
    else
    {score_comp+=comp[i][j];}
    if(wic_comp==3)
    {cout<<"\nALL OUT!!!"; goto END;}
   }
   }
  END:
  cout<<"\n\nTOTAL SCORE = "<<score_comp<<" WICKETS LOST "<<wic_comp ;
 }



void main()
{
 clrscr();
 open();
 cricket t1;
 t1.score_man=0;
 t1.score_comp=0;
 t1.wic_man=0;
 t1.wic_comp=0;
 t1.bating();
 t1.bowling();
 cout<<"\n\n\n";
 clrscr();
 open();
 cout<<"\n\n\t\t__________________RESULTS_______________";
 cout<<"\n\nYOUR SCORE IS "<<t1.score_man<<" - "<<t1.wic_man;
 cout<<"\n\nCOMPUTER SCORE IS "<<t1.score_comp<<" - "<<t1.wic_comp;
 if(t1.score_comp>t1.score_man)
 cout<<"\nYOU LOSE BY "<<t1.score_comp-t1.score_man<<" RUNS";
 else if(t1.score_comp<t1.score_man)
 cout<<"\nYOU WIN BY "<<t1.score_man-t1.score_comp<<" RUNS";
 else if(t1.score_comp==t1.score_man)
 cout<<"\nMATCH TIED";
 getch();
}
