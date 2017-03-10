# Aj
/*It's all about the code!*/


 //    INCLUDED HEADER FILES        //    

  
  #include"stdio.h" 
  #include"conio.h"
  #include"fstream.h"
  #include"string.h"
  #include"stdlib.h"
 
  
//	     CLASS NAME : BOOK       //
  class book
  {
   int copies;
   char author[40];
   float price;   
   public:
			 char name[40];
			 void getdata();
			 void show();
			 void modify(int);
			 void modifyall();
  }b;

  fstream file;
  
 //	FUNCTIONS TO GET,SHOW & MODIFY DATA          //

  void book::getdata()
  {
	cout<<"\n \"ENTER DETAILS ABOUT BOOK U WANT TO ADD\" :";
	cout<<"\n\n\t\t  Enter Name Of Book :\t";
	gets(name);
	cout<<"\n\t\tEnter Name Of Author :\t";
	gets(author);
	cout<<"\n\t\tEnter No. Of Copies  :\t";
	cin>>copies;
	cout<<"\n\t\tEnter Price          :\t";
	cin>>price;

  }

  void book::show()
  {
	cout<<"\n\n             Name   :"<<name;
	cout<<"\n             Author :"<<author;
	cout<<"\n             Copies :"<<copies;
	cout<<"\n             Price  :"<<price<<endl;
  }

  void book::modify(int x)
  { show();
    copies=copies+x;
  }

  void book::modifyall()
  {
	show();
	cout<<"\n\nEnter new details\n";
	cout<<"\n\n\t\t  Enter Name Of Book :\t";
	gets(name);
	cout<<"\n\t\tEnter Name Of Author :\t";
	gets(author);
	cout<<"\n\t\tEnter Price          :\t";
	cin>>price;

  }
  
  //	    void main()     //
  
  void main()
  { clrscr();
	cout<<"\n\n\n\t\"Books are like mirrors: if a fool looks in,you cannot expect a\n\t genius to look out\"\n\t\t\t\t\t\t\t-J.K. Rowling\n";
	cout<<"\n\n\n\n\t\t\t\<<< WELCOME TO AC BOOKSTORE \>>>";
	getch();
  clrscr(); 
  int a,c;
  char ans;
  long pos;
  int copies;
  char name[40],found='f';
  z:
  clrscr();

  cout<<"\n\tEnter designation\n\t1. Shop Owner\n\t2. Customer\n\t3. Exit\n\n";
  cin>>a;
  
  //	     SHOP OWNER        //
  
  if(a==1)
  {
	clrscr();
	char user[40],pass[40];
    cout<<"\n\tSignup\n\n\tUsername : ";
	gets(user);
	cout<<"\n\tPassword : ";
	gets(pass);
	
	if(strcmp(user,"amit")==0 && strcmp(pass,"1234")==0)
	{ x:
	  clrscr();
	  cout<<"\n\n\tWHAT DO U WANT TO DO:\n\n";
	  cout<<"\n\t1 . TO ADD A BOOK";
      cout<<"\n\t2 . TO ORDER A BOOK";
      cout<<"\n\t3 . TO DELETE A BOOK";
	  cout<<"\n\t4 . TO MODIFY A BOOK";
      cout<<"\n\t5 . TO EXIT\n\n\t";	
	  	  
	  cin>>c;
	  switch(c)
	  {
	  case 1:{
			  clrscr();
			  file.open("book",ios::app|ios::binary);
			  b.getdata();
			  file.write((char*)&b,sizeof(b))<<flush;
			  getch();
			  clrscr();
			  cout<<"\n\tRecord has been successfully added to the file.\n\n";
			  file.close();
			  cout<<"\tDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='Y' || ans=='y') goto x;
			  else break;
			 }	
	  case 2:{clrscr();
		      file.open("book",ios::in|ios::out|ios::binary);
			  cout<<"Enter name of the book you wish to order:";
			  gets(name);
			  cout<<"\nEnter no. of copies:";
			  cin>>copies;
			  while(!file.eof())
			  { 
				pos=file.tellg();
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{ b.modify(copies);
			    file.seekg(pos);
				file.write((char*)&b,sizeof(b));
				found='t';
				break;
				}
			  }
			 if(found=='f')	cout<<"\nbook not found!!\n";
			 file.seekg(0);
			 while(!file.eof())
			  { 
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{b.show();}
			  }
			 getch();
			 file.close();
			 clrscr();
             cout<<"\nBooks have been ordered\n\nDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='Y' || ans=='y') goto x;
			  else break; 			 
	         }		 
	  case 3:{
			  int f=0;
			  clrscr();
			  cout<<"\n\n Enter The Name of the book you wish To Delete:";
			  gets(name);
			  ifstream fin("book",ios::in);
			  ofstream fout("book2",ios::out);
			  while(fin)
			  {
			   fin.read((char*)&b,sizeof(b));
			   if(strcmpi(b.name,name)==0)
			    { f=1; }
			   else fout.write((char*)&b,sizeof(b));
			  }
			  if(f==0) { clrscr();
						 cout<<"Book not Found\n"; }
			  fin.close();
			  fout.close();
			  remove ("book");
			  rename ("book2","book");
			  cout<<"\n\n\n\n\n\tRecord deleted\n\n";
			  cout<<"\tDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='Y' || ans=='y') goto x;
			  else break;
			  
			 }
	  case 4:{clrscr();
		      file.open("book",ios::in|ios::out|ios::binary);
			  cout<<"Enter name of the book you wish to modify:";
			  gets(name);
			  while(!file.eof())
			  { 
				pos=file.tellg();
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{ b.modifyall();
			    file.seekg(pos);
				file.write((char*)&b,sizeof(b));
				found='t';
				break;
				}
			  }
			 if(found=='f')	cout<<"\nbook not found!!\n";
			 file.seekg(0);
			 while(!file.eof())
			  { 
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{b.show();}
			  }
			 getch();
			 file.close();
			 clrscr();
             cout<<"\tDo you wish to continue? : ";
			 ans=getch();
			 if(ans=='Y' || ans=='y') goto x;
			 else break; 
			 }
	  case 5:{clrscr();		     
 			  goto z;
			 }		 
	  default:goto x;
	  }
	}	 
	else cout<<"\n\n INVALID username/password";
	getch();
	goto z;
  }
  
  //	     CUSTOMER        // 
  
  else if(a==2)
  {   y:
	  clrscr();
	  cout<<"\tWHAT DO U WANT TO DO:\n\n";
	  cout<<"\n\t1 . TO SHOW ALL BOOKS";
      cout<<"\n\t2 . TO CHECK AVAILABILITY";
      cout<<"\n\t3 . TO PURCHASE A BOOK";\
	  cout<<"\n\t4 . TO RETURN A BOOK";
      cout<<"\n\t5 . TO EXIT\n\n\t";	
	  	  
	  cin>>c;
	  
	  switch(c)
	  {
	  case 1:{clrscr();
			  file.open("book",ios::in|ios::binary);
			  file.seekg(0);
			  cout<<"\n\n";
			  int ctr=0;
			  cout<<"List of all the books available\n";
			  while(file.read((char*)&b,sizeof(b)))
				  {
					ctr++;
					cout<<"\n"<<ctr<<". "<<b.name;
				  }
			  getch();
			  file.seekp(0,ios::end);
			  file.close();
			  clrscr();
			  cout<<"End of records\n";
			  cout<<"Do you wish to continue? : ";
			  ans=getch();
			  if(ans=='y'|| ans=='Y') goto y;
			  else break;
		     } 
	  case 2:{clrscr();
			  file.open("book",ios::in|ios::binary);
			  file.seekg(0);
			  cout<<"\n\n\n Enter the name of the book :";
			  gets(name);
			  int e=0;
			  while(file.read((char*)&b,sizeof(b)))
				{
				 if(strcmpi(b.name,name)==0)
					 {  cout<<"\tBook Available!!!\n";
						b.show();
						e=1;
						getch();
					 }
				}
			  if(e==0) { cout<<"Book not available\n"; }
			  file.close();
			  cout<<"\nDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='y'|| ans=='Y') goto y;
			  else break;
			 }
	  case 3:{clrscr();
		      file.open("book",ios::in|ios::out|ios::binary);
			  cout<<"Enter name of the book you wish to purchase:";
			  gets(name);
			  cout<<"\nEnter no. of copies:";
			  cin>>copies;
			  copies=0-copies;
			  while(!file.eof())
			  { 
				pos=file.tellg();
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{ b.modify(copies);
			    file.seekg(pos);
				file.write((char*)&b,sizeof(b));
				found='t';
				break;
				}
			  }
			 if(found=='f')	cout<<"\nbook not found!!\n";
			 file.seekg(0);
			 while(!file.eof())
			  { 
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{b.show();}
			  }
			 getch();
			 file.close();
			 clrscr();
             cout<<"\tThanks for purchasing\n\n\tDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='Y' || ans=='y') goto y;
			  else break;}
	  case 4:{clrscr();
		      file.open("book",ios::in|ios::out|ios::binary);
			  cout<<"Enter name of the book you wish to return:";
			  gets(name);
			  cout<<"\nEnter no. of copies:";
			  cin>>copies;
			  while(!file.eof())
			  { 
				pos=file.tellg();
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{ b.modify(copies);
			    file.seekg(pos);
				file.write((char*)&b,sizeof(b));
				found='t';
				break;
				}
			  }
			 if(found=='f')	cout<<"\nbook not found!!\n";
			 file.seekg(0);
			 while(!file.eof())
			  { 
				file.read((char*)&b,sizeof(b));
				if(strcmpi(b.name,name)==0)
				{b.show();}
			  }
			 getch();
			 file.close();
			 clrscr();
             cout<<"\tDo you wish to continue? : ";
			  ans=getch();
			  if(ans=='Y' || ans=='y') goto y;
			  else break;}
	  case 5:{clrscr();		     
 			  goto z;
			 }
	  default:goto y;
	  }
  }
  else if(a==3) {clrscr();		     
				 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t       \"THANKS FOR VISITING\"";
			     getch();
				 exit(1);
				}
  else cout<<"\n\nInvalid choice \n";
  getch();
  goto z;
  }
  //Program over
	  
	  
	  
	  

	
  
 
  
  
  
  
  

 
