#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include<string>
class police
{
   public:
   void disp()
   {
     cout<<"\t\t\t\t\t\t\t\t\tWELCOME TO POLICE MANAGEMENT SYSTEM\t\t\t\t\t\t\t\t\t\t\t\t"<<endl;
     cout<<"\n\n\n"<<endl;
	 cout<<"Which record do you want to view \n a)Officer records b)Criminal record\n"<<endl;
    }
};
class officerrecords:public police
{
    string id[50],name[100],address[80],dob[50],currentpost[80],doj[50],sex[50];
    public:
    int total=0;                    //to store total record in system
    void enter()
    {
      int ch=0;                     //to store how many records user want to enter
      cout<<"How many officer data do you want to enter ??"<<endl;
      cin>>ch;
      if(total==0)
      {
	     total=ch+total;
	     for(int i=0;i<ch;i++)
	     {
	         cout<<"\nEnter the data of officer "<<i+1<<endl;
	         cout<<"Enter name:"<<endl;
	         cin>>name[i];
	         cout<<"Enter id:"<<endl;
	         cin>>id[i];
	         cout<<"Enter gender:"<<endl;
	         cin>>sex[i];
	         cout<<"Enter address:"<<endl;
	         cin>>address[i];
	         cout<<"Enter date of birth[DD/MM/YYYY]:"<<endl;
	         cin>>dob[i];
	         cout<<"Enter current post:"<<endl;
	         cin>>currentpost[i];
	         cout<<"Enter date of joining[DD/MM/YYYY]:"<<endl;
	         cin>>doj[i];
	         cout<<"\n"<<endl;
	     }
      }
      else
      {
	   for(int i=total;i<ch+total;i++)
	    {
	     cout<<"Enter the data of officer"<<i+1<<endl;
	     cout<<"Enter name:"<<endl;
	     cin>>name[i];
	     cout<<"Enter id:"<<endl;
	     cin>>id[i];
	     cout<<"Enter gender:"<<endl;
	     cin>>sex[i];
	     cout<<"Enter address:"<<endl;
	     cin>>address[i];
	     cout<<"Enter date of birth(DD/MM/YYYY):"<<endl;
	     cin>>dob[i];
	     cout<<"Enter current post:"<<endl;
	     cin>>currentpost[i];
	     cout<<"Enter date of joining(DD/MM/YYYY):"<<endl;
	     cin>>doj[i];
	     cout<<"\n"<<endl;
	   }
	total=ch+total;
    }
}

void show()
{  
   ifstream onfile("officer_records.txt");
   if(!onfile)
   {
   	cerr<<"file not opened";
   	exit(1);
   }
    string line;
    while(getline(onfile,line))
    {
         cout<<line<<endl;
     }
   onfile.close();
}


void search()
{
   if(total==0)
   {
     cout<<"No data entered\n"<<endl;
   }
   else
   {
      string idd;            //to store id entered from user
      cout<<"\nEnter id of officer"<<endl;
      cin>>idd;
      for(int i=0;i<total;i++)
      {
	    if(idd==id[i])
	    {
	           cout<<"\nResult for officer "<<endl;
	           cout<<"Full name:"<<name[i]<<endl;
	           cout<<"Id:"<<id[i]<<endl;
	            cout<<"Enter gender:"<<sex[i]<<endl;
	           cout<<"Address:"<<address[i]<<endl;
	           cout<<"Dob:"<<dob[i]<<endl;
	           cout<<"Post of officer:"<<currentpost[i]<<endl;
	           cout<<"Date of joining:"<<doj[i]<<endl;
	           cout<<"\n"<<endl;
        }
	  }
    }
}


void update()
{
      if(total==0)
      {
	 cout<<"No data is entered\n"<<endl;
      }
      else
      {
           string rollno;        // to store id to be updated from user         
	       cout<<"\nEnter id of officer which you want change"<<endl;
	       cin>>rollno;
   	       for(int i=0;i<total;i++)
        	{
	           if(rollno==id[i])
	           {
	                cout<<"\nPrevious data entered:"<<endl;
	                cout<<"Full name:"<<name[i]<<endl;
	                cout<<"Id:"<<id[i]<<endl;
	                 cout<<"Enter gender:"<<sex[i]<<endl;
	                cout<<"Address:"<<address[i]<<endl;
	                cout<<"Dob:"<<dob[i]<<endl;
	                cout<<"Post of officer:"<<currentpost[i]<<endl;
	                cout<<"Date of joining:"<<doj[i]<<endl;
	                cout<<"\n Please enter new data"<<endl;
	                cout<<"Enter new name:"<<endl;
	                cin>>name[i];
	                cout<<"Enter gender:"<<endl;
	                cin>>sex[i];
	                cout<<"Enter new address:"<<endl;
	                cin>>address[i];
	                cout<<"Enter new date of birth (DD/MM/YYYY):"<<endl;
	                cin>>dob[i];
	                cout<<"Enter new current post:"<<endl;
	                cin>>currentpost[i];
	                cout<<"Enter new date of joining (DD/MM/YYYY):"<<endl;
	                cin>>doj[i];
	                cout<<"RECORD UPDATED.\nPlease click on save option to save updated record."<<endl;
	                cout<<"\n"<<endl;
	            }
	        }
        }
 }



  void delete1()
  {
    if(total==0)
    {
     cout<<"No data is entered yet\n"<<endl;
    }
    else
    {
      int a;                 //to store choice for all deleting records
      cout<<"\nAre you sure to delete all record"<<endl;
      cout<<"Press 1 to delete all record"<<endl;
      cin>>a;
      if(a==1)
      {
	      total=0;
	      cout<<"All record deleted !!\n please click on save option\n"<<endl;
      }
      else
      {
       	  cout<<"Please press 1 to delete all record"<<endl;
      }
    }
}  



 // Function to save data to a text file
    void saveToFile() {
        ofstream onFile("officer_records.txt");
        if (onFile.is_open()) {
            for (int i = 0; i < total; i++) {
                onFile << "Id:" << id[i] << endl;
                onFile << "Full name:" << name[i] << endl;
                onFile << "Gender:" << sex[i] << endl;
                onFile << "Address:" << address[i] << endl;
                onFile << "Dob:" << dob[i] << endl;
                onFile << "Post of officer:" << currentpost[i] << endl;
                onFile << "Date of joining:" << doj[i] << endl;
                onFile << "\n" << endl;
            }
            onFile.close();
            cout << "\nData saved to officer_records.txt\n" << endl;
        }
        else
		 {
            cout << "Unable to open file" << endl;
        }
    }
};



class criminal:public police
{
    string id1[50],name1[100],address1[80],dob1[50],doa[80],skin[50],crime[100],gender[50];
    public:
    int totals=0;               // to store total criminals records in system
    void add()
    {
      int cho=0;                 // to store how many user want to enter
      cout<<"How many criminal data do you want to enter ??"<<endl;
      cin>>cho;
      if(totals==0)
      {
	    totals=cho+totals;
	    for(int i=0;i<cho;i++)
	    {
	        cout<<"\nEnter the data of criminal "<<i+1<<endl;
	        cout<<"Enter name:"<<endl;
	        cin>>name1[i];
	        cout<<"Enter criminal id:"<<endl;
	        cin>>id1[i];
	        cout<<"Enter gender:"<<endl;
	        cin>>gender[i];
	        cout<<"Enter address:"<<endl;
	        cin>>address1[i];
	        cout<<"Enter date of birth (DD/MM/YYYY):"<<endl;
	        cin>>dob1[i];
	        cout<<"Enter of arrest (DD/MM/YYYY):"<<endl;
	        cin>>doa[i];
	        cout<<"Enter skin colour:"<<endl;
	        cin>>skin[i];
	        cout<<"Enter crime:"<<endl;
	        cin>>crime[i];
	        cout<<"\n"<<endl;
	     }
      }
      else
      {
	   for(int i=totals;i<cho+totals;i++)
	    {
	        cout<<"Enter the data of criminal "<<i+1<<endl;
	        cout<<"Enter name:"<<endl;
	        cin>>name1[i];
	        cout<<"Enter id:"<<endl;
	        cin>>id1[i];
	        cout<<"Enter gender:"<<endl;
	        cin>>gender[i];
	        cout<<"Enter address:"<<endl;
	        cin>>address1[i];
	        cout<<"Enter date of birth (DD/MM/YYYY):"<<endl;
	        cin>>dob1[i];
	        cout<<"Enter date of arrest (DD/MM/YYYY):"<<endl;
	        cin>>doa[i];
	        cout<<"Enter skin colour:"<<endl;
	        cin>>skin[i];
	        cout<<"Enter crime:"<<endl;
	        cin>>crime[i];
	        cout<<"\n"<<endl;
	    }
	  totals=cho+totals;
      }
    }
    
    
    

void display()
{  
   ifstream onfile("criminal_records.txt");
   if(!onfile)
   {
   	cerr<<"file not opened";
   	exit(1);
   }
    string line;
    while(getline(onfile,line))
    {
         cout<<line<<endl;
     }
   onfile.close();
}



void find()
{
   if(totals==0)
   {
     cout<<"No data entered\n"<<endl;
   }
   else
   {
      string iddd;               // to store id entered from user
      cout<<"\nEnter id of criminal"<<endl;
      cin>>iddd;
      for(int i=0;i<totals;i++)
      {
	    if(iddd==id1[i])
	    {
	         cout<<"\nResult for criminal "<<endl;
	         cout<<"Full name:"<<name1[i]<<endl;
	         cout<<"Id:"<<id1[i]<<endl;
	          cout<<"Gender"<<gender[i]<<endl;
	         cout<<"Address:"<<address1[i]<<endl;
	         cout<<"Dob:"<<dob1[i]<<endl;
	         cout<<"Date of arrest:"<<doa[i]<<endl;
	         cout<<"Skin colour:"<<skin[i]<<endl;
	          cout<<"Crime"<<crime[i]<<endl;
	         cout<<"\n"<<endl;
        }
	  }
    }
}


void edit()
{
      if(totals==0)
      {
	     cout<<"No data is entered\n"<<endl;
      }
      else
      {
           string roll;          // to store id entered from user
       	   cout<<"\nEnter id of criminal which you want change"<<endl;
	       cin>>roll;
	       for(int i=0;i<totals;i++)
	       {
	          if(roll==id1[i])
	          {
	           cout<<"\nPrevious data entered:"<<endl;
	           cout<<"Full name:"<<name1[i]<<endl;
	           cout<<"Id:"<<id1[i]<<endl;
	            cout<<"Gender"<<gender[i]<<endl;
	           cout<<"Address:"<<address1[i]<<endl;
	           cout<<"Dob:"<<dob1[i]<<endl;
	           cout<<"Date of arrest:"<<doa[i]<<endl;
	           cout<<"Skin colour:"<<skin[i]<<endl;
	            cout<<"Crime:"<<crime[i]<<endl;
	           cout<<"\n Please enter new data"<<endl;
	           cout<<"Enter new name:"<<endl;
	           cin>>name1[i];
	           cout<<"Enter gender:"<<endl;
	           cin>>gender[i];
	           cout<<"Enter new address:"<<endl;
	           cin>>address1[i];
	           cout<<"Enter new date of birth (DD/MM/YYYY):"<<endl;
	           cin>>dob1[i];
	           cout<<"Enter new date of arrest:"<<endl;
	           cin>>doa[i];
	           cout<<"Enter skin colour:"<<endl;
	           cin>>skin[i];
	           cout<<"Enter crime:"<<endl;
	           cin>>crime[i];
	           cout<<"RECORD UPDATED.Please click on save option."<<endl;
	           cout<<"\n"<<endl;
	         }
     	}
      }
}
 

  void remove()
  {
    if(totals==0)
    {
     cout<<"\nno data is entered yet\n"<<endl;
    }
    else
    {
      int b;
      cout<<"\nAre you sure to delete all record ??"<<endl;
      cout<<"Press 1 to delete all record"<<endl;
      cin>>b;
      if(b==1)
      {
	      totals=0;
	      cout<<"All record deleted !!\nPlease click on save button.\n"<<endl;
      }
      else
      {
	      cout<<"Please press 1 to delete all record"<<endl;
      }
    }
} 

  // Function to save data to a text file
    void saveFile() {
        ofstream onFile("criminal_records.txt");
        if (onFile.is_open()) 
		{
            for (int i = 0; i < totals; i++)
			 {
                onFile << "Id:" << id1[i] << endl;
                onFile << "Full name:" << name1[i] << endl;
                onFile << "Gender:" << gender[i] << endl;
                onFile << "Address:" << address1[i] << endl;
                onFile << "Dob:" << dob1[i] << endl;
                onFile << "date of arrest:" << doa[i] << endl;
                onFile << "skin colour:" << skin[i] << endl;
                onFile << "crime:" << crime[i] << endl;
                onFile << "\n" << endl;
            }
            onFile.close();
            cout << "\nData saved to criminal_records.txt\n" << endl;
        }
        else 
		{
            cout << "Unable to open file" << endl;
        }
    }
};


int main()
{
  int d;
  char choice;
  officerrecords ob;
  criminal ob1;
  ob.disp();
  cout<<"Please enter 'a' for officer records or 'b' for criminal records"<<endl;
  cin>>choice;
  if(choice=='a')
  {
  	   cout<<"WELCOME TO OFFICERS RECORDS\nWHAT DO YOU WANT ?\n"<<endl;
       while(1)
       {
           cout<<"1.Add"<<endl;
           cout<<"2.Show"<<endl;
           cout<<"3.Search"<<endl;
           cout<<"4.Update"<<endl;
           cout<<"5.Delete"<<endl;
           cout<<"6.save"<<endl;
           cout<<"7.exit"<<endl;
           cout<<"Enter your choice"<<endl;
           cin>>d;
           switch(d)
           {
                case 1:
                {
                   ob.enter();
                   break;
                }
                case 2:
                {
                   ob.show();
                   break;
                }
                case 3:
                {
                  ob.search();
                  break;
                }
                case 4:
                {
                   ob.update();
                   break;
                }
                case 5:
                {
                    ob.delete1();
                    break;
                }  
                case 6:
                	{
                ob.saveToFile(); // Call the saveToFile function
                break;	
					}
                case 7:
                {
                    exit(0);
                }
                default:
                {
                  cout<<"Invalid input"<<endl;
                  break;
                }
                
            }
        }
    }
    else if (choice=='b')
    {
    cout<<"WELCOME TO CRIMINAL RECORDS\nWHAT DO YOU WANT ?\n"<<endl;
       while(1)
       {
           cout<<"1.Add"<<endl;
           cout<<"2.Show"<<endl;
           cout<<"3.Search"<<endl;
           cout<<"4.Update"<<endl;
           cout<<"5.Delete"<<endl;
           cout<<"6.save"<<endl;
           cout<<"7.exit"<<endl;
           cout<<"Enter your choice"<<endl;
           cin>>d;
           switch(d)
           {
                case 1:
                {
                   ob1.add();
                   break;
                }
                case 2:
                {
                   ob1.display();
                   break;
                }
                case 3:
                {
                  ob1.find();
                  break;
                }
                case 4:
                {
                   ob1.edit();
                   break;
                }
                case 5:
                {
                    ob1.remove();
                    break;
                }  
                case 6:
                {
                ob1.saveFile(); // Call the saveToFile function
                break;	
				}
                case 7:
                {
                    exit(0);
                }
                default:
                {
                  cout<<"Invalid input"<<endl;
                  break;
                }
            }
        }
    }
    else
    {
    	cout<<"\nTHANK YOU FOR VISITING."<<endl;
	}
}