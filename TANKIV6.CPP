/*               ..................................................
		 :   ||||||||                                     :
		 :	||	   /\       |\      |    |   /    :
		 :	||       /    \     |  \    |    |_/      :
		 :	||      |......|    |    \  |    |  \     :
		 :	||      |      |    |      \|    |    \   :
		 :                                                :
		 :   (C) $ANB$ 2015-2016.All rights reserved      :
		 ..................................................
*/

#include<tank.h>

void main(void)
{char chk;
int gd=DETECT,gm=gm;
initgraph(&gd,&gm,"");
int xc=getmaxx()/2,yc=getmaxy()-20;
int deg=90,dupd=deg,dupx=xc,dup_spoke=90,spoke=90,check=0,r=45,rndm=0,x_ball;
int h,cnt=0,dx,dy,hit=0,g=0,col[4]={15,2,4,14},coli=0,dupcol,ene=0,x_ene,y_ene,ene_col=0,ene_chk=0,y=0;
int ch,t_col[4]={5,9,1,6},t_spd[4]={4,7,2,2},b_spd[4]={4,4,6,3},t_hp[4]={60,40,80,120},score=0;
char t[1],ps[2];
player p;
double rad,a;   //enemy shoot angle;
cover();

while(1)
{
ch=chose_tank();
if(ch!=-1)
{cleardevice();
break;
}
else
{cleardevice();
continue;
}
}
cleardevice();

delay(2000);
int d=t_hp[ch];
sprintf(t,"%c",t);
t[0]=3;
settextstyle(0,0,1);
setcolor(RED);

for(h=0;h<(d/20);h++)
{outtextxy(500+(20*h),10,t);
}
setcolor(15);

while(1)
{delay(20);

 //CHECKING AND DETECTING KEYPRESS//

  if(kbhit())
  {chk=getch();
    if(chk=='l')                    //L to angle barrel towards right
    {if(deg-10>=0)
     {dup_spoke=spoke;
      dupd=deg;
      dupx=xc;
      deg-=10;
     }
    }
    else if(chk=='j')
    {if(deg+10<=180)                //J to angle barrel towards left
     {dup_spoke=spoke;
      dupd=deg;
      dupx=xc;
      deg+=10;
     }
    }
   else if(chk=='d')                //D to move tank towards right
   {if(xc<=getmaxx()-30)
    {dup_spoke=spoke;
     spoke+=10;
     dupx=xc;
     dupd=deg;
     xc+=t_spd[ch];
    }
   }
   else if(chk=='a')                //A to move tank towards left
   {if(xc>=30)
    {dup_spoke=spoke;
     spoke-=10;
     dupx=xc;
     dupd=deg;
     xc-=t_spd[ch];
    }
   }
   else if(chk=='s')                //S to shoot
   {check=1;
   }
   else if(chk=='k')                //K to change colour of your ball
   {coli++;
    if(coli>=4)
    coli=0;
   }

  else if(chk==27)
  {char tp;
  settextstyle(0,0,0);
   do
   {rectangle(getmaxx()/2-50,getmaxy()/2+50,getmaxx()/2+50,getmaxy()/2-50);
   outtextxy(getmaxx()/2-40,getmaxy()/2,"Do You want to exit ? (Y/N)");
   tp=getche();
   if((tp=='y')||(tp=='Y'))
   {cleardevice();
   writefl(p);
   cleardevice();
   readfl();
   getch();
  exit(0);
  }
  }while((tp=='n')||(tp=='N'));
   settextstyle(0,0,1);

   cleardevice();
     setcolor(RED);                    //
     outtextxy(470,10,"LIVES:");
     for(h=0;h<(t_hp[ch]/20);h++)      //DISPLAY LIFE
     {outtextxy(520+(20*h),10,t);      //
     }


   setcolor(15);                    //
      outtextxy(470,40,"SCORE: ");     //DISPLAY SCORE
      outtextxy(570,40,ps);            //

  }
  }


    //DRAWING THE TANK
   tank(dupx,yc,dupd,0,dup_spoke);     //Blackout Previous tank image(useful after 1 loop)
   tank(xc,yc,deg,t_col[ch],spoke);           //Draw present tank figure
    //-----------------//

   cnt++;
   if(cnt<100)
   continue;


   //-----ENEMY SHOOT-----//
   setcolor(0);
   circle(x_ene+((g-4)*cos(a)),y_ene-((g-4)*sin(a)),5);     //blackout ball
   setcolor(col[ene_col]);
   circle(x_ene+(g*cos(a)),y_ene-(g*sin(a)),5);             //new ball
   if((x_ene+(g*cos(a))-5>xc-30)&&(x_ene+(g*cos(a))+5<xc+30)&&(y_ene-(g*sin(a))-5>yc-20)&&(y_ene-(g*sin(a))+5<yc+20))
   {t_hp[ch]-=20;
    setcolor(0);
    circle(x_ene+((g)*cos(a)),y_ene-((g)*sin(a)),5);     //blackout ball
    outtextxy(500+(20*(--h)),10,t);
    setcolor(15);
    g=3000;
    if(t_hp[ch]==0)                   //GAME OVER health==0
    {cleardevice();

     outtextxy((getmaxx()/2)-70,getmaxy()/2,"GAME OVER");		   //
     delay(3000);
     settextstyle(3,HORIZ_DIR,2);
     outtextxy((getmaxx()/2)-100,(getmaxy()/2)+50,"PRESS ANY KEY TO CONTINUE");
     getch();			  //

    writefl(p);              //
    exit(0);
    }//$ANBS  PUT A GOOD EXIT REDIRECT TO MENU
   }


   g+=4;                                                    //SPEED of the ball




   if(hit==0)
   enemy(dx,dy,col[ene_col]);


   //--Detect Hit (WE hit the enemy)--//

   if((x_ball+(r*cos(rad))>=x_ene-40)&&(x_ball+(r*cos(rad))<=x_ene+40)&&(yc-20-(r*sin(rad))<=y_ene+20)&&(yc-20-(r*sin(rad))>=y_ene-20)&&(col[coli]==col[ene_col]))
   {  p.score++;     // ^This compares the coordinates of our bullet and the enemy ship positions. Also checks if colour of ship and bullet match//
      sprintf(ps,"%d",p.score);

      outtextxy(570,40,ps);
      ene_chk=1;      //< Make hit=positive to go into a loop to create new enemy and blast animation//
      r=45;            //
      check=0;         //The ball comes back to the barrel as soon as ball leaves screen
      rndm=0;          //
      ene=0;
      hit=1;
      score++;
   }

   //---WHEN YOU SHOOT---//

   if(check==1)
      {if(rndm==0)              //
      {rad=(deg*3.1415926)/180; // Useful only in the beginning till you dont shoot                                                                   //ball logic//
       x_ball=xc;               //
       dupcol=coli;             //
      }                         //

   setcolor(0);                                         //--BLACKOUT BALL--

   circle(x_ball+(r*cos(rad)),yc-20-(r*sin(rad)),5);
   r+=b_spd[ch];                                                //<--This is the speed of the ball

   //----------------------//

   //--for color of our ball--//

   setcolor(col[dupcol]);
   circle(x_ball+(r*cos(rad)),yc-20-(r*sin(rad)),5);
   rndm++;                                              //so the default angle of program start (ie 90)


   if((x_ball+(r*cos(rad))>=getmaxx()+5)||(x_ball+(r*cos(rad))<=-6)||(yc-20-(r*sin(rad))<=-6))
    {r=45;           //
    check=0;         //The ball comes back to the barrel as soon as ball leaves screen
    rndm=0;          //
    }
   }

   //---WHEN YOU DONT SHOOT---//
  else
   {rad=(dupd*3.1415926)/180;
    setcolor(0);
    circle(dupx+(r*cos(rad)),yc-20-(r*sin(rad)),5);
    setcolor(col[coli]);
    rad=(deg*3.1415926)/180;
    circle(xc+(r*cos(rad)),yc-20-(r*sin(rad)),5);
    }

    //--ENEMY--//
    if(ene_chk==1)            //If enemy is hit
    {enemy(x_ene,y_ene,0);    //Blackout previous enemy image
     ene=-100;                //Delays next enemy for 100 loops (short rest time for player)
     ene_chk=0;
     for(int i=1;i<30;i++)    //Blast animation
     {delay(10);
     setcolor(0);
     circle(x_ene,y_ene,i-1);
     setcolor(col[coli]);
     circle(x_ene,y_ene,i);
     }
     cleardevice();

     setcolor(RED);                    //
     for(h=0;h<(t_hp[ch]/20);h++)      //DISPLAY LIFE
     {outtextxy(500+(20*h),10,t);      //
     }

      setcolor(15);                    //
      outtextxy(470,40,"SCORE: ");     //DISPLAY SCORE
      outtextxy(570,40,ps);            //

    }

    if(ene==400)                  //when the previous enemy escapes//
    {
    ene=0;
    enemy(x_ene,y_ene,0);
    }

    //--FOR ENEMY--//

    if(ene==0)
    {hit=0;
     x_ene=random(getmaxx()-100)+30;                 //randomize the enemy position
     y_ene=random(getmaxy()-100)+40;                //randomize the enemy position
    dx=x_ene;
    dy=y_ene;
    a=asin(abs(x_ene-xc)/(sqrt(pow((x_ene-xc),2)+pow((y_ene-yc),2)))); //detecting angle of the line betn us and enemy
    if(x_ene<xc)
    a=(3*(3.1415926535897)/2)+a;
    else
    a=(3*(3.1415926535897)/2)-a;
    g=0;
    ene_col=random(4);                               //randomize the enemy color
    enemy(x_ene,y_ene,col[ene_col]);
    }
    ene++;
    //--------------------//


}
getch();
}





