#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
using namespace std;



string bus_open()
    {
        ifstream temp_busread;
        string temp_busno = "none",temp_driver,temp_source,temp_destination,temp_arrival,temp_departure;
        string no;
        cout<<"Enter the Bus Number"<<endl;
        cin>>no;
        temp_busread.open("BUSFILE.csv");
        for(int i=0;temp_busread.good();i++)
        {
            getline(temp_busread,temp_busno,',');
            getline(temp_busread,temp_driver,',');
            getline(temp_busread,temp_source,',');
            getline(temp_busread,temp_destination,',');
            getline(temp_busread,temp_arrival,',');
            getline(temp_busread,temp_departure,'\n');
            if(temp_busno == no)
             {
              cout<<endl<<"The Bus is :-"<<endl<<endl;
              cout<<"Bus Number :-"<<temp_busno<<endl<<"Bus Driver :-"<<temp_driver<<endl<<"From :-"<<temp_source<<endl;
              cout<<"To :-"<<temp_destination<<endl<<"Arrival :-"<<temp_arrival<<endl<<"Departure :-"<<temp_departure<<endl<<endl;

              return (temp_busno);
            }



        }


    }

    class seat
    {
    public:
        string no;
        string passenger;
        string age;
        string phone;
        string status;

    };

class bus
{
    string busno;
    string driver;
    string source;
    string destination;
    string arrival;
    string departure;
    string add =".csv";
    string filename;

    int seats = 50;
    int seatno;
public:
    bus()
    {
        busno =" ";
        driver = " ";
        source = " ";
        destination =" ";
        arrival =" ";
        departure =" ";
        filename= " ";
    }

    void set_busno()
    {
        cout<<endl<<endl<<"          Bus Number :- ";
        cin>>busno;
    }

    void set_driver()
    {
        cout<<endl<<endl<<"          Bus Driver Name :-";
        cin>>driver;
    }


    void set_source()
    {
        cout<<endl<<endl<<"          From :- ";
        cin>>source;
    }
    void set_destination()
    {
        cout<<endl<<endl<<"          To :-";
        cin>>destination;
    }

    void set_arrival()
    {
        cout<<endl<<"          Arrival Time :-";
        cin>>arrival;
    }
    void set_departure()
    {
        cout<<endl<<endl<<"          Departure Time :-";
        cin>>departure;
    }

    void install()
    {
      string text;
       bus b[50];
       set_busno();
       set_driver();
       set_source();
       set_destination();
       set_arrival();
       set_departure();
       ofstream busfile;
       ifstream tempfile;
       tempfile.open("BUSFILE.csv");
       if(!tempfile)
       {
       tempfile.close();
       busfile.open("BUSFILE.csv",ios::app);
       busfile<<"BUS NO"<<","<<"BUS DRIVER"<<","<<"SOURCE"<<","<<"DESTINATION"<<","<<"ARRIVAL"<<","<<"DEPARTURE"<<endl;
       busfile<<busno<<","<<driver<<","<<source<<","<<destination<<","<<arrival<<","<<departure<<endl;
       busfile.close();
       }
       else
       {
       busfile.open("BUSFILE.csv",ios::app);
       busfile<<busno<<","<<driver<<","<<source<<","<<destination<<","<<arrival<<","<<departure<<endl;
       busfile.close();
       }
       tempfile.close();
       filename = busno;
       filename.append(add);
       busfile.open(filename.c_str());
       for(int i=1;i<=50;i++)
       {

           busfile<<i<<","<<" "<<","<<" "<<","<<" "<<","<<" "<<endl;
       }
       busfile.close();
       cout<<"        BUS INSTALLED SUCCESSFULLY"<<endl;

    }



    void reserve_seat()
    {
       int i;
       string temp;
       ofstream buswrite;
       ifstream busread;
       busno = bus_open();
       if(busno == "none")
       {
           cout<<"Bus not Available"<<endl;
       }
       else
       {
           seat v[50];
           filename = busno;
           filename.append(add);
           busread.open(filename.c_str());
           for(i=0;i<50;i++)
           {
               getline(busread,v[i].no,',');
               getline(busread,v[i].status,',');
               getline(busread,v[i].passenger,',');
               getline(busread,v[i].age,',');
               getline(busread,v[i].phone,'\n');
               if(v[i].passenger != " ")
               {
                   seats--;
               }
           }


           cout<<endl<<"Vacant Seats Available :-"<<seats<<endl;
           string seat;
           while(1)
           {
           cout<<endl<<endl<<"Enter the Seat Number :-";
           cin>>seat;
           stringstream geek(seat);
           int x = 0;
           geek>>x;
           if(x<=50)
           {
               break;
           }
           else
           {
               cout<<endl<<"Only 50 Seats available"<<endl<<"Enter a Valid Seat"<<endl;
           }
           }


           for(i=0;v[i].no!= seat;i++);
           if(v[i].status !="reserved")
           {
           cout<<endl<<"Enter the Passenger Name :-"<<endl;
           cin>>v[i].passenger;
           cout<<"Enter the Passenger Age"<<endl;
           cin>>v[i].age;
           while(1)
           {
           cout<<endl<<"Enter the Passenger Phone Number :-"<<endl;
           cin>>v[i].phone;
           stringstream geek(v[i].phone);
           int s = 0;
           geek>>s;
           if(s/100000>10000 && s/100000 < 100000)
           {
               break;
           }
           else
           {
               cout<<endl<<"Enter a 10 digit Phone Number"<<endl;
           }
           }
           v[i].status = "reserved";
           cout<<endl<<"Seat Reserved Successfully"<<endl;
           }
           else
           {
               cout<<"Seat is Already Reserved"<<endl;

           }


           busread.close();

           buswrite.open(filename.c_str());
           if(seats == 50)
           {
               buswrite<<"SEAT NO"<<","<<"STATUS"<<","<<"PASSENGER NAME"<<","<<"AGE"<<","<<"PHONE"<<endl;
           }
           for(i=0;i<50;i++)
           {
               buswrite<<v[i].no<<","<<v[i].status<<","<<v[i].passenger<<","<<v[i].age<<","<<v[i].phone<<endl;
           }
           buswrite.close();

        }


   }


   void show_bus()
   {
       int i;
       string temp;
       ofstream buswrite;
       ifstream busread;
       busno = bus_open();
       if(busno == "none")
       {
           cout<<"Bus not Available"<<endl;
       }
       else
       {
           seat v[51];
           filename = busno;
           filename.append(add);
           busread.open(filename.c_str());
           for(i=0;i<50;i++)
           {
               getline(busread,v[i].no,',');
               getline(busread,v[i].status,',');
               getline(busread,v[i].passenger,',');
               getline(busread,v[i].age,',');
               getline(busread,v[i].phone,'\n');
               if(v[i].passenger != " " && v[i].passenger !="PASSENGER NAME")
               {
                   seats--;
               }
           }

            for(i=0;i<50;i++)
            {
                if(v[i].status !="reserved")
                {
                    v[i].status ="        ";
                }
            }




           cout<<endl<<"Vacant Seats Available :-"<<seats<<endl<<endl;

           cout<<"            "<<"1.   "<<v[1].status<<"   "<<"2.   "<<v[2].status<<"   "<<"3.   "<<v[3].status<<"   "<<"4.   "<<v[4].status<<"   "<<"5.   "<<v[5].status<<"   "<<endl;
           cout<<"            "<<"6.   "<<v[6].status<<"   "<<"7.   "<<v[7].status<<"   "<<"8.   "<<v[8].status<<"   "<<"9.   "<<v[9].status<<"   "<<"10.   "<<v[10].status<<"   "<<endl;
           cout<<"            "<<"11.  "<<v[11].status<<"   "<<"12.  "<<v[12].status<<"   "<<"13.  "<<v[13].status<<"   "<<"14.  "<<v[14].status<<"   "<<"15.  "<<v[15].status<<"   "<<endl;
           cout<<"            "<<"16.  "<<v[16].status<<"   "<<"17.  "<<v[17].status<<"   "<<"18.  "<<v[18].status<<"   "<<"19.  "<<v[19].status<<"   "<<"20.  "<<v[20].status<<"   "<<endl;
           cout<<"            "<<"21.  "<<v[21].status<<"   "<<"22.  "<<v[22].status<<"   "<<"23.  "<<v[23].status<<"   "<<"24.  "<<v[24].status<<"   "<<"25.  "<<v[25].status<<"   "<<endl;
           cout<<"            "<<"26.  "<<v[26].status<<"   "<<"27.  "<<v[27].status<<"   "<<"28.  "<<v[28].status<<"   "<<"29.  "<<v[29].status<<"   "<<"30.  "<<v[30].status<<"   "<<endl;
           cout<<"            "<<"31.  "<<v[31].status<<"   "<<"32.  "<<v[32].status<<"   "<<"33.  "<<v[33].status<<"   "<<"34.  "<<v[34].status<<"   "<<"35.  "<<v[35].status<<"   "<<endl;
           cout<<"            "<<"36.  "<<v[36].status<<"   "<<"37.  "<<v[37].status<<"   "<<"38.  "<<v[38].status<<"   "<<"39.  "<<v[39].status<<"   "<<"40.  "<<v[40].status<<"   "<<endl;
           cout<<"            "<<"41.  "<<v[41].status<<"   "<<"42.  "<<v[42].status<<"   "<<"43.  "<<v[43].status<<"   "<<"44.  "<<v[44].status<<"   "<<"45.  "<<v[45].status<<"   "<<endl;
           cout<<"            "<<"46.  "<<v[46].status<<"   "<<"47.  "<<v[47].status<<"   "<<"48.  "<<v[48].status<<"   "<<"49.  "<<v[49].status<<"   "<<"50.  "<<v[50].status<<"   "<<endl;
       }

   }



   void delete_bus()
   {
       int i,k=0;
       ifstream temp_busread;
       ofstream temp_buswrite;
       string temp_busno;
       string temp_filename;

       int count=0;
       bus b[50];

       temp_busread.open("BUSFILE.csv");
       for(int i=0;temp_busread.good();i++)
        {
            getline(temp_busread,b[i].busno,',');
            getline(temp_busread,b[i].driver,',');
            getline(temp_busread,b[i].source,',');
            getline(temp_busread,b[i].destination,',');
            getline(temp_busread,b[i].arrival,',');
            getline(temp_busread,b[i].departure,'\n');
            count++;
        }
        temp_busread.close();

        cout<<"Enter the Bus Number to be Deleted"<<endl;
        cin>>temp_busno;
        for(k=0;k<count;k++)
        {
            if(b[k].busno == temp_busno)
            {
                temp_filename = b[k].busno;
                break;


            }
        }

            cout<<endl<<"The Deleted Bus is :-"<<endl<<endl;
                cout<<"Bus Number :-"<<b[k].busno<<endl<<"Bus Driver :-"<<b[k].driver<<endl<<"From :-"<<b[k].source<<endl;
                cout<<"To :-"<<b[k].destination<<endl<<"Arrival :-"<<b[k].arrival<<endl<<"Departure :-"<<b[k].departure<<endl<<endl;
                while(k<count)
                {
                  b[k] = b[k+1];
                  k++;

                }
                cout<<"Bus Deleted Successfully"<<endl;
        temp_buswrite.open("BUSFILE.csv");
        for(k=0;k<count;k++)
        {
            temp_buswrite<<b[k].busno<<","<<b[k].driver<<","<<b[k].source<<","<<b[k].destination<<","<<b[k].arrival<<","<<b[k].departure<<endl;
        }
        temp_buswrite.close();
        temp_filename.append(add);
        remove(temp_filename.c_str());




   }


   void cancel_seat()
   {
       int i;
       seat s[51];
       fstream busfile;
       string temp_filename;
       string temp_busno;
       string temp_seat;
       cout<<endl<<"Enter the Bus Number :-";
       cin>>temp_busno;
       temp_filename = temp_busno;
       temp_filename.append(add);
       busfile.open(temp_filename.c_str(),ios::in);

       for(i=0;i<50;i++)
       {
           getline(busfile,s[i].no,',');
           getline(busfile,s[i].status,',');
           getline(busfile,s[i].passenger,',');
           getline(busfile,s[i].age,',');
           getline(busfile,s[i].phone,'\n');
       }
       cout<<endl<<"Enter the Seat Number :-"<<endl;
       cin>>temp_seat;

       for(i=0;i<=50;i++)
       {
           if(s[i].no == temp_seat)
           {
               cout<<"Passenger Cancelled is "<<endl;
               cout<<"Seat Number :-"<<s[i].no<<endl<<"Passenger Name :-"<<s[i].passenger<<endl<<"Passenger Age :-"<<s[i].age<<endl<<"Phone Number :-"<<s[i].phone<<endl<<endl;
               s[i].status =" ";
               s[i].passenger = " ";
               s[i].age =" ";
               s[i].phone = " ";
               cout<<"Reservation Cancelled Successfully"<<endl<<endl;
           }
       }
       busfile.close();


       busfile.open(temp_filename.c_str(),ios::out);
       for(i=0;i<=50;i++)
       {
           busfile<<s[i].no<<","<<s[i].status<<","<<s[i].passenger<<","<<s[i].age<<","<<s[i].phone<<endl;


       }
       busfile.close();


   }






};

int login()
   {
       int choice;
       int p=0;
       int t =0;
       string username;
       string password;
       char temp[55];
       string username1;
       string password1;
       fstream file;
       cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
       cout<<"----------------------------------------------- LOGIN PAGE --------------------------------------------------------"<<endl;
       cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;

       cout<<endl<<endl<<"                  1. REGISTER AS ADMIN"<<endl;
       cout<<endl<<endl<<"                  2. LOGIN"<<endl;
       cin>>choice;
       switch(choice)
       {
       case 1:
           file.open("ADMIN USERS.csv",ios::out | ios::app);
           cout<<endl<<endl<<"                USERNAME :- ";
           cin>>username;
           cout<<endl<<endl<<"                PASSWORD :-";


          do{
             temp[p]=getch();
             if(temp[p]!='\r')
                {
                  cout<<"*";
                }
              p++;
            }while(temp[p-1]!='\r');
            temp[p-1]='\0';
            password = temp;;
           file<<username<<","<<password<<endl;
           t = 1;
           file.close();
        break;

         case 2:
             p =0;
           cout<<endl<<endl<<"                USERNAME :-";
           cin>>username;
           cout<<endl<<endl<<"                PASSWORD :-";
           do{
             temp[p]=getch();
             if(temp[p]!='\r')
                {
                  cout<<"*";
                }
              p++;
            }while(temp[p-1]!='\r');
            temp[p-1]='\0';
            password = temp;

           file.open("ADMIN USERS.csv",ios::in);
           while(file.good())
           {
           getline(file,username1,',');
           getline(file,password1,'\n');
           if(username1 ==username && password1 == password)
           {

               t =2;
           }
           }
           break;

         default:
            cout<<"Invalid Choice"<<endl;
            break;

         }
           if(t == 1)
           {
               cout<<endl<<endl<<"               ACCOUNT CREATED SUCCESSFULLY"<<endl;
           }
           else if(t ==2)
           {
               cout<<endl<<endl<<"               LOGGED IN SUCCESSFULLY"<<endl;
           }
           else if(t == 0)
           {
               cout<<endl<<endl<<"                WRONG USERNAME OR PASSWORD";
               cout<<endl<<endl<<"                TRY  AGAIN"<<endl;

           }
           return(t);







   }





int main()
{
    int i,t=0;
    bus b[50];
    while(1)
    {
    system("cls");
    system("color 0E");
    t = login();
    if(t==2)
    {
        getch();
      break;
    }
    getch();
    }
    for(i=0;i<50;i++)
    {
    system("cls");
    system("color 5E");
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<"--------------------------------------BUS  RESERVATION SYSTEM--------------------------------------------"<<endl;
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl<<endl;

    cout<<"                                            1.BUS  INSTALL"<<endl;
    cout<<"                                            2.BUS  RESERVATION"<<endl;
    cout<<"                                            3.SHOW  BUS"<<endl;
    cout<<"                                            4.DELETE  BUS"<<endl;
    cout<<"                                            5.CANCEL  RESERVATION."<<endl;

    cin>>t;
    switch(t)
    {
        case 1:
          system("cls");
           system("color 3E");
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
          cout<<endl<<"--------------------------------------BUS  INSTALLATION--------------------------------------------"<<endl;
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
          b[i].install();
          getch();
          break;

        case 2:
            system("cls");
            system("color 4F");
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
          cout<<endl<<"--------------------------------------BUS  RESERVATION-------------------------------------------------------"<<endl;
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
           b[i].reserve_seat();
           getch();
           break;

        case 3:
            system("cls");
            system("color 0E");
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
          cout<<endl<<"--------------------------------------BUS  DISPLAY----------------------------------------------------------"<<endl;
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
           b[i].show_bus();
           getch();
           break;

           case 4:
            system("cls");
            system("color 8E");
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
          cout<<endl<<"--------------------------------------BUS  CANCELLATION--------------------------------------------"<<endl;
          cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
           b[i].delete_bus();
           getch();
           break;

           case 5:
            system("cls");
            system("color FC");
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
            cout<<endl<<"--------------------------------------CANCEL RESERVATION--------------------------------------------"<<endl;
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
            b[i].cancel_seat();
            getch();
            break;

          default:
          cout<<"                Invalid Choice"<<endl;
          break;
    }

    }


    return 0;
}
