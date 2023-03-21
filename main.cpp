#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<sstream>
#include<conio.h>
#include"monsters.h"

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<ncurses.h>
#include<pthread.h>
#include<signal.h>
#include<cstring>
#include<string.h>
//Fix up fighting mechanics to utilize new tools
//finalize tool stats
//make sure resource gathering is affected by tools
//simplify base controlls, asdw, fruit, tool, equip, stats, inventory, quit
//axe, radar, hammer 
//axe chop trees, hammer break rocks, shield, sword chop bushes, wand use portals

//tree, stationary blockage until chopped
//rocks, can be pushed or broken
//bushes, 100% monster spawn point
//portals, transport around map
//shield, temporary portection from monsters?
string treeFall(string); 
Resourcs chopTree(Resourcs,char);
PlayerStats smashRock(PlayerStats);
string left(Resourcs,int);
string healt(int);
string magict(int);
string defenset(float,string);
string expit(int);
char color(char);
string p1Stat(PlayerStats,string);
string winInv(Resourcs,string);
string getDistance(int,int,int,int,string);
string getDirection(int,int,int,int,string);
void saveScore(PlayerStats,int,int,int,string,char,int,int,int,int,int,int,int);
PlayerStats store(PlayerStats);
PlayerStats items(PlayerStats);
char yesNo(string);
int numb(string,string,int,int);
Monster getMon(int);
string makeCol(string,string,char,int,int=-1);
PlayerStats level(PlayerStats);

int main(){
//initalize map print vari, dual used game set up. Init strings.
 char a1,a2,a3,a4,a5,b1,b2,b3,b4,b5,c1,c2,c3,c4,c5,d1,d2,d3,d4,d5,e1,e2,e3,e4,e5,near;
 int x,y;
	string name="defaultMap",trash,mapstring;
	char teleporters[46]={'0','1','2','3','4','5','6','7','8','9','b','B','d','D','e','E','f','F','g','G','h','H','i','I','j','J','l','L','n','N','q','Q','r','R','t','T','u','U','v','V','w','W','y','Y','z','Z'};
 a1=yesNo("Would you like to make a new map? y/n: ");
 unsigned int seed=time(0);
 srand(seed);
 if(a1=='y'){
  int dense=0,ewm,nsm,im,jm,num,kr,kc,teleportc=0,mondense,stone,tr=0,tc=0,tcount=0,bush;
  bool happy=false;
  string nametxt;
  while(happy==false){
   cout<<"Enter map name: ";
   cin>>name;
   getline(cin,trash);
   if(name=="continue"||name=="winningMap"||name=="defaultMap"||name=="leaderboard")cout<<"You may not name your map that!\n";
   else happy=true;}
  cout<<"Map name is: "<<name<<endl;
  happy=false;
  nsm=numb("Please enter a North to South size: ","size",2,500);
  ewm=numb("Please enter an East to West size: ","size",2,500);
  char teleportrc[nsm][ewm];
  int storec=((nsm*ewm/850)+ 1);
  dense=numb("Enter a desired tree density from 1 to 99: ","density",1,99);
  stone=numb("Enter a desired stone density from 0 to 50: ","density",0,50);
  bush=numb("Enter a desired bush density from 0 to 100: ","density",0,50);
  if((nsm*ewm)>=400)a5=yesNo("Do you wish to add teleporters? y/n: ");
//initalize teleport cord array
  for(im=0;im<nsm;im++)
   for(jm=0;jm<ewm;jm++)
    teleportrc[im][jm]='X';
  if(a5=='y'){//****Broken****
   if((nsm*ewm)/400>0)tr=1;
   teleportc=((nsm*ewm)/700)+tr;
   tr=0;
   if(teleportc>46)teleportc=46;
   for(im=0;im<teleportc;im++){
    happy=false;
    while(happy==false){
     tr=rand()%nsm;
     tc=rand()%ewm;
     if(teleportrc[tr][tc]=='X'){
      teleportrc[tr][tc]=teleporters[im];
      tcount++;
      if(tcount==2){
       tcount=0;
       happy=true;}}}}}
  happy=false,tr=0,tc=0;
  for(im=0;im<storec;im++)
   while(happy==false){
    happy=false;
    tr=rand()%nsm;
    tc=rand()%ewm;
    if(teleportrc[tr][tc]=='X'){
     teleportrc[tr][tc]='$';
     happy=true;}}
  mondense=numb("Enter a desired map monster density from 0 to 100: ","density",0,100);
  std::cout<<u8"\033[2J\033[1;1H";
//Map construction
  nametxt=name+".txt";
  ofstream pFile;
  pFile.open(nametxt);
  pFile<<"rows: "<<nsm<<" columns: "<<ewm<<" teleporters: "<<teleportc<<" density: "<<dense<<" monsters: "<<mondense<<endl;
  kr=rand()%nsm;//rand port local
  kc=rand()%ewm;
  while(teleportrc[kr][kc]!='X'){//X in teleportrc for none
   kr=rand()%nsm;
   kc=rand()%ewm;}
  for(im=0;im<nsm;im++){
   for(jm=0;jm<ewm;jm++){
    num=1+rand()%100;
    if(im==kr&&jm==kc)pFile<<"O";
    else if(teleportrc[im][jm]!='X')pFile<<teleportrc[im][jm];
    else if(num<dense)pFile<<"X";
    else{
     num=1+rand()%100;
     if(num<stone)pFile<<"o";
     else{
      num=1+rand()%100;
      if(num<bush)pFile<<"m";
      else pFile<<" ";}}}
   pFile<<endl;}
  pFile.close();}//Map make
 a3=yesNo("Do you want to play the game? y/n: ");//prompt to choose to play the game
 if(a3=='n')return 0;
//Reading map to array, init map vari
 string map,line,mapname,dirctTree,text="",number="0";
 int ns,ew,i,j,k,l,m,n,rc,rr,telecount,ir,ic,tempr,tempc,moves=0,chops=0,cmax=5,chance=0,zc=0,qcount=10,cardinal=0,turn=2,ultimate=0,compass=1,quse=0,dense,mondense,heal,magic;
 bool happy=false,t=false,axe=false,z=false,apricot=false,h=false,e=false,stonePush=false,ham=false,start=true;
 char mode='x',h1='>',h2='<',v1='{',v2='}',dn='x',de='}',ds='x',dw='{',dnw='<',dne='>',dsw='<',dse='>',direction;
 PlayerStats p1;
 Fruit f;
 Shopping s;
 Monsters mon;
 ifstream Map;
 while(happy==false){
  cout<<"Which map do you wish to play on?: ";
  cin>>map;
  getline(cin,trash);
  mapname=map;
  map+=".txt";
  Map.open(map);
  if(Map&&map!="winningMap.txt"&&map!="leaderboard.txt")happy=true;
  else if(mapname==name){
   happy=true;
   cout<<endl;}
  else cout<<"That's not a valid map. Try entering \""<<name<<"\".\n";}//get map name
//init inv and vari for game.
 if(map!="continue.txt")Map>>trash>>ns>>trash>>ew>>trash>>telecount>>trash>>dense>>trash>>mondense;
 else Map>>trash>>ns>>trash>>ew>>trash>>telecount>>trash>>dense>>trash>>mondense>>mapname>>p1.inv.f[1]>>p1.inv.f[3]>>p1.inv.f[2]>>p1.inv.f[4]>>p1.inv.wood>>p1.inv.f[0]>>p1.inv.f[5]>>p1.inv.f[11]>>p1.inv.f[6]>>p1.inv.f[7]>>p1.inv.f[12]>>p1.inv.f[8]>>p1.inv.f[9]>>p1.inv.f[10]>>p1.inv.items[0]>>ir>>ic>>moves>>chops>>zc>>qcount>>mode>>turn>>ultimate>>cardinal>>compass>>quse>>p1.monplus>>p1.monhelp>>p1.single>>p1.hp>>p1.mp>>p1.maxhp>>p1.maxmp>>p1.attack>>p1.defense>>p1.expi>>p1.expigoal>>p1.level;//edit this
 getline(Map,line);
 char cord[ns][ew];
 if(telecount>0)t=true;
 happy=false;
 for(i=0;i<ns;i++){
  getline(Map,line);
  for(j=0;j<ew;j++){
   cord[i][j]=line[j];
   if(line[j]=='O'){
    k=i;
    l=j;}
   if(line[j]==' '||line[j]=='m')happy=true;}}//get map info
 Map.close();
 if(happy==false){
  cout<<"\nYour map is too dense to play on!\nTry again but enter larger N/S and E/W values or smaller densities.\n";
  return 0;}//if map bad
 if(map!="continue.txt")a4=yesNo("Would you like randomize the position of \"O\"? y/n: ");//portal rand
 if(a4=='y'){
  cord[k][l]=' ';
  k=rand()%ns;
  l=rand()%ew;
  cord[k][l]='O';
  text+="Your O's position has been randomized.\nYou will not be able to check the map to see where the \"O\" is located.\n";}
 if(map!="continue.txt"){
  ir=k;
  ic=l;
  while(cord[ir][ic]!=' '&&cord[ir][ic]!='m'){
   ir=rand()%ns;
   ic=rand()%ew;}}//rand start post
 ew--;
 ns--;
 std::cout<<u8"\033[2J\033[1;1H";
//Game mode setup
 a3=' ';
 if(mode=='x')a1=yesNo("Would you like to play on easy mode? y/n: ");//easy
 if(a1!='y'&&mode=='x')a2=yesNo("Would you like to play on hard mode? y/n: ");//hard
 if(turn==2)a3=yesNo("Would you like to play in turn mode? y/n: ");//turn
 if(a3=='y')a4=yesNo("Would you like to play on ultimate turn mode? y/n: ");//turn ult
 if(p1.monplus==2)a5=yesNo("Would you like to show the compass? y/n: ");//compass
 if(mondense>0&&p1.monplus==2){
  b1=yesNo("Would you like to play on battle mode+? y/n: ");
  b2=yesNo("Would you like assistance learning to battle? y/n: ");
  b3=yesNo("Would you like to play in multi monster mode? y/n: ");}//mon options
 std::cout<<u8"\033[2J\033[1;1H";
//game prompts
 cout<<text;
 text="";
 if(a1=='y'||mode=='e'){
  mode='e';
  e=true;
  cout<<"You're playing on easy mode.\n";}
 else if(a2=='y'||mode=='h'){
  h=true;
  mode='h';
  cout<<"You're playing on hard mode. Good luck!\n";}
 else if(h==false&&e==false){
  mode='n';
  cout<<"You're playing on the normal difficulty.\n";}
 if(a3=='y'||turn== 1){
  turn=1;
  if(a4=='y'||ultimate==1){
   cout<<"You're playing on turn mode ultimate!\nYou cannot see behind yourself.\n";
   ultimate=1;}
  else cout<<"You're playing on turn mode!\n";}
 else turn=0;
 if(a5=='n'||compass==0){
  cout<<"You're playing without a compass.\n";
  compass=0;}
 else{
  cout<<"You're playing with a compass.\n";
  compass=1;
  dn='N';de='E';ds='S';dw='W';}
 if(b1=='y'||p1.monplus==1){
  cout<<"You're playing on battle mode+.\n";
  p1.monplus=1;}
 else p1.monplus=0;
 if(b2=='y'||p1.monhelp==1){
  cout<<"You'll get assistance in battle.\n";
  p1.monhelp=1;}
 else p1.monhelp=0;
 if(b3=='y'||p1.single==0){
  cout<<"You'll see multiple monsters in battle.\n";
  p1.single=0;}
 else{
  cout<<"You will only encounter one monster at a time.\n";
  p1.single=1;}
 printf("\033[0;31m");//red
 cout<<"\nIncrease the height of your play window to see 15+ lines.\n";
 printf("\033[0m");
 cout<<"Enter anything to continue: ";
 cin>>trash;
 getline(cin,trash);
 std::cout<<u8"\033[2J\033[1;1H";
 
 text=text+"You find yourself in a forest, armed with";
 if(p1.inv.items[0]==1)text+=" an axe.\n";
 else if(p1.inv.items[0]>1)text+=" axes.\n";
 else text+="out an axe.\n";
 text+="You must locate the portal \"O\" home.\nEnter q to find how far the portal is.\nEnter e to prepare your axe.\n";
//You are at cord[ir][ic] and need to get to cord[k][l]
 string tree="There is a tree!\n",rock="You beat the rock with your hammer!\n",wall="There is a wall.\n",axerock="You aggressively swing your axe at the boulder. \nThe boulder shows not signs of damage.\n",roll="You roll the boulder\n",rockport="The boulder disappears into the portal.\n",rockno="The boulder won't budge.\n",chop1="You use your axe and chop one of your ",chop2="You use your axe and chop your ",why="! Why would you do that?\n",chop3="You attempt to use your axe to chop a ",kill=", but it's too small. You slip and kill yourself!\n";
 while(p1.win==false){
  if(start==false){
//actions for asdw inputs
   stonePush=false;
   if(direction=='a'||direction=='A'){
    if(turn==1){
     cardinal--;
     if(cardinal==-1)cardinal=7;}
    else{
     x=-1;
     y=0;
     dirctTree="Western ";}}//move west / turn
   else if(direction=='d'||direction=='D'){
    if(turn==1){
     cardinal++;
     if(cardinal==8)cardinal=0;}
    else{
     x=1;
     y=0;
     dirctTree="Eastern ";}}//move east / turn right in turn
   else if(direction=='w'||direction=='W'){
    if(cardinal>0&&cardinal<4)x=1;
    else if(cardinal>4)x=-1;
    else x=0;
    if(cardinal>2&&cardinal<6)y=1;
    else if(cardinal<2||cardinal>6)y=-1;
    else y=0;
    dirctTree=="";
    if(turn==0)dirctTree=="Northern ";}//move north / move in turn
   else if(direction=='s'||direction=='S'){
    if(turn==1)text+="You cannot go backwards in turn mode!\n";
    else{
     x=0;
     y=1;
     dirctTree="Southern ";}}//move south

   else if(direction=='q'||direction=='Q'){
    if(qcount>9||e==true){
     text=getDistance(k,l,ir,ic,text);
     qcount=0;
     quse++;}
    else text+="You've used this command too recently. \n";}//get distance to portal Q

   else if(direction=='E'&&p1.equip[2]!=36){
    if(p1.equip[2]/6==2){
     text+="You ready your hammer.\n";
     ham=true;}
    else text+="Please equip a hammer.\n";}//prepare hammer
   else if(direction=='e'||direction=='E'){
    if(p1.equip[0]/6==0){
     text+="You pepare your axe.\n";
     axe=true;}
    else text+="You don't have an axe equipped.\n";}//prepare axe <equipment> E
   else if(direction=='r'){
    if(p1.inv.wood>=20){
     //p1.sharp+=0.1;//edit this
     p1.inv.wood-=20;
     //text=text+"You use your wood to sharpen your "+p1.weapon+".\n";
     }
    else text+="You don't have enough wood to sharpen your anything.\n";}//sharp enhance <equipment> R
   else if(direction=='R'){
    if(p1.inv.wood>=20){
     for(int i=0;i<4;i++)
      if(p1.equip[i]!=36)text+="Edit this String";///checks all that is equipped....edit this
     //p1.cunning+=0.1;
     p1.inv.wood-=20;
     //text=text+"You use your wood to enhance your "+p1.weapon+"'s casting ability.\n";
     }
    else text+="You don't have enough wood to upgrade anything's casting ability.\n";}//wand

   else if(direction=='f'||direction=='F'){//<use fruit> F
    x=0;
    for(int i=0;i<14;i++){
     if(p1.inv.f[i]>0){
      cout<<(char)(65+i)<<": "<<makeCol(f.n[i],": ",' ',13,p1.inv.f[i])<<" | ";
      x++;}
     if(x%2!=1||i==13)
      cout<<"\n";}
    cout<<"Which Fruit would you like to use?: ";
    cin>>a1;
    getline(cin,trash);
    a1=tolower(a1);
    x=a1- 97;
    if(x>=12)text+="You can't use those outside of battle!\n";
    else if(p1.inv.f[x]>0){
     p1.inv.f[x]--;
     if(axe==true){
      if(f.kill[x]==true){
       text+=chop3+f.n[x]+kill;
       axe=false;
       ham=false;
       p1.alive=false;
       p1.win=true;}
      else{
       if(p1.inv.f[x]>1)text+=chop2+f.n2[x]+why;
       else text+=chop1+f.n2[x]+why;
       if(cord[ir][ic]==' ')cord[ir][ic]=f.path[x];
       axe=false;
       ham=false;}}//cut
     else{
      heal=f.hp[x];
      heal+=rand()%f.hpv[x];
      p1.hp+=heal;
      if(p1.hp>p1.maxhp){
       heal-=(p1.hp-p1.maxhp);
       p1.hp=p1.maxhp;}
      magic=(f.mp[x])+rand()%(f.mpv[x]);
      p1.mp+=magic;
      if(p1.mp>p1.maxmp){
       magic-=(p1.mp-p1.maxmp);
       p1.mp=p1.maxmp;}
      text+=healt(heal)+magict(magic)+f.uses[x]+"\n";
      if(x==0){if(cord[ir][ic]==' ')cord[ir][ic]='c';}
      else if(x==1){
       if(mode!='e')text+="You eat an apple. You can see a bit furthur.\n";
       else text+="You eat an apple. You can sense if the portal is near.\n";
       z=true;
       zc+=5;}
      else if(x==2)apricot=true;
      else if(x==3)text=getDirection(k,l,ir,ic,text);
      else if(x==4)text+="You are at ("+to_string(ic)+", "+to_string(ir)+").\n";
      else if(x==5){
       p1.defense-=0.005;
       if(p1.defense<=0)p1.defense=0;
       text+=defenset(p1.defense," ");}
      else if(x==6){
       p1.mdefense-= 0.005;
       if(p1.mdefense<=0)p1.mdefense=0;
       p1.expi+=7;
       p1=level(p1);
       text+=defenset(p1.mdefense," magic ")+expit(7)+p1.text;}
      else if(x==7)x=x;
      else if(x==8){
       p1.expi+=8;
       p1=level(p1);
       text+=expit(8)+p1.text;}
      else if(x==9)x=x;
      else if(x==10){
       heal=rand()%2;
       if(heal==1){
        p1.defense-=0.005;
        if(p1.defense<=0)p1.defense=0;
        text+=defenset(p1.defense," ");}
       else{
        p1.mdefense-=0.005;
        if(p1.mdefense<=0)p1.mdefense=0;
        text+=defenset(p1.mdefense," magic ");}}
      else if(x>10){
       p1.inv.f[x]++;}}//use
     text+=left(p1.inv, x);}//some
    else text+=f.none[x]+"\n";//none
   }

   else if(direction=='0'){
    printf("\033[0;31m");//red
    a1=yesNo("Would you like to quit? y/n: ");
    printf("\033[0m");
    if(a1=='y'){
     printf("\033[0;31m");//red
     char saveanswer=yesNo("Would you like to save your game? y/n\nNOTE! This will write over any old data: ");
     printf("\033[0m");
     if(saveanswer=='y'){
      ofstream saving;
      saving.open("continue.txt");
      saving<<"rows: "<<ns+ 1<<" columns: "<<ew+ 1<<" teleporters: "<<telecount<<" density: "<<dense<<" monsters: "<<mondense<<" "<<mapname<<" "<<p1.inv.f[1]<<" "<<p1.inv.f[3]<<" "<<p1.inv.f[2]<<" "<<p1.inv.f[4]<<" "<<p1.inv.wood<<" "<<p1.inv.f[0]<<" "<<p1.inv.f[5]<<" "<<p1.inv.f[11]<<" "<<p1.inv.f[6]<<" "<<p1.inv.f[7]<<" "<<p1.inv.f[12]<<" "<<p1.inv.f[8]<<" "<<p1.inv.f[9]<<" "<<p1.inv.f[10]<<" "<<p1.inv.items[0]<<" "<<ir<<" "<<ic<<" "<<moves<<" "<<chops<<" "<<zc<<" "<<qcount<<" "<<mode<<" "<<turn<<" "<<ultimate<<" "<<cardinal<<" "<<compass<<" "<<quse<<" "<<p1.monplus<<" "<<p1.monhelp<<" "<<p1.single<<" "<<p1.hp<<" "<<p1.mp<<" "<<p1.maxhp<<" "<<p1.maxmp<<" "<<p1.attack<<" "<<p1.defense<<" "<<p1.expi<<" "<<p1.expigoal<<" "<<p1.level<<endl;//edit this
      for(i=0;i<=ns;i++){
       for(j=0;j<=ew;j++)
        saving<<cord[i][j];
       saving<<endl;}
      saving.close();
      cout<<"Your game has been saved. \nPlay on map \"continue\" to resume your journey\n";}
     else cout<<"The game has been abandoned. Good bye.\n";
     return 0;}
    else text+="The game shall resume.\n";}//exit/save
   else if(direction=='1')text=winInv(p1.inv,text);//check inventory
   else if(direction=='2')text=p1Stat(p1,text);//check player health/stats
   else if(direction=='3'&&cord[ir][ic]=='$')p1=store(p1);//store
   else if(direction=='3')p1=items(p1);//equip

   else text+="That's not a valid input.\n";//invalid inpit

   if((direction=='a'||direction=='A'||direction=='d'||direction=='D'||direction=='s'||direction=='S')&&cardinal==0||direction=='w'||direction=='W'){
    if((ir+y)>ns||(ic+x)>ew||(ir+y)<0||(ic+x)<0)text+=wall;
    else if(cord[ir+y][ic+x]=='X'){
     if(axe==true){
      cord[ir+y][ic+x]='*';
      p1.inv=chopTree(p1.inv,direction);
      chops++;
      text+=treeFall(dirctTree);}
     else text+=tree;}
    else if(cord[ir+y][ic+x]=='o'){//walk into rock
     if(axe==true){
      chops=cmax;
      text+=axerock;}
     else if(ham==true){
      p1=smashRock(p1);
      text+=rock;
      if(p1.equip[2]!=17)cord[ir+y][ic+x]=' ';}
     else{
      for(int i=1;i<11;i++){
       if(ir+y*i>ns||ic+x*i>ew||ir+y*i<0||ic+x*i<0)break;
       if(cord[ir+y*i][ic+x*i]==' '){
        cord[ir+(y*i)][ic+(x*i)]='o';//empty to rock
        text+=roll;
        stonePush=true;
        break;}
       else if(cord[ir+y*i][ic+x*i]=='O'){
        text+=rockport;
        stonePush=true;
        break;}
       else if(cord[ir+y*i][ic+x*i]!='o')break;}
      if(stonePush==false)text+=rockno;
      else{
        cord[ir+y][ic+x]=' ';//rock to empty
        ir+=y;
        ic+=x;
        chance=1+rand()%100;
        qcount++;}}}
    else{
     ir+=y;
     ic+=x;
     chance=1+rand()%100;
     qcount++;}
    ham=false;
    axe=false;}
//Random Chance event
   if(chance==50){
    text+="You found an axe!\n";
    p1.inv.items[0]++;}
   if((chance<mondense&&chance!=0&&cord[ir][ic]==' '&&stonePush==false)||cord[ir][ic]=='m')p1=encounter(p1);
   if(t==true&&chance!=0)
    for(i=0;i<telecount;i++)
     if(cord[ir][ic]==teleporters[i]){
      for(j=0;j<=ns;j++)
       for(m=0;m<=ew;m++)
        if(cord[j][m]==cord[ir][ic])
         if(j!=ir||m!=ic){
          text+="You teleported!\n";
          tempr=j;
          tempc=m;}
      ir=tempr;
      ic=tempc;}
   if(chance!=0&&cord[ir][ic]=='$')text+="You've found a store!!! Enter the store menu with 3.\n";
   if(chance!=0)//regeneration
    if(p1.hp<p1.maxhp)p1.hp++;
   chance=0;
//Consequences using axe. Chance happens 4 times in code
    if(chops>=cmax){
    text+="Your axe broke!\n";
    chops=0;
    //p1.cunning=0.0;
    //p1.sharp=0.0;
    p1.inv.items[p1.equip[0]]--;
    if(p1.inv.items[p1.equip[0]]!=1)text=text+"You have "+to_string(p1.inv.items[0])+" axes left.\n";
    else text+="You have 1 axe left.\n";}
//Win test
   if(ir==k&&ic==l){
    if(moves!=0)cout<<"You're about to win in "<<moves+1<<" moves!\n";
    else cout<<"You're gonna win in just 1 move! Did you get lucky, or plan this?\n";
    p1.win=true;
    printf("\033[0;31m");//red
    char winanswer=yesNo("Would you like to save your winning map? y/n\nThis will write over any old winning map data: ");
    printf("\033[0m");
    if(winanswer=='y'||winanswer=='Y'){
     ofstream results;
     results.open("winningMap.txt");
     results<<"\"O\" is at ("<<k<<", "<<l<<")\n";
     for(i=0;i<=ns;i++){
      for(j=0;j<=ew;j++)
       results<<cord[i][j];
      results<<endl;}
     results.close();}
    text=winInv(p1.inv,text);}
   moves++;}
//clear
  std::cout<<u8"\033[2J\033[1;1H";
// Map Printing
//Apricot number map
  if(apricot==true){
   int countw=-1,counte=-1,countn=-1,counts=-1,countnw=-1,countne=-1,countsw=-1,countse=-1;
   for(i=1;i<ns;i++){
    if(((cord[ir-i][ic])=='X'||(ir-i)<0)&&countn<0)countn=i- 1;
    if(((cord[ir+i][ic])=='X'||(ir+i)>ns)&&counts<0)counts=i- 1;}
   for(i=1;i<ew;i++){
    if(((cord[ir][ic-i])=='X'||(ic-i)<0)&&countw<0)countw=i- 1;
    if(((cord[ir][ic+i])=='X'||ic==ew)&&counte<0)counte=i- 1;
    if(((cord[ir-i][ic-i])=='X'||(ic-i)<0||(ir-i)<0)&&countnw<0)countnw=i- 1;
    if(((cord[ir-i][ic+i])=='X'||(ic+i)>ew||(ir-i)<0)&&countne<0)countne=i- 1;
    if(((cord[ir+i][ic-i])=='X'||(ic-i)<0||(ir+i)>ns)&&countsw<0)countsw=i- 1;
    if(((cord[ir+i][ic+i])=='X'||(ic+i)>ew||(ir+i)>ns)&&countse<0)countse=i- 1;}
   cout<<countnw<<" "<<countn<<" "<<countne<<endl<<countw<<" # "<<counte<<endl<<countsw<<" "<<counts<<" "<<countse<<endl;
   apricot=false;}
//print map, multi use
  else{
   if((ic- 2)<0){
    if(cardinal==0||cardinal==4)a1=b1=c1=d1=e1='|';
    else if(cardinal==6||cardinal==2)a1=b1=c1=d1=e1='_';
    else if(cardinal==3||cardinal==7)a1=b1=c1=d1=e1='/';
    else if(cardinal==5||cardinal== 1)a1=b1=c1=d1=e1='\\';}
   else{
    a1=cord[ir-2][ic-2];b1=cord[ir-1][ic-2];c1=cord[ir][ic-2];d1=cord[ir+1][ic-2];e1=cord[ir+2][ic-2];}
   if((ic-1)<0){
   if(cardinal==0||cardinal==4)a2=b2=c2=d2=e2='|';
   else if(cardinal==6||cardinal==2)a2=b2=c2=d2=e2='_';
   else if(cardinal==3||cardinal==7)a2=b2=c2=d2=e2='/';
   else if(cardinal==1||cardinal==5)a2=b2=c2=d2=e2='\\';}
   else{
    a2=cord[ir-2][ic-1];b2=cord[ir-1][ic-1];c2=cord[ir][ic-1];d2=cord[ir+1][ic-1];e2=cord[ir+2][ic-1];}
   if((ic+1)>=ew){
    if(cardinal==0||cardinal==4)a5=b5=c5=d5=e5='|';
    else if(cardinal== 6||cardinal==2)a5=b5=c5=d5=e5='_';
    else if(cardinal==7||cardinal==3)a5=b5=c5=e5=d5='/';
    else if(cardinal==1||cardinal==5)a5=b5=c5=d5=e5='\\';}
   else{
    a5=cord[ir-2][ic+2];b5=cord[ir-1][ic+2];c5=cord[ir][ic+2];d5=cord[ir+1][ic+2];e5=cord[ir+2][ic+2];}
   if(ic>=ew){
    if(cardinal==0||cardinal==4)a4=b4=c4=d4=e4='|';
    else if(cardinal==6||cardinal==2)a4=b4=c4=d4=e4='_';
    else if(cardinal==7||cardinal==3)a4=b4=c4=d4=e4='/';
    else if(cardinal== 5 || cardinal == 1)a4=b4=c4=d4=e4='\\';}
   else{
    a4=cord[ir-2][ic+1];
    b4=cord[ir-1][ic+1];
    c4=cord[ir][ic+1];
    d4=cord[ir+1][ic+1];
    e4=cord[ir+2][ic+1];}
   if((ir-2)<0){
    if(cardinal==0||cardinal==4)a1=a2=a3=a4=a5='_';
    else if(cardinal== 6||cardinal==2)a1=a2=a3=a4=a5='|';
    else if(cardinal==5||cardinal==1)a1=a2=a3=a4=a5='/';
    else if(cardinal==7||cardinal==3)a1=a2=a3=a4=a5='\\';}
   else a3=cord[ir-2][ic];
   if((ir-1)<0){
    if(cardinal==0||cardinal==4)b1=b2=b3=b4=b5='_';
    else if(cardinal==6||cardinal==2)b1=b2=b3=b4=b5='|';
    else if(cardinal==5||cardinal==1)b1=b2=b3=b4=b5='/';
    else if(cardinal == 7||cardinal==3)b1=b2=b3=b4=b5='\\';}
   else b3=cord[ir-1][ic];
   if(ir>=ns){
    if(cardinal==0||cardinal==4)d1=d2=d3=d4=d5='_';
    else if(cardinal==2||cardinal==6)d1=d2=d3=d4=d5='|';
    else if(cardinal==5||cardinal==1)d1=d2=d3=d4=d5='/';
    else if(cardinal==7||cardinal==3)d1=d2=d3=d4=d5='\\';}
   else d3=cord[ir+1][ic];
   if((ir+1)>=ns){
    if(cardinal==0||cardinal==4)e1=e2=e3=e4=e5='_';
    else if(cardinal==6||cardinal==2)e1=e2=e3=e4=e5='|';
    else if(cardinal==5||cardinal==1)e1=e2=e3=e4=e5='/';
    else if(cardinal==7||cardinal==3)e1=e2=e3=e4=e5='\\';}
   else e3=cord[ir+2][ic];
//turn map if cardinal is not 0, turn it counter clockwise until it's pointed the right way
   if(cardinal!=0){
    char hold;
    for(i=0;i<cardinal;i++){
     hold=a1;a1=a3;a3=a5;a5=c5;c5=e5;e5=e3;e3=e1;e1=c1;c1=hold;hold=a2;a2=a4;a4=b5;b5=d5;d5=e4;e4=e2;e2=d1;d1=b1;b1=hold;hold=b3;b3=b4;b4=c4;c4=d4;d4=d3;d3=d2;d2=c2;c2=b2;b2=hold;}}
   if(ultimate==1)c1=c5=d1=d2=d3=d4=d5=e1=e2=e3=e4=e5='?';
//if on easy mode and apple active, set '!' to be printed when the 'O' is near.
   if(k>=ir- 3&&k<=ir+ 3&&l<=ic+ 3&&l>=ic- 3&&z==true&&mode=='e')near='!';
   else near=' ';
   if(turn==1&&compass==1&&(direction=='A'||direction=='a'||direction=='d'||direction=='D')){
    if(cardinal%2==0){
     dnw=dsw='<';dne=dse='>';}
    else{
     dn=ds='x';de='}';dw='{';}
    if(cardinal==0){
     dn='N';de='E';ds='S';dw='W';}
    else if(cardinal==1){
     dnw='N';dne='E';dse='S';dsw='W';}
    else if(cardinal==2){
     dn='E';de='S';ds='W';dw='N';}
    else if(cardinal==3){
     dnw='E';dne='S';dse='W';dsw='N';}
    else if(cardinal==4){
     dn='S';de='W';ds='N';dw='E';}
    else if(cardinal==5){
     dnw='S';dne='W';dse='N';dsw='E';}
    else if(cardinal==6){
     dn='W';de='N';ds='E';dw='S';}
    else if(cardinal==7){
     dnw='W';dne='N';dse='E';dsw='S';}}
//apple 5x5 map
   if((z==true&&h==false)||mode=='e'){
    cout<<color(dnw)<<color(h1)<<color(h2)<<color(dn)<<color(h1)<<color(h2)<<color(dne)<<endl<<color(v1)<<color(a1)<<color(a2)<<color(a3)<<color(a4)<<color(a5)<<color(v2)<<endl<<color(v2)<<color(b1)<<color(b2)<<color(b3)<<color(b4)<<color(b5)<<color(v1)<<endl<<color(dw)<<color(c1)<<color(c2)<<color('#')<<color(c4)<<color(c5)<<color(de)<<' '<<near<<endl<<color(v2)<<color(d1)<<color(d2)<<color(d3)<<color(d4)<<color(d5)<<color(v1)<<endl<<color(v1)<<color(e1)<<color(e2)<<color(e3)<<color(e4)<<color(e5)<<color(v2)<<endl<<color(dsw)<<color(h1)<<color(h2)<<color(ds)<<color(h1)<<color(h2)<<color(dse)<<endl;
    if(z==true)zc--;
    if (zc==0)z=false;}
//regular map
   else if(z==true||h==false){
    cout<<color(dnw)<<color(h2)<<color(dn)<<color(h1)<<color(dne)<<endl<<color(v2)<<color(b2)<<color(b3)<<color(b4)<<color(v1)<<endl<<color(dw)<<color(c2)<<color('#')<<color(c4)<<color(de)<<endl<<color(v2)<<color(d2)<<color(d3)<<color(d4)<<color(v1)<<endl<<color(dsw)<<color(h2)<<color(ds)<<color(h1)<<color(dse)<<endl;
    if(z==true){
     zc--;
     if(zc==0)z=false;}}
//hard mode map
   else cout<<color(dnw)<<color(h2)<<color(dn)<<color(h1)<<color(dne)<<endl<<color(v2)<<color('?')<<color(b3)<<color('?')<<color(v1)<<endl<<color(dw)<<color(c2)<<color('#')<<color(c4)<<color(de)<<endl<<color(v2)<<color('?')<<color(d3)<<color('?')<<color(v1)<<endl<<color(dsw)<<color(h2)<<color(ds)<<color(h1)<<color(dse)<<endl;
   for(int y=0;y<mapstring.length(); y++)
    //wprintw(mapspace,"%c",color(mapstring[y]));}//not mapspace?
    cout<<color(mapstring[y]);}
  if(p1.alive==false)printf("\033[0;31m");//red
  else printf("\033[0m");//normal
  cout<<text;
  text="";
  if(p1.win==false){
   if(turn==0) cout<<"move with asdw: ";
   else cout<<"move forwards with w, turn with a or d: ";
   cin>>direction;
   getline(cin,trash);}
  else if(p1.alive==true){
   cout<<"You won in "<<moves<<" moves!\n";
   saveScore(p1,chops,quse,moves,mapname,mode,dense,ultimate,turn,compass,ns,ew,mondense);}
  start=false;}
 if(p1.alive==false) cout<<"You Died.\n";
 return 0;}
string treeFall(string dir){
 string text="The "+dir+"tree comes falling down. You gather the material.\n";
 return text;}
string p1Stat(PlayerStats p1,string text){
 string number;
 text=text+"HP: "+to_string(p1.hp)+ "/"+to_string(p1.maxhp)+"\nMP: "+to_string(p1.mp)+"/"+to_string(p1.maxmp);
 text=text+"\nAttack: "+to_string(p1.attack)+"\nDefense: "+to_string(p1.defense);
 text=text+"\nExperience: "+to_string(p1.expi)+"/"+to_string(p1.expigoal)+"\nLevel: "+to_string(p1.level)+"\n";
	return text;}
string winInv(Resourcs inv,string text){
 string end;
 Fruit fru;
 for(int i=0;i<13;i++){
  if(i%2==0)text+="\n";
  else text+=" | ";
  text+=makeCol(fru.n2[i],": ",' ',15,inv.f[i]);}
 text=text+" | "+makeCol("wood",": ",' ',15,inv.wood)+"\n"+makeCol("axes",": ",' ',15,inv.items[0])+" | \n\n";
	return text;}
string left(Resourcs inv, int x){
 string f;
 Fruit fru;
 f=fru.n2[x];
 if(inv.f[x]==1)f=fru.n[x];
 f="You have "+to_string(inv.f[x])+" "+f+" left.\n";
 return f;}
Resourcs chopTree(Resourcs inv,char direction){
 int type,count;
 string trash;
 char tap;
 Fruit f;
 type=rand()%15 - 1;
 if(type==0)count=rand()%11+ 10;
 else if(type==1)count=rand()%6+ 2;
 else if(type==2)count=rand()%8+ 3;
 else if(type==3)count=rand()%4+ 2;
 else if(type==4)count=rand()%10+ 5;
 if(type<5){
  inv.f[type]+=count;
  cout<<"The tree has "<<count<<" "+f.n2[type]+"!\n";}
 count=rand()%21+ 5;\
 cout<<"You'll be able to gather "<<count<<" pieces of wood from the tree.\n";
 inv.wood+=count;
 cout<<"You hack and hack at the tree trunk, but it hasn't fallen yet\n";
 while(count!=2){
  count=rand()%3;
  while(tap!=direction){
   cout<<"Use "<<direction<<" to knock the tree down: ";
   cin>>tap;
   getline(cin,trash);}
  tap='p';
  if(count!=2)cout<<"You tapped the tree.\n";}
 return(inv);}
PlayerStats smashRock(PlayerStats p){
 char x;
 string pe=" pieces of ",item[4]={"rock","quartz","iron","gold"},trash;
 float mult[4]={0,0,0,0};
 int base[4]={10,5,3,1},chance[4]={20,15,10,5};
 if(p.equip[2]==12)mult[0]=1;//Hammer
 if(p.equip[2]==13){
  mult[0]=1.25;
  mult[1]=1;}//Strong
 if(p.equip[2]==14){
  mult[0]=2.5;
  mult[1]=2;
  mult[2]=1.75;}//Bounty's
 if(p.equip[2]==15){
  mult[0]=1.5;
  mult[1]=1.5;
  mult[2]=1.25;
  mult[3]=1;}//Magic
 if(p.equip[2]==16){
  mult[0]=1.75;
  mult[1]=1.75;
  mult[2]=1.5;
  mult[3]=1.25;}//War
 if(p.equip[2]==17){
  mult[0]=1;
  mult[1]=0.75;
  mult[2]=0.5;
  mult[3]=0.25;}//Strange
 for(int i=0;i<4;i++){
  base[i]=(rand()%chance[i]+base[i])*mult[i];
  p.inv.m[i]+=base[i];};
 int count;
 while(count!=1){
  count=rand()%2;
  while(x!='E'){
   cout<<"Enter E to hit the rock!: ";
   cin>>x;
   getline(cin,trash);}
  x='p';
  if(count!=1)cout<<"Your hammer bounces off the rock with a loud kathunk!\n";}
 if(p.equip[2]!=17)cout<<"The Rock shatters into a pile of material!\n";
 else cout<<"Oddly, materials emerge from the rock, yet the rock remains unharmed.\n";
 for(int i=0;i<4;i++){
  if(base[i]>0){
   if(base[i]==1)pe=" piece of ";
   cout<<"Congratulations, you've collected "<<base[i]<<pe<<item[i]<<"!\n";}
  pe=" pieces of ";}
 cout<<"Enter anything to continue: ";
 cin>>x;
 getline(cin,trash);;
 return p;}
string getDirection(int k,int l,int ir,int ic,string text){
 string ns,ew;
 if(k>ir)ns="South";
 else if(k<ir)ns="North";
 else ns="Due";
 if(l>ic)ew="East";
 else if(l<ic)ew="West";
 else ew="Due";
 if(ew=="Due")text=text+"The \"O\" is Due "+ns+".\n";
 else if(ns == "Due")text=text+"The \"O\" is Due "+ew+".\n";
 else text=text+"The \"O\" is to the "+ns+" "+ew+".\n";
 return text;}
string getDistance(int k,int l,int ir,int ic,string text){
 int nsdistance,ewdistance,distance;
 string number;
 if(k>ir)nsdistance=k-ir;
 else nsdistance=ir-k;
 if(l>ic)ewdistance=l-ic;
 else ewdistance=ic-l;
 distance=sqrt(ewdistance*ewdistance+nsdistance*nsdistance);
 if(distance!=1)text=text+"You are about "+to_string(distance)+" meters from the \"O\".\n";
 else text+="You are about 1 meter from the \"O\".\n";
 return text;}
void saveScore(PlayerStats p1,int chops,int quse,int moves,string mapname,char mode,int dense,int ultimate,int turn,int compass,int ns,int ew,int mondense){
 int score,size,axes,fruit,spaceone,spacetwo;
 float modeM=1.0,turnM=1.0,compassM=1.0,multiplier=1.0;
 string name;
 if(mode=='h')modeM=2.0;
 else if(mode=='e')modeM=0.333;
 if(turn==1){
  if(ultimate==1){
   if(mode=='h')turnM=1.75;
   else if(mode=='e')turnM = 2.0;
   else turnM = 1.833;}
  else turnM=1.5;
  if(compass==0)compassM=1.5;}
 dense=dense/100;
 multiplier=(multiplier*modeM*turnM*compassM)+dense;
 size=(ns+ 1)*(ew+ 1)/(moves+ 1)*0.5;
 quse=quse*3.75;
 axes=((p1.inv.items[0]*5)-chops)*3;
 fruit=(p1.inv.f[1]*20)+p1.inv.f[2]+(p1.inv.f[3]*15)+(p1.inv.f[4]*5)+(p1.inv.f[0]*3)+(p1.inv.wood/20)-quse+axes;
 score=size*multiplier*10000+fruit*1000;
 fruit=(p1.inv.f[5])+(p1.inv.f[11]*2)+(p1.inv.f[6]*2)+p1.inv.f[7]+(p1.inv.f[12]*10)+(p1.inv.f[8]*3)+(p1.inv.f[9]*4)+p1.inv.f[10]+(p1.level*10);
 dense=mondense/100;
 multiplier=1.0;
 if(p1.monplus==1)turnM==2.0;
 else if(p1.monplus==0)turnM==1.0;
 else turnM==0;
 if(p1.monhelp==1)modeM==0.75;
 else modeM==1.25;
 multiplier=(turnM*modeM)+dense;
 size=size*multiplier*10000+fruit*1000;
 score=score+size;
 cout<<"Enter your name: ";
 getline(cin,name);
 ofstream leaderboard;
 leaderboard.open("leaderboard.txt",ios::app);
 spaceone=13-to_string(score).length();
 spacetwo=25-mapname.length();
 leaderboard<<"  "<<score<<" ";
 for(int i=0;i<spaceone;i++)leaderboard<<"-";
 leaderboard<<" "<<mapname<<" ";
 for(int i=0;i<spacetwo;i++)leaderboard<<"-";
 leaderboard<<" "<<name<<endl;
 leaderboard.close();
 return;}
string expit(int ex){
 string text="You gained "+to_string(ex)+" experience.\n";
 return text;}
string defenset(float def,string t){
 def=(1.0-def)*100;
 string text="You're now at "+to_string(def)+"%"+t+"defense.\n";
 return text;}
string healt(int heal){
 string text;
 if(heal>0)
  text="You healed "+to_string(heal)+" hp.\n";
 return text;}
string magict(int magic){
 string text;
 if(magic>0)
  text="You recovered "+to_string(magic)+" mp.\n";
 return text;}
PlayerStats store(PlayerStats p){
 std::cout<<u8"\033[2J\033[1;1H";
 int worth[9]={p.inv.wood,p.inv.m[0],p.inv.m[1],p.inv.m[2],p.inv.m[3],p.inv.f[2],p.inv.f[0],p.inv.f[7],p.inv.f[10]};
 char answer=' ';
 string space="",text="",trash,cost;
 Shopping shop;
 int type=6,look;
 bool afford;
 while(answer!='x'&&answer!='X'){
  std::cout<<u8"\033[2J\033[1;1H";
  cout<<text;
  text="";
  cout<<makeCol("","",'_',24)<<"\n|";
  for(int i=0;i<36;i++)
   if(p.level>=shop.level[i]&&(i/6==type||type==6))cout<<" "<<makeCol(shop.item[i],"",' ',20,i)<<" |\n|";
  cout<<makeCol("","",'_',22)<<"|\n";
  cout<<"\n L: Look At     F: filter    X: Quit  \n\n Input: ";
  cin>>answer;
  getline(cin,trash);
  answer=tolower(answer);
  look=40;
  if(answer=='f'){
   std::cout<<u8"\033[2J\033[1;1H";
   cout<<"_______________\n| A: Axes     |\n| S: Swords   |\n| H: Hammers  |\n| W: Wands    |\n| P: Shields  |\n| F: Fruit    |\n| I: All      |\n|_____________|\n\n Please enter the letter of your desired filter: ";
   cin>>answer;
   answer=tolower(answer);
   getline(cin,trash);
   if(answer=='a')type=0;
   if(answer=='s')type=1;
   if(answer=='h')type=2;
   if(answer=='w')type=3;
   if(answer=='p')type=4;
   if(answer=='f')type=5;
   if(answer=='i')type=6;}
  else if(answer=='l'){
   look=numb(" Which Item number do you wish to Look at: ","Item",0,35);
   if(p.level>=shop.level[look]){
    std::cout<<u8"\033[2J\033[1;1H";
    cout<<makeCol("","",'_',23)<<"\n| ";
    cout<<makeCol(shop.item[look],"",' ',20)<<"|\n|";
    cout<<makeCol(" Required Level: ","",' ',20,shop.level[look])<<" |\n|"<<makeCol("","",' ',21)<<"|\n";
    if(look<30){
     cout<<makeCol("| Strength","",' ',21,((shop.stats[look][0]- 1)*10))<<" |\n"<<makeCol("| Magic Power","",' ',21,((shop.stats[look][1]- 1)*10))<<" |\n";
     cout<<makeCol("| Defense","",' ',21,((1-shop.stats[look][2])*10))<<" |\n"<<makeCol("| Magic Defense","",' ',21,((1-shop.stats[look][3])*10))<<" |\n|"<<makeCol("","",'_',21)<<"|\n"<<makeCol("| Price:","",' ',22)<<"|\n";}
    afford=true;
    for(int i=0;i<9;i++)
     if(shop.price[look][i]>0){
      cout<<"| ";
      if(worth[i]>=shop.price[look][i])printf("\033[1;32m");//green
      else{
       afford=false;
       printf("\033[0;31m");//red
      }
      cost=to_string(worth[i])+"/"+to_string(shop.price[look][i]);
      cout<<makeCol(shop.money[i],cost,' ',19);
      printf("\033[0m");
      cout<<" |\n";}
    cout<<"|"<<makeCol("","",'_',21)<<"|\n\n ";
    if(afford==true)cout<<"P: Purchase  ";
    cout<<"R: Return\n Input: ";
    cin>>answer;
    getline(cin,trash);
    if((answer=='p'||answer=='P')&&afford==true){
     text=" Thank you for purchasing a "+shop.item[look]+"!\n";
     for(int i=0;i<9;i++)
      worth[i]-=shop.price[look][i];
     if(look<30){
      p.inv.items[look]++;
      text=text+" You may edit your equipment with '3' after leaving the store.\n\n";}
     else p.inv.f[(int)shop.stats[look][0]]++;}
    else if(answer=='p'||answer=='P')text=" Sorry, but you can't afford a "+shop.item[look]+"!\n";}}}
 p.inv.wood;
 p.inv.m[0]=worth[0];
 p.inv.m[1]=worth[1];
 p.inv.m[2]=worth[2];
 p.inv.m[3]=worth[3];
 p.inv.f[2]=worth[4];
 p.inv.f[0]=worth[5];
 p.inv.f[7]=worth[6];
 p.inv.f[10]=worth[7];
 return p;}
PlayerStats items(PlayerStats p){
 string type[4]={"Axe","Weapon","Hammer","Shield"};
 string eft[6]={"Strength","Magic Power","Defense","Magic Defense","Sharpness","Powress"};
 string text,txt;
 Shopping x;
 int y,k;
 char input='q';
 bool happy;
 while(input!='x'&&input!='X'){
  std::cout<<u8"\033[2J\033[1;1H";
  cout<<makeCol("","",'_',93)<<"\n|";
  cout<<makeCol("Axe:",x.item[p.equip[0]],' ',18)<<" | "<<makeCol("Weapon:",x.item[p.equip[1]],' ',18)<<" | "<<makeCol("Hammer:",x.item[p.equip[2]],' ',18)<<" | "<<makeCol("Shield:",x.item[p.equip[3]],' ',18)<<" |\n|";
  cout<<makeCol("","",'_',91)<<"|\n|"<<makeCol("","",' ',91)<<"|\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[0],"",' ',18,((x.stats[p.equip[i]][0]- 1)*10))<<" | ";
  cout<<"\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[1],"",' ',18,((x.stats[p.equip[i]][1]- 1)*10))<<" | ";
  cout<<"\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[2],"",' ',18,((1-x.stats[p.equip[i]][2])*10))<<" | ";
  cout<<"\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[3],"",' ',18,((1-x.stats[p.equip[i]][3])*10))<<" | ";
  cout<<"\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[4],"",' ',18,((x.stats[p.equip[i]][4]- 1)*10))<<" | ";
  cout<<"\n|";
  for(int i=0;i<4;i++)
   cout<<makeCol(eft[5],"",' ',18,((x.stats[p.equip[i]][5]- 1)*10))<<" | ";
  cout<<"\n|"<<makeCol("","",'_',91)<<"|\n";
  cout<<"\n A:Edit Axe       W:Edit Weapon    H:Edit Hammer    S:Edit Shield    V:View Items     X:Return\n\n Go To: ";
  cin>>input;
  input=tolower(input);
  if(input=='a')y=0;
  else if(input=='w')y=1;
  else if(input=='h')y=2;
  else if(input=='s')y=3;
  else if(input=='v')y=4;
  else y=5;
  std::cout<<u8"\033[2J\033[1;1H";
  if(input!='x'){
   happy=false;
   while(happy==false){
    std::cout<<u8"\033[2J\033[1;1H";
    cout<<makeCol("","",'_',20)<<"\n|";
    cout<<makeCol(type[y],"Number",' ',18)<<"|\n|";
    cout<<makeCol("","",'_',18)<<"|\n|";
    for(int i=0;i<37;i++){//axe:0 sword:1 hammer:2 wand:3 shield:4
     if(p.inv.items[i]>0){
      if(i/6==0&&(y==0||y==1||y==4))cout<<makeCol(x.item[i],": ",' ',18,i)<<"|\n|";
      if(i/6==2&&(y==2||y==4||y==1))cout<<makeCol(x.item[i],": ",' ',18,i)<<"|\n|";
      if((i/6==3||i/6==1)&&(y==1||y==4))cout<<makeCol(x.item[i],": ",' ',18,i)<<"|\n|";
      if(i/6==4&&(y==3||y==4))cout<<makeCol(x.item[i],": ",' ',18,i)<<"|\n|";
      if(i==36)cout<<makeCol(x.item[i],": ",' ',18,i)<<"|\n|";}}
    cout<<makeCol("","",'_',18)<<"|\n";
    if(y<4){
     cout<<text;
     text="\nItem number would you like to use as your "+type[y]+": ";
     k=numb(text,type[y],0,36);
     text="";
     std::cout<<u8"\033[2J\033[1;1H";
     if(p.inv.items[k]>0){
      cout<<makeCol("","",'_',44)<<"\n|";
      cout<<makeCol("Previous",x.item[p.equip[y]],' ',18)<<" | "<<makeCol("New",x.item[k],' ',18)<<"|\n|"<<makeCol("","",'_',42)<<"|\n";
      for(int i=0;i<6;i++){
       if(i<2)cout<<"|"<<makeCol(eft[i],"",' ',18,((x.stats[p.equip[y]][i]- 1)*10))<<" | "<<makeCol(eft[i],"",' ',18,((x.stats[k][i]- 1)*10))<<"|\n";
       else cout<<"|"<<makeCol(eft[i],"",' ',18,((1-x.stats[p.equip[y]][i])*10))<<" | "<<makeCol(eft[i],"",' ',18,((1-x.stats[k][i])*10))<<"|\n";}
       cout<<"|"<<makeCol("","",'_',42)<<"|\n";
       text="\n Would you like to Equip the "+x.item[k]+" as your "+type[y]+"? Y/N: ";
       input=yesNo(text);
       text="";
       happy=true;
       if(input=='y')p.equip[y]=k;
/*       if(y==0){}//axe
       if(y==1){//weapon
        for(int m=0;m<6;m++)
         p.wea[m]=x.stats[k][m];
        p.weapon=x.item[k];}
       if(y==2){}//hammer
       else{//shield
        for(int m=0;m<6;m++)
         p.shi[m]=x.stats[k][m];
        p.shield=x.item[k];}*/}
     else text=" Sorry, but you don't appear to have one of those.\n";}
    else{
     input=yesNo("\n Are you done Looking y/n: ");
     if(input=='y')happy=true;}}}}
 return p;}
char yesNo(string text){
 char ans='0';
 string trash;
 while(ans!='y'&&ans!='n'){
  cout<<text;
  cin>>ans;
  getline(cin,trash);
  ans=tolower(ans);}
 return ans;}
int numb(string text,string value,int min,int max){
 int numb=max+ 1;
 string trash;
 while(numb<min||numb>max){
  cout<<text;
  cin>>numb;
  if(cin.fail()){
   cin.clear();
   cin.ignore();
   cout<<"Please enter a numeric "<<value<<"!\n";}
  else if(numb>max)cout<<"Please enter a "<<value<<" less than "<<max+ 1<<"!\n";
  else if(numb<min)cout<<"Plese enter a"<<value<<" more than "<<min+ 1<<"!\n";
  getline(cin,trash);
  cin.clear();}
 return numb;}
string makeCol(string text,string end,char space,int width,int count){
 if(count>999)count=999;
 if(count==-1)width+=3;
 string text2=to_string(count);
 width-=text.length();
 width-=end.length();
 for(int i=0;i<width;i++)
  text+=space;
 text+=end;
 if(count!=-1){
  for(int i=0;i<(3-text2.length());i++)
   text+=space;
  text+=text2;}
  

 return text;}//("Apples", ": ", ' ', 14