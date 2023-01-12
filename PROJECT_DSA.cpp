//A CODE BY ZAHID YASIN
#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<string.h>
#include<conio.h>
#include "MMsystem.h"
using namespace std;
struct node_shoes{
  int price;
  string brand_name;
  string shoes_name;
  int stock;
  int id;
  int discount;
  node_shoes* next;
};
struct node_staff{
  string name_staff;
  string username_staff;
  string password_staff;
  int id;
  node_staff* next;
};
string login_admin_key="ADMIN@1";
node_shoes* start_shoes=NULL;
node_shoes* last_shoes=NULL;
node_staff* start_staff=NULL;
node_staff* last_staff=NULL;
double totalcollection=0;
int number_of_pair_sold=0;
int total_bill=0;
int total_customer=0;
int count_sound=1;
int color_change=0;
int vioce_change=1;
void loading(){
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\tloading : ";
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("loading"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("loadig(mathev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("loading(kid)"), NULL, SND_ASYNC);
  }
	char kp=219;
	for(int i=0; i<35; i++)
	{
		cout<<kp;
		if(i<10)
		Sleep (300);
		if(i>=10 && i<20)
		Sleep(150);
		if(i>=10)
		Sleep(25);
	}
	system("cls");
}
node_shoes* search(node_shoes* start1,int id1){
  if(start1==NULL){
    return NULL;
  }
  if(start1->id==id1){
    return start1;
  }
  search(start1->next,id1);
}
void setvalue_shoes(node_shoes* start1,int id){
  cout<<"\t\t\t\t\tEnter Brand Name Of Shoses"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->brand_name;
  cout<<"\t\t\t\t\tEnter Shoes Name"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->shoes_name;
  cout<<"\t\t\t\t\tEnter Price Shoeses"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->price;
  cout<<"\t\t\t\t\tEnter The StocK Of Shoses"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->stock;
  start1->id=id;
  cout<<"\t\t\t\t\tEnter The Discount On Shoes In Perscent"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->discount;
}
void add_shoes(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           SHOES ADDITION PENAL            |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  node_shoes* start1=start_shoes;
  int com_id;
  cout<<"\t\t\t\t\tEnter ID Of Shoes"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>com_id;
  node_shoes* cur=search(start1,com_id);
  if(start_shoes==NULL)
  {
    start_shoes=new node_shoes;
    setvalue_shoes(start_shoes,com_id);
    start_shoes->next=NULL;
    last_shoes=start_shoes;
  }
  else if(cur!=NULL)
  {
    int st;
    cout<<"\t\t\t\t\tThis Shoes Already Present Please Enter The New Stock You Want To Add"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>st;
    cur->stock=(cur->stock)+st;
  }
  else
  {
    node_shoes* temp=new node_shoes;
    setvalue_shoes(temp,com_id);
    last_shoes->next=temp;
    last_shoes=temp;
    temp->next=NULL;
  }
  cout<<"\t\t\t\t\tShoes Are Added!!!"<<endl;
}
void remove_shoes(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           SHOES REMOVAL PENAL             |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  int com_id;
  cout<<"\t\t\t\t\tEnter The ID Of Shoes You Want To Delete"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>com_id;
  node_shoes* curr=start_shoes;
  node_shoes* pre;
  while(curr!=NULL && com_id!=curr->id){
    pre=curr;
    curr=curr->next;
  }
  if(curr==NULL){
    cout<<"\t\t\t\t\tItem Do Not Found"<<endl;
  }
  else{
    pre->next=curr->next;
    delete curr;
  }
}
void updateprice_shoes(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|         SHOES PRICE-UPADATE PENAL          |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  int com_id;
  cout<<"\t\t\t\t\tEnter The Id Of Shoes You Want To Update Price"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>com_id;
  node_shoes* cur=search(start_shoes,com_id);
  cout<<"\t\t\t\t\tEnter The Price You Want To Update"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>cur->price;
}
void setvalue_staff(node_staff* start1){
  cout<<"\t\t\t\t\tEnter Name Of Staff"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->name_staff;
  cout<<"\t\t\t\t\tEnter The Id Of Staff"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->id;
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("username"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("username(metthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("username(kid)"), NULL, SND_ASYNC);
  }
  cout<<"\t\t\t\t\tEnter The Username Avail To Staff"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->username_staff;
  Sleep(800);
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("password"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("password(metthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("password(kid)"), NULL, SND_ASYNC);
  }
  cout<<"\t\t\t\t\tEnter The Pssword Avail To Staff"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>start1->password_staff;
}
void viewstock_shoes(node_shoes* start1){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           SHOES VIEWSTOCK PENAL           |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  if(start1==NULL)
  return;
  cout<<"\t\t\t\t\tBrand Name Of Shoses:"<<start1->brand_name<<endl;
  cout<<"\t\t\t\t\tShoes Name:"<<start1->shoes_name<<endl;
  cout<<"\t\t\t\t\tPrice Shoeses:"<<start1->price<<endl;
  cout<<"\t\t\t\t\tThe Stoct Of Shoses:"<<start1->stock<<endl;
  cout<<"\t\t\t\t\tThe Id Of Shoses:"<<start1->id<<endl;
  cout<<"\t\t\t\t\tDiscount On Shoes:"<<start1->discount<<endl;
  cout<<"\t\t\t\t\t";
  viewstock_shoes(start1->next);
}
void add_discount_shoes(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           SHOES DISCOUNT PENAL            |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  int choice;
  cout<<"\t\t\t\t\tPress 1 To Add Discount On All Shoes"<<endl;
  cout<<"\t\t\t\t\tPress 2 To Add Discount On Specific Shoes"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>choice;
  int discount;
  cout<<"\t\t\t\t\tEnter The Discount In Percentage"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>discount;
  if(choice==1){
    node_shoes* temp=start_shoes;
    while (temp!=NULL)
    {
      temp->discount=discount;
      temp=temp->next;
    }
    cout<<"\t\t\t\t\tDscount Is Applied!!!"<<endl;
  }
  else if(choice==2){
    int com_id;
    cout<<"\t\t\t\t\tEnter Id Of Shoes"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>com_id;
    node_shoes* cur=search(start_shoes,com_id);
    if(cur==NULL){
      cout<<"\t\t\t\t\tShoes Cannot Found With That Id"<<endl;
    }
    else{
      cur->discount=discount;
      cout<<"\t\t\t\t\tDiscount Is Applied!!!"<<endl;
    }
  }
  else{
    cout<<"\t\t\t\t\tWrong Selection!!! \tGoing Back To Main Menu"<<endl;
  }
}
void add_staff(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           STAFF ADDITION PENAL            |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  if(start_staff==NULL){
    start_staff=new node_staff;
    setvalue_staff(start_staff);
    last_staff=start_staff;
  }
  else{
    node_staff* temp=new node_staff;
    setvalue_staff(temp);
    temp->next=NULL;
    last_staff=temp;
  }
}
void remove_staff(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           STAFF REMOVAL PENAL             |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  int com_id;
  cout<<"\t\t\t\t\tEnter The Id Of Staff You Want To Remove"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>com_id;
  node_staff* curr=start_staff;
  node_staff* pre;
  while(curr!=NULL && com_id!=curr->id){
    pre=curr;
    curr=curr->next;
  }
  if(curr==NULL){
    cout<<"\t\t\t\t\tItem Do Nnot Found"<<endl;
  }
  else{
    pre->next=curr->next;
    delete curr;
  }
}
bool verify_login(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|                LOGIN PENAL                |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  string username;
  string password;
  int choice;
  labell_4:
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("username"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("username(metthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("username(kid)"), NULL, SND_ASYNC);
  }
  cout<<"\t\t\t\t\tEnter Your Username"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>username;
  Sleep(800);
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("password"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("password(metthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("password(kid)"), NULL, SND_ASYNC);
  }
  cout<<"\t\t\t\t\tEnter Your Password"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>password;
  node_staff* cur=start_staff;
  while(cur!=NULL){
    if((cur->username_staff)==username && (cur->password_staff)==password){
      cout<<"\t\t\t\t\tYou Have Logined Successfully!!!"<<endl;
        if(count_sound==1){
        if(vioce_change==1)
            PlaySound(TEXT("sucess"), NULL, SND_ASYNC);
        if(vioce_change==2)
            PlaySound(TEXT("sucess(metthev)"), NULL, SND_ASYNC);
        if(vioce_change==3)
            PlaySound(TEXT("sucess(kid)"), NULL, SND_ASYNC);
        }
      Sleep(2500);
      return true;
    }
    cur=cur->next;
  }
  if(cur==NULL){
    cout<<"\t\t\t\t\tEntered Wrong Password Or Username!!!"<<endl;
    cout<<"\t\t\t\t\tPress 1 To Enter Again Or Any Number To Exist"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>choice;
    if(choice==1)
    goto labell_4;
    else
    return false;
  }
}
void change_password(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|         PASSWORD CHANGING PENAL           |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  int id;
  if(verify_login()){
  cout<<"\t\t\t\t\tEnter Your Id"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>id;
  node_staff* cur=start_staff;
  while(cur!=NULL && cur->id!=id){
    cur=cur->next;
  }
  if(cur==NULL)
    cout<<"\t\t\t\t\tYou Entered Wrong Id!!!"<<endl;
  else{
    cout<<"\t\t\t\t\tEnter Your New Password"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>cur->password_staff;
    cout<<"\t\t\t\t\tPassword Updated!!!!"<<endl;
  }
  }
  else{
    cout<<"\t\t\t\t\tYou Entered Wrong Credentials"<<endl;
  }
}
void placeorder(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|            SHOES ORDER PENAL              |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  labell:
  int com_id;
  cout<<"\t\t\t\t\tEnter The Id Of Shoes You Want To Order"<<endl;
  cout<<"\t\t\t\t\t";
  cin>>com_id;
  node_shoes* temp=search(start_shoes,com_id);
  if(temp==NULL){
    cout<<"\t\t\t\t\tItem Donot Fount!!!"<<endl;
  }
  else{
    int st;
    cout<<"\t\t\t\t\tEnter Number Of Shoes You Want To Order"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>st;
    if((temp->stock)<st){
      cout<<"\t\t\t\t\tStock Is Not Avalible!!!!"<<endl;
      cout<<"\t\t\t\t\tAvailable Stock Is:  "<<temp->stock<<endl;
      goto labell;
    }
    else{
      total_customer++;
      int choice;
      cout<<"\t\t\t\t\tDiscount On That Shoes Is: "<<temp->discount<<"%"<<endl;
      if(temp->discount>0){
        int discou;
        int price=temp->price;
        discou=((temp->price)*(temp->discount))/100;
        total_bill+=(price-discou);
      }
      else{
        total_bill=(temp->price);
      }
      totalcollection+=total_bill;
      temp->stock-=st;
      number_of_pair_sold+=st;
      cout<<"\t\t\t\t\tPress 1 To If You Want To Order More Shoes Or Any Number To Get Total Bill"<<endl;
      cout<<"\t\t\t\t\t";
      cin>>choice;
      if(choice==1){
        goto labell;
      }
      else{
        cout<<"\t\t\t\t\tYour Total Bill Is: "<<total_bill<<endl;
        total_bill=0;
      }
    }
  }
}
void analytics(){
  cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t|           SHOES ANALYTICS PENAL           |"<<endl;
  Sleep(500);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
  cout<<"\t\t\t\t\tTotal Sales Is: "<<totalcollection<<endl;
  cout<<"\t\t\t\t\tTotal Pair Of Shoes Sold: "<<number_of_pair_sold<<endl;
  cout<<"\t\t\t\t\tTotal Number Of Customer: "<<total_customer<<endl;
  cout<<"\t\t\t\t\tThe Stock Which Is Not Avalible"<<endl;
  node_shoes* temp=start_shoes;
    while (temp!=NULL)
    {
      if(temp->stock<=0){
        cout<<"\t\t\t\t\tBrand Name Of Shoses:"<<temp->brand_name<<endl;
        cout<<"\t\t\t\t\tShoes Name:"<<temp->shoes_name<<endl;
        cout<<"\t\t\t\t\tThe Id Of Shoses:"<<temp->id<<endl;
      }
      temp=temp->next;
    }
}
void welcome_1(){
  system("color 9f");
  Sleep(700);
  cout << "\t\t\t\t\t\t******************************************************************" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t------------------------------------------------------------------" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t------------------------------------------------------------------" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t******************************************************************" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t*******                      WELCOME                       *******" <<endl;
  if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("welcome_versace"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("versace(matthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("versace(kid)"), NULL, SND_ASYNC);
  }
  Sleep(700);
	cout << "\t\t\t\t\t\t*******                        TO                          *******" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t*******                    VERSACE  SHOES                  *******" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t******************************************************************" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t------------------------------------------------------------------" << endl;
  Sleep(700);
	cout << "\t\t\t\t\t\t------------------------------------------------------------------" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t******************************************************************" << endl;
  Sleep(700);
  if(count_sound==1){
  PlaySound(TEXT("next"), NULL, SND_ASYNC);
  }
	cout << "\t\t\t\t\t\t* * *"<<"\tPress Any Key For    Next....    ";getch();
  system("color 9f");
  loading();
  Sleep(700);
  cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t      ---------------------------------" << endl;
	Sleep(700);
  cout << "\t\t\t\t\t\t\t    **************************************" << endl;
	Sleep(700);
  cout << "\t\t\t\t\t\t\t  ------------------------------------------" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t\t************************************************" << endl;
	Sleep(700);
	cout<<  "\t\t\t\t\t\t\t------------------------------------------------\n\n";
  Sleep(700);
  cout<<  "\t\t\t\t\t\t\t               About Of the Project        \n\n";
  Sleep(700);
  cout<<  "\t\t\t\t\t\t\t------------------------------------------------\n\n";
  Sleep(700);
  cout<<  "\t\t\t\t\t\t\tThis Application Is Specially Made For Managing\n\t\t\t\t\t\t\tShoes store Data and its staff members\n\n ";
  Sleep(700);
  cout<<  "\t\t\t\t\n "<<endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t\t************************************************" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t\t  -----------------------------------------" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t\t    **************************************" << endl;
  Sleep(700);
  cout << "\t\t\t\t\t\t\t      ---------------------------------" << endl;
  if(count_sound==1){
  PlaySound(TEXT("next"), NULL, SND_ASYNC);
  }
  cout <<"\n\n\n\n\t\t\t\t\t\t\t   Press Any Key For Go In To Program    ";
  getch();
  loading();
  system("color 9f");
  Sleep(500);
  if(count_sound==1){
  PlaySound(TEXT("members"), NULL, SND_ASYNC);
  }
  cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t"<< endl;
  cout << "\t\t\t\t\t    ==========Group Members are============================================"<<endl;
  Sleep(1300);
  cout << "\n\t\t\t\t\t    ||   Name : MUHAMMAD ZAHID  \t\tRoll No : F2021065216    ||\n"<<endl;
  Sleep(1300);
  cout << "\t\t\t\t\t    ||   Name : Sheeza Mujahid  \t\tRoll No : F2019065252    ||\n" << endl;
  Sleep(1300); 
  cout << "\t\t\t\t\t    ||   Name : MUHAMMAD SAMI   \t\tRoll No : F2021065322    ||\n" << endl;
	Sleep(1300);
  cout << "\t\t\t\t\t    ||   Name : SANWAL ALI      \t\tRoll No : F2021065202    ||\n" << endl;
  Sleep(1300);
	cout << "\t\t\t\t\t    ======================================================================="<<endl;
	Sleep(500);
  if(count_sound==1){
  PlaySound(TEXT("next"), NULL, SND_ASYNC);
  }
	cout <<"\t\t\t\t\t\tpress any key for    next....    ";
  getch();
  loading();
}
int main()
{
  welcome_1();
  int profile_choice;
  string key;
  labell_6:
    if(color_change==0)
    system("color 9f");
    if(color_change==1)
    system("color f0");
    if(color_change==2)
    system("color f4");
    if(color_change==3)
    system("color 21");
    if(color_change==4)
    system("color e0");
    else if(color_change==5)
    system("color 1f");
    cout<<"\t\t\t\t\t\t\t----------------------------------------"<<endl;
    Sleep(500);
    if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("welcome_versace"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("versace(matthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("versace(kid)"), NULL, SND_ASYNC);
  }
	  cout<<"\t\t\t\t\t\t\t|       WELCOME TO VERSACE SHOES        |"<<endl;
    Sleep(500);
	  cout<<"\t\t\t\t\t\t\t----------------------------------------\n"<<endl;
    Sleep(1300);
    cout<<"\n\t\t\t\t**************************CHOOSE YOUR LOGIN PROFILE*********************\n"<<endl;
    Sleep(700);
    if(count_sound==1){
    if(vioce_change==1)
      PlaySound(TEXT("login"), NULL, SND_ASYNC);
    if(vioce_change==2)
      PlaySound(TEXT("login(matthev)"), NULL, SND_ASYNC);
    if(vioce_change==3)
      PlaySound(TEXT("login(kid)"), NULL, SND_ASYNC);
    }
    cout<<"\t\t\t\tPress 1 To Login As Admin"<<endl;
    cout<<"\t\t\t\tPress 2 To Login As Staff"<<endl;
    cout<<"\t\t\t\tPress 3 Setting"<<endl;
    cout<<"\t\t\t\t";
    cin>>profile_choice;
    switch(profile_choice){
      case 1:
      cin.ignore();
      labell_3:
      cout<<"\t\t\t\tEnter Your Special Key"<<endl;
      cout<<"\t\t\t\t";
      cin>>key;
      if(login_admin_key==key){
        cout<<"\t\t\t\tYou Have Logined Successfully!!!"<<endl;
        if(count_sound==1){
        if(vioce_change==1)
            PlaySound(TEXT("sucess"), NULL, SND_ASYNC);
        if(vioce_change==2)
            PlaySound(TEXT("sucess(metthev)"), NULL, SND_ASYNC);
        if(vioce_change==3)
            PlaySound(TEXT("sucess(kid)"), NULL, SND_ASYNC);
      }
      Sleep(2500);
        labell_1:
        loading();
        if(color_change==0)
        system("color 9f");
        if(color_change==1)
        system("color f0");
        if(color_change==2)
        system("color f4");
        if(color_change==3)
        system("color 21");
        if(color_change==4)
        system("color e0");
        else if(color_change==5)
        system("color 1f");
        cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
        Sleep(500);
        if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("ADMIN"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("ADMIN(matthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("ADMIN(kid)"), NULL, SND_ASYNC);
        }
	      cout<<"\t\t\t\t\t\t\t|           WELCOME TO ADMIN PENAL          |"<<endl;
        Sleep(500);
	      cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
        cout<<"\t\t\t\t\tPress 1  To Add Shoes"<<endl;
        cout<<"\t\t\t\t\tPress 2  To Remove Shoes"<<endl;
        cout<<"\t\t\t\t\tPress 3  To Update Price"<<endl;
        cout<<"\t\t\t\t\tPress 4  To View Stock"<<endl;
        cout<<"\t\t\t\t\tPress 5  To Offer Discout"<<endl;
        cout<<"\t\t\t\t\tPress 6  To View Analytics"<<endl;
        cout<<"\t\t\t\t\tPress 7  To Add Staff"<<endl;
        cout<<"\t\t\t\t\tPress 8  To Remove Staff"<<endl;
        cout<<"\t\t\t\t\tPress 9  To Update Your Key"<<endl;
        cout<<"\t\t\t\t\tPress 10 To Exist The Program"<<endl;
        cout<<"\t\t\t\t\tPress 11 To Goto Login Profile"<<endl;
        cout<<"\t\t\t\t\t";
        Sleep(1000);
        if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("option"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("option(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("option(kid)"), NULL, SND_ASYNC);
        }
        cin>>profile_choice;
        switch(profile_choice){
          case 1:
          loading();
          add_shoes();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Manu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 2:
          loading();
          remove_shoes();
          cout<<"\t\t\t\t\tPress 1 to Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 3:
          loading();
          updateprice_shoes();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 4:
          loading();
          viewstock_shoes(start_shoes);
          cout<<"\t\t\t\t\tPress 1 To goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 5:
          loading();
          add_discount_shoes();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 6:
          loading();
          analytics(); 
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 7: 
          loading();
          add_staff();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 8:
          loading();
          remove_staff();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Manu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 9:
          loading();
          cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t|            KEY CHANGING PENAL             |"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
          cout<<"\t\t\t\t\tEnter Your Previous Key"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>key;
          if(login_admin_key==key){
            cout<<"\t\t\t\t\tEnter Your New Key"<<endl;
            cout<<"\t\t\t\t\t";
            cin>>login_admin_key;
            cout<<"\t\t\t\t\tYour Key is Updated!!!"<<endl;
          }
          else{
            cout<<"\t\t\t\t\tYou Entered Wrong Key!!!!"<<endl;
          }
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_1;
          }
          else{
            loading();
            goto labell_2;
          }
          case 10:
          loading();
          goto labell_2;
          case 11:
          loading();
          goto labell_6;
          default:
          cout<<"\t\t\t\t\tYou Select Wrong Manu Going Again To Menu"<<endl;
          goto labell_1;
        }
      }
      else{
        cout<<"\t\t\t\t\tWrong Key!!!! Enter Again"<<endl;
        loading();
        goto labell_3;
      }
      case 2:
      labell_5:
      loading();
      if(start_staff==NULL){
          cout<<"\n\n\n\n\n\n\t\t\t\t\tThere Is No Staff Member Please Add Staff From Admin Section!!!"<<endl;
          cout<<"\n\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cin.ignore();
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            loading();
            goto labell_6;
          }
          else{
            loading();
            goto labell_2;
          }
      }
      else if(verify_login()){
        labell_4:
        loading();
        if(color_change==0)
        system("color 9f");
        if(color_change==1)
        system("color f0");
        if(color_change==2)
        system("color f4");
        if(color_change==3)
        system("color 21");
        if(color_change==4)
        system("color e0");
        if(color_change==5)
        system("color 1f");
        cout<<"\t\t\t\t\t\t\t--------------------------------------------"<<endl;
        Sleep(500);
        if(count_sound==1){
          PlaySound(TEXT("STAFF"), NULL, SND_ASYNC);
        }
        if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("STAFF"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("STAFF(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("STAFF(kid)"), NULL, SND_ASYNC);
        }
	      cout<<"\t\t\t\t\t\t\t|              STAFF PENAL                |"<<endl;
        Sleep(500);
	      cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
        cout<<"\t\t\t\t\tPress 1 To Order Shoes"<<endl;
        cout<<"\t\t\t\t\tPress 2 To View Product"<<endl;
        cout<<"\t\t\t\t\tPress 3 To Change Password"<<endl;
        cout<<"\t\t\t\t\tPress 4 To Exist From Program"<<endl;
        cout<<"\t\t\t\t\tPress 5 To Goto Login Profile"<<endl;
        Sleep(1000);
        if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("option"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("option(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("option(kid)"), NULL, SND_ASYNC);
        }
        cout<<"\t\t\t\t\t";
        cin>>profile_choice;
        switch (profile_choice){
          case 1:
          loading();
          placeorder();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_4;
          }
          else{
            loading();
            goto labell_2;
          }
          case 2:
          loading();
          viewstock_shoes(start_shoes);
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_4;
          }
          else{
            loading();
            goto labell_2;
          }
          case 3:
          loading();
          change_password();
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
          loading();
          goto labell_4;
          }
          else{
          loading();
          goto labell_2;
          }
          case 4:
          loading();
          goto labell_2;
          case 5:
          loading();
          goto labell_6;
          default:
          cout<<"\t\t\t\t\tYou Select Wrong Menu Going Again To Menu"<<endl;
          goto labell_4;
        }
      }
      else{
        cout<<"\t\t\t\t\tWrong  Credientials!!!!"<<endl;
        goto labell_5;
      }
      case 3:
      	{
          labell_7:
          loading();
          if(color_change==0)
          system("color 9f");
          if(color_change==1)
          system("color f0");
          if(color_change==2)
          system("color f4");
          if(color_change==3)
          system("color 21");
          if(color_change==4)
          system("color e0");
          if(color_change==5)
          system("color 1f");
          cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
          Sleep(500);
          if(count_sound==1){
            if(vioce_change==1)
              PlaySound(TEXT("setting"), NULL, SND_ASYNC);
            if(vioce_change==2)
              PlaySound(TEXT("setting(matthev)"), NULL, SND_ASYNC);
            if(vioce_change==3)
              PlaySound(TEXT("setting(kid)"), NULL, SND_ASYNC);
          }
	        cout<<"\t\t\t\t\t\t\t|            WELCOME TO SETTING              |"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
          if( count_sound==1){
      		  cout<<"\t\t\t\t\tPress 1 To Turn Off Sound!!!!"<<endl;
          }
          else{
            cout<<"\t\t\t\t\tPress 1 To Turn ONN Sound!!!!"<<endl;
          }
          cout<<"\t\t\t\t\tPress 2 To Change Voice!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 3 To Turn Change color!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 4 To Goto Main Manu!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 5 To Exist From Program!!!!"<<endl;
          Sleep(1000);
          if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("option"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("option(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("option(kid)"), NULL, SND_ASYNC);
        }
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          switch (profile_choice){
          case 1:
          if(count_sound==1){
      		  count_sound=0;
          }
          else{
            count_sound=1;
          }
          cout<<"\t\t\t\t\tsound changed succcessfully!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_7;
          }
          else{
            loading();
            goto labell_2;
          }
          case 2:
          loading();
          cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t|     WELCOME TO VOICE CHANGING PENEL        |"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
          cout<<"\t\t\t\t\tPress 1 To Change Voice Woman (DEFAULT)!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 2 To Change Voice Man!!!!"<<endl;
          cout<<"\t\t\t\t\tPress 3 To Change Voice Child!!!!"<<endl;
          if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("option"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("option(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("option(kid)"), NULL, SND_ASYNC);
          }
          cout<<"\t\t\t\t\t";
          cin>>vioce_change;
          cout<<"\n\t\t\t\t\tVoice changed succcessfully!!!!"<<endl;
          cout<<"\n\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_7;
          }
          else{
            loading();
            goto labell_2;
          }
          case 3:
          loading();
          cout<<"\t\t\t\t\t\t\t---------------------------------------------"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t|     WELCOME TO COLOR CHANGING PENEL        |"<<endl;
          Sleep(500);
	        cout<<"\t\t\t\t\t\t\t--------------------------------------------\n\n"<<endl;
          cout<<"\n\t\t\t\t\tPress 0 To Use Light Blue and Bright White (Default)"<<endl;
          cout<<"\t\t\t\t\tPress 1 To Use White Backgound With Black Text"<<endl;
          cout<<"\t\t\t\t\tPress 2 To Use White Backgound With Red Text"<<endl;
          cout<<"\t\t\t\t\tPress 3 To Use Green Backgound With Blue Text"<<endl;
          cout<<"\t\t\t\t\tPress 4 To Use Light Yellow Backgound With Black Text"<<endl;
          cout<<"\t\t\t\t\tPress 5 To Use Blue Backgound With White Text"<<endl;
          if(count_sound==1){
          if(vioce_change==1)
            PlaySound(TEXT("option"), NULL, SND_ASYNC);
          if(vioce_change==2)
            PlaySound(TEXT("option(metthev)"), NULL, SND_ASYNC);
          if(vioce_change==3)
            PlaySound(TEXT("option(kid)"), NULL, SND_ASYNC);
          }
          cout<<"\t\t\t\t\t";
          cin>>color_change;
          if(color_change==0)
          system("color 9f");
          if(color_change==1)
          system("color f0");
          if(color_change==2)
          system("color f4");
          if(color_change==3)
          system("color 21");
          if(color_change==4)
          system("color e0");
          if(color_change==5)
          system("color 1f");
          cout<<"\n\t\t\t\t\tColor changed succcessfully!!!!"<<endl;
          cout<<"\n\t\t\t\t\tPress 1 To Goto Previous Menu And Other Number To End Program"<<endl;
          cout<<"\t\t\t\t\t";
          cin>>profile_choice;
          if(profile_choice==1){
            goto labell_7;
          }
          else{
            loading();
            goto labell_2;
          }
          case 4:
          loading();
          goto labell_6;
          }
          case 5:
          loading();
          goto labell_2;
          default:
          goto labell_7;
		}
    }
    labell_2:
    return 0;
}

