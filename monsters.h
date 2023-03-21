#ifndef MONS
#define MONS
#include <iostream>
using namespace std;
struct Monsters{
 string name[12]={"Blubatty","Limeiten","Sorcberry","Papain","Duriable","Kiwitten","Cheridile","Fightful Pear","Apericot","Grapethreat","Manghost","Raspbeing"};
 int health[12]={3,2,8,1,6,4,8,3,5,15,10,5};
 float defense[12]={1,3,4,1,15,4,10,5,4,8,6,14};
 float mdefense[12]={1,4,8,4,8,1,8,7,3,14,7,3};
 int attack[12]={3,4,3,1,4,5,15,3,6,10,7,4};
 int mattack[12]={2,5,8,2,1,3,3,5,4,6,13,5};
 int speed[12]={3,4,6,5,8,2,8,6,3,5,7,2};
 int lf[12]={5,11,6,7,12,8,0,3,2,4,9,10};
 int lootcount[12]={12,3,4,2,2,5,20,5,5,20,3,15};
 int lootvari[12]={9,13,3,2,6,3,9,3,12,11,4,6};
 int expi[12]={6,7,10,3,12,10,17,7,10,18,13,15};
 char char1[12]={'b','l','s','p','d','k','c','f','a','g','m','r'};
 char char2[12]={'B','L','S','P','D','K','C','F','A','G','M','R'};
 char sact[12]= {'f','h','s','s','a','f','d','S','s','S','A','f'};
};
struct Fruit{
 string n[14]={"cherry","apple","apricot","pear","grape","blueberry","strawberry","papaya","kiwi","mango","raspberry","lime","durian","exit"};
 string n2[13]={"cherries","apples","apricots","pears","grapes","blueberries","strawberries","papayas","kiwis","mangoes","raspberries","limes","durians"};
 string none[13]={"To much dismay, it seems you're without a cherry!","Try again when you have an apple!","You go to bite into an apricot only to realize your apricot pocket is empty.","You haven't any pears!","You realize grapes don't even grow on trees and thus you haven't any to use.","You don't have a blueberry, come to think of it, do blueberries even grow on trees?","Strawberries DEFINITLY don't grow on trees, why is this even in the game?","Papaya? You don't have one of those.","Kiwi!? Where? ... oh, no where.","Man, where did your mangoes go?","Sorry, no raspberries here.","You don't have any limes.","You don't have any durians."};
 string uses[13]={"You drop a cherry on the path.","","You eat an apricot. You can sense how far away trees are.","You eat a pear. You can sense the direction of the portal.","A figment of your imagination pops a grape in your mouth. You now know your location.","You eat one plump juicy blueberry.","You bite into a sweet sweet strawberry.","As you're eatting the papaya, you begin to count the seeds, 1, 2, 3, there are so many.","You ate a kiwi, the whole thing too!","You dig into a very juicy mango, now you have juice in your hair.","You eat a soft and delicious raspberry.","Sorry, you can only use limes in battle.","Sorry, you can only use durians in battle."};
 int hp[13]={0,12,7,10,4,2,6,13,5,9,1,0,0};
 int hpv[13]={1,5,3,2,3,2,6,9,5,8,4,1,1};
 int mp[13]={0,0,0,0,1,0,0,17,0,12,0,0,0};
 int mpv[13]={1,1,1,1,4,1,1,10,1,6,1,1,1};
 bool kill[13]={true,false,false,false,true,true,false,false,false,false,true,false,false};
 char path[13]={'c','A','a','p','0','0','s','P','k','M','0','0','0'};
};
struct Monster{
 string name, loot;
 int health=0, attack, speed, lootcount, expi, mattack, id, post, off, lf;
 float defense, mdefense, mult[4]={1.0, 1.0, 1.0, 1.0};
 char char1, char2, M, sact;//active char
 bool newM;
};
struct Fighting{
 Monster enemy[24];
 string text="";
};
Monster getMon(int m,int lvl){
 Monsters get;
 Monster mon;
 mon.name=get.name[m];
 mon.health=(rand()%(get.health[m]+lvl)+(((get.defense[m]+rand()%lvl)- 1)*5))*2;
 mon.attack=rand()%(get.attack[m]+lvl)+(((get.defense[m]+rand()%lvl)- 1)*5);
 mon.speed=get.speed[m];
 mon.lootcount=0;
 mon.expi=get.expi[m]+(rand()%lvl)- 1;
 mon.mattack=rand()%(get.mattack[m]+lvl)+(get.mattack[m]*5);
 mon.id=m;
 mon.off=rand()%get.speed[m];
 mon.lf=get.lf[m];
//mon.defense=(((get.defense[m]+rand()%lvl)- 1)*5)+(rand()%int(get.defense[m]+lvl));
//mon.mdefense=((get.mdefense[m]+(rand()%lvl)- 1)*5)+(rand()%int(get.mdefense[m]+lvl));
 mon.defense=get.defense[m]-((rand()%int(get.defense[m]*20))/100);
 mon.mdefense=get.mdefense[m]-((rand()%int(get.mdefense[m]*20))/100);
 mon.char1=get.char1[m];
 mon.char2=get.char2[m];
 mon.M=mon.char1;
 mon.sact=get.sact[m];
 mon.newM=true;
 return mon;
}
struct Shopping{
 string item[37]={
 "Axe","Wood Axe","Great Axe","Axe of Bounty","Axe of Cunning","Axe of Sharpness",
 "Sword","Great Sword","Quick Blade","Magic Sword","Master's Sword","Magic Quick Blade",
 "Hammer","Strong Hammer","Bounty's Hammer","Magic Hammer","War Hammer","Strange Hammer",
 "Magic Wand","Great Magic Wand","Multi-Purpose Staff","Efficient Wand","Wand of Healing","GOATed Wand",
 "Shield","Magic Shield","Reinforced Shield","Greater Magic Shield","Offensive Shield","Shield of Defense",
 "Mango","Apple","Pear","Blueberry","Strawberry","Kiwi",
 "Fists"};
 int level[36]={
  1,3,5,7,9,11,
  2,3,6,8,10,12,
  1,3,6,7,9,11,
  2,4,5,8,10,12,
  2,4,5,8,10,11,
  1,4,6,7,9,12};
//wood,stone,quartz,iron,gold,apricot=dist,cherry=path,papaya=mp,raspberry=def
 int price[36][9]={
  {50,0,0,0,0,0,0,0,0},{75,10,0,0,0,0,0,0,0},{50,20,0,0,0,0,0,0,0},{200,0,0,0,0,5,5,5,5},{50,15,20,0,5,0,50,0,0},{50,15,0,20,5,0,50,0,0},
  {25,10,0,0,0,0,0,0,0},{30,20,0,0,0,0,0,0,0},{25,25,5,5,0,0,0,0,0},{15,5,15,0,1,10,0,0,0},{20,20,20,20,10,15,0,0,0},{50,50,50,50,50,20,0,0,0},
  {25,0,0,0,0,0,0,0,0},{25,20,0,0,0,0,0,0,0},{10,75,5,0,0,0,0,0,0},{10,45,15,5,0,0,0,0,0},{20,20,5,20,5,0,0,0,0},{0,200,5,5,5,0,0,0,0},
  {20,15,0,0,0,0,0,0,0},{30,25,1,0,0,0,0,0,0},{30,30,3,0,0,0,0,0,0},{20,5,30,0,1,0,0,10,0},{20,0,30,0,5,5,5,5,5},{20,5,30,5,20,0,0,20,0},
  {30,5,0,0,0,0,0,0,0},{35,15,1,0,0,0,0,0,0},{30,30,0,2,0,0,0,0,0},{70,30,15,0,2,0,0,0,10},{20,10,0,20,5,0,0,0,20},{70,20,100,0,30,0,0,0,50},
  {10,0,0,0,0,0,0,0,0},{30,0,0,0,0,0,0,0,0},{20,0,0,0,0,0,0,0,0},{15,0,0,0,0,0,0,0,0},{15,0,0,0,0,0,0,0,0},{0,0,5,0,5,0,0,0,0}};
//attack 0, m attack 1, defense 2, m defense 3;
 float stats[37][4]={
  {1.0,1.0,1.0,1.0},{1.25,1.0,1.0,1.0},{1.5,1.0,1.0,1.0},{1.4,1.0,1.0,1.0},{1.5,1.25,1.0,1.0},{1.75,1.0,1.0,1.0},
  {1.25,0.8,1.0,1.0},{1.5,1.0,1.0,1.0},{1.25,1.0,1.0,1.0},{1.5,1.4,1.0,1.0},{1.75,1.5,0.75,1.0},{1.4,1.4,1.0,1.0},
  {1.125,1.0,0.875,1.0},{1.25,1.0,0.75,1.0},{1.3,1.0,0.7,1.0},{1.125,1.4,0.875,0.75},{1.5,1.25,0.6,1.0},{0.75,1.2,0.75,0.75},
  {0.8,1.25,1.0,1.0},{1.0,1.5,1.0,1.0},{1.25,1.5,1.0,1.0},{1.0,1.6,1.0,1.0},{1.0,1.6,1.0,1.0},{1.0,1.85,1.0,0.75},
  {1.0,1.0,0.75,1.0},{1.0,1.0,1.0,0.75},{1.0,1.0,0.5,1.0},{1.0,1.0,0.875,0.5},{1.25,1.0,0.5,1.0},{1.0,1.0,0.25,0.5},
  {9,0,0,0},{1,0,0,0},{3,0,0,0},{5,0,0,0},{6,0,0,0},{8,0,0,0},
  {1.0,1.0,1.0,1.0}};
 string money[9]={"Wood","Stone","Quartz","Iron","Gold","Apricots","Cherries","Papayas","Raspberries"};
};
struct Resourcs{
 Weapon w[20];
 //int items[30]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 int wood=0;
 int m[4]={0,0,0,0};//stone quartz iron gold
 int f[13]={5,5,5,5,5,5,5,5,5,5,5,5,5};//fruit
 //int f[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
};
Fighting SpecialAttack(Fighting mon,Monster mo,int i,int*intnumb,int*numb,int monplus,int lvl){
 int chance[12]={10,7,8,3,15,3,5,5,3,10,8,5};
 Monsters get;
 int go=rand()%20+chance[i];
 char sact=mo.sact;
 int m,k=*numb;
 if(go>19){
  if(sact=='S'||sact=='s'){
   if((*intnumb<8&&monplus==0)||(*intnumb<24&&monplus==1)){
    for(int j=*intnumb;j>*numb;j--)
     mon.enemy[j+ 1]=mon.enemy[j];
    *intnumb+=1;
    *numb+=1;
    k+=1;
    if(sact=='s'){
     m=3;
     mon.text="The "+mon.enemy[i].name+" summomed a Papain!\n";
    }//summon
    else{
     m=mo.id;
     mon.text="The "+mo.name+" split into two!\n";}//split
    mon.enemy[k]=getMon(m,lvl);
    mon.enemy[k].name+="(s)";
    if(sact=='s'){
     mon.enemy[k].health=(rand()%(get.health[m]/5)+get.health[m])*2;
     mon.enemy[k].post=8;}
    else{
     mon.enemy[k].health=mo.health/2+ 1;
     mon.enemy[i].health=mo.health/2+ 1;
     mon.enemy[k].post=mo.post+ 1;}}}//summon or split
  else if(sact=='f'){
   mon.enemy[i].expi=0;
   if(mon.enemy[k].lootcount>0)
    mon.enemy[k].lootcount=1;
   mon.enemy[i].health=0;
   mon.text="The "+mon.enemy[i].name+" fled the scene!\n";}//flee
  else if(sact=='d'){
   if(mon.enemy[i].defense>mon.enemy[i].mdefense){
    mon.enemy[i].defense-=0.05;
    mon.text="The "+mo.name+" raised it's defense!\n";}
   else{
    mon.enemy[i].mdefense-=0.05;
    mon.text="The "+mo.name+" raised it's magical defense!\n";}}//def+
  else if(sact=='A'){
   mon.enemy[i].mattack+=5;
   mon.text="The "+mo.name+" raised it's magical attack power!\n";}//matk+
  else if(sact=='a'){
   mon.enemy[i].attack+=5;
   mon.text="The "+mo.name+" raised it's attack power!\n";}//atk+
  else if(sact=='h'){
   mon.enemy[i].health+=5;
   mon.text="The "+mo.name+" healed 5 hp!\n";}//heal
  }
 return mon;}
struct Weapon{
 string name;
 float stats[6];//atk,matk,def,mdef,defign,mdefign
 int duribility=0,id=36;};
struct PlayerStats{
 int equip[4]={1,0,0,0};//axe,weapon,hammer,shield
 int hp=150,mp=100,maxhp=150,maxmp=100,attack=15,mattack=5;
 float defense=0.9,mdefense=0.9;//defense; 0 > 1
 int expi=0,level=1,expigoal=15;
 float mult[4]={1.0, 1.0, 1.0, 1.0};//attack 0, m attack 1, defense 2, m defense 3; multipliers
 int monplus=2,monhelp=2,monone=2,single=1;//user settings
 bool alive=true,win=false;
 char effect='n';
 Resourcs inv;
 string text="";};
PlayerStats level(PlayerStats p){
 p.text="";
 while(p.expi>=p.expigoal){
  p.level++;
  p.expigoal=p.expigoal*2;
  cout<<"You leveled up to level "<<p.level<<"!!!\n";
  p.text+="You leveled up to level "+to_string(p.level)+"!!!\n";
  p.maxhp+=10;
  p.maxmp+=10;
  p.attack+=5;
  p.mattack+=5;
  p.defense-=0.05;
  if(p.defense<=0)
   p.defense=0;
  p.mdefense-=0.05;
  if(p.mdefense<=0)
   p.mdefense=0;}
 return p;}
char moncolor(char p){
 if(p=='b'||p=='B')
  printf("\033[0;36m");//cyan blue
 else if(p=='l'||p=='L'||p =='k'||p=='K'||p=='f'||p=='F')
  printf("\033[1;32m");//lime
 else if(p=='s'||p=='S'||p=='c'||p=='C')
  printf("\033[1;31m");//cherry red
 else if(p =='p'||p=='P'||p=='a'||p=='A')
  printf("\033[0;33m");//orange
 else if(p=='d'||p=='D')
  printf("\033[0;32m");//green
 else if(p=='g'||p=='G')
	 printf("\033[0;35m");//purple
 else if(p=='r'||p=='R')
  printf("\033[1;35m");//light purple/pink
 else if(p =='m'||p=='M')
  printf("\033[1;33m");//yellow
 return p;}
char color(char p){
 if (p=='c'||p=='s')
  printf("\033[1;31m");//cherry red
 else if (p=='X')
  printf("\033[0;32m");//green 
 else if (p=='?'||p==' ')
  printf("\033[1;37m");//white
 else if (p=='a'||p=='*'||p=='P')
  printf("\033[0;33m");//orange
 else if (p=='O'||p=='#')
  printf("\033[1;35m");//light purple/pink
 else if (p=='p'||p=='k'||p=='<'||p=='>'||p=='{'||p=='}'||p=='x'||p=='m')
  printf("\033[1;32m");//lime
 else if (p=='A'||p=='M')
  printf("\033[1;33m");//yellow
 else if (p=='|'||p=='_'||p=='\\'||p=='/')
  printf("\033[1;30m");//grey
 else if (p=='o')
	 printf("\033[0;37m");//light grey
 else
  printf("\033[1;34m");//light blue
/*printf("\033[0;30m");//black
printf("\033[0;31m");//red
printf("\033[0;35m");//purple
printf("\033[0;34m");//blue
printf("\033[0;36m");//cyan blue
printf("\033[1;36m");//cyan*/
 return p;
}
PlayerStats battle(PlayerStats p1,Fighting mon,int numb){
//First, initilize values
/* string text,killed="",weapon="fists";
 Fruit f;
 int moveaim,aim,post,move,position,damage,count=0,atck,addin,mult,ponum,first=0,axe=0,x;
 int intnumb=numb;
 Shopping items;
 if(p1.inv.items[p1.equip[1]]>0){
  axe=0.25;
  weapon=items.item[p1.equip[1]];}
 char grid[24]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},hurt[6],attack,sword,M,h1='>',h2='<',v1='{',v2='}',dn='x',prev;
 char character[23]={'q','w','e','d','c','x','z','a','Q',' ','W',' ','E',' ','D',' ','C',' ','X',' ','Z',' ','A'};
 int multcount[4]={0,0,0,0};// how many more turns you get the upgrade
 bool direct[4]={false,false,false,false};//this is for keeping directionally special attacks
 float temp[4]={1.0,1.0,1.0,1.0}, tempsingle[4]={1.0,1.0,1.0,1.0};
//{attack, m attack, defense, m defense}
 bool dodge=false, upper, monattack, flee=false, amove=false, happy;
//Then find where each monster starts
 int posts=8;
 if(p1.monplus==1)
  posts=24;
 for(int i=0;i<=numb;i++){
  mon.enemy[i].M=mon.enemy[i].char1;
  happy=false;
  while(happy==false){
   position=rand()%posts;
   if(grid[position]==' ')
    happy=true;}
  mon.enemy[i].post=position;
  grid[position]=mon.enemy[i].M;}
 bool danger=false;
 int dPost;
//loop until battle done
 while(numb>=0&&killed==""){
//capital status
  danger=false;
  for(int i=0;i<=numb;i++){
   if(((count+mon.enemy[i].off)%(mon.enemy[i].speed)==0)&&(count>0)){
    mon.enemy[i].M=mon.enemy[i].char2;
    danger=true;}
   else
    mon.enemy[i].M=mon.enemy[i].char1;}
  if(danger==false)
   dPost=30;
//move mons
  for(int i=0;i<=numb;i++){
   int before=mon.enemy[i].post;
   if(mon.enemy[i].health>0){
    if(amove==true){//whistle
     if((before<8&&moveaim==9||before>7&&moveaim==8)){
      if(p1.monplus==1)
       move=2;
      else
       move=0;}//distance
     else if(before>7&&moveaim==9||before<8&&moveaim==8)
      move=0;
     else if(moveaim<8){
      if(before+ 4==moveaim||(before<8&&before- 4==moveaim)||before==(2*moveaim)+ 16||(moveaim>3&&before==moveaim*2)){
       move=((rand()%2));
       if(move==0)
        move=-1;}//monster behind 
      else if(before==moveaim||before==(2*moveaim)+ 8)
       move=0;//monster front
      else if((moveaim<4&&(before>(2*moveaim)+ 8&&before<(2*moveaim)+ 16))||(moveaim>3&&(before>(2*moveaim)+ 8||before<2*moveaim)))
       move=-1;//counter clockwise
      else if((moveaim<4&&(before<(2*moveaim)+ 8||before>(2*moveaim)+ 16))||(moveaim>3&&(before<(2*moveaim)+ 8&&before>2*moveaim)))
       move=1;//clockwise
      }}
    else if(p1.monplus==1)
     move=((rand()%4)- 1);
    else
     move=((rand()%3)- 1);
    if(move==2){
     if((before>7&&before%2==0)&&grid[(before- 8)/2]==' '){
      mon.enemy[i].post=(before- 8)/2;
      grid[mon.enemy[i].post]=mon.enemy[i].M;}
     else if(before>7&&grid[(before- 9)/2]==' '){
      mon.enemy[i].post=(before- 9)/2;
      grid[mon.enemy[i].post]=mon.enemy[i].M;}
     else if(before<8&&grid[(before*2)+ 8]==' '){
      mon.enemy[i].post=(before*2)+ 8;
      grid[mon.enemy[i].post]=mon.enemy[i].M;}
     else if(mon.enemy[i].newM==true&&grid[before]!=' '){
      mon.enemy[i].post=0;
      while(grid[mon.enemy[i].post]!=' ')
       mon.enemy[i].post++;
      grid[mon.enemy[i].post]=mon.enemy[i].M;}
     else 
      grid[mon.enemy[i].post]=mon.enemy[i].M;
     if(mon.enemy[i].newM==false&&mon.enemy[i].post!=before)
      grid[before]=' ';}
    else{
     position=before+move;
     if(position<0)
      position=7;
     else if(position>23)
      position=8;
     else if(position==8&&move==1)
      position=0;
     else if(position==7&&move==-1)
      position=23;
     if(mon.enemy[i].newM==true){
      if(grid[position]!=' ')
       position=0;
      while(grid[position]!=' ')
       position++;
      mon.enemy[i].post=position;
      grid[position]=mon.enemy[i].M;}
     else if(grid[position]==' '){
      grid[mon.enemy[i].post]=' ';
      mon.enemy[i].post=position;
      grid[mon.enemy[i].post]=mon.enemy[i].M;}
     else
      grid[before]=mon.enemy[i].M;}}
   if(danger==true&&mon.enemy[i].M==mon.enemy[i].char2)
    dPost=mon.enemy[i].post;
   mon.enemy[i].newM=false;
   }
  amove=false;
  std::cout<< u8"\033[2J\033[1;1H";
  if(p1.monplus==1)//^< 8, 0, count clockwise to 23, 7
   cout<<color(h2)<<color(h1)<<color(h2)<<color(dn)<<color(h1)<<color(h2)<<color(h1)<<endl<<color(v1)<<moncolor(grid[8])<<moncolor(grid[9])<<moncolor(grid[10])<<moncolor(grid[11])<<moncolor(grid[12])<<color(v2)<<endl<<color(v2)<<moncolor(grid[23])<<moncolor(grid[0])<<moncolor(grid[1])<<moncolor(grid[2])<<moncolor(grid[13])<<color(v1)<<endl<<color(v1)<<moncolor(grid[22])<<moncolor(grid[7])<<color('#')<<moncolor(grid[3])<<moncolor(grid[14])<<color(v2)<<endl<<color(v2)<<moncolor(grid[21])<<moncolor(grid[6])<<moncolor(grid[5])<<moncolor(grid[4])<<moncolor(grid[15])<<color(v1)<<endl<<color(v1)<<moncolor(grid[20])<<moncolor(grid[19])<<moncolor(grid[18])<<moncolor(grid[17])<<moncolor(grid[16])<<color(v2)<<endl<<color(h2)<<color(h1)<<color(h2)<<color(dn)<<color(h1)<<color(h2)<<color(h1)<<endl;
  else
   cout<<color(h2)<<color(h2)<<color(dn)<<color(h1)<<color(h1)<<endl<<color(v2)<<moncolor(grid[0])<<moncolor(grid[1])<<moncolor(grid[2])<<color(v1)<<endl<<color(v1)<<moncolor(grid[7])<<color('#')<<moncolor(grid[3])<<color(v2)<<endl<<color(v2)<<moncolor(grid[6])<<moncolor(grid[5])<<moncolor(grid[4])<<color(v1)<<endl<<color(h2)<<color(h2)<<color(dn)<<color(h1)<<color(h1)<<endl;
  printf("\033[0m");//clear color
  cout<<text<<mon.text;
  text="";
  mon.text="";
  cout<<"You: "<<p1.hp<<endl;
//printing enemy health
  for(int j=0;j<=numb;j++){
   cout<<mon.enemy[j].name<<": "<<mon.enemy[j].health<<"   ";
   if(j%2==1||(j==numb&&j%2==0))
    cout<<endl;}
  if(p1.monhelp==0)
   cout<<"Enter your action type letter: ";
  else if(p1.monhelp==1){
   if(p1.inv.f.inv[12]>0)
    cout<<"You have a durian, you can use it with Q.\n";
   if(p1.inv.f.inv[11]>0)
    cout<<"You have a lime, you can use it with q.\n";
   if(p1.hp<20&&p1.mp>=5)
    cout<<"Your hp is low! You can press E to use magic or e to eat fruit: ";
   else if(p1.hp<20){
    cout<<"Your hp is low! Use e to eat fruit: ";}
   else if(amove==true&&p1.single!=1)
    cout<<"Capitalize for a magic attack\nThe enemies have are gathered, use W or w to attack multiple: ";
   else if(danger==false&&p1.mp>=15){
    cout<<"Tip You can use 'a' to contol what direction the monsters move in next.\nZ is an offensive move while z is a defensive move.\n";
    cout<<"No enemy is attacking, you can use z, or Z to improve stats: ";}
   else if(danger==false)
    cout<<"No enemy is attacking, you can use A to improve stats: ";
   else{
    if(p1.hp>95&&(dPost%2==0||dPost<8)){
     cout<<"The S attack will cause you to take 15 points of damage, but is a stronger attack than s.\n";
     cout<<"An enemy is about to attack! Deal a strong blow to them with S: ";}
    else if(p1.hp<40||(dPost%2==1&&dPost>7)){
     cout<<"D defends against magic attacks while d defends against physical attacks.\n";
     cout<<"An enemy is about to attack! Protect yourself with D or d: ";}
    else if(p1.mp>75&&(dPost%2==0||dPost<8)){
     cout<<"X is a stonger magic attack, but uses more magic power.\n";
     cout<<"An enemy is about to attack! Attack back with magic by using X or x: ";}
    else if(dPost%2==0||dPost<8)
     cout<<"An enemy is about to attack! Prepare your attack with s: ";}}//help prompts
  cin>>sword;
  if(p1.monhelp==0)
   cout<<"Enter the direction of your action attack: ";
  else if(p1.monhelp==1){
   if(sword=='w'||sword=='W'){
    cout<<"Directional multi attacks are stronger and can hit up to ";
    if(p1.monplus=1)
     cout<<"6 enemies!\nEnter S to attack outer monsters, s for inner mosters or a specify a direction: ";
    else
     cout<<"3 enemies!\nEnter s to attack all monsters, or specify a direction: ";}
   else if(sword=='a'){
    if(p1.monplus=1)
     cout<<"Enter s to draw enemies closer, S to send them back, or a direction to draw their attention: ";
    else
     cout<<"Enter a direction to whistle in, the monsters will move in that direction: ";}
   else if(sword=='A'){
    cout<<"Use capitals to increase your magic attacks, or lower case to increase your physical attacks. This is temporary.\n";
    cout<<"Entering a direction will increased your attack a lot, but only if your next action takes that same direction.\n";
    cout<<"Enter s/S to increase your attack power a little, or a direction to raise it a lot: ";}
   else if(sword=='E'){
    if(p1.mp>=20)
     cout<<"You can use S to heal 40 hp";
    else
     cout<<"You can use s to heal 15 hp";
    if(danger==true)
     cout<<"!\nOr steal some hp, just ";
    else
     cout<<": ";}
   else if(sword=='e'){
    for(int i=1;i<11;i++){
     cout<<p1.inv.n[i]<<"("<<(char)(65+i)<<"): "<<p1.inv.f.inv[i];
     if(i!=10)
      cout<<", ";
     else
      cout<<"/n";
    }
    cout<<"Use the same letter as you normally would to select a fruit to eat.\nCapitilize it to eat as many as you can manage, or don't to defend yourself as you eat just one: ";}
   else if(sword=='D'||sword=='d'){
    if(p1.single!=0)
     cout<<"Enter s to defend against closer monsters of S for further monsters.\n";
    else
     cout<<"You can enter s to defend yourself from all sides.\nBUT ";
    cout<<"A perfectly aimed defense will fully protect you from that monster's attack, so ";}
   else if(sword=='Z'||sword=='z'){
    cout<<"Capital inputs affect magic stats, while lowercase inputs affect physical stats.\n";
    if(sword=='Z')
     cout<<"Use s/S to improve your attack power OR use a direction to weaken your enemie's defense: ";
    else
     cout<<"Use capital S to increase your defense OR use a direction to weaken your enemie's attack: ";}
   else if(sword=='Q')
    cout<<"Eat the durian with s, or cut it with S or to chuck it right at an enemy, ";
   else if(sword=='q')
    cout<<"Capititalize your aim to cause status efects or don't to just throw the lime.\nEat the lime with s or use it against your enemy, ";
   if(sword=='s'||sword=='S'||sword=='x'||sword=='X'||(sword=='E'&&danger==true)||sword=='Q'||sword=='q'||sword=='d'||sword=='D'){
    if(danger==true)
     cout<<"Aim at the attacking monster with "<<character[dPost]<<": ";
    if(danger==false){
     if(p1.monplus==0||sword=='q')
      cout<<"Aim at a monster by using q,w,e,d,c,x,z, or a: ";
     else
      cout<<"Aim at a monster by using q,w,e,d,c,x,z, or a, Capitilize it for further monsters: ";}}}//help prompts
  cin>>attack;
//Set hurt array
  if(attack=='q'||attack=='Q'||attack=='w'||attack=='W'||attack=='E'||attack=='e'||attack=='d'||attack=='D'||attack=='c'||attack=='C'||attack=='x'||attack=='X'||attack=='z'||attack=='Z'||attack=='a'||attack=='A'){
   if(attack=='q'||attack=='w'||attack=='e'||attack=='d'||attack=='c'||attack=='x'||attack=='z'||attack=='a')
    upper=false;
   else
    upper=true;
   if(attack=='w'||attack=='W')
    ponum=0;
   else if(attack=='e'||attack=='E')
    ponum=1;
   else if(attack=='d'||attack=='D')
    ponum=2;
   else if(attack=='c'||attack=='C')
    ponum=3;
   else if(attack=='x'||attack=='X')
    ponum=4;
   else if(attack=='z'||attack=='Z')
    ponum=5;
   else if(attack=='a'||attack=='A')
    ponum=6;
   else if(attack=='q'||attack=='Q')
    ponum=7;
//weird numbers
//calculate who would get hurt in multiattack.
   addin=0;
   mult=1;
   for(int j=0;j<6;j++){
    if(j==3){
     addin=9;
     mult=2;}
    hurt[j]=(ponum*mult)+addin;
    if(hurt[j]>23)
     hurt[j]=hurt[j]- 16;
    if(j<3&&hurt[j]>7)
     hurt[j]=hurt[j]- 8;
    addin+=1;}//hurt[]
  }
  else{
   for(int j=0;j<6;j++)
    hurt[j]=30;}//clear hurt[]
  for(int l=0;l<4;l++){
   if(direct[l]==true){//if directional
    if(tolower(attack)==tolower(prev)){}
    else{
     temp[l]=0;//back to 0
     direct[l]=false;//directional off
     multcount[l]=0;}}
   if(multcount[l]==0&&temp[l]!=0)
    temp[l]==0;
   if(multcount[l]>0)
     multcount[l]--;}//checking the multi boost loop
//loop through monsters, calculate much
  for(int i=0;i<=numb;i++){
   if(mon.enemy[i].health>0){
    position=mon.enemy[i].post;
    dodge=false;
    monattack=true;
//Aim type
    if((attack=='q'&&position==0)||(attack=='w'&&position==1)||(attack=='e'&&position==2)||(attack=='d'&&position==3)||(attack=='c'&&position==4)||(attack=='x'&&position==5)||(attack=='z'&&position==6)||(attack=='a'&&position==7))
     aim=0;//correct aim; near
    else if((attack=='Q'&&position==8)||(attack=='W'&&position==10)||(attack=='E'&&position==12)||(attack=='D'&&position==14)||(attack=='C'&&position==16)||(attack=='X'&&position==18)||(attack=='Z'&&position==20)||(attack=='A'&&position==22))
     aim=1;//aim correct; far
    else if((ponum==7&&(position==0||position==8))||(ponum==0&&(position==1||position==10))||(ponum==1&&(position==2||position==12))||(ponum==2&&(position==3||position==14))||(ponum==3&&(position==4||position==16))||(ponum==4&&(position==5||position==18))||(ponum==5&&(position==6||position==20))||(ponum==6&&(position==7||position==22)))
     aim=2;//aim correct
    else if((ponum==7&&(position==4||position==16))||(ponum==0&&(position==5||position==18))||(ponum==1&&(position==6||position==20))||(ponum==2&&(position==7||position==22))||(ponum==3&&(position==0||position==8))||(ponum==4&&(position==1||position==10))||(ponum==5&&(position==2||position==12))||(ponum==6&&(position==3||position==14)))
     aim=3;//aim away
    else if(attack=='s')
     aim=4;
    else if(attack=='S')
     aim=5;
    else
     aim=6;//bad aim
//monster near
    if(position<8)
      post='0';//mon near attackable
    else if(position%2==0)
     post='1';//mon far attackable
    else//mon unattackable
     post='2';
    if(i==0){
     happy=true;
     if(sword=='X'&&p1.mp>=15){
      text+="You cast a powerful magic attack.\n";
      p1.mp-=15;}
     else if(sword=='X'){
      text+="You need 15 mp to cast this spell.\n";
      happy=false;}
     else if(sword=='x'&&p1.mp>=5){
      text+="You cast a magic attack.\n";
      p1.mp-=5;}
     else if(sword=='x'){
      text+="You need 5 mp to cast this spell.\n";
      happy=false;}
     else if(sword=='S'){
      text+="This is going to hurt, but that's the cost of such a strong attack.\n";
      p1.hp-=15;
      if(p1.hp<=0)
       killed="yourself";}
     else if(sword=='W'&&p1.mp>=15)
      p1.mp-=15;
     else if(sword=='W'){
      text+="You need 15 mp to cast this spell.\n";
      happy=false;}
     else if(sword=='q'&&p1.inv.f.inv[11]>=1)
      p1.inv.f.inv[11]--;
     else if(sword=='q'){
      text+="You don't have any limes.\n";
      happy=false;}
     else if(sword=='Q'&&p1.inv.f.inv[12]>=1)
      p1.inv.f.inv[12]-=1;
     else if(sword=='Q'){
      text+="You don't have any durians.\n";
      happy=false;}
     else if((sword=='z'||sword=='Z')&&hurt[0]!=30&&p1.mp>=15)
      p1.mp-=15;
     else if((sword=='z'||sword=='Z')&&hurt[0]!=30){
      text+="You need 15 mp to cast this spell!\n";
      happy=false;}}//pay price x1
    if((sword=='a'||sword=='A')&&i==0){
     if(attack=='s'){
      if(sword=='a'){
       text+="You whistle, drawing enemies closer to you.\n";
       amove=true;
       moveaim=8;}//draw enemies in a + s
      else{
       temp[0]+=1.25;
       if(multcount[0]==0)
       multcount[0]=1;
       else
        multcount[0]+=2;
        text+="You focus your energy into planning a stronger attack.\n";}//skip turn=increase atk. A + s
       }
     else if(attack=='S'){
      if(sword=='a'){
       text+="You whistle, it causes enemies to take a step back.\n";
       amove=true;
       moveaim=9;}//push enemies out a + S
      else{
       text+="You meditate to increase your magical attack power.\n";
       temp[1]+=1.25;
       if(multcount[1]==0)
        multcount[1]=1;
       else
        multcount[1]+=2;}//skip turn=increase magic atk. A + S
      }
     else if(upper==true&&sword=='A'){
      text+="You focus your energy in the desired direction, this next magic attack will be powerful.\n";
      temp[1]+=2;
      if(multcount[1]==0)
       multcount[1]=1;
      else
       multcount[1]+=2;
      direct[1]=true;
      prev=attack;}// skip turn=powerful directional mgc atk A + CAP
     else if(hurt[0]!=30){
      if(sword=='a'){
       text+="You whistle, it causes the enemies to gather infront of you.\n";
       amove=true;
       if(attack=='q'||attack=='Q')
        moveaim=0;
       else
        moveaim=ponum+ 1;}//aim the direction for enemies to move a + dirc
      else{
       text+="You focus your "+weapon+" in the direction, the next attack will be powerful.\n";
       temp[0]+=2;
       if(multcount[0]==0)
        multcount[0]=1;
       else
        multcount[0]+=2;
       direct[0]=true;
       prev=attack;}// skip turn=powerful directional weapon atk A + low
      }}//bide(A) and whistle(a)
    else if((sword=='s'||sword=='S')&&aim<3){
     if(sword=='S')
      tempsingle[0]=2.0;// get a 2.0 attack multiplier for S
     if(aim==2){
      text+="You swing your "+weapon+" at the "+mon.enemy[i].name+", it strikes, but you could have aimed better.\n";
      tempsingle[0]=tempsingle[0]*0.75;
      tempsingle[2]=0.25;
      tempsingle[3]=0.5;}// 3/4 attack mult if aim is wrong distance s
     else{
      text+="You skillfully swing your "+weapon+" at the "+mon.enemy[i].name+".\n";
      tempsingle[2]=0.125;
      tempsingle[3]=0.25;}//normal attack if aim is right s
//atk = atk 100% to 120% * multipliers
     atck=(p1.attack+(rand()%(p1.attack/5)))*(p1.mult[0]+axe)*temp[0]*tempsingle[0];
//dmg=atk*(enemy def+sharp)
     damage=atck*(((mon.enemy[i].defense*mon.enemy[i].mult[1]))+p1.sharp);
     mon.enemy[i].health-=damage;
     tempsingle[0]=1;}//sword atk(s) -hp sword atk(S)
    else if(sword=='d'||sword=='D'){
     if(sword=='d'){
      if(aim<2){
       tempsingle[2]=0;
       if(mon.enemy[i].M==mon.enemy[i].char2&&mon.enemy[i].mattack*mon.enemy[i].mult[1]<=mon.enemy[i].attack*mon.enemy[i].mult[0])
        text+="You deflect the "+mon.enemy[i].name+"'s attack perfectly.\n";}// perfect aim = 0 dmg
      else if(aim==2)
       tempsingle[2]=0.2;// aim dist wrong = .2 dmg
      else if(aim==3){
       tempsingle[2]=((rand()%3));
       if(tempsingle[2]==2)
        tempsingle[2]==0.5;
        else if(tempsingle[2]==1){}
        else if(mon.enemy[i].M==mon.enemy[i].char2&&mon.enemy[i].mattack*mon.enemy[i].mult[1]<=mon.enemy[i].attack*mon.enemy[i].mult[0])
          text+="You dodged the "+mon.enemy[i].name+"'s attack.\n";}// aim to run=0 dmg OR .5 damage OR normal
      else if(aim==4){
       if(mon.enemy[i].post<8)
        tempsingle[2]=0.3;}// aim inner?=.3 damage d+s
      else if(aim==5){
       if(mon.enemy[i].post>7)
        tempsingle[2]=0.3;}// aim outer?=.3 damage d+S
      else if(post==2){
       for(int j=0;j<6;j++){
        if(mon.enemy[i].post==hurt[j])
         tempsingle[2]=0.35;}}// undefendable monster 0.35 in hurt[]
      else{
       for(int j=0;j<6;j++){
        if(mon.enemy[i].post==hurt[j])
         tempsingle[2]=0.4;}}// use hurt[6]=.4 damage
      }//phy def d
     else{
      if(aim<2){
       tempsingle[3]=0;
       if(mon.enemy[i].M==mon.enemy[i].char2&&mon.enemy[i].mattack*mon.enemy[i].mult[1]>mon.enemy[i].attack*mon.enemy[i].mult[0])
        text+="You perfectly deflect the "+mon.enemy[i].name+"'s magical attack.\n";}// perfect aim = 0 dmg
      else if(aim==2)
       tempsingle[3]=0.2;//aim dist wrong=.2 dmg
      else if(aim==3){
       tempsingle[3]=(rand()%3);
       if(tempsingle[3]==2)
        tempsingle[3]==0.5;
       else if(tempsingle[2]==1){}
       else if(mon.enemy[i].M==mon.enemy[i].char2&&mon.enemy[i].mattack*mon.enemy[i].mult[1]>mon.enemy[i].attack*mon.enemy[i].mult[0])
        text+="You dodged the "+mon.enemy[i].name+"'s magic attack.\n";}// aim to run=0 dmg OR .5 dmg OR normal
      else if(aim==4)
       if(mon.enemy[i].post<8)
        tempsingle[3]=0.3;// aim inner? = .3 damage D + s
      else if(aim==5)
       if(mon.enemy[i].post>7)
        tempsingle[3]=0.3;//aim outer? = .3 damage D + S
      else if(post==2)
       for(int j=0;j<6;j++)
        if(mon.enemy[i].post==hurt[j])
         tempsingle[3]=0.35;//undefendable monster 0.35 in hurt[]
      else
       for(int j=0;j<6;j++)
        if(mon.enemy[i].post==hurt[j])
         tempsingle[3]=0.4;//use hurt[6] = .4 damage
      }//mgc def D
    }//defend attack(d) defend magic(D)
    else if(sword=='z'||sword=='Z'){
     if(aim<3&&upper==true&&happy==true){
      if(sword=='z'){
       if(mon.enemy[i].mult[0]>0.2)
        mon.enemy[i].mult[0]-=0.2;
       text+="You cast magic causing the "+mon.enemy[i].name+"'s attack power to weaken.\n";}//decrease enemy attack z + AIM
      else{
       mon.enemy[i].mult[2]+=0.2;
       text+="You cast magic causing the "+mon.enemy[i].name+"'s defense to weaken\n";}//decrease enemy defense Z + AIM
     }
     else if(aim<3&&upper==false&&happy==true){
      if(sword=='z'){
       if(mon.enemy[i].mult[1]>0.2)
        mon.enemy[i].mult[1]-=0.2;
       text+="You cast magic causing the "+mon.enemy[i].name+"'s magical attack power to weaken.\n";}//decrease enemy mattack z + aim
      else{
       mon.enemy[i].mult[3]+=0.2;
       text+="You cast magic causing the "+mon.enemy[i].name+"'s magical defense to weaken\n";}//decrease enemy mdefense Z + aim
     }
     else if(attack=='s'&&i==0){
      if(sword=='z'){
       if(p1.mp>8){
        for(int l=0;l<4;l++){
         if(l<2){
          if(temp[l]<1.0)
           temp[l]=1.0;}
         else{
          if(temp[l]>1.0)
           temp[l]=1.0;}}
        p1.mp-=8;
        text+="You use magic to return your offence and defense to normal.\n";}
       else
        text+="You don't have enough magic to cure your ailments.\n";}//heal status ailments z + s
      else{
       if(p1.mp>=15){
        temp[0]+=0.5;
        multcount[0]+=3;
        p1.mp-=15;
        text+="You cast magic raising your attack power.\n";}
       else
        text+="You need 15 mp to raise your attack.\n";}//raise attack Z + s
     }
     else if(attack=='S'&&i==0){
      if(sword=='z'){
       if(p1.mp>10){
        if(temp[2]>=0.2)
         temp[2]-=0.2;
        else
         temp[2]==0;
        if(temp[3]>=0.2)
         temp[3]-=0.2;
        else
         temp[3]==0;
        multcount[2]+=3;
        multcount[3]+=3;
        p1.mp-=10;
        text+="You cast protection to raise your magical and physical defense\n";}
       else
        text+="You need 10 mp to cast protection.\n";}//raise defenses z + S
      else{
       if(p1.mp>=15){
        temp[1]+=0.5;
        multcount[1]+=3;
        p1.mp-=15;
        text+="You cast magic raising your magic attack power.\n";}
       else
        text+="You need 15 mp to raise your magic attack.\n";}//raise magic attack Z + S
      }}//status effects
    else if((sword=='x'||sword=='X')&&aim<3){
     if(sword=='X')
      tempsingle[1]=2.0;// get a 2x magic attack multiplier for X
     if(aim==2){
      text+="Your magic attack hits the "+mon.enemy[i].name+", but you could have cast more accurately.\n";
      tempsingle[1]=tempsingle[1]*0.5;
      tempsingle[3]=0.25;
      tempsingle[2]=0.5;}// half attack multiplier if aim is wrong distance x
     else{
      text+="You skillfully attack the "+mon.enemy[i].name+" with magic.\n";
      tempsingle[3]=0.125;
      tempsingle[2]=0.25;}//normal attack if aim is right s
//attack = attack 100% - 120% * multipliers
     atck=(p1.mattack+(rand()%(p1.mattack/5)))*(p1.mult[1]+axe)*temp[1]*tempsingle[1];
     damage=atck*(((mon.enemy[i].mdefense*mon.enemy[i].mult[3]))+p1.cunning);
     mon.enemy[i].health=mon.enemy[i].health-damage;
     tempsingle[1]=1;}//magic attack
    else if((sword=='q'||sword=='Q')&&happy==true){
     if(sword=='Q'){
      if(aim<2){
       mon.enemy[i].health-=40;
       text+="You chuck a durian at the "+mon.enemy[i].name+".\n";
       monattack=false;}
      else if(attack=='s'&&i==0){
       p1.hp-=5;
       p1.mult[0]+=0.2;
       if(p1.mult[2]>0.05)
        p1.mult[2]-=0.05;
       text+="You take a HUGE bite out of a stinky Durian. Your natural attack and defense increase.\n";}
      else if(attack=='S'&&i==0){
       for(int l=0;l<=numb;l++){
        if(mon.enemy[l].health>0&&mon.enemy[l].post<8){
         mon.enemy[l].speed+=2;
         mon.enemy[l].attack-=15;
         mon.enemy[l].defense+=0.25;
         mon.enemy[l].mattack-=15;
         mon.enemy[l].mdefense+=0.25;
         if(mon.enemy[l].mattack<0)
          mon.enemy[l].mattack=0;
         if(mon.enemy[l].attack<0)
          mon.enemy[l].attack=0;}
        else if(mon.enemy[l].health>0&&mon.enemy[l].post>7){
         mon.enemy[l].speed+=1;
         mon.enemy[l].attack-=10;
         mon.enemy[l].defense+=0.15;
         mon.enemy[l].mattack-=10;
         mon.enemy[l].mdefense+=0.15;
         if(mon.enemy[l].mattack<0)
          mon.enemy[l].mattack=0;
         if(mon.enemy[l].attack<0)
          mon.enemy[l].attack=0;}}
       text+="You cut into the Durian causing ailments to your foes.\n";}}//durian
     else{
      if(aim<3&&upper==true){
       mon.enemy[i].defense+=0.2;
       mon.enemy[i].attack-=15;
       mon.enemy[i].speed+=3;
       if(mon.enemy[i].attack<0)
        mon.enemy[i].attack=0;
       text+="You squirt the lime into the eyes of the "+mon.enemy[i].name+".\n";}
      else if(aim<3&&upper==false&&(grid[(mon.enemy[i].post- 8)/2]==' '||mon.enemy[i].post<8)){
       mon.enemy[i].health-=20;
       attack=false;
       text+="You chuck the lime at the "+mon.enemy[i].name+".\n";}
      else if(attack=='s'&&i==0){
       p1.mp-=5;
       if(p1.mp<0)
        p1.mp=0;
       p1.mult[1]+=0.2;
       if(p1.mult[3]>=0.05)
        p1.mult[3]-=0.05;
       text+="You brace the sour and devour the lime. You're now more magically advanced.\n";}}//lime
    }//durian and lime
    else if((sword=='W'||sword=='w')&&happy==true){
     if(hurt[0]!=30){
      for(int l=0;l<6;l++){
       if(mon.enemy[i].post==hurt[l]){
        if(sword=='w'){
         atck=(p1.attack+(rand()%(p1.attack/5)))*(p1.mult[0]+axe)*temp[0]*0.4;
         damage=atck*(((mon.enemy[i].defense*mon.enemy[i].mult[2]))+p1.sharp);
         mon.enemy[i].health-=damage;
         tempsingle[2]=0.5;}//multi attack directional
        else{
         atck=(p1.mattack+(rand()%(p1.mattack/5)))*(p1.mult[1])+axe*temp[1]*0.4;
         damage=atck*(((mon.enemy[i].mdefense*mon.enemy[i].mult[3]))+p1.cunning);
         mon.enemy[i].health-=damage;
         tempsingle[3]=0.5;}//multi magic attack directional
        }}}
     else if(attack=='s'){
      if(mon.enemy[i].post < 8){
       if(sword=='w'){
        atck=(p1.attack+(rand()%(p1.attack/5)))*(p1.mult[0]+axe)*temp[0]*0.3;
        damage=atck*(((mon.enemy[i].defense*mon.enemy[i].mult[2]))+p1.sharp);
        mon.enemy[i].health=mon.enemy[i].health-damage;
        tempsingle[2]=0.5;}//multi attack inner
       else{
        atck=(p1.mattack+(rand()%(p1.mattack/5)))*(p1.mult[1]+axe)*temp[1]*0.3;
        damage=atck*(((mon.enemy[i].mdefense*mon.enemy[i].mult[3]))+p1.cunning);
        mon.enemy[i].health-=damage;
        tempsingle[3]=0.5;}//multi magic attack inner
       }}
     else if(attack=='S'){
      if(mon.enemy[i].post>7){
       if(sword=='w'){
        atck=(p1.attack+(rand()%(p1.attack/5)))*(p1.mult[0]+axe)*temp[0]*0.2;
        damage=atck*(((mon.enemy[i].defense*mon.enemy[i].mult[2])));
        mon.enemy[i].health-=damage;
        tempsingle[2]=0.5;}//multi attack outer
       else{
        p1.mp-=15;
        atck=(p1.mattack+(rand()%(p1.mattack/5)))*(p1.mult[1]+axe)*temp[1]*0.2;
        damage=atck*(((mon.enemy[i].mdefense*mon.enemy[i].mult[3])));
        mon.enemy[i].health-=damage;
        tempsingle[2]=0.5;}//multi magic attack outer
       }}}//multi aattack
    else if((sword=='E'||sword=='e')){
     int k=1;
     string fruit,mag="You don't have enough magic power to preform this action.\n";
     if(attack=='s'&&p1.mp>=5&&sword=='E'&&i==0){
      p1.mp-=5;
      p1.hp+=15;
      text+="You cast magic that heals a few wounds.\n";}
     else if(attack=='S'&&p1.mp>=20&&sword=='E'&&i==0){
      p1.mp-=20;
      p1.hp+=40;
      text+="You cast magic healing many wounds.\n";}
     else if(sword=='E'&&aim<2){
      if(mon.enemy[i].M==mon.enemy[i].char2){
       if(p1.mp>=5){
        p1.mp-=5;
        k=mon.enemy[i].health/5;
        mon.enemy[i].health-=(k*3);
        p1.hp+=(k*3);
        if(p1.hp>p1.maxhp)
         p1.hp=p1.maxhp;
        text+="You do a magic spell stealing 3/5 of the "+mon.enemy[i].name+"'s health.\n";}
       else
        text+=mag;}
      else
       text+="You can only preform this attack on an enemy that's about to attack.\n";}
     else if(sword=='E'&&(attack=='s'||attack=='S')&&(i==0||aim<2))text+=mag;
     else if(tolower(attack)>98&&tolower(attack)<107&&sword=='e'&&i==0){
      attack=tolower(attack);
      x=attack- 97;
      if(p1.inv.f.inv[x]>0){
       fruit=p1.inv.f.name[x];
       if(upper==true){
        k=rand()%(5)+ 1;
        if(k>p1.inv.f.inv[x])k=p1.inv.f.inv[x];
        if(k>1)fruit=p1.inv.f.names[x];}
       else{
        tempsingle[2]=0.5;
        tempsingle[3]=0.5;}
       for(int m=0;m<k;m++){
        p1.hp+=(p1.inv.f.hp[x]+rand()%p1.inv.f.hpv[x]);
        p1.mp+=(p1.inv.f.mp[x]+rand()%p1.inv.f.mpv[x]);
        if(x==5)p1.defense-=0.002;
        if(x==6)p1.mdefense-= 0.005;}
       if(p1.mp>p1.maxmp){
        p1.mp=p1.maxmp;
        text+="You're at full magic power.\n";}
       if(p1.defense<0)p1.defense=0;
       if(p1.mdefense<0)p1.mdefense=0;
       if(x==5)text+="Your defense increased.\n";
       if(x==6)text+="Your magic defense increased\n";
       if(x==4||x==7||x==9)text+="You restored some mp.\n";
       p1.inv.f.inv[x]-=k;
       text+="You restored some hp by eatting "+to_string(k)+" "+fruit+".\n";}
      else text+="You don't have any "+p1.inv.f.names[x]+"\n";}
     if(p1.hp>=p1.maxhp&&i==0){
      p1.hp=p1.maxhp;
      text+="You're at full health.\n";}}//healing

    if(mon.enemy[i].M!=mon.enemy[i].char2)
     monattack=false;
    if(mon.enemy[i].post>7)
     mon.enemy[i].mult[1]+=0.125;
    else if(mon.enemy[i].post<8)
     mon.enemy[i].mult[0]+=0.125;
    if(mon.enemy[i].mattack*mon.enemy[i].mult[1]>mon.enemy[i].attack*mon.enemy[i].mult[0]&&mon.enemy[i].health>0&&monattack==true&&mon.enemy[i].M==mon.enemy[i].char2){
     atck=(mon.enemy[i].mattack-rand()%(mon.enemy[i].mattack/5))*mon.enemy[i].mult[1];
     damage=atck*(p1.mdefense*p1.mult[3]*temp[3]*tempsingle[3]);
     if(damage>0){
      p1.hp-=damage;
      text+="The "+mon.enemy[i].name+" did "+to_string(damage)+" points of magic attack damage to you.\n";}}//stronger magic
    else if(mon.enemy[i].health>0&&monattack==true&&mon.enemy[i].M==mon.enemy[i].char2){
     atck=(mon.enemy[i].attack-rand()%(mon.enemy[i].attack/5))*mon.enemy[i].mult[0];
     damage=atck*(p1.defense*p1.mult[2]*temp[2]*tempsingle[2]);
     if(damage>0){
      p1.hp-=damage;
      text+="The "+mon.enemy[i].name+" did "+to_string(damage)+" points of attack damage to you.\n";}}//stronger physical
    else if(mon.enemy[i].health>0&&mon.enemy[i].newM==false)
     mon=SpecialAttack(mon,mon.enemy[i],i,&intnumb,&numb,p1.monplus,p1.level);
    else
     text+="You killed the "+mon.enemy[i].name+".\n";
    if(killed==""&&p1.hp<=0)
     killed=mon.enemy[i].name;//who killed
    if(mon.enemy[i].post>7)
     mon.enemy[i].mult[1]-=0.125;
    else if(mon.enemy[i].post<8)
     mon.enemy[i].mult[0]-=0.125;
    monattack=false;
    for(int j=0;j<4;j++)
     tempsingle[j]= 1.0;//reset single use mult
    }}
  for(int j=0;j<=numb;j++){
   if(mon.enemy[j].health<=0){
    mon.enemy[intnumb+ 1]=mon.enemy[j];
    if(mon.enemy[j].lootcount>0)
     first=intnumb+ 1;
    grid[mon.enemy[j].post]=' ';
    for(int k=j;k<=intnumb;k++){
     if(mon.enemy[k].lootcount>0)
      first-=1;
     mon.enemy[k]=mon.enemy[k+ 1];}
    numb-=1;
    j-=1;}}// remove dead mons
  count+=1;}
 std::cout<< u8"\033[2J\033[1;1H";
 if(numb<0){
  if(mon.enemy[first].expi==0)
   cout<<mon.text;
  else
   cout<<"You beat the "<<mon.enemy[first].name<<"!\n";
  cout<<"The "<<mon.enemy[first].name<<" dropped "<<mon.enemy[first].lootcount<<" "<<f.n2[mon.enemy[first].lf]<<".";
  int x=mon.enemy[first].lf;
  p1.inv.f.inv[x]+=mon.enemy[first].lootcount;
  if(x==0)
   cout<<" outside of battle";
  else if(x==12||x==11)
   cout<<" in battle";
  cout<<".\n";
  damage=0;
  for(int j=0;j<=intnumb;j++){
   p1.expi+=mon.enemy[j].expi;
   damage+=mon.enemy[j].expi;}
  cout<<"You gained "<<damage<<" expirience points!\n";
  p1=level(p1);//leveling
 }//loot + experience
 else if(flee==false){
  printf("\033[0;31m");//red
  cout<<"You were killed by "<<killed<<"!\n";
  p1.win=true;
  p1.alive=false;}//death message
 */return p1;
}
PlayerStats encounter(PlayerStats p1){
 Monsters get;
 Fighting mon;
 string trash;
 int monsternumb=rand()%100,m,count=1,i=0,k;
 bool more=true;
//determine which monster is getting fought
 if(monsternumb<13)m=0;
 else if(monsternumb<24)m=1;
 else if(monsternumb<30)m=2;
 else if(monsternumb<45)m=3;
 else if(monsternumb<51)m=4;
 else if(monsternumb<60)m=5;
 else if(monsternumb<64)m=6;
 else if(monsternumb<75)m=7;
 else if(monsternumb<84)m=8;
 else if(monsternumb<86)m=9;
 else if(monsternumb<90)m=10;
 else m=11;
 k=m;
 while(more==true){
//get the monster stats
  mon.enemy[i]=getMon(m,p1.level);
  mon.enemy[i].newM=false;
  if(i==0)mon.enemy[i].lootcount=rand()%get.lootvari[m]+get.lootcount[m];
 //numerate repeat monsters
  if(i!=0&&mon.enemy[i- 1].id==mon.enemy[i].id){
   if(mon.enemy[i- 1].name==mon.enemy[i].name)mon.enemy[i- 1].name+="(1)";
   count+=1;
   mon.enemy[i].name=mon.enemy[i].name+"("+to_string(count)+")";}
  else count=1;
//to prevent too many monsters
//if mon- limit 4 (4/8)
  if(p1.monplus==0&&i==3)more=false;
//if mon+ limit 9 (9/24)
  else if(p1.monplus==1&&i==8)more=false;
  else if(p1.single==1)more=false;
  else if(k==0){
   if(p1.monplus==0){
    if(i<1){}
    else if(i<2&&mon.enemy[i].id==0){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else{
      monsternumb=rand()%2;
      if(monsternumb==0)m=8;
       else more=false;}}
    else{
     monsternumb=rand()%2;
     if(monsternumb==0)m=8;
     else more=false;
     if(mon.enemy[i].id==8)more=false;}}
   else{
    if(i<2){}
    else if(i<6&&mon.enemy[i].id==0){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else{
      monsternumb=rand()%2;
      if(monsternumb==0)m=8;
      else more=false;}}
    else if(mon.enemy[i- 1].id==0){
     monsternumb=rand()%2;
     if(monsternumb==0)m=8;
     else more=false;}
    else more=false;}}//Blubatty
  else if(k==1){
   if(p1.monplus==0){
    if(i<2){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else more=false;}
    else more=false;}
   else{
    if(i<1){}
    else if(i<5){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else more=false;}
    else more=false;}}//Limeiten
  else if(k==2){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%4;
     if(monsternumb==0)more=false;
     else if(monsternumb==1)m=3;
     else if(monsternumb==2)m=0;
     else m=5;}
    else if(i<3){
     monsternumb=rand()%2;
     if(monsternumb==0)more=false;}
    else more=false;}
   else{
    if(i==0){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else{
      monsternumb=rand()%4;
      if(monsternumb==0)more=false;
      else if(monsternumb==1)m=3;
      else if(monsternumb==2)m=0;
      else m=5;}}
    else if(i<8||(i<9&&mon.enemy[1].id==2)){
     monsternumb=rand()%3;
     if(monsternumb==0)more=false;
     else if(mon.enemy[i].id==2){
      monsternumb=rand()%3;
      if(monsternumb==0)m=3;
      else if(monsternumb==1)m=0;
      else if(monsternumb==2)m=5;}
     else if(mon.enemy[i- 1].id==m){
      monsternumb=rand()%2;
      if(monsternumb==0){
       monsternumb=rand()%4;
       if(monsternumb==0)m=3;
       else if(monsternumb==1)m=0;
       else if(monsternumb==2)m=5;
       else more=false;}}}
    else more=false;}}//Sorcberry
  else if(k==3){
   if(p1.monplus==0){
    if(i<1){}
    else if(mon.enemy[i].id==3){
     monsternumb=rand()%3;
     if(monsternumb==0)more=false;
     else if(monsternumb==1)m=0;}
    else{
     monsternumb=rand()%2;
     if(monsternumb==0)m=0;
     else more=false;}}
   else{
    if(i<2){}
    else if(mon.enemy[i].id==3){
     monsternumb=rand()%3;
     if(monsternumb==0)more=false;
     else if(monsternumb==1)m=0;}
    else{
     monsternumb=rand()%2;
     if(monsternumb==0)m=0;
     else more=false;}}}//Papain
  else if(k==4){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%2;
     if(monsternumb==0)more=false;
     else m=11;}
    else more=false;}
   else{
    if(i<3){
     monsternumb=rand()%2;
     if(monsternumb==0)more=false;
     else m=11;}
    else more=false;}}//Duriable
  else if(k==5){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else{
      monsternumb=rand()%3;
      if(monsternumb==0)m=0;
      else if(monsternumb==1)m=3;
      else more=false;}}
    else if(mon.enemy[i].id==5){
     monsternumb=rand()%3;
     if(monsternumb==0)m=0;
     else if(monsternumb==1)m=3;
     else more=false;}
    else more=false;}
   else{
    if(i==0){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else{
      monsternumb=rand()%2;
     if(monsternumb==0)m=0;
      else m=3;}}
    else if(mon.enemy[i].id==5){
     monsternumb=rand()%2;
     if(monsternumb==0)m=0;
     else m=3;}
    else if(i>1&&mon.enemy[i- 2].id!=mon.enemy[i].id){
     monsternumb=rand()%2;
     if(monsternumb==0)more=false;}
    else more=false;}}//Kiwitten
  else if(k==6){
   if(p1.monplus==0)more=false;
   else{
    monsternumb=rand()%2;
    if(monsternumb==0)m=3;
    else more=false;
    if(i==2)more=false;}}//Cheridile
  else if(k==7){
   if(p1.monplus==0){
    if(i<1){}
    else more=false;}
   else{
    if(i<1){}
    else if(i<3){
     monsternumb=rand()%2;
     if(monsternumb==0)m=0;
     else more=false;}
    else more=false;}}//Fightful Pear
  else if(k==8){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%4;
     if(monsternumb==0)m=7;
     else if(monsternumb==1)m=1;
     else if(monsternumb==2)more=false;}
    else if(i==1&&mon.enemy[i].id==8){
     monsternumb=rand()%3;
     if(monsternumb==0)m=7;
     else if(monsternumb==1)m=1;
     else more=false;}
    else if(mon.enemy[i].id!=mon.enemy[i- 1].id){}
    else more=false;}
   else{
    if(i < 2){}
    else if(i==2){
     monsternumb=rand()%4;
     if(monsternumb==0)m=7;
     else if(monsternumb==1)m=1;
     else if(monsternumb==2)more=false;}
    else if(i==3&&mon.enemy[i].id==8){
     monsternumb=rand()%3;
     if(monsternumb==0)m=7;
     else if(monsternumb==1)m=1;
     else more=false;}
    else if(mon.enemy[i].id!=mon.enemy[i- 1].id){
     if(mon.enemy[i].id==1){
      monsternumb=rand()%2;
      if(monsternumb==0)more=false;}}
    else more=false;}}//Apericot
  else if(k==9)more=false;//Grapethreat
  else if(k==10){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%3;
     if(monsternumb==0)m=11;
     else if(monsternumb==1)more=false;}
    else if(mon.enemy[i].id==10){
     monsternumb=rand()%23;
     if(monsternumb==0)m=11;
     else more=false;}
    else more=false;}
   else{
    if(i<1){}
    if(i==1){
     monsternumb=rand()%3;
     if(monsternumb==0)m=11;
     else if(monsternumb==2)more=false;}
    else if(mon.enemy[i].id==10){
     monsternumb=rand()%2;
     if(monsternumb==0)m=11;
     else more=false;}
    else if(mon.enemy[i].id==11&&mon.enemy[i- 1].id==10){
     monsternumb=rand()%2;
     if(monsternumb==0)m=11;
     else more=false;}
    else more=false;}}//Manghost
  else if(k==11){
   if(p1.monplus==0){
    if(i==0){
     monsternumb=rand()%3;
     if(monsternumb==0)m=10;
     else if(monsternumb==1)m=1;
     else more=false;}
    else if(i<2){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else more=false;}
    else more=false;}
   else{
    if(i==0){
     monsternumb=rand()%3;
     if(monsternumb==0)m=10;
     else if(monsternumb==1)m=1;}
    else if(mon.enemy[i].id==11){
     monsternumb=rand()%2;
     if(monsternumb==0)m=10;
     else if(monsternumb==1)m=1;}
    else if(mon.enemy[i- 1].id==11||mon.enemy[i- 2].id==11){
     monsternumb=rand()%2;
     if(monsternumb==0){}
     else if(monsternumb==1)more=false;}
    else more=false;}}//Raspbeing
  i+=1;}
 cout<<"You encountered a wild "<<mon.enemy[0].name<<"\n";
 i-=1;
 p1=battle(p1,mon,i);
 cout<<endl;
 if(p1.alive==true)
  cout<<"You escaped with "<<p1.hp<<" health\n";
 cout<<"Press anything to continue: ";
 cin>>trash;
 return p1;}
#endif