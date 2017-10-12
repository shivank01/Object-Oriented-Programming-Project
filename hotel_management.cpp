#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define cp(str); printf(str)     


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

class hotel
{
    long d,m,y,nom,n,r,rno;
    char name[40],address[80],a[20],pno[20];

public:
    
    void checkin();
    void search();
    void checkout();
    void food();
};

hotel h;

void gotoxy(int x,int y)
{
   printf("%c[%d;%df",0x1B,y,x);
}


void welcome()
{
    int i,a=12,b=4;
    system("clear");
    gotoxy(30,6);
    cp(MAG"WELCOME"RESET);
    gotoxy(20,12);
    cp(YEL "INTERNATIONAL INSTITUTE\n\t\t   OF INFORMATION TECHNOLOGY\n\t\t\tBHUBANESHWAR"RESET);
    gotoxy(28,15);
    cp(MAG"PROJECT-"RESET);
    gotoxy(22,16);
    cp(YEL"HOTEL MANAGEMENT PROGRAM"RESET);
    gotoxy(14,20);
    cp(MAG"NAME-"RESET);
    cp(YEL "Shivank Pathak"RESET);
    gotoxy(14,22);
    cp(MAG"YEAR-"RESET);
    cp(YEL "2nd"RESET);
    gotoxy(14,24);
    cp(MAG"BRANCH-"RESET);
    cp(YEL "INFORMATION TECHNOLOGY"RESET);
    gotoxy(14,28);
    for(i=0;i<40;++i)
    {gotoxy(a+i,b);
    printf(RED"*"RESET);
    }
    for(i=0;i<40;++i)
    {gotoxy(a+40,b+i);
    printf(RED"*"RESET);
    }
    for(i=0;i<40;++i)
    {gotoxy(a+i,b+35);
    printf(RED"*"RESET);
    }
    for(i=0;i<40;++i)
    {gotoxy(a,b+i);
    printf(RED"*"RESET);
    }
    gotoxy(25,32);
    cp(CYN"PRESS ENTER TO START"RESET);
    getchar();
    system("clear");
}


void hotel::checkin()
{
    int check;
    FILE *f;
    f=fopen("//home//shivank//Desktop//hotel.dat","ab+");
    system("clear");
    gotoxy(5,5);
    cp(BLU"ENTER NAME"RESET);
    gets(name);
    gets(name);
    gotoxy(5,7);
    cp(BLU"ENTER THE NUMBER OF MEMBERS"RESET);
    scanf("%ld",&nom);
    gotoxy(5,9);
    cp(BLU"ENTER YOUR ADDRESS"RESET);
    gets(address);
    gets(address);
    gotoxy(5,11);
    cp(BLU"ENTER YOUR PHONE NUMBER"RESET);
    scanf("%s",pno);
    gotoxy(5,13);
    cp(BLU"ENTER THE NUMBER OF DAYS YOU WANT TO STAY"RESET);
    scanf("%ld",&n);
    gotoxy(5,15);
    cp(BLU"THE TYPE OF ROOM IN WHICH YOU WANT TO STAY IS:"RESET);
    gotoxy(5,17);
    cp(RED"1.DELUXE ROOM");
    gotoxy(5,18);
    cp("2.SUITE");
    gotoxy(5,19);
    cp("3.PARLOUR");
    gotoxy(5,20);
    cp("4.JUNIOR SUITE");
    gotoxy(5,21);
    cp("5.EFFICIENCY ROOM");
    gotoxy(5,22);
    cp("6.HOSPITALITY ROOM"RESET);
    gotoxy(5,23);
    scanf("%d",&check);

    switch(check)
    {case 1:strcpy(a,"DELUXE ROOM");
            break;
    case 2:strcpy(a,"SUITE");
            break;
    case 3:strcpy(a,"PARLOUR");
            break;
    case 4:strcpy(a,"JUNIOUR SUITE");
            break;
    case 5:strcpy(a,"EFFICIENCY ROOM");
            break;
    case 6:strcpy(a,"HOSPITALITY ROOM");
            break;
    default:cp("WRONG INPUT");
    }

    fwrite(&h,sizeof(h),1,f);
 /* struct date d;
    getdate(&d);
    e.d=d.da_day;
    e.m=d.da_mon;
    e.y=d.da_year; */
    gotoxy(10,30);
    cp("THANK YOU");
    getchar();
    getchar();
    fclose(f);
}


void hotel::search()
{
    FILE *f;
    f=fopen("//home//shivank//Desktop//hotel.dat","rb+");
    fread(&h,sizeof(h),1,f);
    char na[20];
    int a=0;
    system("clear");
    gotoxy(5,5);
    cp(BLU"ENTER NAME TO BE SEARCHED"RESET);
    printf("\n");
    gets(na);
    gets(na);
    system("clear");
    while(1)
    {
        if(feof(f))
        break;
        if(strcmp(na,name)==0)
        {
            gotoxy(5,8);
            cp(GRN"NAME="RESET);
            gotoxy(12,8);
            printf("%s",name);
            gotoxy(5,10);
            cp(GRN"NO. OF MEMBERS="RESET);
            gotoxy(19,10);
            printf("%ld",nom);
            gotoxy(5,12);
            cp(GRN"PHONE NUMBER="RESET);
            gotoxy(20,12);
            printf("%s\n",pno);
            /*gotoxy(5,14);
            cp("DATE OF CHECKIN=");
            cout<<e.d<<"/"<<e.m<<"/"<<e.y<<endl;*/
            gotoxy(5,14);
            cp(GRN"NO. OF DAYS TO STAY:"RESET);
            gotoxy(25,14);
            printf("%ld\n",n);
            gotoxy(5,16);
            cp(GRN"TYPE OF ROOM IN WHICH THE PERSON STAYED IS:"RESET);
            gotoxy(40,16);
            printf("%s\n",a);
            a=1;
        }
    fread(&h,sizeof(h),1,f);
    }
    if(a==0)
    {
        cp("NOT FOUND");
    }
    getchar();
    fclose(f);
}


void hotel::checkout()
{
    FILE *f;
    char na[40];
    system("clear");
    gotoxy(5,5);
    cp(BLU"ENTER YOUR NAME"RESET);
    printf("\n");
    gets(na);
    gets(na);
    system("clear");
    gotoxy(10,4);
    cp("BILL\n");
    gotoxy(4,6);
    cp(YEL"NAME:\n"RESET);
    printf(MAG"%s",na);
    gotoxy(4,8);
    cp(YEL"ROOM TYPE:\n"RESET);
    f=fopen("//home//shivank//Desktop//hotel.dat","rb+");
    FILE *f1;
    f1=fopen("//home//shivank//Desktop//tempr.dat","wb+");
    FILE *f2;
    f2=fopen("//home//shivank//Desktop//cht.dat","ab+");
    fread(&h,sizeof(h),1,f);
    while(1)
    {
        if(feof(f))
        break;
        if(strcmp(na,name)==0)
        {
            fwrite(&h,sizeof(h),1,f2);
            gotoxy(15,8);
            printf(MAG"%s"RESET,a);
            gotoxy(4,10);
            cp(YEL"TOTAL AMOUNT TO BE PAID:\n"RESET);
            if(strcmp(a,"DELUXE ROOM"))
            {
                printf("%ld",50000*n);
            }
            else if(strcmp(a,"SUITE"))
            {
                printf("%ld",45000*n);
            }
            else if(strcmp(a,"PARLOUR"))
            {
                printf("%ld",40000*n);
            }
            else if(strcmp(a,"JUNIOUR SUITE"))
            {
                printf("%ld",35000*n);
            }
            else if(strcmp(a,"EFFICIENCY ROOM"))
            {
                printf("%ld",30000*n);
            }
            else if(strcmp(a,"HOSPITALITY ROOM"))
            {
                printf("%ld",25000*n);
            }
        }
        fwrite(&h,sizeof(h),1,f1);
        fread(&h,sizeof(h),1,f);
        }
        fclose(f1);
        rename("hotel.dat","tempr.dat");
        fclose(f2);
        fclose(f);
        gotoxy(10,15);
        cp("THANK YOU");
        getchar();
}


void hotel::food()
{
    system("clear");
    int f,q;
    gotoxy(25,5);

    cp(RED"MENU CARD");
    gotoxy(25,7);
    cp("1.PIZZA");
    gotoxy(25,8);
    cp("2.DOSA");
    gotoxy(25,9);
    cp("3.MOMOS");
    gotoxy(25,10);
    cp("4.DHOKLA"RESET);
    gotoxy(40,5);
    cp(YEL"PRICE");
    gotoxy(40,7);
    cp("RS.500");
    gotoxy(40,8);
    cp("RS.150");
    gotoxy(40,9);
    cp("RS.100");
    gotoxy(40,10);
    cp("RS.300");
    gotoxy(20,30);
    cp("ENTER THE FOOD YOU WANT TO ORDER");
    scanf("%d",&f);
    gotoxy(20,34);
    cp("ENTER THE QUANTITY OF FOOD YOU WANT TO ORDER");
    scanf("%d",&q);
    gotoxy(20,36);
    cp("PAY RS."RESET);
    switch(f)
    {case 1:printf("%d",500*q);
    break;
    case 2:printf("%d",150*q);
    break;
    case 3:printf("%d",100*q);
    break;
    case 4:printf("%d",300*q);
    break;
    default:cp("WRONG INPUT");
    }
    getchar();
    getchar();
}


int main()
{
    
    int y,k,a=29,b=14,i;
    welcome();
    do
    {
        system("clear");

        for(i=0;i<16;++i)
        {
            gotoxy(a+i,b);
            cp(CYN"*");
        }
        for(i=0;i<8;++i)
        {
            gotoxy(a,b+i);
            cp("*");
        }
        for(i=0;i<8;++i)
        {
            gotoxy(a+16,b+i);
            cp("*");
        }
        for(i=0;i<16;++i)
        {
            gotoxy(a+i,b+8);
            cp("*");
        }
        gotoxy(30,15);
        cp(YEL"MAIN MENU:"RESET);
        gotoxy(30,16);
        //tc(CYAN);
        cp(CYN"1.CHECKIN");
        gotoxy(30,17);
        cp("2.CHECKOUT");
        gotoxy(30,18);
        cp("3.SEARCH");
        gotoxy(30,19);
        cp("4.FOOD");
        gotoxy(30,20);
        cp("5.EXIT");
        printf("\n");
        gotoxy(15,25);
        cp(GRN"ENTER YOUR CHOICE"RESET);
        gotoxy(35,25);
        scanf("%d",&y);
        switch(y)
        {
            case 1:h.checkin();
            break;
            case 2:h.checkout();
            break;
            case 3:h.search();
            break;
            case 4:h.food();
            break;
            case 5:system("clear");
            gotoxy(25,14);
            cp(RED"ARE YOU SURE YOU WANT TO EXIT"RESET);
            gotoxy(28,15);
            cp(YEL"1.YES       2.NO"RESET);
            int x;
            scanf("%d",&x);
            if(x!=1)
            y++;
        }
    }while(y!=5);

    
    return(0);
}
