#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
int tday,tmonth,tyear,thour,nd,nm,ny,pt=1,total=0;
struct employee
{
    char name[100];
    char job[50];
    int salary;
    struct employee *left;
    struct employee *right;
}*root;
struct employee1
{
    char name[100];
    char job[50];
    int salary;
};
struct employee1 emp[10]={{"Robin Johanson","Chef",30000},{"James Smith","Cook",26000},{"Maria Garcia","Housekeeping",45000},{"Maria Martinez","Receptionist",52244},{"Wilson Jobs","Housekeeping",24626},{"Martha Wayne","Receptionist",30555},{"Tony Rogers","Attendant",12000},{"Steve Stark","Driver",32000},{"Bob Barton","Chef",42560},{"Nick Fury","Housekeeping",35600}};
struct food
{
    int no;
    char item[50];
    int cost;
    struct food *next;
}*snack,*course,*dess,*temp,*curr;
struct food1
{
    int no;
    char item[50];
    int cost;
}snack1[10],course1[20],dess1[10];
struct revenue1
{
    char month[30];
    int y;
    int m;
    struct revenue1 *next;
}*start,*current,*temp1;
struct revenue
{
    char month[30];
    int y;
    int m;
}s[12]={{"JANUARY",2020,110000},{"FEBRUARY",2020,150000},{"MARCH",2020,125000},{"APRIL",2020,102000},{"MAY",2020,900000},{"JUNE",2020,86000},{"JULY",2020,95000},{"AUGUST",2020,150000},{"SEPTEMBER",2020,82000},{"OCTOBER",2020,80000},{"NOVEMBER",2020,50000}};;
struct bill
{
    char B_type[30];
    int amount;
    struct bill *next;
}*start1,*end1,*current1,*point1;
struct place
{
    char place_name[100];
    float distance;
}place[10]={{"Mahalaxmi Temple",8.9},{"Binkhambi Ganesh Temple",8.4},{"Rankala Lake\t",9.9},{"Jyotiba Temple\t",32.2},{"New Palace\t",10.1},{"Kaneri Math\t",6.6},{"Sidhagiri Museum",6.9},{"Panchaganga River",10.1},{"Panhala Fort\t",29.5},{"Bhavani Mandap\t",8.7}};
struct feature
{
    int room;
    char typ[15];
    int charges;
    int advance;
    int capacity;
    int bed;
    char ac[4];
    char geyser[4];
    char tv[4];
}F[5]={{7,"Special_Delux",1500,750,5,3,"Yes","Yes","Yes"},{4,"Delux",1000,500,5,2,"Yes","Yes","Yes"},{6,"General",750,400,5,2,"No","Yes","No"},{5,"Couple",1000,500,2,1,"No","Yes","Yes"},{6,"Couple_Delux",1500,750,2,1,"Yes","Yes","Yes"}};
struct guest_details
{
    int stay,d,m,y,room_no,members;
    char name[100],address[500],nat[30],email[30],room_type[15],id[20],phone[20];
}det;
struct services
{
    char name[20];
    int cost;
}ser[10]={{"Gym",200},{"Hair Spa",2000},{"Laundry",250},{"Sanitization",500},{"Swimming Pool",200},{"Indoor games",500},{"Vehicle",1000},{"Vehicle+Driver",2000},{"Sauna",1000},{"Massage",700}};
void bill_details(int x,char y[50],int z)
{
    if(z==1)
    {
        current1=(struct bill*)malloc(sizeof(struct bill));
        strcpy(current1->B_type,y);
        current1->amount=x;
        total=total+x;
        if(start1==NULL)
        {
            start1=current1;
            start1->next=NULL;
        }
        else
        {
            point1=start1;
            while(point1->next!=NULL)
            {
                point1=point1->next;
            }
            point1->next=current1;
            current1->next=NULL;
        }
    }
    else
    {
        point1=start1;
        while(point1!=NULL)
        {
            printf("\t\t\t\t\t%s\t\tRs.%2d\n\n",point1->B_type,point1->amount);
            point1=point1->next;
        }
        printf("\n\t\t\t\t\tTotal : Rs. %d\n\n",total);
    }
}
void add_to_customer()
{
    FILE *p;
    p=fopen("customers.csv","a");
    fputc('8',p);
    fputc('\n',p);
    fprintf(p,"%s ,%d,%d,%s , %s , %s , %s , %d/%d/%d ,4",det.name,det.stay,det.members,det.phone,det.email,det.nat,det.room_type,det.d,det.m,det.y);
    fclose(p);
}
void color(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
void welcome()
{
    int x=0;
    next:
    if(x==0)color(189);
    printf(" \n\n\t\t\t\t ___________________________________________________________________________ \n");
    printf("\t\t\t\t|                                                                           |\n");
    printf("\t\t\t\t| $$              $$ $$$$$$  $$        $$$$$   $$$$   $$$$    $$$$  $$$$$$  |\n");
    if(x==0)
    {
        color(177);
        Sleep(500);
    }
    printf("\t\t\t\t|  $$            $$  $$      $$       $$      $$  $$  $$ $$  $$ $$  $$      |\n");
    if(x==0)
    {
        color(178);
        Sleep(500);
    }
    printf("\t\t\t\t|   $$    $$    $$   $$$$$$  $$      $$      $$    $$ $$  $$$$  $$  $$$$$$  |\n");
    if(x==0)
    {
        color(181);
        Sleep(500);
    }
    printf("\t\t\t\t|    $$ $$  $$ $$    $$      $$       $$      $$  $$  $$        $$  $$      |\n");
    if(x==0)
    {
        color(184);
        Sleep(500);
    }
    printf("\t\t\t\t|     $$      $$     $$$$$$  $$$$$$$   $$$$$   $$$$   $$        $$  $$$$$$  |\n");
    printf("\t\t\t\t|___________________________________________________________________________|\n\n ");
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    Sleep(500);
    color(180);
    if(x==0)
    {
        x=1;
        system("cls");
        goto next;
    }
    printf("\t\t\t\t\t\t\tWelcome to Hotel SUNSHINE.\n\n");
    printf("\t\t\t\t\t\t\tPress any key to continue. ");
    getch();
    fflush(stdin);
}
void head_title()
{
    int i;
    for(i=0;i<=9;i++)
    {
        system("cls");
        if(i%2==0)color(191);
        else if(i%3==0)color(177);
        else color(188);
        printf("\n\n\t\t\t\t\t\t\t  ### HOTEL SUNSHINE ###\n\n");
        printf("_________________________________________________________________________________________________________________________________________\n\n");
        Sleep(30);
    }
    color(180);
}
void create_revenue()
{
    int i;
    for(i=0;i<11;i++)
    {
        temp1=(struct revenue1*)malloc(sizeof(struct revenue1));
        temp1->y=s[i].y;
        strcpy(temp1->month,s[i].month);
        temp1->m=s[i].m;
        if(start==NULL)
        {
            start=temp1;
            start->next=NULL;
            current=start;
        }
        else
        {
            current->next=temp1;
            current=current->next;
            current->next=NULL;
        }
    }
}
void revenue()
{
    temp1=start;
    head_title();
    printf("\n\t\t\t\t\t\t\t  REVENUE");
    printf("\n\n\n\t\t\t\t\t   Year\t\tMonth\t\tRevenue\n");
    printf("\t\t\t\t\t  _____________________________________________\n\n\n");
    while(temp1!=NULL)
    {
        printf("\t\t\t\t\t  %d\t%15s\t\tRs.%5d\n\n",temp1->y,temp1->month,temp1->m);
        temp1=temp1->next;
    }
    printf("\n\n\n\t\t\t\t\t( Press any key to continue. ) ");
    getch();
    fflush(stdin);
}
void nearby()
{
    int  i;
    char x;
    head_title();
    printf("\n       \t\t\t\t\t       Place\t\t\t  Distance from Hotel");
    printf("\n       \t\t\t\t\t========================================================\n\n");
    for(i=0;i<10;i++)
    {
        printf("       \t\t\t\t\t%s\t\t%15f km\n\n",place[i].place_name,place[i].distance);
    }
    printf("\n\n\t\t\t\t\tWant any vehicle to travel? (Yes - 1)");
    x=getch();
    fflush(stdin);
    if(x=='1')
    {
        head_title();
        printf("\n\t\t\t\t\t1 - Book a lodge vehicle\n\n\t\t\t\t\t2 - Book a lodge vehicle and a driver\n\n\t\t\t\t\t3 - Ignore   ");
        x=getch();
        fflush(stdin);
        if(x=='1')
        {
            printf("\n\n\t\t\t\t\tA lodge vehicle is booked.");
            bill_details(1000,"Vehicle",1);
            printf("\n\n\t\t\t\t\t(Press any key to continue.)");
            getch();
            fflush(stdin);
        }
        else if(x=='2')
        {
            printf("\n\n\t\t\t\t\tA lodge vehicle and a driver is booked.");
            bill_details(2000,"Vehicle+Driver",1);
            printf("\n\n\t\t\t\t\t(Press any key to continue.)");
            getch();
            fflush(stdin);
        }
    }
}
void customers()
{
    int x2,x3,d,m,y,i;
    char x1[100],x4[100],x5[100],x6[100],x7[100];
    head_title();
    FILE *p;
    p=fopen("customers.csv","r");
    printf("\n\t\t\t\t\t\t\tCustomer Details\n\n\n");
    while(i!=4)
    {
        fscanf(p,"%s ,%d ,%d ,%s ,%s ,%s ,%s ,%d /%d /%d ,%d",x1,&x2,&x3,x4,x5,x6,x7,&d,&m,&y,&i);
        printf("\n\t\t\t\t\t\t Customer Name  :  %s",x1);
        printf("\n\t\t\t\t\t\t Period         :  %d",x2);
        printf("\n\t\t\t\t\t\t No of member   :  %d",x3);
        printf("\n\t\t\t\t\t\t Phone          :  %s",x4);
        printf("\n\t\t\t\t\t\t Email          :  %s",x5);
        printf("\n\t\t\t\t\t\t Nationality    :  %s",x6);
        printf("\n\t\t\t\t\t\t Room Type      :  %s",x7);
        printf("\n\t\t\t\t\t\t Arrival Date   :  %d/%d/%d\n",d,m,y);
        printf("\t\t\t\t\t\t_____________________________________\n\n\n");
    }
    fclose(p);
    printf("\n\n\t\t\t\t\t\t(Press any key to continue.)");
    getch();
    fflush(stdin);
}
void guest_details()
{
    printf("\n Room No        :  %d",det.room_no);
    printf("\n Customer Name  :  %s",det.name);
    printf("\n Period         :  %d",det.stay);
    printf("\n Phone          :  %s",det.phone);
    printf("\n Room Type      :  %d",det.room_type);
    printf("\n Address        :  %d",det.address);
    printf("\n Nationality    :  %s",det.nat);
    printf("\n No of member   :  %d",det.members);
    printf("\n Arrival Date   :  %d/%d/%d",det.d,det.m,det.y);

 }
void today_date()
{
  time_t time2=time(NULL);
  struct tm time1 = *localtime(&time2);
  tday=time1.tm_mday;
  tmonth=time1.tm_mon+1;
  tyear=time1.tm_year+1900;
  thour=time1.tm_hour;
}
int date_check(int d,int m,int y)
{
    if((m>12)||(m<1))
    {
        printf("\n\n\t\t\t\t\tWrong month number entered. Try again.\n\n");
        return 5;
    }
    else if(m==2)
    {
        if(y%4==0)
        {
            if(d>29)
            {
                printf("\n\n\t\t\t\t\tLeap year has only 29 days in February. Try again.\n\n");
                return 5;
            }
        }
        if(d>28)
        {
            printf("\n\n\t\t\t\t\tFebruary has only 28 days. Try again.\n\n");
            return 5;
        }
    }
    else if(m==4||m==6||m==9||m==11)
    {
        if(d>30)
            {
                printf("\n\n\t\t\t\t\tThis month don't have more than 30 days. Try again.\n\n");
                return 5;
            }
    }
    else
    {
        if(d>31)
        {
            printf("\n\n\t\t\t\t\tNo month has more than 31 days. Try again.\n\n");
            return 5;
        }
    }
    return 0;
}
int date_cmp(int d,int m,int y)
{
    if(y==tyear)
    {
        if(m==tmonth)
        {
            if(d>=tday)
            {
                return 3;
            }
        }
        else if(m>tmonth)return 3;
    }
    else if(y>tyear)return 3;
    printf("\n\n\t\t\t\t\tYou have entered some older date.\n\n\t\t\t\t\tToday's date is:  %d / %d / %d\n",tday,tmonth,tyear);
    return 8;
}
void booking()
{
    int dd,mm,yy,i;
    char x;
    head_title();
    printf("\n\t\t\t\t\t\t\tDo you want to book a room?\n\n\t\t\t\t\t\t\t   ( Yes - 1 )  ");
    x=getch();
    if(x=='1')
    {
        printf("\n\n\n");
        nextt:
        for(i=0;i<5;i++)
        {
            printf("\n\t\t\t\t\t\t    %d - %s",i+1,F[i].typ);
        }
		printf("\n\n\n\t\t\t\t\t\tWhich type of room you would like to book?  ");
        x=getch();
        if(!((x=='1')||(x=='2')||(x=='3')||(x=='4')||(x=='5')))
        {
            head_title();
            printf("\n\n\t\t\t\t\t\t   You entered- %c\n\t\t\t\t\t\t   Please enter between 1 to 5.\n\n",x);
            goto nextt;
        }
        i=x-48;
        if(F[i-1].room==0)
        {
            head_title();
            printf("\n\t\t\t\tSorry. No room is available of type %s.\n\t\t\t\tPlease select other type of room.\n\n",F[i-1].typ);
            goto nextt;
        }
        strcpy(det.room_type,F[i-1].typ);
        det.room_no=(i*100)+F[i-1].room;
        F[i-1].room=F[i-1].room-1;
        head_title();
        printf("\n\n\t\t\t\t\t\t   *Please enter your details*\n\n");
		printf("\n\n\t\t\t\t\tRoom type : %s",det.room_type);
		printf("\n\n\t\t\t\t\tRoom number : %d",det.room_no);
		printf("\n\n\t\t\t\t\tPer day charges : Rs. %d",F[i-1].charges);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tName : ");
		scanf("%[^\n]s",&det.name);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tNumber of members : ");
		scanf("%d",&det.members);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tAddress : ");
		scanf("\n%[^\n]s",&det.address);
		fflush(stdin);
		nexttt:
		printf("\n\n\t\t\t\t\tEnter the Id proof you will submit:\n\n\t\t\t\t\t1 - PAN CARD\n\t\t\t\t\t2 - ADDHAR CARD\n\t\t\t\t\t3 - GOVERNMENT ID\n\t\t\t\t\t4 - LICENSE\n\t\t\t\t\t5 - PASSPORT\n\n\t\t\t\t\t : ");
		x=getch();
		if(!((x=='1')||(x=='2')||(x=='3')||(x=='4')||(x=='5')))
        {
           printf("\n\n\t\t\t\t\tYou entered - %c\n\n\t\t\t\t\tEnter between 1 to 5\n",x);
           goto nexttt;
        }
        else
        {
            switch(x)
            {
                case'1':
                    strcpy(det.id,"Pan_card");
                    break;
                case'2':
                    strcpy(det.id,"Addhar_card");
                    break;
                case'3':
                    strcpy(det.id,"Government_id");
                    break;
                case'4':
                    strcpy(det.id,"License");
                    break;
                case'5':
                    strcpy(det.id,"Passport");
                    break;
            }
        }
		printf("\n\n\t\t\t\t\tPhone Number :");
		scanf("\n%[^\n]s",det.phone);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tNationality : ");
		scanf("\n%[^\n]s",&det.nat);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tEmail : ");
		scanf("\n%[^\n]s",&det.email);
		fflush(stdin);
		nextttt:
		printf("\n\n\t\t\t\t\tArrival date(dd/mm/yyyy) : ");
		scanf("%d/%d/%d",&dd,&mm,&yy);
		fflush(stdin);
		i=date_check(dd,mm,yy);
		if(i==5)goto nextttt;
        i=date_cmp(dd,mm,yy);
		if(i==8)goto nextttt;
		det.d=nd=dd;
		det.m=nm=mm;
		det.y=ny=yy;
		printf("\n\n\t\t\t\t\tNumber of days of stay : ");
		scanf("%d",&det.stay);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tTotal charges for %d days : Rs. %d",det.stay,det.stay*F[i-1].charges);
		fflush(stdin);
        printf("\n\n\n\n\t\t\t\t\tRoom is successfully booked!!!\n\n\t\t\t\t\t(Press any key to continue.)");
        getch();
        fflush(stdin);
        add_to_customer();
        bill_details(det.stay*F[i-1].charges,"Room",1);
    }
    else
    {
        printf("\n\n\n\n\t\t\t\t\t\t  HOPE YOU HAVE A VERY NICE DAY!!!");
        printf("\n\n\t\t\t\t\t\t(Press any key to continue.)");
        getch();
        fflush(stdin);
    }
}
void room_details(int x)
{
    int i;
    head_title();
    printf("\t\t\t\t\t\tFollowing are the types of rooms available:\n\n");
    for (i=0;i<5;i++)
    {
        printf("\n\n\t\t\t\t\t\t\t  Type Number:- %d",i+1);
        printf("\n\t\t\t\t  =================================================================");
        printf("\n\t\t\t\t                              %s",F[i].typ);
        printf("\n\t\t\t\t  =================================================================");
        printf("\n\n\t\t\t\t\t  ----------------------------------------------");
        printf("\n\n\t\t\t\t\t\t  Room charges      |  Rs.%d per day",F[i].charges);
        printf("\n\n\t\t\t\t\t\t  Advance           |  Rs.%d",F[i].advance);
        printf("\n\n\t\t\t\t\t\t  No. of Bed        |  %d",F[i].bed);
        printf("\n\n\t\t\t\t\t\t  Guest capacity    |  %d",F[i].capacity);
        if(x==2)printf("\n\n\t\t\t\t\t\t  Rooms available   |  %d",F[i].room);
        printf("\n\n\t\t\t\t\t  ------------------------------------------------");
        printf("\n\n\t\t\t\t\t\t    Additional features");
        printf("\n\n\t\t\t\t\t\t  1.A/C availability    |%s",F[i].ac);
        printf("\n\n\t\t\t\t\t\t  2.Geyser availability |%s",F[i].geyser);
        printf("\n\n\t\t\t\t\t\t  3.TV availability     |%s",F[i].tv);
        printf("\n\n\t\t\t\t\t  ------------------------------------------------\n\n\n\n\n");
   }
   printf("\t\t\t\t\t\tPress any key to continue. ");
   getch();
   fflush(stdin);
   if(x==1)booking();
}
void view_food(struct food *node,char x[50],int i)
{
    int y,z,k=0,j,g;
    char q;
    head_title();
    printf("\n\t\t\t\t\t\t\t%s",x);
	printf("\n\n\t\t\t\t\t_______________________________________________________\n\n");
	printf("\t\t\t\t\tFood Code          Name                   Price\n\n\t\t\t\t\t");
	printf("_______________________________________________________\n\n");
	temp=node;
    while(temp!=NULL)
    {
        printf("\t\t\t\t\t  %d   |  %-25s     |    Rs. %0.2d   \n\n",temp->no,temp->item,temp->cost);
        temp=temp->next;
    }
    if(i==1)
    {
        printf("\n\n\n\t\t\t\t\tWant to order something? ( Yes - 1 )  ");
        q=getch();
        fflush(stdin);
        if(q=='1')
        {
            next:
            temp=node;
            printf("\n\n\t\t\t\t\tEnter the food code : ");
            scanf("%d",&y);
            for(g=0;g<y;g++)
            {
                if(temp==NULL)break;
                if(y==temp->no)
                {
                    k++;
                    printf("\n\n\t\t\t\t\tEnter quantity - ",temp->item);
                    scanf("%d",&z);
                    printf("\n\n\t\t\t\t\t%s ordered.\n\n\t\t\t\t\tTotal - Rs. %d",temp->item,(temp->cost)*z);
                    bill_details((temp->cost)*z,temp->item,1);
                    printf("\n\n\t\t\t\t\t(Press any key to continue.)");
                    getch();
                    fflush(stdin);
                    return;
                }
                temp=temp->next;
            }
            if(k==0)
            {
                printf("\n\n\t\t\t\t\tYou have entered more than food items. Try again.\n");
                goto next;
            }
        }
    }
    else
    {
        nextt:
        printf("\n\n\t\t\t\t\t1 - Add food item\n\n\t\t\t\t\t2 - Delete food item\n\n\t\t\t\t\t3 - Exit");
        q=getch();
        fflush(stdin);
        if(q=='1')
        {
            printf("\n\n\t\t\t\t\tEnter Food name : ");
            scanf("%s",curr->item);
            printf("\n\n\t\t\t\t\tEnter Food price : ");
            scanf("%d",&curr->cost);
            temp=node;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            curr->no=(temp->no)+1;
            temp->next=curr;
            temp=temp->next;
            temp->next=NULL;
            printf("\n\n\t\t\t\t\t%s added in %s list.",temp->item,x);
        }
        else if(q=='2')
        {
            nexttt:
            printf("\n\n\t\t\t\t\tEnter food code to be deleted - ");
            scanf("%d",&k);
            temp=node;
            for(j=1;j<k-1;j++)
            {
                if(temp==NULL)
                {
                    printf("\n\n\t\t\t\t\tYou have entered wrong food code. Try again.\n");
                    goto nexttt;
                }
                temp=temp->next;
            }
            curr=temp->next;
            temp->next=temp->next->next;
            printf("\n\n\t\t\t\t\t%s removed from %s",curr->item,x);
            free(curr);
        }
        else if(q=='3')return;
        else
        {
            printf("\n\t\t\t\t\t\t\tYou entered - %c\n\t\t\t\t\t\t\tPlease enter between 1,2 or3.\n\n",q);
            goto nextt;
        }
    }
}
void food1()
{
    head_title();
    char x;
    next:
    printf("\n\n\t\t\t\t\tPlease select a food type.\n\n\n\t\t\t\t\t\t1 - Snacks\n\n\t\t\t\t\t\t2 - Main Course\n\n\t\t\t\t\t\t3 - Dessert");
    x=getch();
    fflush(stdin);
    if(x=='1')view_food(snack,"SNACKS",1);
    else if(x=='2')view_food(course,"MAIN COURSE",1);
    else if(x=='3')view_food(dess,"DESSERTSs",1);
    else
    {
        head_title();
        printf("\n\t\t\t\t\tYou entered - %c\n\n\t\t\t\t\tEnter 1,2 or 3.",x);
        goto next;
    }
    printf("\n\n\t\t\t\t\tSee more food items? ( Yes - 1 )  ");
    x=getch();
    fflush(stdin);
    if(x=='1')food1();
}
void food2()
{
    head_title();
    char x;
    next:
    printf("\n\n\t\t\t\t\tPlease select a food type.\n\n\n\t\t\t\t\t\t1 - Snacks\n\n\t\t\t\t\t\t2 - Main Course\n\n\t\t\t\t\t\t3 - Dessert");
    x=getch();
    fflush(stdin);
    if(x=='1')view_food(snack,"SNACKS",2);
    else if(x=='2')view_food(course,"MAIN COURSE",2);
    else if(x=='3')view_food(dess,"DESSERTS",2);
    else
    {
        head_title();
        printf("\n\t\t\t\t\tYou entered - %c\n\n\t\t\t\t\tEnter 1,2 or 3.",x);
        goto next;
    }
    printf("\n\n\t\t\t\t\tSee more food items? ( Yes - 1 )  ");
    x=getch();
    fflush(stdin);
    if(x=='1')food2();
}
struct employee* create_node(int x,char y[100],char z[50])
{
    struct employee* newnode;
    newnode=(struct employee*)malloc(sizeof(struct employee));
    strcpy(newnode->name,y);
    strcpy(newnode->job,z);
    newnode->salary=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct employee* insert(struct employee *root,int x,char y[100],char z[50])
{
    if(root==NULL)
    {
        root=create_node(x,y,z);
    }
    else if(x<(root->salary))root->left=insert(root->left,x,y,z);
    else if(x==root->salary)root->right=insert(root->right,x+1,y,z);
    else root->right=insert(root->right,x,y,z);
    return root;
}
void employee_create()
{
    int i;
    for(i=0;i<10;i++)
    {
        root=insert(root,emp[i].salary,emp[i].name,emp[i].job);
    }
}
void inorder(struct employee *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\t\t\t\t%25s\t%10s\t\tRs. %d\n\n",root->name,root->job,root->salary);
        inorder(root->right);
    }
}
struct employee* deleteNode(struct employee* root, int key)
{
    if(root== NULL)return root;
    if(key<root->salary)root->left=deleteNode(root->left, key);
    else if(key>root->salary)root->right=deleteNode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            struct employee* temp=root->right;
            free(root);
            printf("\n\t\t\t\t\t\tEmployee fired.\n");
            return temp;
        }
        else if(root->right==NULL)
        {
            struct employee* temp=root->left;
            free(root);
            printf("\n\t\t\t\t\t\tEmployee fired.\n");
            return temp;
        }
    }
    return root;
}
void employee_details()
{
    int x;
    char q,y[100],z[50];
    head_title();
    printf("\n\n\t\t\t\t\t\tFollowing are employees working in SUNSHINE\n\t\t\t\t\t\t   ( In ascending order of salary. )\n\n\n");
    printf("\t\t\t\t\t\tName\t\t     Job\t\t    Salary\n");
    printf("\t\t\t\t\t_____________________________________________________________\n\n\n");
    inorder(root);
    next:
    printf("\n\n\t\t\t\t\t1 - Add employee\n\n\t\t\t\t\t2 - Remove employee\n\n\t\t\t\t\t3 - Exit  ");
    q=getch();
    fflush(stdin);
    if(q=='1')
    {
        head_title();
        printf("\n\n\t\t\t\t\tEmployee Recruitment\n\n\n\t\t\t\t\tEnter name of employee : ");
        scanf("%[^\n]s",y);
        printf("\n\n\t\t\t\t\tEnter job profile of employee : ");
        scanf("%s",z);
        printf("\n\n\t\t\t\t\tEnter salary of employee : Rs. ");
        scanf("%d",&x);
        root=insert(root,x,y,z);
        printf("\n\n\n\t\t\t\t\tRecruitment Successful.\n\n\t\t\t\t\t(Press any key to continue.)");
        getch();
        fflush(stdin);
    }
    else if(q=='2')
    {
        printf("\n\n\n\t\t\t\t\tEnter salary of employee to be fired. : ");
        scanf("%d",&x);
        root=deleteNode(root,x);
    }
    else if(q=='3')return;
    else
    {
        printf("\n\n\t\t\t\t\tYou entered - %c Enter 1,2 or 3.\n",q);
        goto next;
    }
}
void services(int x)
{
    int i,t;
    char q;
    head_title();
    printf("\n\n\t\t\t\t\t\tFollowing are services available at SUNSHINE :\n");
    printf("\t\t\t\t\t\t_________________________________________________\n\n\n");
    for(i=0;i<10;i++)
    {
        printf("\t\t\t\t\t\t%2d) %15s\t\tRs.%d\n\n",i+1,ser[i].name,ser[i].cost);
    }
    if(x==1)
    {
        printf("\n\n\t\t\t\t\tWant to get some service? ( Yes - 1 )  ");
        q=getch();
        fflush(stdin);
        if(q=='1')
        {
            next:
            printf("\n\n\t\t\t\t\tEnter service number. : ");
            scanf("%d",&t);
            if(t>10)
            {
                printf("\n\t\t\t\t\tYou have entered more than 10. Try again.");
                goto next;
            }
            bill_details(ser[t-1].cost,ser[t-1].name,1);
            printf("\n\n\t\t\t\t\tService - %s booked for you.\n\n\t\t\t\t\t( Press any key to continue. )",ser[t-1].name);
            getch();
            fflush(stdin);
        }
    }
}
void manager()
{
    head_title();
	int i,j=1;
	char p[5],u[10],x;
	next:
    printf("\n\n\t\t\t\t\t\t\tUser: ");
    scanf("%s",u);
    fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\tPassword : ");
	for(i=0;i<4;i++)
    {
        p[i]=getch();
        fflush(stdin);
        printf("*");
    }
    fflush(stdin);
	if((!strcmp("1234",p))&&(!strcmp("abcd",u)))
    {
        head_title();
        printf("\n\n\t\t\t\t\t\t\tLog in successful.\n\n");
        nextt:
        printf("\n\n\t\t\t\t\t\tWhat option would you like to select.\n\n\t\t\t\t\t\t\t1 - Room details\n\n\t\t\t\t\t\t\t2 - Services\n\n\t\t\t\t\t\t\t3 - Food\n\n\t\t\t\t\t\t\t4 - Customer details\n\n\t\t\t\t\t\t\t5 - Employee details\n\n\t\t\t\t\t\t\t6 - Revenue  ");
        x=getch();
        fflush(stdin);
        switch(x)
        {
            case '1':
                room_details(2);
                break;
            case '2':
                services(2);
                break;
            case '3':
                food2();
                break;
            case '4':
                customers();
                break;
            case '5':
                employee_details();
                break;
            case '6':
                revenue();
                break;
            default:
                head_title();
                printf("\n\n\t\t\t\tYou entered - %c Try again.\n\n",x);
                goto nextt;
                break;
        }
        printf("\n\n\n\t\t\t\t\tLog out? ( Yes - 1 )");
        x=getch();
        fflush(stdin);
        if(x=='1')return;
        else
        {
            head_title();
            goto nextt;
        }
    }
    else
    {
        if(j>2)
        {
            head_title();
            printf("\n\n\t\t\t\t\t\tEntered wrong user name or password more than 3 times.\n\n\t\t\t\t\t\tNo more attempts allowed.\n\n");
            Sleep(6000);
            return;
        }
        else
        {
            head_title();
            printf("\n\n\t\t\t\t\t\t%d wrong attempts. Try again.",j);
            j++;
            goto next;
        }
    }
}
void notification()
{
    if(pt==det.stay)
    {
        head_title();
        printf("\n\t\t\t\t\tDay - %d.\n\n\t\t\t\t\tThis is your last day of stay.\n\t\t\t\t\tIt was a very good experience with you.\n\n",det.stay);
        printf("\n\n\t\t\t\t\t(Press any key to continue.)");
        getch();
        fflush(stdin);
    }
    else
    {
        head_title();
        printf("\n\t\t\t\t\tDay - %d\n\t\t\t\t\tNo notifications today.",pt);
        printf("\n\n\t\t\t\t\t(Press any key to continue.)");
        getch();
        fflush(stdin);
    }
}
void guest()
{
    int r,s=1;
    char j,n[100];
    head_title();
    if((thour<12)&&(thour>=5))printf("\t\t\t\t\t\t\tGOOD MORNING");
    else if(thour<18)printf("\t\t\t\t\t\t\tGOOD AFTERNOON");
    else printf("\t\t\t\t\t\t\tGOOD EVENING");
    printf(" MADAM / SIR ........\n\n");
    next:
    printf("\t\t\t\t\t\t\tHave you:\n\n\t\t\t\t\t\t\t1 - Already booked a room.\n\t\t\t\t\t\t\t2 - Want to book a room.  ");
    j=getch();
    fflush(stdin);
    switch(j)
    {
        case '1':
            if(det.room_no==0)
            {
                printf("\n\n\t\t\t\t\t\t\tNo room is booked. Please book a room.  ");
                Sleep(3000);
                room_details(1);
                break;
            }
            head_title();
            nextt:
            printf("\n\t\t\t\t\t\t\tEnter your name. : ");
            scanf("%s",n);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t\t\tEnter your room no. : ");
            scanf("%d",&r);
            fflush(stdin);
            if((!strcmp(det.name,n))&&(det.room_no==r))
            {
                head_title();
                nexttt:
                printf("\n\n\t\t\t\tWelcome %s.",det.name);
                printf("\n\n\t\t\t\tPlease choose an option:\n\n\t\t\t\t1 - Notification\n\n\t\t\t\t2 - Day complete\n\n\t\t\t\t3 - Services\n\n\t\t\t\t4 - Tourist Places\n\n\t\t\t\t5 - Food\n\n\t\t\t\t6 - My Bill",det.name);
                j=getch();
                fflush(stdin);
                switch(j)
                {
                    case'1':
                        notification();
                        break;
                    case'2':
                        if(pt==det.stay)printf("\n\n\t\t\t\t\tThis is your last day of stay.");
                        else pt=pt+1;
                        break;
                    case'3':
                        services(1);
                        break;
                    case'4':
                        nearby();
                        break;
                    case'5':
                        food1();
                        break;
                    case '6':
                        head_title();
                        printf("\n\n\t\t\t\t\tFollowing is your total bill till now :\n\n\t\t\t\t\tName\t\t\tAmount\n\n");
                        bill_details(1,"x",2);
                        break;
                    default:
                        head_title();
                        printf("\n\t\t\t\t\t\t\tYou entered - %c\n\t\t\t\t\t\t\tPlease enter between 1 to 6.\n\n",j);
                        goto nexttt;
                        break;
                }
                printf("\n\n\t\t\t\t\tLog out? ( Yes - 1 )");
                j=getch();
                fflush(stdin);
                if(j=='1')return;
                else
                {
                    head_title();
                    goto nexttt;
                }
            }
            if(!((!strcmp(det.name,n))&&(det.room_no==r)))
            {
                if(s<3)
                {
                    head_title();
                    printf("\n\n\t\t\t\tYou have entered wrong name or room number %d times.\n\n",s);
                    s++;
                    goto nextt;
                }
            }
            break;
        case '2':
            room_details(1);
            break;
        default:
            head_title();
            printf("\n\t\t\t\t\t\t\tYou entered - %c\n\t\t\t\t\t\t\tPlease enter 1 or 2.\n\n",j);
            goto next;
            break;
    }

}
void employee()
{
    head_title();
	int i,j=1;
	char p[5],x;
	next:
	printf("\n\t\t\t\t\t\tEnter the common employee password\n\t\t\t\t\t\t\t: ");
	for(i=0;i<4;i++)
    {
        p[i]=getch();
        fflush(stdin);
        printf("*");
    }
    if(!strcmp("1234",p))
    {
        head_title();
        printf("\n\n\t\t\t\t\t\t\tLog in successful.\n\n");
        nextt:
        printf("\n\n\t\t\t\t\t\tWhat option would you like to select.\n\n\t\t\t\t\t\t\t1 - Food\n\t\t\t\t\t\t\t2 - Room\n\t\t\t\t\t\t\t3 - Customer details   ");
        x=getch();
        fflush(stdin);
        switch(x)
        {
            case '1':
                food2();
                break;
            case '2':
                room_details(2);
                break;
            case '3':
                customers();
                break;
            default:
                head_title();
                printf("\n\n\t\t\t\t\t\tYou entered - %c Try again.\n\n",x);
                goto nextt;
                break;
        }
        printf("\n\n\n\t\t\t\t\tLog out? ( Yes - 1 )");
        x=getch();
        fflush(stdin);
        if(x=='1')return;
        else
        {
            head_title();
            goto nextt;
        }
    }
    else
    {
        if(j>2)
        {
            head_title();
            printf("\n\n\t\t\t\t\t\tEntered wrong password more than 3 times.\n\n\t\t\t\t\t\tNo more attempts allowed.\n\n");
            Sleep(6000);
            return;
        }
        else
        {
            head_title();
            printf("\n\n\t\t\t\t\t\t%d wrong attempts. Try again.",j);
            j++;
            goto next;
        }
    }
}
void create_food()
{
    int i;
    struct food1 snack1[10]={{1,"Tea",30},{2,"Green Tea",40},{3,"Hot Chocolate",80},{4,"Coffee",50},{5, "Cold Coffee ",  80},{6, "Masala Papad", 30},{7, "French Fries",142},{8, "Veg Hara Bhara Kebab", 153},{9, "Grilled Cheese Sandwich",150},{10, "Paneer Tikka Kati Roll",212}};
    struct food1 course1[20]={{1, "Chapati",30},{2, "Jawar Roti", 30},{3, "Tandoori Roti", 30},{4, "Butter Roti", 35},{5, "Butter Naan ", 59},{6, "Jeera Rice", 153},{7, "Plain Rice", 130},{8, "Dal Khichdi", 212},{9, "Kashmiri Pulao", 177},{10, "Veg Biryani", 212},{11, "Veg Tawa Masala",  248},{12, "Paneer Kadai",  248},{13, "Paneer Tikka Masala",  248},{14, "Navratan Korma", 248},{15, "Methi Mattar Malai", 294},{16, "Dum Aloo Kashmiri",  248},{17, "Veg Kolhapuri",  248},{18, "Malai Kofta", 330},{19, "Kaju Curry",330},{20, "Dal Tadka", 177}};
    struct food1 dess1[10]={{1, "Choco lava cake", 150},{2, "chocolate Waffle",  150},{3, "Chocolate Cake",  250},{4, "Red Velevet Cake",  350},{5, "Strawberry Mouse",100},{6, "Orea Freakshake",  150},{8 , "Fruit Milkshake", 80},{9 , "Vanilla Ice cream",  118},{10 , "Chocolate Ice cream",  118}};
    for(i=0;i<10;i++)
    {
        temp=(struct food*)malloc(sizeof(struct food));
        temp->no=snack1[i].no;
        strcpy(temp->item,snack1[i].item);
        temp->cost=snack1[i].cost;
        if(snack==NULL)
        {
            snack=temp;
            curr=snack;
            snack->next=NULL;
        }
        else
        {
            curr->next=temp;
            curr=curr->next;
            curr->next=NULL;
        }
    }
    for(i=0;i<20;i++)
    {
        temp=(struct food*)malloc(sizeof(struct food));
        temp->no=course1[i].no;
        strcpy(temp->item,course1[i].item);
        temp->cost=course1[i].cost;
        if(course==NULL)
        {
            course=temp;
            curr=course;
            course->next=NULL;
        }
        else
        {
            curr->next=temp;
            curr=curr->next;
            curr->next=NULL;
        }
    }
    for(i=0;i<9;i++)
    {
        temp=(struct food*)malloc(sizeof(struct food));
        temp->no=dess1[i].no;
        strcpy(temp->item,dess1[i].item);
        temp->cost=dess1[i].cost;
        if(dess==NULL)
        {
            dess=temp;
            curr=dess;
            dess->next=NULL;
        }
        else
        {
            curr->next=temp;
            curr=curr->next;
            curr->next=NULL;
        }
    }
}
void main()
{
    char d,x;
    printf("Start ->                                                                                                                              |");
    getch();
    fflush(stdin);
    today_date();
    create_food();
    employee_create();
    create_revenue();
    color(180);
    nextt:
    system("cls");
    welcome();
    head_title();
    next:
    printf("\n\n\t\t\t\t\t\t\tYou are Hotel SUNSHINE's:\n\n\n");
    printf("\t\t\t\t\t\t\t1 - GUEST\n\n\t\t\t\t\t\t\t2 - EMPLOYEE\n\n\t\t\t\t\t\t\t3 - MANAGER\n\n\t\t\t\t\t\t\t4 - (Exit) ");
    x=getch();
    fflush(stdin);
    switch(x)
    {
        case '1':
            guest();
            break;
        case '2':
            employee();
            break;
        case '3':
            manager();
            break;
        case '4':
            break;
        default:
            head_title();
            printf("\n\t\t\t\t\t\t\tYou entered - %c.\n\t\t\t\t\t\t\tPlease enter between 1 to 4.\n\n",x);
            goto next;
    }
    head_title();
    printf("\n\n\t\t\t\t\t\t\tTRY THE PROGRAM AGAIN? (Yes-1) : ");
    d=getch();
    fflush(stdin);
    if(d=='1')goto nextt;
    printf("\n\nPROGRAM FINISHED\n\n\n\n\n\n");
}



