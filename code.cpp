#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu{
protected:
    string userName;  // hide admin name
public:
    ManageMenu(){

        system("color 0A"); //Change terminal color...
        cout<<"\n\n\n\tEnter yout Name to continue as an Admin: "<<endl;
        getline(cin>>ws, userName);
        system("cls");
        menu();
    }

    ~ManageMenu(){};
};

class Customers{
    public:
        string name, gender, address;
        int age, mobNo;
        static int cusID;
        string fileData;

        void getDetails(){
            ofstream out("old-customers.txt", ios::app); //app - append mode (add at eof)...
            
            cout<<"Enter Customer ID: "<<endl;
            cin>>cusID;
            cout<<"Enter Customer Name: "<<endl;
            getline(cin>>ws, name);
            cout<<"Enter Customer Gender: "<<endl;
            getline(cin>>ws, gender);
            cout<<"Enter Customer Age: "<<endl;
            cin>>age;
            cout<<"Enter Customer Address: "<<endl;
            getline(cin>>ws, address);
            cout<<"Enter Customer Mobile No.: "<<endl;
            cin>>mobNo;

            out << "\nCustomer ID: "<<cusID<<"\nName: "<<name<<"\nGender: "<<gender<<"\nAge: "<<age<<"\nAddress: "<<address<<"\nMobile No.: "<<mobNo<<endl;
            
            // close the old-customer.txt file...
            out.close();
            cout<<"\nSAVED \nNOTE: your details are saved for record purpose."<<endl;
        }

        void showDetails(){
            
            ifstream in("old-customers.txt");
            {
                // if file not successfully opened......
                if(!in){
                    cout<<"File Not Found!"<<endl;
                }
                //Execute until eof.....
                while(!in.eof()){
                    getline(in, fileData);
                    cout<<fileData<<endl;
                }
                //closing the old-customers.txt file...
                in.close();
            }
        }

};

int Customers :: cusID;

class Cabs{
    public:
        int cabChoice;
        int dist;
        float cabCost;
        static float lastCabCost;

        void cabDetails(){
            cout<<"We collaborated with fastest, safest and smartest cab services around the country"<<endl;
            cout<<"---------------ABC Cabs---------------"<<endl;
            cout<<"1. Rent a standard cab - Rs.15 per KM"<<endl;
            cout<<"2. Rent a luxury cab - Rs.25 per KM"<<endl;

            cout<<"\nTo calculate cost for your journey:"<<endl;
            cout<<"Enter your preferred cab choice"<<endl;
            cin>>cabChoice;
            cout<<"Enter kilometers yo have to travel"<<endl;
            cin>>dist;

            int hireCab;

            if(cabChoice == 1){
                cabCost = dist*15;
                cout<<"\nYour ride costs "<<cabCost<<" rupees for a standard cab"<<endl;
                cout<<"Press 1 to hire this cab"<<endl;
                cout<<"Press 2 to select another cab"<<endl;
                cin>>hireCab;

                system("cls"); //to make the terminal clear...

                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout<<"\nYou have successfully booked a standard cab"<<endl;
                    cout<<"Go to Menu and take the receipt"<<endl;
                }
                else if(hireCab == 2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
                    Sleep(999); //suspend execution...
                    system("cls");
                    cabDetails();
                }
            }
            else if(cabChoice == 2){
                cabCost = dist*25;
                cout<<"\nYour ride costs "<<cabCost<<" rupees for a luxury cab"<<endl;
                cout<<"Press 1 to hire this cab"<<endl;
                cout<<"Press 2 to select another cab"<<endl;
                cin>>hireCab;

                system("cls"); //to make the terminal clear...

                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout<<"\nYou have successfully booked a luxury cab"<<endl;
                    cout<<"Go to Menu and take the receipt"<<endl;
                }
                else if(hireCab == 2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input! Redirecting to previous menu \nPlease wait...!"<<endl;
                    Sleep(999); //suspend execution...
                    system("cls");
                    cabDetails();
                }
            }
            else{
                cout<<"Invalid Input! Redirecting to Main Menu \nPlease wait...!"<<endl;
                Sleep(999);
                system("cls");
                menu();
            }

            cout<<"\nPress 1 to Redirect Main Menu: "<<endl;
            cin>>hireCab;
            system("cls");
            if(hireCab == 1){
                menu();
            }
            else{
                menu();
            }
        }
};

float Cabs :: lastCabCost;

class Booking{
    public:
        int choiceHotel;
        int packChoice;
        static float hotelCost;

        void hotels(){
            string hotelName[] = {"Castle Inn", "Alpha Residency", "Magenta Bay"};
            for(int i=0; i<3; ++i){
                cout<<(i+1)<<". "<<hotelName[i]<<endl;
            }

            cout<<"Currently we have collaborated above listed hotels"<<endl;
            cout<<"Enter the hotel number you want to book. \n Or press any other key to go back."<<endl;
            cin>>choiceHotel;

            system("cls");

            if(choiceHotel == 1){
                cout<<"---------------WELCOME TO HOTEL CASTLE INN---------------"<<endl;
                cout<<"Packages offered by Castle Inn"<<endl;
                cout<<"1. Standard Pack:"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.5000"<<endl;
                cout<<"2. Premium Pack:"<<endl;
                cout<<"\tEnjoy Premium: Rs.9000"<<endl;
                cout<<"3. Luxury Pack:"<<endl;
                cout<<"\tLive a Luxury life at Castle Inn: Rs.12000"<<endl;
                
                cout<<"Enter package number or any other key to go back."<<endl;
                cin>>packChoice;

                system("cls");

                if(packChoice == 1){
                    hotelCost = 5000.00;
                    cout<<"\nYou have successfully booked Standard Pack at Castle Inn"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 2){
                    hotelCost = 9000.00;
                    cout<<"\nYou have successfully booked Preimium Pack at Castle Inn"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 3){
                    hotelCost = 12000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at Castle Inn"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu. \nPlease wait...!"<<endl;
                    Sleep(999);
                    system("cls");
                    hotels();
                }

                int goToMenu;
                cout<<"Press 1 to redirect to Main Menu."<<endl;
                cin>>goToMenu;
                if(goToMenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else if(choiceHotel == 2){
                cout<<"---------------WELCOME TO HOTEL ALPHA RESIDENCY---------------"<<endl;
                cout<<"Packages offered by Alpha Residency"<<endl;
                cout<<"1. Standard Pack:"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.3500"<<endl;
                cout<<"2. Premium Pack:"<<endl;
                cout<<"\tEnjoy Premium: Rs.5000"<<endl;
                cout<<"3. Special Premium Pack:"<<endl;
                cout<<"\tEnjoy Special Premium Pack at Alpha Residency: Rs.7500"<<endl;
                
                cout<<"Enter package number or any other key to go back."<<endl;
                cin>>packChoice;

                system("cls");

                if(packChoice == 1){
                    hotelCost = 3500.00;
                    cout<<"\nYou have successfully booked Standard Pack at Alpha Residency"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 2){
                    hotelCost = 5000.00;
                    cout<<"\nYou have successfully booked Preimium Pack at Alpha Residency"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 3){
                    hotelCost = 7500.00;
                    cout<<"\nYou have successfully booked Special Premium Pack at Alpha Residency"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu. \nPlease wait...!"<<endl;
                    Sleep(999);
                    system("cls");
                    hotels();
                }

                int goToMenu;
                cout<<"Press 1 to redirect to Main Menu."<<endl;
                cin>>goToMenu;
                if(goToMenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else if(choiceHotel == 3){
                cout<<"---------------WELCOME TO HOTEL MAGENTA BAY---------------"<<endl;
                cout<<"Packages offered by Me"<<endl;
                cout<<"1. Standard Pack:"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.3000"<<endl;
                cout<<"2. Premium Pack:"<<endl;
                cout<<"\tEnjoy Premium: Rs.6000"<<endl;
                cout<<"3. Luxury Pack:"<<endl;
                cout<<"\tEnjoy Luxury Pack at Magenta Bay: Rs.10000"<<endl;
                
                cout<<"Enter package number or any other key to go back."<<endl;
                cin>>packChoice;

                system("cls");

                if(packChoice == 1){
                    hotelCost = 3000.00;
                    cout<<"\nYou have successfully booked Standard Pack at Magenta Bay"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 2){
                    hotelCost = 6000.00;
                    cout<<"\nYou have successfully booked Preimium Pack at Magenta Bay"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else if(packChoice == 3){
                    hotelCost = 10000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at Magenta Bay"<<endl;
                    cout<<"Go to Main Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu. \nPlease wait...!"<<endl;
                    Sleep(999);
                    system("cls");
                    hotels();
                }

                int goToMenu;
                cout<<"Press 1 to redirect to Main Menu."<<endl;
                cin>>goToMenu;
                if(goToMenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else{
                cout<<"Invalid Input! Redirecting to Main Menu. \nPlease wait...!"<<endl;
                Sleep(999);
                system("cls");
                menu();
            }
        }
};

float Booking :: hotelCost;

// for calculating charges. Multi-level Inheritance Concept used here....
class Charges : public Booking, Cabs, Customers{
    public:
        void printBill(){
            ofstream out("receipt.txt");

            out<<"--------------ABC Travel Agency--------------"<<endl;
            out<<"------------------Receipt--------------------"<<endl;
            out<<"_____________________________________________"<<endl;
            out<<"Customer ID: "<<Customers :: cusID<<endl<<endl;
            out<<"Description \t\tTotal"<<endl;
            out<<"Hotel Cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
            out<<"Travel (Cab) Cost:\t"<<fixed<<setprecision(3)<<Cabs::lastCabCost<<endl;
            out<<"_____________________________________________"<<endl;
            out<<"Total Charges:\t\t"<<fixed<<setprecision(2)<<(Booking::hotelCost + Cabs::lastCabCost)<<endl;
            out<<"_____________________________________________"<<endl;
            out<<"-----------------THANK YOU-------------------"<<endl;

            out.close();
        }

        void showBill(){
            ifstream in("receipt.txt");

            string fileLine;
            if(!in){
                cout<<"File Opening Error...!"<<endl;
            }
            else{
                while(!in.eof()){
                    getline(in, fileLine);
                    cout<<fileLine<<endl;
                }
            }

            in.close();
        }
};

// Main Menu function...
void menu(){

    int mainChoice;
    int inChoice;
    int goToMenu;


    cout<<"\t\t    *ABC Travels*\n"<<endl;
    cout<<"-------------------Main Menu-------------------"<<endl;
    cout<<"\t________________________________________"<<endl;
    cout<<"\t|\tCustomer Management  -> 1\t|"<<endl;
    cout<<"\t|\tCabs Management      -> 2\t|"<<endl;
    cout<<"\t|\tHotels Management    -> 3\t|"<<endl;
    cout<<"\t|\tCharges and Bill     -> 4\t|"<<endl;
    cout<<"\t|\tExit                 -> 5\t|"<<endl;
    cout<<"\t________________________________________"<<endl;
    
    cout<<"\nEnter your Choice"<<endl;
    cin>>mainChoice;

    system("cls");

    Customers c1;
    Cabs c2;
    Booking b1;
    Charges c3;

    if(mainChoice == 1){
        cout<<"----------Customers----------"<<endl;
        cout<<"1. Enter New Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\nEnter Choice: ";
        cin>>inChoice;

        system("cls");

        if(inChoice == 1){
            c1.getDetails();
        }
        else if(inChoice == 2){
            c1.showDetails();
        }
        else{
            cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait...!"<<endl;
            Sleep(999);
            system("cls");
            menu();
        }

        cout<<"\nPress 1 to Redirect to Main Menu: ";
        cin>>goToMenu;
        system("cls");

        if(goToMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }

    else if(mainChoice == 2){
        c2.cabDetails();
    }

    else if(mainChoice == 3){
        b1.hotels();
    }

    else if(mainChoice == 4){
        cout<<"--> Get your Receipt <--"<<endl;
        c3.printBill();
        cout<<"\nYout receipt is already printed you can get it from file path."<<endl;
        cout<<"To display your receipt Enter 1. \nOr Enter any other key to go back Main Menu"<<endl;

        cin>>goToMenu;

        if(goToMenu == 1){
            system("cls");
            c3.showBill();
            cout<<"\nPress 1 to redirect Main Menu: ";
            cin>>goToMenu;
            system("cls");

            if(goToMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("cls");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout<<"--> GOOD BYE <--"<<endl;
        Sleep(999);
        system("cls");
        exit(0);
    }
    else{
        cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait...!"<<endl;
        Sleep(999);
        system("cls");
        menu();
    }
}

int main(){

    ManageMenu startObj;

    return 0;
}