#include <iostream>
#include <string>

using namespace std;
int rooms[] = { 1,2,3,4,5,6,7,8,9,10 }; //room numbers
int total_rooms = 10; // total rooms
int room_book; //pang book ng rooms
int booked_rooms[10]; //storage ng occupied rooms
string fname[10]; //storage ng firstnames
string lname[10]; //storage ng lastnames
string email_address[10]; //storage ng email address
string age[10]; //storage ng age
string time_in[10]; ///storage ng time in
string time_out[10]; //storage ng time out
int counter_array; // counter para sa info ng user

void selecting() {

    cout << "\t\t\t\t\t\tEnter what room number do you want:";
    cin >> room_book;
    int arraylength = sizeof(booked_rooms) / sizeof(booked_rooms[0]);
    for (int a = 0; a < arraylength; a++) {
        if (booked_rooms[a] == room_book) {
            cout << "\t\t\t\t\t\tRoom is occupied! Choose other room." << endl;
            selecting();
            break;
        }
    }
    booked_rooms[counter_array] = room_book; //declaration na magiging occupied na yung room
    for (int i = 0; i < total_rooms; i++) //for loop para mabawasan yung available rooms
    {
        if (rooms[i] == room_book)
        {
            for (int j = i; j < (total_rooms - 1); j++)
                rooms[j] = rooms[j + 1];

            i--;
            total_rooms--;
        }
    }

}
int menu() {               //menu
    int choice;
    int a;
    cout << "\n\t\t\t\t\t\t*************************";
    cout << "\n\t\t\t\t\t\t* Welcome to Sogo hotel *";
    cout << "\n\t\t\t\t\t\t*************************";
    cout << "\n\t\t\t\t\t\t1.See available rooms";
    cout << "\n\t\t\t\t\t\t2.Book a room";
    cout << "\n\t\t\t\t\t\t3.Occupied Rooms";
    cout << "\n\t\t\t\t\t\t4.Renters";
    cout << "\n\t\t\t\t\t\t5.Exit";
    cout << "\n\n\t\t\t\t\t\tEnter Your Choice: ";
    cin >> choice;
    switch (choice) {
    case 1: // didisplay yung available rooms
        cout << "\t\t\t\t\t\tAvailable Rooms:\n" << total_rooms;
        for (a = 0; a < total_rooms; a++) {
            cout << "\t\t\t\t\t\tRoom Number: " << rooms[a] << endl;
        }
        menu(); //after i display balik ulit sa menu
        break;

    case 2: //booking menu
        for (; counter_array < 10; counter_array++) {
            char selection;

                cout << "\t\t\t\t\t\tWelcome to Booking Menu!" << endl;
                selecting();
            // inputing renter info
            cout << "\t\t\t\t\t\tEnter First Name:";
            cin >> fname[counter_array];
            cout << "\t\t\t\t\t\tEnter Last Name:";
            cin >> lname[counter_array];
            cout << "\t\t\t\t\t\tEnter Email Address:";
            cin >> email_address[counter_array];
            cout << "\t\t\t\t\t\tEnter Age:";
            cin >> age[counter_array];
            cout << "\t\t\t\t\t\tEnter Exact Time in:";
            cin >> time_in[counter_array];
            cout << "\t\t\t\t\t\tEnter Exact Time out:";
            cin >> time_out[counter_array];
            cout << "\t\t\t\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t\t\t\tRoom Number: " << booked_rooms[counter_array] << endl;
            cout << "\t\t\t\t\t\tFirst Name: " << fname[counter_array] << endl;
            cout << "\t\t\t\t\t\tLast Name: " << lname[counter_array] << endl;
            cout << "\t\t\t\t\t\tEmail Address: " << email_address[counter_array] << endl;
            cout << "\t\t\t\t\t\tAge: " << age[counter_array] << endl;
            cout << "\t\t\t\t\t\tTime In: " << time_in[counter_array] << endl;
            cout << "\t\t\t\t\t\tTime out: " << time_out[counter_array] << endl;
            cout << "\t\t\t\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t\t\t\tDo you want to do another booking? Y(yes) and N(no):"; //selection if user want to book another room
            cin >> selection;
            if (selection == 'N' || selection == 'n') {
                counter_array++; //counter for another index ng mga array sa info
                menu();
            }
        }
        break;
    case 3: // displaying booked rooms
        cout << "\t\t\t\t\t\tThe booked rooms are:" << endl;
        for (a = 0; a < sizeof(booked_rooms) / sizeof(booked_rooms[0]); a++) {
            if (booked_rooms[a] > 0) {
                cout << "\t\t\t\t\t\tRoom Number: " << booked_rooms[a] << endl;
            }
        }
        menu();
        break;

    case 4: //displaying renters info including their room numbers

        cout << "\t\t\t\t\t\tList of Renters:" << endl;
        for (int info = 0; info < counter_array; info++) {
            cout << "\t\t\t\t\t\t ---------------------------------------" << endl;
            cout << "\t\t\t\t\t\t Room Number: " << booked_rooms[info] << endl;
            cout << "\t\t\t\t\t\t First Name: " << fname[info] << endl;
            cout << "\t\t\t\t\t\t Last Name: " << lname[info] << endl;
            cout << "\t\t\t\t\t\t Email Address: " << email_address[info] << endl;
            cout << "\t\t\t\t\t\t Age: " << age[info] << endl;
            cout << "\t\t\t\t\t\t Time In: " << time_in[info] << endl;
            cout << "\t\t\t\t\t\t Time In: " << time_out[info] << endl;
            cout << "\t\t\t\t\t\t ---------------------------------------" << endl;
        }
        menu();
        break;

    case 5:
        cout << "\t\t\t\t\t\tThe program will now exit!";
        exit(0);
        break;
    default:
        cout << "\t\t\t\t\t\tInvalid Selection! The program will now exit!";
        exit(0);
        break;
    }
}

int main()
{
    string user = "user"; //default user
    string pass = "admin"; //default pass
    string user_login;
    string pass_login;
    int trial;
    for (trial = 3; trial > 0; trial--) { // 3times lang pede magkamali ng pag login
        cout << "\t\t\t\t\t\tEnter username:";
        cin >> user_login;
        cout << "\t\t\t\t\t\tEnter Password:";
        cin >> pass_login;
        if (user == user_login) {
            if (pass == pass_login) {
                menu();
                break;


            }
            else {
                cout << "\t\t\t\t\tInvalid password, Please try again \n";
            }
        }
        else {
            cout << "\t\t\t\t\tInvalid User, Please try again \n";

        }

    }
    if (trial == 0) {
        cout << "\n\t\t\t\t\tYou already attempted 3 times! The program will now exit!";
        return 0;

    }

    return 0;
}
