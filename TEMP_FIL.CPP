#include<fstream.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class player
{public:
 char nm[25];
 unsigned long int score;
 player(){score=0;}
  void getdata();
 void putdata();
};
void player::getdata()
{cout<<"Enter Your name\n";
  gets(nm);
  cin>>score;
}
void player::putdata()
 {puts(nm);
  cout<<"          "<<score<<"\n";
 }

void main()
{player p;
 clrscr();

 ofstream fout("scores.dat",ios::out|ios::binary);
 for(int i=0;i<10;i++)
 {p.getdata();
  fout.write((char *)&p,sizeof(p));
 }
 fout.close();
}