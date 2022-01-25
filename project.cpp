#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** initial_hotel(int Floor, int Room);
void display_all_rooms(int** hotel, int Floor, int Room);
void display_all_occupied_suite_rooms(int ** hotel, int Floor, int Room);
void display_all_empty_suite_rooms(int** hotel, int Floor, int Room);
void display_all_occupied_deluxe_rooms(int ** hotel, int Floor, int Room);
void display_all_empty_deluxe_rooms(int** hotel, int Floor, int Room);
void display_all_occupied_executive_rooms(int ** hotel, int Floor, int Room);
void display_all_empty_executive_rooms(int** hotel, int Floor, int Room);

int** get_data_from_file(int Floor, int Room);
void transfer_data_to_file(int** hotel, int Floor, int Room);

int main()
{
    cout << "\t\t\t\t\t\t********************************************" << endl;
    cout << "\t\t\t\t\t\t* \t\t\t\t\t   *" << endl;
    cout << "\t\t\t\t\t\t* \t\t\t\t\t   *" << endl;
    cout << "\t\t\t\t\t\t*    Welcome to Hotel Management System    *" << endl;
    cout << "\t\t\t\t\t\t* \t\t\t\t\t   *" << endl;
    cout << "\t\t\t\t\t\t* \t\t\t\t\t   *" << endl;
    cout << "\t\t\t\t\t\t********************************************" << endl;
    cout << endl;


    int Floor = 5; 
    int Room = 6;
    int **hotel;
    int S_room = 9500;
    int D_room = 7000;
    int E_room = 4500;
    
    // initialize hotel's floor and rooms 
    hotel= initial_hotel(Floor, Room);
    
    int enter = 1;
    while(enter == 1)
    {
        char option;
        cout << "Are You A Manager (Press M/m) Or A Customer (Press C/c) : ";
        cin >> option;
        cout << endl;
        
        if(option == 'M' || option == 'm')
        {
            cout << "HI, Dear Manager what would you like to see." << endl;
            
            int opt = 0;
            cout << "Press (1), For Hotel Menu" << endl;
            cout << "Press (2), For All Occupied & Avaliable Rooms" << endl;
            cout << "Press (3), For Updation of Occupied & Avaliable Rooms" << endl;
            cout << "Press (4), For Updation of Room Prices" << endl;

            cout << endl;
            cout << "What is your choice : ";
            cin >> opt;
            cout << endl << endl;

            if(opt == 1)
            {
                cout << "Per Night stay at out Hotel for Suite Room is : Rs."<< S_room <<"/-" << endl;
                cout << "Per Night stay at out Hotel for Deluxe Room is : Rs."<< D_room <<"/-" << endl;
                cout << "Per Night stay at out Hotel for Executive Room is : Rs."<< E_room <<"/-" << endl;
            }
            else if(opt ==2 )
            {
                display_all_rooms(hotel, Floor, Room);
            }
            else if(opt == 3)
            {
                int room_type, floor, room;
                cout << "Enter Room Type (S/s for Suite, D/d for deluxe, E/e for executive) : ";
                cin >> room_type;
                cout << endl;
                cout << "Enter Floor Number : ";
                cin >> floor;
                cout << endl;
                cout << "Enter Room Number : ";
                cin >> floor;

                if(room_type == 'S' || room_type == 's')
                {
                    floor = floor - 1;
                    room = room - 1;
                    hotel[floor][room] = -3;
                }
                else if(room_type == 'D' || room_type == 'd')
                {
                    floor = floor - 1;
                    room = room - 1;
                    hotel[floor][room] = -2;
                }
                else if(room_type == 'E' || room_type == 'e')
                {
                    floor = floor - 1;
                    room = room - 1;
                    hotel[floor][room] = -1;
                }
            }
            else if(opt == 4)
            {
                cout << "Enter new price for Suite Room : ";
                cin >> S_room;
                cout << endl;
                cout << "Enter new price for Deluxe Room : ";
                cin >> D_room;
                cout << endl;
                cout << "Enter new price for Executive Room : ";
                cin >> E_room;
                cout << endl;
            }
        }
        else if(option == 'C' || option == 'c')
        {
            cout << "HI, Dear Customer what would you like to see." << endl;
            
            int opt = 0;
            cout << "Press (1), For Hotel Menu" << endl;
            cout << "Press (2), For Avaliable Suite Rooms" << endl;
            cout << "Press (3), For Avaliable Deluxe Rooms" << endl;
            cout << "Press (4), For Avaliable Executive Rooms" << endl;
            cout << "Press (5), If you would like to stay at our Hotel" << endl;

            cout << endl;
            cout << "What is your choice : ";
            cin >> opt;
            cout << endl << endl;

            if(opt == 1)
            {
                cout << "Per Night stay at out Hotel for Suite Room is : Rs."<< S_room <<"/-" << endl;
                cout << "Per Night stay at out Hotel for Deluxe Room is : Rs."<< D_room <<"/-" << endl;
                cout << "Per Night stay at out Hotel for Executive Room is : Rs."<< E_room <<"/-" << endl;
            }
            else if(opt == 2)
            {
                display_all_empty_suite_rooms(hotel, Floor, Room);
            }
            else if(opt == 3)
            {
                display_all_empty_deluxe_rooms(hotel, Floor, Room);
            }
            else if(opt == 4)
            {
                display_all_empty_executive_rooms(hotel, Floor, Room);
            }
            else if(opt == 5)
            {
                cout << "We appriciate that you want to stay at our hotel." << endl << endl;                 

                cout << "Which Rooms will you be want to stay in." << endl;
                cout << "Press (3), Suite Rooms" << endl;
                cout << "Press (2), Deluxe Rooms" << endl;
                cout << "Press (1), Executive Rooms" << endl;
                cout << endl;

                int choice, night, floor, room;
                cout << "Your choice : ";
                cin >> choice;
                cout << endl << endl;
                cout << "And how many nights would like to stay : ";
                cin >> night;
                cout << endl;
                cout << "And please give us the floor number on which ou would like to stay : ";
                cin >> floor;
                cout << endl;
                cout << "And please give us the room number on which ou would like to stay : ";
                cin >> room;
                cout << endl << endl;
                cout << endl << endl;

                if(choice == 3)
                {
                    floor = floor -1;
                    room = room -1;
                    cout << "The amount for staying in Suite Room Number-" << room << " of " << floor << " Floor will be : Rs." <<  night * S_room << "/-" << endl;
                    hotel[floor][room] = 3;
                    transfer_data_to_file(hotel, Floor, Room);
                }
                else if(choice == 2)
                {
                    floor = floor -1;
                    room = room -1;
                    cout << "The amount for staying in Deluxe Room Number-" << room << " of " << floor << " Floor will be : Rs." <<  night * D_room << "/-" << endl;
                    hotel[floor][room] = 2;
                    transfer_data_to_file(hotel, Floor, Room);
                }
                else if(choice == 1)
                {
                    floor = floor -1;
                    room = room -1;
                    cout << hotel[floor][room];
                    cout << "The amount for staying in Executive Room Number-" << room << " of " << floor << " Floor will be : Rs." <<  night * E_room << "/-" << endl;
                    hotel[floor][room] = 1;
                    cout << hotel[floor][room];
                    transfer_data_to_file(hotel, Floor, Room);
                }                
            }
            else
            {
                
            }
            
        }     
        
        cout << endl;
        cout << "******************************************************************************" << endl;
        cout << "Do you want to Exit the Hotel, If No (Press 1) else to Press Any Button to Exit : ";
        cin >> enter;
        cout << "******************************************************************************" << endl << endl;
    }
    
    // display all hotel's floors and rooms
    // display_all_rooms(hotel, Floor, Room);
    
    // display all hotel's occupied suite rooms
    //display_all_occupied_suite_rooms(hotel, Floor, Room);
    
    // display all hotel's empty suite rooms
    // display_all_empty_suite_rooms(hotel, Floor, Room);
    
    // display all hotel's occupied deluxe rooms
    // display_all_occupied_deluxe_rooms(hotel, Floor, Room);
    
    // display all hotel's empty deluxe rooms
    // display_all_empty_deluxe_rooms(hotel, Floor, Room);
    
    // display all hotel's occupied deluxe rooms
    // display_all_occupied_executive_rooms(hotel, Floor, Room);
    
    // display all hotel's empty deluxe rooms
    // display_all_empty_executive_rooms(hotel, Floor, Room);

    // insert data into the file
    // transfer_data_to_file(hotel, Floor, Room);

    
    /** this function is not working yet. ***/
    // get data from file
    //get_data_from_file(Floor, Room);


    return 0;
}

// initialize the data given in the project file
int** initial_hotel(int Floor, int Room)
{
    int** hotel = new int*[Floor];
    for(int i=0; i< Floor; i++)
    {
        hotel[i] = new int[Room];
        for(int j=0; j < Room; j++)
        {
            hotel[i][j] = 0;
        }
    }
    
    hotel[0][0] = 2;
    hotel[0][1] = 2;
    hotel[0][2] = 1;
    hotel[0][3] = 1;
    hotel[0][4] = 1;
    hotel[0][5] = -3;
    
    hotel[1][0] = -2;
    hotel[1][1] = -1;
    hotel[1][2] = -1;
    hotel[1][3] = -1;
    hotel[1][4] = 3;
    hotel[1][5] = 3;
    
    hotel[2][0] = -1;
    hotel[2][1] = -1;
    hotel[2][2] = -1;
    hotel[2][3] = -3;
    hotel[2][4] = -3;
    hotel[2][5] = 2;
    
    hotel[3][0] = -1;
    hotel[3][1] = -1;
    hotel[3][2] = 2;
    hotel[3][3] = 2;
    hotel[3][4] = -3;
    hotel[3][5] = -3;
    
    hotel[4][0] = 1;
    hotel[4][1] = 1;
    hotel[4][2] = 2;
    hotel[4][3] = 2;
    hotel[4][4] = -3;
    hotel[4][5] = -3;

    
    return hotel;
}

// display all rooms with status
void display_all_rooms(int** hotel, int Floor, int Room)
{
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            int count1 = j + 1;
            cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : " << hotel[i][j] << endl;
        }
        cout << endl;
    }
}

// display all occupied suite rooms
void display_all_occupied_suite_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Occupied Suite Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == 3)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Suite-Occupied (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
    }
}

// display all empty suite rooms
void display_all_empty_suite_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Empty Suite Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == -3)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Suite-Empty (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
        
    }
}

// display all occupied deluxe rooms
void display_all_occupied_deluxe_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Occupied Deluxe Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == 2)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Deluxe-Occupied (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
    }
}

// display all empty deluxe rooms
void display_all_empty_deluxe_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Empty Deluxe Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == -2)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Deluxe-Empty (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
        
    }
}

// display all occupied executive rooms
void display_all_occupied_executive_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Occupied Executive Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == 1)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Executive-Occupied (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
    }
}

// display all empty executive rooms
void display_all_empty_executive_rooms(int ** hotel, int Floor, int Room)
{
    cout << "All Empty Executive Rooms in the Hotel are as following," << endl << endl;
    
    for(int i = 0; i < Floor; i++)
    {
        int count = i + 1;
        for(int j=0; j < Room; j++)
        {
            if(hotel[i][j] == -1)
            {
                int count1 = j + 1;
                cout << "Floor Number : " << count << " and Room Number : " << count1 << ", Status : Executive-Empty (" << hotel[i][j] << ")";                
                cout << endl<< endl;
            }
        }
        
    }
}


// write data to file
void transfer_data_to_file(int** hotel, int Floor, int Room)
{
    ofstream fout; // outdata is like cin

    fout.open("data.txt");

   if(!fout)
   {
       cout << "Error in creating file!!!";
       exit(1);
   }
   else
   {
       for(int i=0; i < Floor; i++)
       {
           for(int j=0; j < Room; j++)
           {
               fout << hotel[i][j] << " ";
           }
           fout << endl;
       }

       cout << "Data inserted into file successfully...!" << endl;
   }
}


// read data from file
// int** get_data_from_file(int Floor, int Room)
// {

//     ifstream fin; // indata is like cin

//     fin.open("data.txt"); // opens the file

//     int** hotel = new int*[Floor];
//     while ( !fin.eof() ) 
//     { 
//         // getline(fin, data);
        
//         for(int i=0; i< Floor; i++)
//         {
//             hotel[i] = new int[Room];
//             for(int j=0; j < Room; j++)
//             {
//                 if(fin == " ")
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     fin >> hotel[i][j];
//                     cout << hotel[i][j];
//                 }
//             }
//         }
//     }

//     fin.close();
//     cout << "End-of-file reached.." << endl;
// }