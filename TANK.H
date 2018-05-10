#include<graphics.h>
#include<iomanip.h>
#include<string.h>
#include<math.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
void h_bar(int h)
{rectangle(450,67,470,5);
 int i=1;
 h/=20;
 h=60/h;
 for(int j=0;j<h;j++)
 {i*=h;
 for(;i>5;i--)
 {line(451,i,469,i);
 }
 }
}
void tank(int x,int y,int deg,int c,int spoke)
{setcolor(c);
moveto(x,y);
lineto(x+30,y);
moveto(x,y);
lineto(x-30,y);
ellipse(x,y,0,180,30,20);
circle(x-15,y+5,5);
circle(x+15,y+5,5);
moveto(x,y-20);
double rad,rad_spoke;
rad=(deg*3.1415926)/180;
lineto(x+(40*cos(rad)),y-20-(40*sin(rad)));


rad_spoke=(spoke*3.1415926)/180;
line(x-15+(5*cos(rad_spoke)),y+5+(5*sin(rad_spoke)),x-15-(5*cos(rad_spoke)),y+5-(5*sin(rad_spoke)));
rad_spoke=((spoke+90)*3.1415926)/180;
line(x-15+(5*cos(rad_spoke)),y+5+(5*sin(rad_spoke)),x-15-(5*cos(rad_spoke)),y+5-(5*sin(rad_spoke)));

rad_spoke=(spoke*3.1415926)/180;
line(x+15+(5*cos(rad_spoke)),y+5+(5*sin(rad_spoke)),x+15-(5*cos(rad_spoke)),y+5-(5*sin(rad_spoke)));
rad_spoke=((spoke+90)*3.1415926)/180;
line(x+15+(5*cos(rad_spoke)),y+5+(5*sin(rad_spoke)),x+15-(5*cos(rad_spoke)),y+5-(5*sin(rad_spoke)));
setcolor(15);
setlinestyle(1,1,3);
line(0,getmaxy()-3,getmaxx(),getmaxy()-3);
line(0,getmaxy()-1,getmaxx(),getmaxy()-1);
line(0,getmaxy()-5,getmaxx(),getmaxy()-5);
setlinestyle(0,0,0);

}

class player
{public:
 char nm[25];
 unsigned long int score;
 player(){score=0;}
  void getdata();
 void putdata();
// ~player();

};
void player::getdata()
{cout<<"Enter Your name\n";
  gets(nm);
}
void player::putdata()
 {cout<<nm;
  int len=strlen(nm);
  cout<<setw(19-len)<<score<<"\n";
 }

void writefl(player p)
{cleardevice();
 p.getdata();
 player l;
 char chk='y';
 ifstream file("scores.dat",ios::in|ios::binary);
 ofstream fout("temp.dat",ios::out|ios::binary);
 while(!file.eof())
 {file.read((char *)&l,sizeof(l));
  if(p.score<=l.score)
  fout.write((char*)&l,sizeof(l));
  else
 {fout.write((char*)&p,sizeof(p));
  fout.write((char*)&l,sizeof(l));
  chk='n';
  break;
 }
}
  if(chk=='y')
   fout.write((char*)&p,sizeof(p));
  else if(!file.eof())
   {while(!file.eof())
    {file.read((char*)&l,sizeof(l));
     fout.write((char*)&l,sizeof(l));
    }
   }

   file.close();
   fout.close();
   remove("scores.dat");
   rename("temp.dat","scores.dat");
}

  void readfl()
  {ifstream file("scores.dat",ios::in|ios::binary);
   ofstream fout("temp.dat",ios::out|ios::binary);
   player p;
   int cnt=0;
    while(!file.eof())
    {file.read((char*)&p,sizeof(p));
     cnt++;
     if(cnt<=10)
     {fout.write((char*)&p,sizeof(p));
      }
  else
  break;
 }
 file.close();
 fout.close();
 remove("scores.dat");
 rename("temp.dat","scores.dat");
 int k=0;
 ifstream fi("scores.dat");
 while(!fi.eof())
 {fi.read((char*)&p,sizeof(p));
  if(k==0)
  cout<<"NAME"<<setw(19)<<"SCORE\n";
  if(k<10)
  p.putdata();
  k++;
 }
}

void viewscore()
{moveto(0,0);
 readfl();
 getch();
}





int chose_tank()
{
int x=getmaxx()/2;
int y=getmaxy()/2;

rectangle(x-230,y+100,x-130,y-100);
tank(x-180,y-25,45,5,90);
outtextxy(x-220,y,"HP = 60");
outtextxy(x-220,y+15,"Mov_spd = 4");
outtextxy(x-220,y+30,"ballspd = 4");


rectangle(x-110,y+100,x-10,y-100);
tank(x-60,y-25,45,9,90);
outtextxy(x-100,y,"HP = 40");
outtextxy(x-100,y+15,"Mov_spd = 7");
outtextxy(x-100,y+30,"ballspd = 4");

rectangle(x+10,y+100,x+110,y-100);
tank(x+60,y-25,45,1,90);
outtextxy(x+20,y,"HP = 80");
outtextxy(x+20,y+15,"Mov_spd = 2");
outtextxy(x+20,y+30,"ballspd = 6");


rectangle(x+130,y+100,x+230,y-100);
tank(x+180,y-25,45,6,90);
outtextxy(x+140,y,"HP = 120");
outtextxy(x+140,y+15,"Mov_spd = 2");
outtextxy(x+140,y+30,"ballspd = 3");
int i;
outtextxy(x-230,y+120,"Enter Your choice (1,2,3,4) ---> ");
cin>>i;
if((i==1)||(i==2)||(i==3)||(i==4))
return(i-1);
else
{outtextxy(x-230,y+130,"Invalid choice entered (press any key)");
getch();
return(-1);
}


}
int loading()
{int x=getmaxx()/2;
int y=getmaxy()/2,dup=0;

rectangle(x-100,y+10,x+100,y-10);
tank(x,(2*y)-20,90,15,90);
setcolor(RED);
settextstyle(TRIPLEX_FONT,0,2);
outtextxy(x-45,y+20,"L");
outtextxy(x-30,y+15,"O");
outtextxy(x-15,y+20,"A");
outtextxy(x,y+15,"D");
outtextxy(x+15,y+20,"I");
outtextxy(x+30,y+15,"N");
outtextxy(x+45,y+20,"G");
outtextxy(x+65,y+20,"...");


setcolor(YELLOW);
while(1)
{int k=random(49);
 dup+=k;
 for(int i=1;(i<=dup)&&((i+x-100)<(x+100));i++)
 line(x-100+i,y+9,x-100+i,y-9);
 delay(500);
 if(dup>=200)
 break;
}
setcolor(15);
cleardevice();
return 0;
}

void enemy(int x,int y,int c)
{setcolor(c);
circle(x,y,5);
moveto(x,y+20);
lineto(x+15,y+20);
lineto(x+20,y+15);
moveto(x,y+20);
lineto(x-15,y+20);
lineto(x-20,y+15);

moveto(x,y-20);
lineto(x+15,y-20);
lineto(x+20,y-15);
moveto(x,y-20);
lineto(x-15,y-20);
lineto(x-20,y-15);

ellipse(x-20,y,90,270,15,15);
ellipse(x+20,y,270,90,15,15);
}

int htp()
{int x=getmaxx()/2;
int y=getmaxy(),i=0;

tank(x,y-20,90,15,90);
delay(2000);
for(i=0;i<30;i++)
{outtextxy(x-30,y/2,"D to MOVE RIGHT");
 tank(x+(5*i),y-20,90,15,90-(45*i));
 delay(70);
 tank(x+(5*i),y-20,90,0,90-(45*i));
}
cleardevice();
for(i=0;i<30;i++)
{outtextxy(x-30,y/2,"A to MOVE LEFT");
 tank(x-(5*i),y-20,90,15,90+(45*i));
 delay(70);
 tank(x-(5*i),y-20,90,0,90+(45*i));
}
cleardevice();
for(i=0;i<18;i++)
{outtextxy(x-30,y/2,"L to MOVE CLOCKWISE");
 tank(x,y-20,90-(i*5),15,90);
 delay(150);
 tank(x,y-20,90-(i*5),0,90);
}
cleardevice();
for(i=0;i<18;i++)
{outtextxy(x-30,y/2,"J to MOVE ANTI-CLOCKWISE");
 tank(x,y-20,90+(i*5),15,90);
 delay(150);
 tank(x,y-20,90+(i*5),0,90);
}
cleardevice();
for(i=0;i<18;i++)
{setcolor(15);
  outtextxy(x-30,y/2,"S to SHOOT");
 tank(x,y-20,90,15,90);
 circle(x,y-90-(4*i),5);
 delay(150);
 setcolor(0);
 circle(x,y-90-(4*i),5);
}
cleardevice();
for(i=0;i<10;i++)
{setcolor(15);
  outtextxy(x-30,y/2,"K to change COLOR");

setcolor(random(15)+1);
 circle(x,y-90,5);
tank(x,y-20,90,15,90);
 delay(500);
}

return 0;
}


int cover()
{int z=0;
int k,col[4]={4,15,15,15};        //=4,col2=15,col3=15,
int cc,color1=1,color2;
int x=getmaxx()/2;
int y=getmaxy()/2;
char chr;
while(1)
{if(z==30)
{ z=0;
cleardevice();
{for(int o=1;o<100;o++)
{int k=random(2*x);
int g=random(2*y);
putpixel(k,g,15);
}
}
}
setcolor(15);
settextstyle(1,0,3);
outtextxy(x-103,y-120,"ALIEN");
tank(x,y-100,90,15,90);
outtextxy(x+45,y-120,"SHOOTER");
settextstyle(1,0,2);
setcolor(col[0]);
outtextxy(x-40,y+20,"1.PLAY");
setcolor(col[1]);
outtextxy(x-40,y+50,"2.HOW TO PLAY");
setcolor(col[2]);
outtextxy(x-40,y+80,"3.HIGH SCORES");
setcolor(col[3]);
outtextxy(x-40,y+110,"4.QUIT");
z++;
if(kbhit())
{
chr=getch();
if((chr=='s')&&(col[3]==4))
{
col[0]=4;
col[3]=15;
col[1]=15;
col[2]=15;

}
else if((chr=='s')&&(col[0]==4))
{
col[1]=4;
col[0]=15;
col[2]=15;
col[3]=15;

}
else if((chr=='s')&&(col[1]==4))
{
col[2]=4;
col[1]=15;
col[3]=15;
col[0]=15;

}
else if((chr=='s')&&(col[2]==4))
{
col[2]=15;
col[3]=4;
col[1]=15;
col[0]=15;

}

else if(chr==13)
{if(col[0]==4)
{cleardevice();
settextstyle(0,0,0);
return 0;
}
else if(col[2]==4)
{cleardevice();
 viewscore();
 cleardevice();
 continue;	       ////////////
}
else if(col[1]==4)
{cleardevice();
 htp();
 continue;
}
else if(col[3]==4)
exit(0);
}
}
}
}

