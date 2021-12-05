#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<iomanip.h>
#include<fstream.h>
char tips[40][500]=
{
"A healthy outside starts from the inside.",
"Love yourself enough to live a healthy lifestyle.",
"To keep the body in good health is a duty, otherwise we shall not be able to keep our mind strong and clear.",
"Health is not valued till sickness comes.",
"Take care of your body. It's the only place you have to live.",
"Health is the greatest gift.",
"Health is the crown on the well persons head that only the ill person can see.",
"It is health that is real wealth and not pieces of gold and silver.",
"Those who think they have no time for healthy eating will sooner or later have to find time for illness.",
"You can't enjoy wealth if you're not in good health.",
"The mind and body are not separate. what affects one, affects the other.",
"Happiness is the highest form of health.",
"The first wealth is health.",
"Healthy citizens are the greatest asset any country can have.",
"There is no diet that will do what eating healthy does. Skip the diet. Just eat healthy.",
"You learn good health and family are it, and nothing else matters.",
"Your body deserves the best.",
"Take care of yourself, be healthy, and always believe you can be successful in anything you truly want.",
"If you're too busy to workout, your priorities need to change. I can't think of too many things more important than your health.",
"I'm healthy as can be – not an ache or pain. A lot of my prayer is thanking God that I am healthy. I pray for long life and good health.",
"The ingredients of health and long life, and great temperance, open air, easy labor, and little care.",
"A healthy mind does not speak ill of others.",
"What you eat literally becomes you. you have a choice in what you're made of.",
"Think positively and exercise daily, eat healthy, work hard, stay strong, build faith, worry less, read more, and be happy.",
"A fool does not care about his health.",
"We know that food is a medicine, perhaps the most powerful drug on the planet with the power to cause or cure most disease.",
"The food you eat can be either the safest and most powerful form of medicine or the slowest form of poison.",
"If it came from a plant, eat it. If it was made in a plant, don't.",
"If you keep good food in your fridge, you will eat good food.",
"When diet is wrong, medicine is of no use. When diet is correct, medicine is of no need.",
"You can't expect to look like a million bucks if you eat from the dollar menu.",
"Health requires healthy food.",
"Sufficient sleep, exercise, healthy food, friendship, and peace of mind are necessities, not luxuries.",
};
void disp()
{
 randomize();
 int n;
 n=random(32);
 cout<<tips[n];
}

void line()
{
cout<<"\n";
for(int i=0;i<=78;i++)
cout<<char(176);
cout<<"\n";
}
void newpage()
{
 textbackground(RED);
 textcolor(WHITE);
 clrscr();

 cout<<"\n\t\t\t\tAPOLLO HOSPITALS";
 cout<<"\n\t\t\t\t\    CHENNAI\t\t\t Emergency:1066";
 line();
 disp();
 line();
}
void main()
{
newpage();


  getch();
}