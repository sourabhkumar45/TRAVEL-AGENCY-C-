#include&lt;conio.h&gt;
#include&lt;stdio.h&gt;
#include&lt;iomanip.h&gt;
#include&lt;dos.h&gt;
#include&lt;fstream.h&gt;
#include&lt;ctype.h&gt;
#include&lt;string.h&gt;
/**********************************************
GLOABAL VARIABLE
**********************************************/
int i=0;
/**********************************************
GLOBAL FUNTIONS
**********************************************/
void startup();
int opening1();
void opening2();
void maketrfile();
void makehofile();
void places();
/**********************************************
CLASS TRAVELAGENCY CONSISTING OF FUNTIONS
AND DATA MEMBERS RELATED TO HOTEL AND
TRANSPORTATION RESERVATIONS.
**********************************************/
class travelagency
{
private:
char name[50],destination[30],hotel[30],add[80],flag1,flag2,trans[30];
float price,price2;
int not1,not2,nor,top,nod,noc,kor1,kor2,top2; //DATA MEMBERS IN PRIVATE AREA
int fst1,fst2,tst1,tst2,nst1,nst2;
int atr1,atr2,ttr1,ttr2,rtr1,rtr2;
public:
int toggle; //DATA MEMBERS IN PUBLIC AREA
void resho();
void showhotel();
void viewhorec();
void showhotelrec();
void delhotelrec(); //MEMBER FUNTIONS FOR HOTEL RESER.
void searchhotrec();
void transferhoteldata();
void edithoteldata();
void transferhoteldata1();
void restr();
void showtransport();
void viewtrrec();
void showtransportrec(); //MEMBER FUNTIONS FOR TRANSPORT RESER.
void deltransportrec();
void searchtransportrec();
void transfertransportdata();
void edittransportdata();
void transfertransportdata1();
void assignprice(); //FUNTION TO CALCULATE PRICE
void nindia(int ndes);
void sindia(int sdes); //FUNTION TO VIEW DIFFERENT DESTINATION
void eindia(int wdes);
void windia(int edes);
void cindia(int cdes);
}user,user1[100]; //GLOBAL CLASS OBJECTS
/*________________________________________________________________________________
_____________*********************************************************************
***************/

/**********************************************
CLASS TRAVELAGENCY FUNTIONS DEFINED
OUTSIDE THE CLASS.
**********************************************/

/*________________________________________________________________________________
_____________*********************************************************************
***************/

/********************************
HOTEL RESERVATIONS
********************************/

/**********************************************
FUNTION USED TO RESERVE HOTEL.
**********************************************/
void travelagency::resho()
{
clrscr();
flag1=&#39;N&#39;;
while(flag1!=&#39;Y&#39;)
{
clrscr();
gotoxy(20,5);cout&lt;&lt;&quot;Please Enter Information For Hotel Reservation&quot;;
gotoxy(20,7);cout&lt;&lt;&quot;Please enter the choice of your hotel......&quot;;
gotoxy(25,9);cout&lt;&lt;&quot;1: 5 Star&quot;;
gotoxy(25,10);cout&lt;&lt;&quot;2: 3 Star&quot;;
gotoxy(25,11);cout&lt;&lt;&quot;3: Normal&quot;&lt;&lt;endl;
gotoxy(26,12);cout&lt;&lt;&quot;......&quot;;cin&gt;&gt;top;
clrscr();
assignprice();
clrscr();
gotoxy(15,2);cout&lt;&lt;&quot;PLEASE FILL IN THE DETAILS ...&quot;;
gotoxy(25,5);cout&lt;&lt;&quot;HOTEL RESERVATION FORM&quot;;
gotoxy(5,8);cout&lt;&lt;&quot;Name: &quot;;
gotoxy(5,10);cout&lt;&lt;&quot;Address: &quot;;
gotoxy(5,12);cout&lt;&lt;&quot;Destination: &quot;;
gotoxy(30,12);cout&lt;&lt;&quot;Name of Hotel: &quot;;
gotoxy(5,14);cout&lt;&lt;&quot;No. of days to stay: &quot;;
gotoxy(5,16);cout&lt;&lt;&quot;Type of Rooms to be Reserved(1/0)&quot; ;
gotoxy(10,18);cout&lt;&lt;&quot;Deluxe: &quot;;
gotoxy(30,18);cout&lt;&lt;&quot;Non Deluxe: &quot;;
gotoxy(10,22);cout&lt;&lt;&quot;Is the information correct(y/n)?? &quot;;
gotoxy(10,8);gets(name);
gotoxy(13,10);gets(add);
gotoxy(19,12);gets(destination);
gotoxy(46,12);gets(hotel);
gotoxy(27,14);cin&gt;&gt;nod;
gotoxy(22,18);cin&gt;&gt;kor1;
gotoxy(45,18);cin&gt;&gt;kor2;
gotoxy(45,22);cin&gt;&gt;flag1;
flag1=toupper(flag1);
}
showhotel();
}
/**********************************************
FUNTION USED TO SHOW HOTEL RESERVATIONS.
**********************************************/
void travelagency::showhotel()
{
int a,b;
if(top==1)
price=(fst1*kor1*nod)+(fst2*kor2*nod);
else
if(top==2)
price=(tst1*kor1*nod)+(tst2*kor2*nod);
else
if(top==3)
price=(nst1*kor1*nod)+(nst2*kor2*nod);
if(toggle==1)
{
clrscr();
textcolor(WHITE+BLINK);
textbackground(BLUE);
for(int h=25;h&lt;50;h++)
{
gotoxy(20,8);cout&lt;&lt;&quot;Please wait while we make the Reservation&quot;;
gotoxy(h,10);cout&lt;&lt;&quot;Û&quot;;
delay(250);
}
toggle=0;
}
clrscr();
gotoxy(25,5);cout&lt;&lt;&quot;Hotel Reservation &quot;;
gotoxy(24,6);cout&lt;&lt;&quot;-----------------------&quot;;
gotoxy(15,8);cout&lt;&lt;&quot;Name:&quot;&lt;&lt;strupr(name);
gotoxy(15,10);cout&lt;&lt;&quot;Address:&quot;&lt;&lt;strupr(add);
gotoxy(15,12);cout&lt;&lt;&quot;Name of the hotel: &quot;&lt;&lt;strupr(hotel)

&lt;&lt;&quot; , &quot;&lt;&lt;strupr(destination);
gotoxy(15,14);cout&lt;&lt;&quot;No. of Days to stay: &quot;&lt;&lt;nod;
gotoxy(15,16);cout&lt;&lt;&quot;No. of DELUXE rooms reserved: &quot;&lt;&lt;kor1;
gotoxy(15,18);cout&lt;&lt;&quot;No. of NON-DELUXE rooms reserved: &quot;&lt;&lt;kor2;
gotoxy(15,20);cout&lt;&lt;&quot;Your Reservations have been done&quot;
&quot;Please pay the Amount!!!&quot;;

gotoxy(25,22);cout&lt;&lt;&quot;Amount: Rs.&quot;&lt;&lt;setprecision(2)&lt;&lt;price;
getch();
}
/**********************************************
FUNTION USED TO VIEW HOTEL RECORDS.
**********************************************/
void travelagency::viewhorec()
{
int option;
while(option!=5)
{
clrscr();
gotoxy(24,5);cout&lt;&lt;&quot;HOTEL RESERVATION INFORMATION&quot;;
gotoxy(25,10);cout&lt;&lt;&quot;choose.....&quot;;
gotoxy(25,12);cout&lt;&lt;&quot;1: View hotel reservation records&quot;;
gotoxy(25,14);cout&lt;&lt;&quot;2: Delete a particular record&quot;;
gotoxy(25,16);cout&lt;&lt;&quot;3: Search for a record&quot;;
gotoxy(25,18);cout&lt;&lt;&quot;4: Edit a record &quot;;
gotoxy(25,20);cout&lt;&lt;&quot;5: Exit..... &quot;;
cin&gt;&gt;option;
switch(option)
{
case 1:showhotelrec();
break;
case 2:delhotelrec();
break;
case 3:searchhotrec();
break;
case 4:edithoteldata();
break;
}
}
}
/**********************************************
FUNTION USED TO SHOW ALL HOTEL RESERVATIONS.
**********************************************/
void travelagency::showhotelrec()
{
fstream fil1;
fil1.open(&quot;hotel.dat&quot;,ios::binary|ios::in);
while(fil1.read((char*)&amp;user,sizeof (user)))
user.showhotel();
fil1.close();
}
/**********************************************
FUNTION USED TO DELETE A HOTEL RECORD.
**********************************************/
void travelagency::delhotelrec()
{
clrscr();
char dname[20];
gotoxy(20,5);cout&lt;&lt;&quot;Enter name to delete record for...&quot;;
gotoxy(30,7);gets(dname);
strupr(dname);
fstream fil2,fil3;
int del=0;
fil2.open(&quot;hotel.dat&quot;,ios::binary | ios::in);
fil3.open(&quot;temp.dat&quot;,ios::binary | ios::out);
while(fil2.read ((char*)&amp;user,sizeof (user)))
{
if ((strcmp(name,dname))!=0)
fil3.write((char*)&amp;user,sizeof (user));
else
del++;
}
if(del!=0)
cout&lt;&lt;endl&lt;&lt;&quot; ...Deleted...&quot;;
else
cout&lt;&lt;endl&lt;&lt;&quot; Record not found..&quot;;
getch();
fil2.close();
fil3.close();
transferhoteldata();
}
/**********************************************
FUNTION USED TO TRANSFER UNDELETED HOTEL RECORDS.
**********************************************/
void travelagency::transferhoteldata()
{
fstream oldfile,newfile;
oldfile.open(&quot;temp.dat&quot;,ios::binary | ios::in);
newfile.open(&quot;hotel.dat&quot;,ios::binary | ios::out);
while(oldfile.read((char*)&amp;user,sizeof(user)))
newfile.write((char*)&amp;user,sizeof (user));
oldfile.close();
newfile.close();
}
/**********************************************
FUNTION USED TO SEARCH FOR A HOTEL RECORD.
**********************************************/
void travelagency::searchhotrec()
{
clrscr();
char sname[20];
gotoxy(20,5);cout&lt;&lt;&quot;Enter Name to search for..&quot;;
gotoxy(25,7);gets(sname);
strupr(sname);
fstream fil4;
fil4.open(&quot;hotel.dat&quot;,ios::binary | ios::in);
int srch=0;
while(fil4.read((char*)&amp;user,sizeof (user)))
{
if(strcmp(name,sname)==0)
{
srch++;
user.showhotel();
}
}
if(srch==0)
cout&lt;&lt;&quot; No Record Exists&quot;;
fil4.close();
getch();
}
/**********************************************
FUNTION USED TO EDIT A HOTEL RECORD.
**********************************************/
void travelagency::edithoteldata()
{
clrscr();
char ename[30];int ede=0;
gotoxy(20,5);cout&lt;&lt;&quot;Enter Name to Edit Record for...&quot;;
gotoxy(25,7);gets(ename);
strupr(ename);
fstream fil5,fil6;
fil5.open(&quot;hotel.dat&quot;,ios::binary | ios::in) ;
fil6.open(&quot;temp1.dat&quot;,ios::binary | ios::out ) ;
while(fil5.read((char*)&amp;user,sizeof(user)))
{
if (strcmp (ename,name)==0)
{
resho();
ede++;
}
fil6.write((char*)&amp;user,sizeof (user));
}
if(ede==0)
{
gotoxy(25,17);cout&lt;&lt;&quot;RECORD DOESNT EXIST!!!!&quot;;
}
getch();
fil5.close();
fil6.close();
transferhoteldata1(); //TO TRANSFER EDITED HOTEL RECORD
}
/**********************************************
FUNTION USED TO TRANSFER EDITED HOTEL RECORDS.
**********************************************/
void travelagency::transferhoteldata1()
{
fstream oldfile2,newfile2;
oldfile2.open(&quot;temp1.dat&quot;,ios::binary | ios::in);
newfile2.open(&quot;hotel.dat&quot;,ios::binary | ios::out);
while(oldfile2.read((char*)&amp;user,sizeof(user)))
newfile2.write((char*)&amp;user,sizeof (user));
oldfile2.close();
newfile2.close();
}
/*________________________________________________________________________________
_____________*********************************************************************
***************/

/********************************
TRANSPORTATION RESERVATIONS
********************************/

/**********************************************
FUNTION USED TO RESERVE TRANSPORTATION.
**********************************************/
void travelagency::restr()
{
clrscr();
flag2=&#39;N&#39;;
while(flag2!=&#39;Y&#39;)
{
clrscr();
gotoxy(20,5);cout&lt;&lt;&quot;Please Enter Information For Transport Reservation&quot;;
gotoxy(20,7);cout&lt;&lt;&quot;Please enter the choice of your mode of transportaion......&quot;;
gotoxy(25,9);cout&lt;&lt;&quot;1: by Air&quot;;
gotoxy(25,10);cout&lt;&lt;&quot;2: by Train&quot;;
gotoxy(25,11);cout&lt;&lt;&quot;3: by Road&quot;&lt;&lt;endl;
gotoxy(26,12);cout&lt;&lt;&quot;......&quot;;cin&gt;&gt;top2;
clrscr();
assignprice();
clrscr();
gotoxy(15,2);cout&lt;&lt;&quot;PLEASE FILL IN THE DETAILS ...&quot;;
gotoxy(25,5);cout&lt;&lt;&quot;TRANSPORT RESERVATION FORM&quot;;
gotoxy(5,8);cout&lt;&lt;&quot;Name: &quot;;
gotoxy(5,10);cout&lt;&lt;&quot;Address: &quot;;
gotoxy(5,12);cout&lt;&lt;&quot;Destination: &quot;;
gotoxy(30,12);cout&lt;&lt;&quot;Mode of Transport: &quot;;
gotoxy(5,14);cout&lt;&lt;&quot;Type of Tickets to be Reserved(1/0)&quot; ;
gotoxy(10,16);cout&lt;&lt;&quot;Executive: &quot;;
gotoxy(30,16);cout&lt;&lt;&quot;Economy: &quot;;
gotoxy(10,22);cout&lt;&lt;&quot;Is the information correct(y/n)?? &quot;;
gotoxy(10,8);gets(name);
gotoxy(13,10);gets(add);
gotoxy(19,12);gets(destination);
gotoxy(50,12);gets(trans);
gotoxy(22,16);cin&gt;&gt;not1;
gotoxy(40,16);cin&gt;&gt;not2;
gotoxy(45,22);cin&gt;&gt;flag2;
flag2=toupper(flag2);
}
showtransport();
}
/**********************************************
FUNTION USED TO SHOW TRANSPORT RESERVATION.
**********************************************/
void travelagency::showtransport()
{
if(top2==1)
price2=(atr1*not1)+(atr2*not2);
else
if(top2==2)
price2=(ttr1*not1)+(ttr2*not2);
else
if(top2==3)
price2=(rtr1*not1)+(rtr2*not2);
if(toggle==1)
{
clrscr();
for(int h=25;h&lt;50;h++)
{
gotoxy(20,8);cout&lt;&lt;&quot;Please wait while we make the Reservation&quot;;
gotoxy(h,10);cout&lt;&lt;&quot;Û&quot;;
delay(250);
}
toggle=0;
}
clrscr();
gotoxy(25,5);cout&lt;&lt;&quot;Transport Reservation &quot;;
gotoxy(24,6);cout&lt;&lt;&quot;-----------------------&quot;;
gotoxy(15,8);cout&lt;&lt;&quot;Name:&quot;&lt;&lt;strupr(name);
gotoxy(15,10);cout&lt;&lt;&quot;Address:&quot;&lt;&lt;strupr(add);
gotoxy(15,12);cout&lt;&lt;&quot;Mode of transportation: &quot;&lt;&lt;trans
&lt;&lt;&quot; Destination:&quot;&lt;&lt;destination;

gotoxy(15,14);cout&lt;&lt;&quot;No. of EXECUTIVE class tickets reserved: &quot;&lt;&lt;not1;
gotoxy(15,16);cout&lt;&lt;&quot;No. of ECONOMY class tickets reserved: &quot;&lt;&lt;not2;
gotoxy(15,20);cout&lt;&lt;&quot;Your Reservations have been done Please pay the Amount!!!&quot;;
gotoxy(25,22);cout&lt;&lt;&quot;Amount: Rs.&quot;&lt;&lt;setprecision(2)&lt;&lt;price2;
getch();
}
/**********************************************
FUNTION USED TO VIEW TRANSPORT RECORDS.
**********************************************/
void travelagency::viewtrrec()
{
int option;
while(option!=5)
{
clrscr();
gotoxy(24,5);cout&lt;&lt;&quot;TRANSPORT RESERVATION INFORMATION...&quot;;
gotoxy(25,10);cout&lt;&lt;&quot;choose.....&quot;;
gotoxy(25,12);cout&lt;&lt;&quot;1: View transport reservation records&quot;;
gotoxy(25,14);cout&lt;&lt;&quot;2: Delete a particular record&quot;;
gotoxy(25,16);cout&lt;&lt;&quot;3: Search for a record&quot;;
gotoxy(25,18);cout&lt;&lt;&quot;4: Edit a record &quot;;
gotoxy(25,20);cout&lt;&lt;&quot;5: Exit... &quot;;
cin&gt;&gt;option;
switch(option)
{
case 1:showtransportrec();
break;
case 2:deltransportrec();
break;
case 3:searchtransportrec();
break;
case 4:edittransportdata();
break;
} } }
/**********************************************
FUNTION USED TO SHOW ALL TRANSPORT RECORDS.
**********************************************/
void travelagency::showtransportrec()
{
fstream file1;
file1.open(&quot;transport.dat&quot;,ios::binary|ios::in);
while(file1.read((char*)&amp;user,sizeof (user)))
user.showtransport();
file1.close();
}
/**********************************************
FUNTION USED TO DELETE A TRANSPORT RECORDS.
**********************************************/
void travelagency::deltransportrec()
{
clrscr();
char delname[20];
gotoxy(20,5);cout&lt;&lt;&quot;Enter name to delete record for...&quot;;
gotoxy(30,7);gets(delname);
strupr(delname);
fstream file2,file3;
int dele=0;
file2.open(&quot;transport.dat&quot;,ios::binary | ios::in);


file3.open(&quot;temp3.dat&quot;,ios::binary | ios::out );
while(file2.read ((char*)&amp;user,sizeof (user)))
{
if ((strcmp(name,delname))!=0)
file3.write((char*)&amp;user,sizeof (user));
else
dele++;
}
if(dele!=0)
cout&lt;&lt;endl&lt;&lt;&quot; ...Deleted...&quot;;
else
cout&lt;&lt;endl&lt;&lt;&quot; Record not found..&quot;;
getch();
file2.close();
file3.close();
transfertransportdata();
}
/**********************************************
FUNTION USED TO TRANSFER UNDELETED TRANSPORT RECORDS.
**********************************************/
void travelagency::transfertransportdata()
{
fstream oldfile1,newfile1;
oldfile1.open(&quot;temp3.dat&quot;,ios::binary | ios::in);
newfile1.open(&quot;transport.dat&quot;,ios::binary | ios::out);
while(oldfile1.read((char*)&amp;user,sizeof(user)))
newfile1.write((char*)&amp;user,sizeof (user));
oldfile1.close();



newfile1.close();
}
/**********************************************
FUNTION USED TO SEARCH FOR A TRANSPORT RECORDS.
**********************************************/
void travelagency::searchtransportrec()
{
clrscr();
char sename[20];
gotoxy(20,5);cout&lt;&lt;&quot;Enter Name to search for..&quot;;
gotoxy(25,7);gets(sename);
strupr(sename);
fstream file4;
file4.open(&quot;transport.dat&quot;,ios::binary | ios::in);
int serch=0;
while(file4.read((char*)&amp;user,sizeof (user)))
{
if(strcmp(name,sename)==0)
{
serch++;
user.showtransport();
}
}
if(serch==0)
cout&lt;&lt;&quot; No Record Exists&quot;;
file4.close();
getch();
}



/**********************************************
FUNTION USED TO EDIT TRANSPORT RECORD.
**********************************************/
void travelagency::edittransportdata()
{
clrscr();
char edname[30];
int ede1=0;
gotoxy(20,5);cout&lt;&lt;&quot;Enter Name to Edit Record for...&quot;;
gotoxy(25,7);gets(edname);
strupr(edname);
fstream file5,file6;
file5.open(&quot;transport.dat&quot;,ios::binary | ios::in) ;
file6.open(&quot;temp2.dat&quot;,ios::binary | ios::out ) ;
while(file5.read((char*)&amp;user,sizeof(user)))
{
if (strcmp (edname,name)==0)
{
restr();
ede1++;
}
file6.write((char*)&amp;user,sizeof (user));
}
if(ede1==0)
{
gotoxy(25,17);cout&lt;&lt;&quot;RECORD DOESNT EXIST!!!!&quot;;
}
getch();


file5.close();
file6.close();
transfertransportdata1(); //TO TRANSFER EDITED TRANSPORT RECORD
}
/**********************************************
FUNTION USED TO TRASFER EDITED TRANSPORT RECORDS.
**********************************************/
void travelagency::transfertransportdata1()
{
fstream oldfile3,newfile3;
oldfile3.open(&quot;temp2.dat&quot;,ios::binary | ios::in);
newfile3.open(&quot;transport.dat&quot;,ios::binary | ios::out);
while(oldfile3.read((char*)&amp;user,sizeof(user)))
newfile3.write((char*)&amp;user,sizeof (user));
oldfile3.close();
newfile3.close();
}
/*________________________________________________________________________________
_____________*********************************************************************
***************/

/**********************************************
MAIN FUNTION
USED TO CALL OTHER FUNTIONS
**********************************************/
/*________________________________________________________________________________
_____________*********************************************************************
***************/
void main()
{
clrscr();


cout.setf(ios::fixed,ios::floatfield);
cout.setf(ios::showpoint);
startup(); //FUNTION TO DISPLAY INTRODUCTION SCREEN
int opt;
while(opt!=5)
{
opt=opening1(); //FUNTION CALL TO DISPLAY MENU
switch(opt)
{
case 1:places(); //FUNTION CALL TO VIEW PLACES
break;
case 2: //FUNTION CALL TO RESERVE TRANSPORT
maketrfile();i++;
break;
case 3: //FUNTION CALL TO RESERVE HOTEL
makehofile();i++;
break;
case 4:clrscr();
int search1;
gotoxy(25,15);cout&lt;&lt;&quot;Enter 1 or 2&quot;;
gotoxy(25,17);cout&lt;&lt;&quot;1: Hotel Reservation Records&quot;;
gotoxy(25,19);cout&lt;&lt;&quot;2: Transport Reservation Records&quot;;
gotoxy(25,21);cout&lt;&lt;&quot;??.....&quot;;cin&gt;&gt;search1;
switch(search1)
{
case 1:user.viewhorec(); //FUNTION CALL FOR HOTEL RECORDS
break;
case 2:user.viewtrrec(); //FUNTION CALL FOR TRANSPORT RECORDS


break;
}
break;
} } }
/**********************************************
FUNTION USED TO MAKE TRANSPORT RECORD.
**********************************************/
void maketrfile()
{
fstream fil;
fil.open(&quot;transport.dat&quot;,ios::binary | ios::out |ios::app);
user1[i].toggle=1;
user1[i].restr();
fil.write((char*)&amp;user1[i],sizeof (user1[i]));
fil.close();
}
/**********************************************
FUNTION USED TO MAKE HOTEL RECORD.
**********************************************/
void makehofile()
{
fstream fil;
fil.open(&quot;hotel.dat&quot;,ios::binary | ios::out |ios::app );
user1[i].toggle=1;
user1[i].resho();
fil.write((char*)&amp;user1[i],sizeof (user1[i]));
fil.close();
}

/**********************************************
FUNTION USED TO DISPLAY INTRODUCTION SCREEN
**********************************************/
void startup()
{
int a;
for(a=50;a&gt;30;a--)
{
clrscr();
textcolor(GREEN);
textbackground(BLUE);
gotoxy(25,10);cout&lt;&lt;&quot;Welcome to the TRAVEL AGENCY&quot;;
gotoxy(a,12);cout&lt;&lt;&quot; HawK Prsents .... &quot;;
delay(50);
}
for(a=42;a&lt;52;a++)
{
gotoxy(27,18);cout&lt;&lt;&quot;Please Wait&quot;;
gotoxy(a,18);cout&lt;&lt;&quot;.&quot;;
delay(400);
}
clrscr();
textcolor(GREEN );
for(int j=0;j&lt;10;j++)
{
clrscr();
gotoxy(j,6); cputs(&quot; อออออออออออออออออออออออออ&quot;);
gotoxy(j,7); cputs(&quot; ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ ÜÜÜÜÜÜ&quot;);


gotoxy(j,8); cputs(&quot; Û Û Û Û Û&quot;);
gotoxy(j,9); cputs(&quot; Û ÛÜÜÜÛ ÛÜÜÜÜÛ&quot;);
gotoxy(j,10);cputs(&quot; Û Û Û Û Û&quot;);
gotoxy(j,11);cputs(&quot; Û Û ÛÛ Û Û&quot;);

gotoxy(51-j,6); cputs(&quot;อออออออออออออออออออออ \n\r&quot;);
gotoxy(51-j,7); cputs(&quot; Ü Ü ÜÜÜÜÜÜ Ü \n\r&quot;);
gotoxy(51-j,8); cputs(&quot; Û Û Û Û \n\r&quot;);
gotoxy(51-j,9); cputs(&quot; Û Û ÛÜÜÜ Û \n\r&quot;);
gotoxy(51-j,10);cputs(&quot; Û Û Û Û \n\r&quot;);
gotoxy(51-j,11);cputs(&quot; ÛÛ ÛÛÛÛÛÛ ÛÛÛÛ \n\r\n\n&quot;);

gotoxy(j,12);cputs(&quot; ÜÜÜÜÜÜÜ Ü Ü&quot;);
gotoxy(j,13);cputs(&quot; Û ÛÛ Û&quot;);
gotoxy(j,14);cputs(&quot; Û Û Û Û&quot;);
gotoxy(j,15);cputs(&quot; Û Û Û Û&quot;);
gotoxy(j,16);cputs(&quot; ÜÜÜÛÜÜÜ Û ÛÛ&quot;);
gotoxy(j,17);cputs(&quot; อออออออออออออออออออ&quot;);
gotoxy(58-j,12);cputs(&quot; ÜÜÜÜÜÜ ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ \n\r&quot;);
gotoxy(58-j,13);cputs(&quot; Û Û Û Û Û \n\r&quot;);
gotoxy(58-j,14);cputs(&quot; Û Û Û ÛÜÜÜÜÛ \n\r&quot;);
gotoxy(58-j,15);cputs(&quot; Û Û Û Û Û \n\r&quot;);
gotoxy(58-j,16);cputs(&quot; ÛÜÜÜÜÛ ÜÜÜÛÜÜÜ Û Û \n\r&quot;);
gotoxy(58-j,17);cputs(&quot;อออออออออออออออออออออออออออ \n\r&quot;);
delay(80);
}
gotoxy(25,25);
cout&lt;&lt;&quot;press any key to continue...&quot;;


getch();
}
/**********************************************
FUNTION USED TO DISPLAY MENU.
**********************************************/
int opening1()
{
int pass;
clrscr();
for(int f=0;f&lt;6;f++)
{
clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(10,f);cout&lt;&lt;&quot;WELLCOME!!!!!!......&quot;

&quot;What would you like us to do for you&quot;;
gotoxy(15,f+3);cout&lt;&lt;&quot;1: View Tourist Places&quot;;
gotoxy(15,f+5);cout&lt;&lt;&quot;2: Reserve Transportation&quot;;
gotoxy(15,f+7);cout&lt;&lt;&quot;3: Reserve Accomodation&quot;;
gotoxy(15,f+9);cout&lt;&lt;&quot;4: View Existing Bookings&quot;;
gotoxy(15,f+11);cout&lt;&lt;&quot;5: Exit&quot;;
gotoxy(13,f+14);cout&lt;&lt;&quot;Enter (1,2,3,4 or 5)....? &quot;;
delay(100);
}
for(f=1;f&lt;13;f++)
{
gotoxy(3,f);cout&lt;&lt;&quot;ฮ&quot;;gotoxy(80,f);cout&lt;&lt;&quot;ฮ&quot;;
gotoxy(3,25-f);cout&lt;&lt;&quot;ฮ&quot;;gotoxy(80,25-f);cout&lt;&lt;&quot;ฮ&quot;;


delay(50);
}
gotoxy(40,19);cin&gt;&gt;pass;
return(pass);
}
void opening2() //function to display menu with places
{
int opt2;
gotoxy(10,21);cout&lt;&lt;&quot;1: Reserve Transportation&quot;;
gotoxy(10,22);cout&lt;&lt;&quot;2: Reserve Accomodation&quot;;
gotoxy(10,23);cout&lt;&lt;&quot;3: Reserve Transportation and Accomodation&quot;;
gotoxy(10,24);cout&lt;&lt;&quot;4: Exit ???.... &quot;;cin&gt;&gt;opt2;
if (opt2!=4)
{
switch(opt2)
{
case 1:maketrfile();i++;
break;
case 2:makehofile();i++;
break;
case 3:maketrfile();i++;
makehofile();i++;
break;
} } }
/**********************************************
FUNTION USED TO DISPLAY CHOICE OF DESTINATION.
**********************************************/
void places()


{
int des;
for(int j=0;j&lt;20;j++)
{
clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Choose Destination&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;
gotoxy(j,11);cout&lt;&lt;&quot;บ 1.NORTH INDIA บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ 2.SOUTH INDIA บ &quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 3.EAST INDIA บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 4.WEST INDIA บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ 5.CENTRAL INDIA บ &quot;&lt;&lt;endl;
gotoxy(j,16);cout&lt;&lt;&quot;บ 6.EXIT บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;.....? บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;
delay(50);
}
gotoxy(45,17);cin&gt;&gt;des;
int des1;
if (des!=6)
{
switch(des)
{
case 1: for(j=0;j&lt;20;j++)
{
clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Where do you want go......&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;


gotoxy(j,11);cout&lt;&lt;&quot;บ 1.JAMMU &amp; KASHMIR บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ 2.HARYANA บ &quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 3.PUNJAB บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 4.HIMACHAL PRADESH บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ 5.EXIT บ &quot;&lt;&lt;endl;
gotoxy(j,16);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;...... บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;
delay(50);
}
gotoxy(45,17);cin&gt;&gt;des1;
if(des1!=5)
user.nindia(des1);
break;

case 2: for(j=0;j&lt;20;j++)
{
clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Where do you want go......&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;
gotoxy(j,11);cout&lt;&lt;&quot;บ 1.KERELA บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ 2.TAMIL NADU บ&quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 3.ANDHRA PRADESH บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 4.MAHARASHTRA บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ 5.ANDAMAN AND NICOBAR บ &quot;&lt;&lt;endl;
gotoxy(j,16);cout&lt;&lt;&quot;บ 6.EXIT บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;...... บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;


delay(50);
}
gotoxy(45,17);cin&gt;&gt;des1;
if(des1!=6)
user.sindia(des1);
break;
case 3: for(j=0;j&lt;20;j++)
{
clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Where do you want go......&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;
gotoxy(j,11);cout&lt;&lt;&quot;บ 1.ASSAM บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ 2.ARUNACHAL PRADESH บ&quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 3.BIHAR บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 4.WEST BENGAL บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ 5.UTTAR PRADESH บ &quot;&lt;&lt;endl;
gotoxy(j,16);cout&lt;&lt;&quot;บ 6.EXIT บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;...... บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;
delay(50);
}
gotoxy(45,17);cin&gt;&gt;des1;
if(des1!=6)
user.eindia(des1);
break;

case 4: for(j=0;j&lt;20;j++)
{



clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Where do you want go......&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;
gotoxy(j,11);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ 1.GUJARAT บ&quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 2.RAJASTHAN บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 3.EXIT บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,16);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;...... บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;
delay(50);
}
gotoxy(45,17);cin&gt;&gt;des1;
if(des1!=3)
user.windia(des1);
break;

case 5: for(j=0;j&lt;20;j++)
{
clrscr();
gotoxy(j+3,5);cout&lt;&lt;&quot;Where do you want go......&quot;;
gotoxy(j,10);cout&lt;&lt;&quot;ษอออออออออออออออออออออออออออออออป &quot;&lt;&lt;endl;
gotoxy(j,11);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,12);cout&lt;&lt;&quot;บ บ&quot;&lt;&lt;endl;
gotoxy(j,13);cout&lt;&lt;&quot;บ 1.ORISSA บ &quot;&lt;&lt;endl;
gotoxy(j,14);cout&lt;&lt;&quot;บ 2.MADHYA PRADESH บ &quot;&lt;&lt;endl;
gotoxy(j,15);cout&lt;&lt;&quot;บ 3.EXIT บ &quot;&lt;&lt;endl;



gotoxy(j,16);cout&lt;&lt;&quot;บ บ &quot;&lt;&lt;endl;
gotoxy(j,17);cout&lt;&lt;&quot;บ ??ENTER CHOICE&gt;&gt;...... บ &quot;&lt;&lt;endl;
gotoxy(j,18);cout&lt;&lt;&quot;ศอออออออออออออออออออออออออออออออะ &quot;&lt;&lt;endl;
delay(50);
}
gotoxy(45,17);cin&gt;&gt;des1;
if(des1!=3)
user.cindia(des1);
break;
} } }
/**********************************************
FUNTION USED TO DISPLAY NORTH-INDIA INFORMATION.
**********************************************/
void travelagency::nindia(int ndes)
{
switch(ndes)
{
case 1:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot;Jammu and Kashmir &quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Kashmir- -Jammu- &quot;&lt;&lt;&quot;\n&quot;;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; BY Air kash. 041 I.A. 12000Rs. 9000Rs. 13:50(d)-15:30(a)&quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; BY Air jam. 042 I.A. 12000Rs. 9000Rs. 8:00(d)- 9:40(a)&quot;&lt;&lt;&quot;\n&quot;; cout&lt;&lt;&quot;
BY Train kash. Kashmir Express 2500Rs. 2000Rs. 13:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train jam. Jammu Mail 2500Rs. 2000Rs. 15:00(d)-16:30(a)&quot;&lt;&lt;&quot;\n&quot;;



cout&lt;&lt;&quot; By Road kash. Bus 700Rs. 500Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; By Road jam. Bus 700Rs. 500Rs. 14:00(d)-15:00(a)&quot;&lt;&lt;&quot;\n&quot;;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; 5 kash Kashmir 5000Rs 3000Rs &quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; 5 jam holiday 5000Rs. 3000Rs. &quot;&lt;&lt;&quot;\n&quot;; cout&lt;&lt;&quot; 3 kash
queen 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 jam passenger 3000Rs. 1500Rs. &quot;&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; normal kash rest 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal jam guest 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 2:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; HARYANA&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Chandigarh- -Gurgaon- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air chan. 051 I.A. 10000Rs. 8000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air chan. 052 I.A. 10000Rs. 8000Rs. 7:00(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train chan. Haryana Express 1500Rs. 1000Rs. 13:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train gur. Punjab Mail 1500Rs. 1000Rs. 14:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road chan. Bus 300Rs. 200Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road gur. Bus 300Rs. 200Rs. 14:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 chan taj 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 gur broadway 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 chan king 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 gur resort 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal chan sarai 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal gur star 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 3:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; PUNJAB&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Amritsar- -Ludhiana- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air amr. 051 I.A. 8000Rs. 6000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air lud. 052 I.A. 8000Rs. 6000Rs. 5:00(d)- 5:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train amr. Haryana Express 1200Rs. 1000Rs. 13:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train lud. Punjab Mail 1200Rs. 1000Rs. 14:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road amr. Bus 300Rs. 200Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road lud. Bus 300Rs. 200Rs. 14:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;



cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 amr Nanda 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 lud Shiraz 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 amr Amaitas 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 lud Gulmor 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal amr salam 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal lud stars 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 4:clrscr();
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(25,1);cout&lt;&lt;&quot; HIMACHAL PRADESH&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Shimla- -Manali- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air shi. 151 I.A. 10000Rs. 8000Rs. 12:30(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air man. 152 I.A. 10000Rs. 8000Rs. 6:50(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train shi. Himachal Express 2000Rs. 1000Rs. 13:00(d)-19:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train man. kalka Mail 2000Rs. 1000Rs. 14:00(d)-19:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road shi. Bus 800Rs. 500Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road man. Bus 800Rs. 500Rs. 14:00(d)-20:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;


cout&lt;&lt;&quot; 5 shi chamba 4000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 man chanakya 4000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 shi geetanjali 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 man parkview 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal shi guesthouse 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal man mountview 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
opening2();
break;
} }
/**********************************************
FUNTION USED TO DISPLAY SOUTH-INDIA INFORMATION.
**********************************************/
void travelagency::sindia(int sdes)
{
switch(sdes)
{
case 1:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; KERELA &quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Trivandram- -Kochi- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air tri. 141 I.A. 15000Rs. 12000Rs. 13:50(d)-16:30(a)&quot;&lt;&lt;endl;


cout&lt;&lt;&quot; BY Air koc. 142 I.A. 15000Rs. 12000Rs. 8:00(d)-11:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train tri. Kerela Express 3500Rs. 2000Rs. 06:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train koc. Jammu Mail 3500Rs. 2000Rs. 05:00(d)-16:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road tri. Bus 1200Rs. 700Rs. 05:00(d)-22:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road koc. Bus 1200Rs. 700Rs. 05:00(d)-23:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 tri Manor 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 koc holiday 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 tri South park 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 koc passenger 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal tri nest 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal koc Jas 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=15000;atr2=12000;ttr1=3500;ttr2=2000;rtr1=1200;rtr2=700;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 2:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; TAMIL NADU&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Chennai- -Bangalore- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Che. 181 I.A. 12000Rs. 10000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Ban. 182 I.A. 12000Rs. 10000Rs. 7:00(d)- 7:40(a)&quot;&lt;&lt;endl;


cout&lt;&lt;&quot; BY Train Che. Madras Express 2500Rs. 1500Rs. 08:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Ban. Madurai Mail 2500Rs. 1500Rs. 09:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Che. Bus 800Rs. 500Rs. 05:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Ban. Bus 800Rs. 500Rs. 06:00(d)-22:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 che taj 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 ban roadway 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 che king 2500Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 ban resort 2500Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal che salam 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal ban hoshu 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=12000;atr2=10000;ttr1=2500;ttr2=1500;rtr1=800;rtr2=500;
fst1=5000;fst2=3000;tst1=2500;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 3:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; ANDHRA PRADESH&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Hyderabad- -Nagpur- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Hyd. 081 I.A. 9000Rs. 7000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Nag. 082 I.A. 9000Rs. 7000Rs. 5:00(d)- 5:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Hyd. hyderabad Express 1200Rs. 1000Rs. 08:00(d)-18:00(a)&quot;&lt;&lt;endl;


cout&lt;&lt;&quot; By Train Nag. Andhra Mail 1200Rs. 1000Rs. 09:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Hyd. Bus 700Rs. 500Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Nag. Bus 700Rs. 500Rs. 06:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Hyd Palace 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Nag Lodge 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Hyd Siddharth 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Nag Yatri 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Hyd salem 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Nag Parklane 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=9000;atr2=7000;ttr1=1200;ttr2=1000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 4:clrscr();
textcolor(RED);
textbackground(GREEN);
gotoxy(25,1);cout&lt;&lt;&quot; MAHARASTRA&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Mumbai- -Pune- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Mum. 351 I.A. 11000Rs. 9000Rs. 12:30(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Pun. 352 I.A. 11000Rs. 9000Rs. 6:50(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Mum. Rajdhani Express 2000Rs. 1000Rs. 10:00(d)-19:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Pun. Pune Mail 2000Rs. 1000Rs. 10:00(d)-19:30(a)&quot;&lt;&lt;endl;


cout&lt;&lt;&quot; By Road Mum. Bus 800Rs. 500Rs. 09:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Pun. Bus 800Rs. 500Rs. 09:00(d)-20:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Mum Centaur 5000Rs 4000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Pun Holiday inn 5000Rs. 4000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Mum Clarks 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Pun seaview 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Mum guesthouse 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Pun niceview 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=11000;atr2=9000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=5000;fst2=4000;tst1=3000;tst2=1500;nst1=800;nst2=500;
opening2();
break;
case 5:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot;ANDAMAN AND NICOBAR&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;-------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Port Blair- -Rangat- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air P.b. 151 I.A. 15000Rs. 12000Rs. 12:30(d)-16:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Ran. 152 I.A. 15000Rs. 12000Rs. 6:50(d)- 9:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Ship P.b. Ship 2000Rs. 1000Rs. 13:00(d)-19:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Ship Ran. Ship 2000Rs. 1000Rs. 14:00(d)-19:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road P.b. N.a. &quot;&lt;&lt;endl;

56

cout&lt;&lt;&quot; By Road Ran. N.a. &quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 P.b. chamba 4000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Ran chanakya 4000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 P.b. geetanjali 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Ran parkview 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal P.b. guest 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Ran nanny 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=15000;atr2=12000;ttr1=2000;ttr2=1000;rtr1=0;rtr2=0;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
opening2();
break;
} }
/**********************************************
FUNTION USED TO DISPLAY EAST-INDIA INFORMATION.
**********************************************/
void travelagency::eindia(int edes)
{
switch(edes)
{
case 1:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; ASSAM &quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Guwahati- &quot;&lt;&lt;endl;

57

gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Guw. 045 I.A. 12000Rs. 9000Rs. 11:50(d)-15:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Guw. 045 I.A. 12000Rs. 9000Rs. 6:00(d)- 9:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Guw. Assam Express 2500Rs. 2000Rs. 08:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Guw. Guwahati Mail 2500Rs. 2000Rs. 09:00(d)-16:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Guw. Bus 700Rs. 500Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Guw. Bus 700Rs. 500Rs. 14:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Guw Ashoka 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Guw Regency 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Guw Kuber 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Guw Nandan 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Guw Home 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Guw Corneto 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 2:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; ARUNACHAL PRADESH&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;-------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Itanagar- -Bomdila- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;

58
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Ita . 751 I.A. 11000Rs. 9000Rs. 07:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Bom. 752 I.A. 11000Rs. 9000Rs. 07:00(d)-10:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Ita. Arunachal Express 4500Rs. 2000Rs. 05:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Bom. Bomdila Mail 4500Rs. 2000Rs. 04:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Ita. Bus 800Rs. 600Rs. 04:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Bom. Bus 800Rs. 600Rs. 02:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Ita Ganga 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Bom Himalaya 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Ita Hornbill 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Bom resort 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Ita sarai 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Bom star 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=11000;atr2=9000;ttr1=4500;ttr2=2000;rtr1=800;rtr2=600;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 3:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; BIHAR&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Patna- -Gaya- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;

59
cout&lt;&lt;&quot; BY Air Pat. 091 I.A. 8000Rs. 6000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Gay. 092 I.A. 8000Rs. 6000Rs. 5:00(d)- 5:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Pat. Patna Express 1200Rs. 1000Rs. 13:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Gay. Gaya Mail 1200Rs. 1000Rs. 14:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Pat. Bus 300Rs. 200Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Gay. Bus 300Rs. 200Rs. 14:00(d)-23:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Pat Patliputra 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Gay Ashok 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Pat Chaitanya 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Gay Mayur 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Pat satkar 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Gay marwari 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 4:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; WEST BENGAL&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Calcutta- -Darjiling- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Cal. 451 I.A. 12000Rs. 10000Rs. 12:30(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Dar. 452 I.A. 12000Rs. 10000Rs. 6:50(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Cal. Rajdhani Express 2000Rs. 1000Rs. 08:00(d)-19:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Dar. kalka Mail 2000Rs. 1000Rs. 09:00(d)-19:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Cal. Bus 800Rs. 500Rs. 05:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Dar. Bus 800Rs. 500Rs. 06:00(d)-20:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Cal Continental 4000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Dar Diplomat 4000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Cal geetanjali 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Dar parkview 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Cal guesthouse 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Dar Paragon 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=12000;atr2=10000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
opening2();
break;
case 5:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; UTTAR PRADESH&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;-------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Lucknow- -Kanpur- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Luc. 121 I.A. 10000Rs. 8000Rs. 12:30(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Kan. 122 I.A. 10000Rs. 8000Rs. 6:50(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Luc. Shatabdi Express 2000Rs. 1000Rs. 13:00(d)-19:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Kan. Frontier Mail 2000Rs. 1000Rs. 14:00(d)-19:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Luc. Bus 800Rs. 500Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Kan. Bus 800Rs. 500Rs. 14:00(d)-20:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Luc Shilton 4000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Kan Plaza 4000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Luc Lindsay 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Kan Minerva 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Luc Fairlawn 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Kan Executive 800Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
opening2();
break;
} }|
/**********************************************
FUNTION USED TO DISPLAY WEST-INDIA INFORMATION.
**********************************************/
void travelagency::windia(int wdes)
{
switch(wdes)
{
case 1:clrscr();
textcolor(RED);
textbackground(YELLOW);



gotoxy(25,1);cout&lt;&lt;&quot; GUJARAT &quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Ahmedabad- -Gandhinagar- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Ahm. 045 I.A. 12000Rs. 9000Rs. 13:50(d)-15:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Gan. 045 I.A. 12000Rs. 9000Rs. 8:00(d)- 9:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Ahm. Ahmedabad Express 2500Rs. 2000Rs. 11:00(d)-
18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Gan. Gujarat Mail 2500Rs. 2000Rs. 12:00(d)-16:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Ahm. Bus 700Rs. 500Rs. 09:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Gan. Bus 700Rs. 500Rs. 10:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Ahm Royal 4000Rs 2000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Gan Kingfort 4000Rs. 2000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Ahm Kinshu 2000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Gan Rama 2000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Ahm best 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Gan jesture 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=4000;fst2=2000;tst1=2000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
case 2:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; RAJASTHAN&quot;;



gotoxy(24,2);cout&lt;&lt;&quot;-------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Jaipur- -Jodhpur- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Jai. 351 I.A. 10000Rs. 8000Rs. 12:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Jod. 352 I.A. 10000Rs. 8000Rs. 7:00(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Jai. Pinkcity Express 1500Rs. 1000Rs. 13:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Jod. Avadh Mail 1500Rs. 1000Rs. 14:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Jai. Bus 300Rs. 200Rs. 12:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Jod. Bus 300Rs. 200Rs. 14:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Jai Clarks 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Jod Rajputana 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Jai copperchimney 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Jod resort 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Jai dholamaru 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Jod Rajstar 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();
break;
} }
/**********************************************
FUNTION USED TO DISPLAY CENTRAL-INDIA INFORMATION.
**********************************************/
void travelagency::cindia(int cdes)



{
switch(cdes)
{
case 1:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; ORISSA &quot;;
gotoxy(24,2);cout&lt;&lt;&quot;------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Bhubaneshwar- -Cuttack- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Bhub. 091 I.A. 13000Rs. 10000Rs. 13:50(d)-17:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Cutt. 092 I.A. 13000Rs. 10000Rs. 8:00(d)-11:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Bhub. Puri Express 2500Rs. 2000Rs. 04:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Cutt. Mundu Mail 2500Rs. 2000Rs. 07:00(d)-16:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Bhub . Bus 700Rs. 500Rs. 03:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Cutt. Bus 700Rs. 500Rs. 07:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Bhub Janpath 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Cutt Lingraj 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Bhub Prachi 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Cutt Keshari 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Bhub Anarkali 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Cutt Pushpak 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=13000;atr2=10000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;



opening2();
break;
case 2:clrscr();
textcolor(RED);
textbackground(YELLOW);
gotoxy(25,1);cout&lt;&lt;&quot; MADHYA PRADESH&quot;;
gotoxy(24,2);cout&lt;&lt;&quot;--------------------&quot;;
gotoxy(20,3);cout&lt;&lt;&quot;Places To Visit:: -Bhopal- -Gwalior- &quot;&lt;&lt;endl;
gotoxy(5,4);cout&lt;&lt;&quot;Transportation Available::(from delhi)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; MODE Place NAME Price:Executive Economy Timings &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Bhop. 061 I.A. 10000Rs. 8000Rs. 11:50(d)-13:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Air Gwal. 062 I.A. 10000Rs. 8000Rs. 6:00(d)- 7:40(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; BY Train Bhop. Deccan Express 1500Rs. 1000Rs. 11:00(d)-18:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Train Gwal. Gwalior Mail 1500Rs. 1000Rs. 07:00(d)-14:30(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Bhop. Bus 300Rs. 200Rs. 07:00(d)-20:00(a)&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; By Road Gwal. Bus 300Rs. 200Rs. 08:00(d)-15:00(a)&quot;&lt;&lt;endl;
gotoxy(5,12);cout&lt;&lt;&quot;Accomodation Available::&quot;&lt;&lt;endl;
cout&lt;&lt;&quot; Star Place NAME Of Hotel Tariff: Deluxe Non-deluxe &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Bhop taj 5000Rs 3000Rs &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 5 Gwal fortview 5000Rs. 3000Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Bhop metro 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; 3 Gwal president 3000Rs. 1500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Bhop shelter 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;&quot; normal Gwal safari 1000Rs. 500Rs. &quot;&lt;&lt;endl;
cout&lt;&lt;setw(10)&lt;&lt;&quot; NOTE::(The Tarrif does not include meals except breakfast) &quot;;
atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
opening2();



break;
} }
/**********************************************
FUNTION USED TOASSIGN PRICE ACCORDING TO DESTINATION.
**********************************************/
void travelagency::assignprice()
{
clrscr();
textcolor(YELLOW);
textbackground(BLUE);
int toasspri;
gotoxy(20,2);cout&lt;&lt;&quot;PLEASE CHOOSE YOUR DESTINATION..&quot;;
gotoxy(5,5);cout&lt;&lt;&quot;1:Kashmir or Jammu 2:Chandigarh or Gurgaon&quot;;
gotoxy(5,7);cout&lt;&lt;&quot;3:Amritsar or Ludhiana 4: Shimla or Manali&quot;;
gotoxy(5,9);cout&lt;&lt;&quot;5:Trivandrum or Kochi 6: Chennai or Bangalore&quot;;
gotoxy(5,11);cout&lt;&lt;&quot;7:Hyderabad or Nagpur 8: Mumbai or Pune &quot;;
gotoxy(5,13);cout&lt;&lt;&quot;9:Port blair or Rangat 10: Guwahati&quot;;
gotoxy(5,15);cout&lt;&lt;&quot;11:Itanagar or Bomdila 12: Patna or Gaya &quot;;
gotoxy(5,17);cout&lt;&lt;&quot;13:Calcutta or Darjiling 14: Lucknow or Kanpur &quot;;
gotoxy(5,19);cout&lt;&lt;&quot;15:Ahmedabad or Gandhinagar 16: Jaipur or Jodhpur &quot;;
gotoxy(5,21);cout&lt;&lt;&quot;17:Bhubneshwar or Cuttack 18: Bhopal or Gwalior &quot;;
gotoxy(5,23);cout&lt;&lt;&quot;Enter (1-18) to Reserve ...&quot;;
gotoxy(45,23);cin&gt;&gt;toasspri;
switch(toasspri)
{
case 1:atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;



case 2:atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 3:atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 4:atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
break;
case 5:atr1=15000;atr2=12000;ttr1=3500;ttr2=2000;rtr1=1200;rtr2=700;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 6:atr1=9000;atr2=7000;ttr1=1200;ttr2=1000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 7:atr1=9000;atr2=7000;ttr1=1200;ttr2=1000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 8:atr1=11000;atr2=9000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=5000;fst2=4000;tst1=3000;tst2=1500;nst1=800;nst2=500;
break;
case 9:atr1=15000;atr2=12000;ttr1=2000;ttr2=1000;rtr1=0;rtr2=0;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
break;
case 10:atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 11:atr1=11000;atr2=9000;ttr1=4500;ttr2=2000;rtr1=800;rtr2=600;



fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 12:atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 13:atr1=12000;atr2=10000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
break;
case 14:atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
break;
case 15:atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=4000;fst2=2000;tst1=2000;tst2=1500;nst1=1000;nst2=500;
break;
case 16:atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 17:atr1=13000;atr2=10000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
case 18:atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
break;
}
}
