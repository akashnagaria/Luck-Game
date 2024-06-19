/*******************************************************
HEADER FILES AND PREPROCESSOR DIRECTIVES USED IN PROJECT
*******************************************************/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#define axb textbackground(WHITE);textcolor(BLACK);
#define hrk textbackground(WHITE);textcolor(BLACK+BLINK);
#define kjw textbackground(BLACK);textcolor(BLUE);
#define kjwbl textbackground(BLACK);textcolor(RED+BLINK);

/*******************************************************
	       CLASSES USED IN PROJECT
*******************************************************/

class match
 {
  int mp_nos;
  int mg_nos;
  int mg_pos;

   public:

   match()
    {
     mg_pos=100;
    }

  int p_nos(){return mp_nos;}
  int g_nos(){return mg_nos;}
  int g_pos(){return mg_pos;}

   void put_p_nos(int a){mp_nos=a;}
   void put_g_nos(int b){mg_nos=b;}
   void put_g_pos(int c){mg_pos=c;}
   void incpos(){mg_pos++;}

    void m_scoreboard()
      {
	cout<<"\nMatch details";
	cout<<"\nNo. of games:"<<mg_nos;
	cout<<"\nNo. of players:"<<mp_nos;

	  if(mg_pos<mg_nos)
	    {
	      cout<<"\nRound number undergoing:"<<mg_pos;
	    }
      }
 }m1;

 class player
  {
    int p_id;
    char name[20];
    int score_p;
    int match;

      public:

       int choice;

      player()
       {
	score_p=0;
	match=0;
	p_id=-12;
       }

	 void nullp()
	   {
	    score_p=0;
	    match=0;
	   }



	 void dispname()
	  {
	    cout<<name;
	  }

	void cpname()
	  {
	    cprintf("%s",name);
	  }

	void modifyname()
	  {
	    gets(name);
	  }

	void putscore(int ye)
	  {
	    score_p=ye;
	  }

	void equpdate(int a)
	  {
	   if(choice==a)
	    {
	     ++score_p;
	     cout<<endl<<name<<" You are lucky";
	    }
	   else
	    {
	     cout<<endl<<name<<" Going to get a 40000 volt shock";
	    }
	   }

	void p_reg()
	 {
	  while(1)
	   {
	    cout<<"\nEnter name:";
	    gets(name);
	    if(strcmpi(name,".")==0)
	     {
	      cout<<"\nInvalid Name.Only Dot Name not allowed.Enter Again\n";
	     }
	    else
	     {
	      break;
	     }
	   }

	 p_id=checkempty()+1+(10*random(11));
	 cout<<"\nYour id for matches:"<<p_id;
       }


	void searchresults()
	 {
	  cout<<"\nPLAYER ID:\t"<<p_id;
	  cout<<"\nNAME:\t"<<name;
	  cout<<"\nTOTAL CAREER SCORE:\t"<<score_p;
	  cout<<"\nTOTAL MATCHES WON:\t"<<match;
	 }

	int getid()
	 {
	  return p_id;
	 }

	int getscore()
	 {
	  return score_p;
	 }

	void imatch()
	 {
	  match++;
	 }

	void matchn(int asdd)
	 {
	  match=asdd;
	 }

	int getmatch()
	 {
	  return match;
	 }

	void newscore(int yew)
	 {
	  score_p+=yew;
	 }

	void scdet()
	 {
	  cout<<p_id<<"\t"<<name<<"\t\t\t"<<score_p<<"\t\t\t"<<match;
	 }

	void scid()
	 {
	  cout<<"\t\t"<<p_id<<"\t"<<name;
	 }

	void scm()
	 {
	  cout<<"\t"<<p_id<<"\t"<<name<<"\t\t\t\t"<<score_p;
	 }

	void nullscore()
	 {
	  score_p=0;
	 }

	void gdata()
	 {
	  cout<<"(ID NO::"<<p_id<<") "<<name;
	 }

	char* retname()
	 {
	  return name;
	 }

	int getpcho()
	 {
	  return choice;
	 }

	void assigncho(int a)
	 {
	  choice=a;
	 }

 }p1,pn;

/*******************************************************
	      FUNCTIONS USED IN PROJECT
*******************************************************/


 void loading(void);

 int modifier(void);

 void search (long);

 void reg(void);

 void game(int);

 void nullmatch(void);

 void remove_player(void);

 void halloffame(void);

 int match_reg(void);

 void match_data(void);

 int check_zero(void);

 void clearrecords(void);

 void profile(void);

 int yn(char []);

 int checkempty(void);

 void playerlist(void);

 void searchmenu(void);

 void rank(player[],match);

 void updatecareer(player);

 player scd(void);
 int checkinmatch(player PCK);

   void loading()
    {
     kjw
      clrscr();

      int i,j;

     for(i=0;i<=100;i++)
      {
       gotoxy(32,15);kjwbl
       cprintf("LOADING...");
       hrk

	if(i<78)
	 {
	  gotoxy(2+i,20);
	  cprintf(" ");
	 }

       gotoxy(2,19);
       cout<<i<<"%";

       gotoxy(1,21);

	if(i==12){cout<<"\n Loading binary files...";delay(800);}
	if(i==23){cout<<"\n Loading game...        ";delay(400);}
	if(i==52){cout<<"\n Sparking game engine...";delay(100);}
	if(i==83){cout<<"\n Starting Up...         ";delay(600);}

	 if(i<82)
	  {
	   delay(25);
	  }

	else
	 {
	  delay(20);
	 }
    }
 }

 void instructions()
  {
   kjw
    clrscr();
      gotoxy(31,1);
      textcolor(WHITE);
      cprintf("INSTRUCTIONS");
      gotoxy(2,3);
      textcolor(BLUE);
      cprintf("\n\n1.To play game registration is required which is in profile menu.");
      gotoxy(2,4);
      cprintf("\n\n2.This game tests luck of your entered choice.");
      gotoxy(2,5);
      cprintf("\n\n3.Match of an entered choice scores a point to the player");
      gotoxy(2,6);
      cprintf("\n\n4.Who wins most rounds wins the match.");
      textcolor(WHITE);
      gotoxy(2,10);
      cprintf("CONTROLS:");
      gotoxy(2,11);
      textcolor(RED);
      cprintf("\nW - option up\nS - option down\nA - option left\nD - option right\n");
      gotoxy(2,17);
      cprintf("\nP - pause game\nENTER key - select option");
      gotoxy(2,19);
      textcolor(WHITE);
      cprintf("\n\nIn case of any problems or errors please contact abcxyz@gmail.com");
      gotoxy(28,21);
      textbackground(WHITE);textcolor(RED+BLINK);
      cprintf("\n\nPress any key to continue");
    getch();
  }

  void main()
   {
     clrscr();
       char x;
       axb
       gotoxy(33,6);
       cprintf("\nA PROJECT ON");
       gotoxy(34,8);
       textcolor(BLUE);
       cprintf("LUCK GAME");
       textbackground(BLACK);textcolor(WHITE);
       gotoxy(35,11);
       textcolor(RED);
       cprintf("MADE BY");
       gotoxy(33,12);
       textcolor(BLUE);
       cprintf("Akash Nagaria");
       gotoxy(28,14);
       textbackground(WHITE);textcolor(RED+BLINK);
       cprintf("\n\n\nPRESS ENTER TO CONTINUE");
       getch();
      kjw
      instructions();
      loading();

       int op=1;
       char res;



	while(1)
	 {
	  kjw
	   clrscr();
	    cout<<"\n              *******************************************";
	    cout<<"\n                     WELCOME TO LUCK TESTING GAME";
	    cout<<"\n              *******************************************";
	    cout<<"\n              (Hint:Enter highlighted option to open it";
	    cout<<"\n                 and 'W' to up and 'S' to down option)";


	     randomize();

	      if(op==1)
	       {
		 hrk gotoxy(31,8);cprintf("INSTRUCTIONS");
		  if(res==13)
		   {
		    instructions();res=0;continue;
		   }
	       }
	      else
	       {
		 kjw gotoxy(31,8);cprintf("INSTRUCTIONS");
	       }

	      if(op==2)
	       {
		hrk gotoxy(31,10);cprintf("NEW GAME");
		 if(res==13)
		  {
		   if(checkempty()<2)
		    {
		     kjwbl
		     clrscr();
		     cout<<"\n\n\n\n\n\n\n\n\t\t\tERROR! PLEASE REGISTER MINIMUM TWO PLAYERS!";
      getch();
      res=0;
      continue;
  }


		      if(!check_zero())
			if(!yn("A resume game is stored do you want to erase the save game?"))
			  {
			    res=0;
			    continue;
			  }
			 clearrecords();
			  if(match_reg())
			   {
			    res=0;continue;
			   }
			   game(1);
			   res=0;
			   continue;}
			}
			else
			 {
			  kjw gotoxy(31,10);
			  cprintf("NEW GAME");
			 }

  if(!check_zero())
   if(op==3)
     {
      hrk gotoxy(31,12);
      cprintf("RESUME GAME");
      if(res==13)
       {
	game(0);
	res=0;
	continue;
      }
    }
   else
    {
     kjw gotoxy(31,12);
     cprintf("RESUME GAME");
    }

  if(op==4)
    {
     hrk
      if(!check_zero())
       gotoxy(31,14);
      else
       gotoxy(31,12);

    cprintf("PROFILE MENU");
      if(res==13)
       {
	profile();
	res=0;
	continue;}
       }
      else
       {
	kjw
	 if(!check_zero())
	  gotoxy(31,14);
	 else
	  gotoxy(31,12);

     cprintf("PROFILE MENU");}
       if(op==5)
	{
	  hrk
	   if(!check_zero())
	    gotoxy(31,16);
	   else
	    gotoxy(31,14);

     cprintf("HALL OF FAME");
       if(res==13)
	{
	 halloffame();
	 res=0;
	 continue;}
	}
       else
	{
	 kjw
	  if(!check_zero())
	   gotoxy(31,16);
	  else
	   gotoxy(31,14);

     cprintf("HALL OF FAME");}
       if(op==6)
	{
	 hrk
	  if(!check_zero())
	   gotoxy(31,18);
	  else
	   gotoxy(31,16);

     cprintf("MATCH SCORE");
       if(res==13)
	{
	 match_data();
	 res=0;
	 continue;
	}
       }
      else
       {
	kjw
	 if(!check_zero())
	  gotoxy(31,18);
	 else
	  gotoxy(31,16);

     cprintf("MATCH SCORE");}
       if(op==7)
	{
	 hrk
	  if(!check_zero())
	   gotoxy(31,20);
	  else
	   gotoxy(31,18);

     cprintf("EXIT");
       if(res==13)
	{
	 cout<<"\n";
	 break;
	}
       }

      else
       {
	kjw
	 if(!check_zero())
	  gotoxy(31,20);
	 else
	  gotoxy(31,18);

     cprintf("EXIT");}

   res=getch();

     if(res=='e' || res=='E')
      break;

     if(check_zero())
      {
       if(op==2 && (res=='s'||res=='S'))
	{
	 op+=2;continue;
	}

       if(op==4 && (res=='w'||res=='W')){op-=2;continue;}
      }

	if(res=='w'||res=='W')op--;
	if(res=='s'||res=='S')op++;

	if(op==8)
	 op=1;
	if(op==0)
	 op=7;
   }
 }

  void profile()
   {
    kjw
    clrscr();
     char t;
     int prp=1;
      while(1)
       {
	kjw
	 clrscr();
	  cout<<"\n              ***********************************";
	  cout<<"\n                            PROFILE MENU";
	  cout<<"\n              ***********************************";
	   if(prp==1)
	    {
	     hrk
	      gotoxy(31,8);
	      cprintf("PROFILE REGISTRATION");
		if(t==13)
		 {
		  if(checkempty()>=9)
		   {
		    kjwbl
		     clrscr();
		     cout<<"\n\n\n\n\n\n\n\n\t\t\tMEMORY FULL";
		     getch();
		     t=0;
		     continue;
		   }
		     reg();
		     t=0;
		     continue;
		  }
   }
    else
     {
      kjw
       gotoxy(31,8);
	cprintf("PROFILE REGISTRATION");
     }

    if(prp==2)
     {
      hrk
       gotoxy(31,10);
       cprintf("DELETE PROFILE");

      if(t==13)
       {
	if(!checkempty())
	  {
	   kjwbl
	   clrscr();
	   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t!!DATABASE IS EMPTY!!";
	   getch();
	   t=0;
	   continue;
	  }
	   remove_player();
	   t=0;
	   continue;}
	 }
       else
	{
	 kjw
	  gotoxy(31,10);
	  cprintf("DELETE PROFILE");
	}

	if(prp==3)
	 {
	  hrk
	   gotoxy(31,12);
	   cprintf("MODIFY NAME");
	if(t==13)
	 {
	  if(!checkempty())
	   {
	    kjwbl
	    clrscr();
	    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t!!DATABASE IS EMPTY!!";
	    getch();
	    t=0;
	    continue;
	   }

	  if( modifier()>0 )
	   {
	    cout<<"\nNAME CHANGED";
	   }
	    getch();
	    t=0;
	    continue;
	   }
	 }
	  else
	   {
	    kjw
	     gotoxy(31,12);
	      cprintf("MODIFY NAME");}

	 if(prp==4)
	  {
	   hrk
	    gotoxy(31,14);
	    cprintf("SEARCH PLAYER");
	 if(t==13)
	  {
	   kjw
	    clrscr();
	    if(!checkempty())
	     {
	      kjwbl
	       clrscr();
	       cout<<"\n\n\n\n\n\n\n\n\t\t\t\t!!DATABASE IS EMPTY!!";
	       getch();
	       t=0;
	       continue;
	     }

	   searchmenu();
	     getch();t=0;
	       continue;

	     }
		  }
	    else
	     {kjw gotoxy(31,14);         cprintf("SEARCH PLAYER");}

	if(prp==5)
	 {
	  hrk
	  gotoxy(31,16);
	  cprintf("EXIT PROFILE MENU");
	if(t==13)
	 {
	  break;
	 }
	}
	else
	 {
	  kjw
	   gotoxy(31,16);
	   cprintf("EXIT PROFILE MENU");
	 }

       t=getch();

       if(t=='w'||t=='W')prp--;
       if(t=='s'||t=='S')prp++;

	if(prp==6)prp=1;
	if(prp==0)prp=5;
    }
  }


	int check_zero()
	 {
	  int p=0;
	   fstream cz("match.dat",ios::in|ios::out|ios::binary);
	   cz.read((char*)&m1,sizeof(m1));

	  if(m1.g_pos()==100)
	   p=1;

	 return p;
	}

	void match_data()
	 {
	  kjw
	   clrscr();
	   match m;
	   int i=0;
	   fstream fil("match.dat",ios::in|ios::out|ios::app|ios::binary);
	   fil.read((char*)&m,sizeof(m));
	   m.m_scoreboard();
	   player*pss=new player[m.p_nos()];
	    while(!fil.eof())
	    {
	     fil.read((char*)&p1,sizeof(p1));
	 if(fil.eof())
	  break;

	pss[i]=p1;
	 i++;
	}
    fil.close();
	cout<<"\n\t\tRECENT MATCH DATA\n\n\n\tID\tName         \t\t\tScore";

	 i=0;
      while(i<m.p_nos())
       {
	cout<<endl;
	pss[i].scm();
	i++;
      }
    fil.close();
   cout<<endl<<endl;

	rank(pss,m);
	 delete pss;

   getch();
 }

 void reg()
  {
   kjw
   clrscr();
   cout<<"\n                     PROFILE REGISTRATION\n";
    ofstream fik("player.dat",ios::out|ios::binary|ios::app);
    pn.p_reg();
   cout<<"\nPlayer registered";
    fik.write((char*)&pn,sizeof(pn));
    fik.close();
   getch();
  }

 void halloffame()
  {
   kjw
   clrscr();
   cout<<"\t\t\tCAREER HALL OF FAME\n\n\nID\tName\t\t\tCareer Score\t\tMatches Won";
    fstream fir("player.dat",ios::in|ios::out|ios::binary);
   while(!fir.eof())
    {
     fir.read((char*)&p1,sizeof(p1));
     cout<<endl;
      if(fir.eof())
       break;
      p1.scdet();
    }
   fir.close();
   getch();
  }

 void remove_player()
  {
   fstream fid("player.dat",ios::in|ios::out|ios::binary);
   fstream fin("rep.dat",ios::in|ios::out|ios::binary);
    player qid;
     kjw
      clrscr();
      qid=scd();


       if(qid.getid()<0)return;
       if(!yn("Do you want to delete the player? "))
	return;
       while(!fid.eof())
	{
	 fid.read((char*)&p1,sizeof(p1));
	  if(fid.eof())break;
	  if(p1.getid()!=qid.getid())
	 fin.write((char*)&p1,sizeof(p1));
	}
     fin.close();
     fid.close();
   remove("player.dat");
   rename("rep.dat","player.dat");
   cout<<"\n\nPlayer record deleted";
  getch();
 }

 int match_reg()
  {
   int i=0,id,g=0,j;
    fstream fm("match.dat",ios::out|ios::trunc|ios::binary);
     while(1)
      {
       kjw
       clrscr();
	int n,k;
	 cout<<"\t\t\tNEW MATCH REGISTRATION\n";
	 cout<<"\t\t\tID LIST\n";
	 playerlist();
	 cout<<"\nEnter no. of players for participation(Max 9):";
	 cin>>n;
	  if(m1.p_nos()>checkempty()){cout<<"\nNot enough profiles";getch();return 1;}
	  cout<<"\nEnter no. of rounds to be played(Max 15):";
	  cin>>k;
	   m1.put_p_nos(n);
	   m1.put_g_nos(k);
	     if(m1.p_nos()==checkempty())
	      {
	       fstream fe("player.dat",ios::in|ios::out|ios::binary);
	       fm.write((char*)&m1,sizeof(m1));
		while(!fe.eof())
		 {
		  fe.read((char*)&p1,sizeof(p1));
		  fm.write((char*)&p1,sizeof(p1));
		 }
 cout<<"\n\nAll players in file loaded.Press any key to continue.";
 getch();
 return 0;
}

 if((m1.g_nos()<=0 || m1.p_nos()<=0)
  && (sizeof(m1.g_nos())==2 && sizeof(m1.p_nos())==2))
   {
    cout<<"\nNo Null Round Match.";
    getch();
    return 1;
   }

 if((m1.p_nos()>9 || m1.g_nos()>15 || m1.p_nos()>checkempty())
  && (sizeof(m1.g_nos())==2 && sizeof(m1.p_nos())==2))
   {
     cout<<"\nOut of memory or invalid value.Please retry.";
     getch();
     return 1;
   }

  else if(m1.p_nos()<2)
   {
    cout<<"\nNo single player game";
    getch();
    return 1;
   }
  else break;
  }

 int*ea=new int[m1.p_nos()];
  fm.write((char*)&m1,sizeof(m1));
  cout<<"\nEnter (-1) or any character(other than integers) for cancellation";

  while(i<m1.p_nos())
   {
    fstream fp("player.dat",ios::in|ios::out|ios::binary);
    fp.seekg(0);
     g=0;
     cout<<"\nEnter player "<<i+1<<" id to play:";cin>>id;
     ea[i]=id;
     j=0;

 if(!(id>0 && sizeof(id)==2))
  {
    cout<<"Registration cancelled";
    getch();
    delete ea;
    return 1;
  }

   if(i>0)
    while(j<i)
     {
      if(id==ea[j]){g=2;break;}
	j++;
     }

    while(!fp.eof())
     {
      fp.read((char*)&p1,sizeof(p1));
	if(p1.getid()==id && g!=2)
	 {
	  fm.write((char*)&p1,sizeof(p1));g=1;i++;break;
	 }
      }
    if(g==0)
     {
      cout<<"\nPlayer does not exist.Try again.";
     }
    if(g==2)
     {
      cout<<"\nNo repeated ids please";
     }
   fp.close();
  }
  fm.close();
   delete ea;
    if(id>0)
     {
      cout<<"\nAll participating players loaded.Press any key to continue.";
      getch();
     }
   return 0;
  }

 void game(int vol)
  {
   kjw
   clrscr();
   randomize();
    int i=0,k,x,y,p=1,rt=-12,sk=0;
     match m;
     fstream fi("match.dat",ios::in|ios::out|ios::binary);
     fi.read((char*)&m,sizeof(m));
     if(vol)m.put_g_pos(1);
      player*pm=new player[m.p_nos()];
    int j=m.g_pos(),cho;

     while(!fi.eof())
      {
	fi.read((char*)&p1,sizeof(p1));
	 if(fi.eof())break;
	  pm[i]=p1;
	 if(vol)pm[i].nullscore();
	  i++;
      }

      while(j<=m.g_nos())
       {
	kjw
	clrscr();

	sk=0;

	 cout<<"\t********LUCK GAME********";
	 cout<<"\n\n\nROUND "<<j<<"(Press 'P' to pause)\n";
	 cout<<"\nChoices are between 0 to 9:\n";
	   i=0;
	  k=random(10);
	   while(i<m.p_nos())
	    {
	     if(p){cout<<"\n";}
	      x=wherex();y=wherey();
		pm[i].gdata();cout<<" Enter your choice:";

	      if(!(i<rt))
	       {cho=getche();}
	      else
	       {cout<<pm[i].getpcho()<<endl;}

	if((cho<48 || cho>57) && !(cho=='p' || cho=='P'))
	 {
	   cout<<"\nInvalid choice.Enter again.";getch();
	   gotoxy(x,y);

	    for(int z=0;z<4;z++)
	     {cout<<"\t\t\t\t\t\n";}

	      gotoxy(x,y);
		p=0;
		continue;
	 }
	else
	 {p=1;}


	 if(cho=='p' || cho=='P')
	  if(yn("Do you want to close and save game ?"))
	   {
	    fi.close();
	    fstream asdw("match.dat",ios::in|ios::out|ios::binary);
	    asdw.seekg(0);
	    asdw.write((char*)&m,sizeof(m));
	    asdw.close();
	    sk=-1;break;
	   }
	  else
	   {
	    rt=i;
	    sk=1;
	   }
	  if(sk==1){cho='0';break;}
	  if(i==rt){rt=-12;}
	  if(!(i<rt))
	  if(cho>='0' && cho<='9')
	   {
	    pm[i].assigncho(cho-48);
	   }
	  else
	  continue;

	   i++;
	  }
  if(sk==1)continue;
  if(sk==-1)break;
   cout<<"\n\nThe random number was "<<k<<"\n\n";
   i=0;

   while(i<m.p_nos())
    {
     pm[i].equpdate(k);
     i++;
    }
     cout<<"\n\nPress any key to continue";
     getch();
      j++;
       if(m.g_pos()<=m.g_nos())
	{
	 m.incpos();
	}
	fi.close();
	if(m.g_pos()>m.g_nos())
	 {
	  cout<<"\n\nRESULT:\n";
	  rank(pm,m);
	  m.put_g_pos(100);
	  getch();
	 }
  }

  fstream fk("match.dat",ios::in|ios::out|ios::binary);
  fk.write((char*)&m,sizeof(m));
   i=0;
    while(!fk.eof() && i<m.p_nos())
     {
      if(fk.eof())break;
      updatecareer(pm[i]);
      fk.write((char*)&pm[i],sizeof(pm[i]));
      i++;
     }
    delete pm;
     fk.close();
 }

 void rank(player s[],match a)
  {
    int l,k=-1;
    player tag;
    player*max=new player[a.p_nos()];
     tag=s[0];

     for(l=0;l<a.p_nos();l++)
      {
	if(s[l].getscore()>tag.getscore())
	 {tag=s[l];}
      }

     for(l=0;l<a.p_nos();l++)
      {
       if(s[l].getscore()==tag.getscore())
	k++;
      }

     if((a.p_nos()-1)!=k)
      {
	for(l=0,k=-1;l<a.p_nos();l++)
	 {
	  if(s[l].getscore()==tag.getscore())
	  {max[++k]=s[l];s[l].imatch();}
	 }
      }
     else
      {
       if(a.p_nos()!=0)
	{
	 if(a.g_pos()>a.g_nos())
	  {
	   cout<<"\nMATCH TIED";
	  }
	 else
	  {
	   cout<<"\nMATCH UNDERGOING TIED STATE";
	  }
	}

	return;
       }

     for(l=0;l<=k;l++)
      {max[l].dispname(); if(l<k)cout<<","; }

       if(a.g_pos()>a.g_nos())
	{
	 if(k==0)
	 cout<<" has won the game\n";
	 if(k>0)
	 cout<<" have won the game\n";
	}
       else
	{
	 if(k==0)
	 cout<<" is in lead of game(MATCH NOT COMPLETED)\n";
	 if(k>0)
	 cout<<" are in lead of game(MATCH NOT COMPLETED)\n";
	}
      }

 void updatecareer(player k)
  {
   long pos;
   fstream lt("player.dat",ios::in|ios::out|ios::binary);
    while(!lt.eof())
     {
      pos=lt.tellg();
      lt.read((char*)&p1,sizeof(p1));
      if(p1.getid()==k.getid())
       {
	p1.newscore(k.getscore());
	p1.matchn(k.getmatch());
	lt.seekg(pos);
	lt.write((char*)&p1,sizeof(p1));
	 break;
       }
      }
  lt.close();
 }

  void clearrecords()
   {
    fstream l("cr.dat",ios::out|ios::in|ios::app|ios::binary);
    m1.put_g_pos(100);
    m1.put_g_nos(0);
    m1.put_p_nos(0);
    l.write((char*)&m1,sizeof(m1));
    l.close();
     remove("match.dat");
     rename("cr.dat","match.dat");
   }


  player scd()
   {
    fstream fdr("player.dat",ios::in|ios::out|ios::binary);
    fdr.seekg(0);
     int a=checkempty(),i=0;
     char t=0;
      player*am=new player[a];
      player pwq,temp;
       while(!fdr.eof() && i<a)
	{
	 fdr.read((char*)&am[i],sizeof(am[i]));
	 i++;
	}
       fdr.close();
    int tqw=0;

	while(1)
	 {
	  kjw
	  clrscr();
	  cout<<"\n                     DELETE PROFILE";
	  cout<<"\nSELECT PLAYER TO DELETE(USING 'W' UP AND 'S' DOWN AND ENTER TO SELECT)";
	  gotoxy(2,4);cout<<"\nID\tNAME";
	   for(i=0;i<a;i++)
	   {
	    gotoxy(2,(int)((2*(i+1))+6));cout<<am[i].getid()<<"\t";am[i].dispname();
	   }
	    gotoxy(2,(int)((2*(a+1))+6));cout<<"EXIT";
	     if(tqw==a)
	      {
		hrk gotoxy(2,(int)((2*(a+1))+6));cprintf("EXIT");
	      }
	     else
	      {
	      hrk gotoxy(2,(int)((2*(tqw+1))+6));
	      cprintf("%d     %s",am[tqw].getid(),am[tqw].retname());
	      }

	     t=getch();
	       if(t==13 && tqw==a){return temp;}
	       if(t==13 && tqw!=a)
		{if(checkinmatch(am[tqw]))
		 {
		  delete am;
		  return temp;
		 }
		pwq=am[tqw];break;}

		if(t=='w'||t=='W')tqw--;
		if(t=='s'||t=='S')tqw++;
		 if(tqw==a+1)tqw=0;
		 if(tqw==-1)tqw=a;
	}
   delete am;
   return pwq;
  }

	int yn(char d[])
	 {
	  char lr;
	  int q=1;
	   while(1)
	    {
	     kjw
	     clrscr();
	      cout<<"\n"<<d;

		if(q==1)
		 {hrk gotoxy(6,3);cprintf("YES");
		if(lr==13){return 1;}}
		else
		 {kjw gotoxy(6,3);cprintf("YES");}

		if(q==2)
		{hrk gotoxy(50,3);cprintf("NO");
		if(lr==13){return 0;}}
		else
		{kjw gotoxy(50,3);cprintf("NO");}


	      lr=getch();

	if(lr=='a'||lr=='A')q--;
	if(lr=='d'||lr=='D')q++;

	if(q==3)q=1;
	if(q==0)q=2;
   }
  }

 int checkempty()
  {
    fstream fadr("player.dat",ios::in|ios::out|ios::app|ios::binary);
    fadr.seekg(0);
    int ue=-1;
     while(!fadr.eof())
      {
       fadr.read((char*)&p1,sizeof(p1));
       ue++;
      }
       fadr.close();

      return ue;
     }

       void playerlist()
	{
	 fstream bmwr("player.dat",ios::in|ios::out|ios::app|ios::binary);
	 bmwr.seekg(0);
	  while(!bmwr.eof())
	   {
	    bmwr.read((char*)&p1,sizeof(p1));
	    cout<<endl;
	     if(bmwr.eof())break;
	      p1.scid();
	   }
	  bmwr.close();
	 }

 int modifier()
  {
   kjw
   clrscr();
    cout<<"\n                     MODIFY NAME";
    int i=0,idea,a=checkempty(),g=0;long pos;
     cout<<"\n\nEnter ID of player to modify name(-1 to cancel):";cin>>idea;

    fstream plo("player.dat",ios::out|ios::in|ios::binary);
     while(!plo.eof() && i<a)
      {
       pos=plo.tellp();
       plo.read((char*)&p1,sizeof(p1));
	if(p1.getid()==idea)
	 {
	  cout<<"\nEnter new name:";
	  p1.modifyname();
	  g=1;
	  plo.seekp(pos);
	  plo.write((char*)&p1,sizeof(p1));
	 }
	i++;
	}
   if(idea<0)
    {
     cout<<"Modify cancelled";
     return -1;
    }

   if(g==0)
    {
     cout<<"This id does not exists";
     return -1;
    }


    plo.close();
    return 1;
   }

 void search(long id)
  {
   int i=0,a=checkempty(),g=0;

    cout<<"\nSEARCH RESULTS:\n";
    fstream plo("player.dat",ios::out|ios::in|ios::binary);
     while(!plo.eof() && i<a)
      {
       plo.read((char*)&p1,sizeof(p1));
	if(p1.getid()==id)
	 {
	  g=1;
	  p1.searchresults();
	  break;
	 }
	i++;
       }

  if(g==0)
   {
    cout<<"\nThis id does not exists";
   }


   plo.close();
  }

 void search(char name[])
  {
   int i=0,a=checkempty(),g=0;

    cout<<"\nSEARCH RESULTS:\n";
    fstream pnm("player.dat",ios::out|ios::in|ios::binary);
    while(!pnm.eof() && i<a)
     {
      pnm.read((char*)&p1,sizeof(p1));
      if(pnm.eof())break;
       if(strcmpi(p1.retname(),name)==0)
	{
	 g=1;
	 p1.searchresults();
	 cout<<"\n\n";
	}
       i++;
      }

  if(g==0)
   {
    cout<<"\nThis name does not exists";
   }
   pnm.close();
 }

 int checkinmatch(player PCK)
  {
    player DUMMY;
    match m;
     int i=0;
      fstream fl("match.dat",ios::in|ios::binary);
      fl.read((char*)&m,sizeof(m));
       while(!fl.eof() && i<checkempty())
	{
	 fl.read((char*)&DUMMY,sizeof(DUMMY));
	  if(PCK.getid()==DUMMY.getid() && m.g_pos()!=100)
	   {
	    cout<<"\tMESSAGE:Cannot delete playing player.";getch();fl.close();return -1;
	   }
	 }
    fl.close(); return 0;
   }

 void searchmenu()
  {
   cout<<"\n                     SEARCH PLAYER\n";
    int clp=1;char typ;
     while(1)
      {
	kjw
	clrscr();
	 cout<<"MENU OPTIONS(Use 'W' and 'S' to scroll up/down and select EXIT to exit)";
	  if(clp==1)
	   {hrk gotoxy(4,3);cprintf("SEARCH BY ID");
	if(typ==13)
	 {
	  long p;
	  kjw
	  clrscr();
	   cout<<"\t\tSEARCHING BY ID";
	   cout<<"\n========================================================================\n";
	   cout<<"\nEnter player id to seach player(-1 to cancel):";
	   cin>>p;
	    if(p<0)
	     {
	      cout<<"\nSearch Cancelled";
	     }
	    else
	     {
	      search(p);
	     }
	 typ=0;getch();continue;
    }
   }
  else
   {kjw gotoxy(4,3);cprintf("SEARCH BY ID");}

    if(clp==2)
     {hrk gotoxy(4,5);cprintf("SEARCH BY NAME");
    if(typ==13)
     {
      char n[10];
      kjw
       clrscr();
       cout<<"\t\tSEARCHING BY NAME";
       cout<<"\n========================================================================\n";
       cout<<"Enter player name to seach player(Enter '.' to cancel):";
      gets(n);
	if(strcmpi(n,".")==0)
	 {
	   cout<<"\nSearch Cancelled";
	 }
	else
	 {
	  search(n);
	 }
	typ=0;getch();continue;
       }
      }
     else
      {kjw gotoxy(4,5);cprintf("SEARCH BY NAME");}

    if(clp==3)
     {hrk gotoxy(4,7);cprintf("EXIT");
      if(typ==13){cout<<"\n";cout<<"\nPress any key to continue";return;}}
    else
     {kjw gotoxy(4,7);cprintf("EXIT");}

      typ=getch();
       if(typ=='e' || typ=='E')return;
       if(typ=='w'||typ=='W')clp--;
       if(typ=='s'||typ=='S')clp++;

    if(clp==4)clp=1;
    if(clp==0)clp=3;
   }
 }



