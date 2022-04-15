#include <iostream>
#include <fstream>

#include "header.h"

using namespace std;

/*
    vscode extension: Better Comments, https://marketplace.visualstudio.com/items?itemName=ms-vscode.better-comments
      normal comment
    ! important comment
    // strike thru comment
    * read this comment
    ? question comment
    todo : todo comment
    ^ note comment
*/

string version = "0.6.4";

// ofstream hasPythonFile("./gwsf/hasPython.gwsf", std::ios_base::app);
// ifstream hasPythonFileR("./gwsf/hasPython.gwsf");

// string hasPython3;

// string temp = "";

// define all files here
fstream hasOpenedFile("./gwsf/hasOpened.gwsf");
int hasOpened;

// ofstream hasOpenedFileWrite("./gwsf/hasOpened.gwsf");
// string hasOpenedWrite;

// ! DONT FOTGET OFSTREAM ONLY WRITES TO THE FILE
// ! IF YOU WANT TO READ FROM THE FILE, USE IFSTREAM, I SPENT HOURS ON THIS >:(

ofstream usrNameFile("./gwsf/usrName.gwsf", std::ios_base::app);
ifstream usrNameFileRead("./gwsf/usrName.gwsf");

string usrName;

ofstream ageFile("./gwsf/age.gwsf", std::ios_base::app);
ifstream ageFileRead("./gwsf/age.gwsf");

int age;

ofstream pathFile("./gwsf/path.gwsf", std::ios_base::app);
ifstream pathFileRead("./gwsf/path.gwsf");

string path;

// log does not work, bc i am lazy
ofstream logFile("./log/log.txt");

void logf(string what);
void press_any_key();

/* 
    TODO : work on application list
    TODO : update/installeion manager
    TODO : work on windows version and the linux version
*/


int main() {
    hasOpenedFile >> hasOpened;

    // usrNameFile.rdbuf() >> usrName;


    usrNameFileRead >> usrName;
    ageFileRead >> age;
    pathFileRead >> path;


    if (hasOpened == 0){
    setup:
        if (system("python3 -V") == 0){
            system("cls");
        }
        else {
            //system("cls");
            cout << "\n### python is not installed ###\nplease install python 3 or greater \n\n";
            endProgram(5);
        }
        cout << "welcome to the GlassWare launcher for the first time\nThis is the setup and you will only need todo this once\n" << endl;
        system("timeout 1 > NULL");

        cout << "please enter your Name/GlassWare username -NO SPACES- (its fine if you dont have an GlassWare account just enter anything, ex. your first name)" << endl;
        logf("asked for username");

        cin >> usrName;
        usrNameFile << usrName;

        // age is not needed for now, but it may be needed for other programs
        
        cout << "please enter your age" << endl;
        logf("asked for age");
        cin >> age;

        logf("checking age");
        if (age < 5){
            cout << "you are too young to use this launcher\nplease contact the developer of this launcher\n\n";
            endProgram(6);
        }
        ageFile << age;

        
        logf("asked for path");
        cout << "do you want to setup where the Glassware programs will be installed? (Y/n)" << endl;
        string answer;
        cin >> answer;
        if (answer == "Y" || answer == "y"){
            logf("asked for path");
            cout << "please enter the path to the Glassware programs folder" << endl;
            cin >> path;            
            pathFile << path;
        }
        else {
            cout << "you can change this later in the launcher settings\n\n";
        }

        // // todo: make a python script to change the hasOpened file to 1, BECAUSE I CANT DO IT IN C++ :/
        
        if (system("python3 -V") == 0){
            // check if python file is in the same directory
            if (system("python3 changeHasOpen.py") == 0){
                cout << "setup conplete - 0\n\n";
            }
            else {
                fixGWSF("changeHasOpen.py");
            }
        }
        else {
            cout << "\n### python is not installed ###\nplease install python \n\n";
        }
        
        cout << "setup complete - 1\n\n";
        cout << "restart the launcher...\n\n";

        usrNameFile.close();
        ageFile.close();
    }
    else if (hasOpened == 1){
    updateCheck:
        cout << "installation manager======>>>>>------\n\n";
        cout << "checking for updates...\n\n";
        system("timeout 1 > NULL");
        
        if (system("python3 -V") == 0){
            // check if python file is in the same directory
            if (system("python3 checkForUpdates.py") == 0){
                cout << "update check complete\n\n";
            }
            else {
                cout << "update check failed\n\n";
            }
        }
        else {
            cout << "\n### python is not installed ###\nplease install python \n\n";
            endProgram(5);
        }
        system("timeout 1 && cls");
    mainMenu:
        system("cls");
    mainMenuNoClear:
        cout << "main menu======>>>>>------\n\n";
        cout << "welcome back "<< usrName << endl;
        cout << "please select an option (1-5 (type a number and press enter))\n\n";
        cout << "1. GlassWare Launcher Programs\n2. GlassWare Launcher Settings\n3. Help\n4. About\n5. Exit\n\n";
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
            
                goto mainMenu;
            case 2:
                system("cls");
                cout << "GlassWare Launcher Settings\n\n";
                cout << "1. Change Username\n2. Change Path\n3. Change Age\n4. factory reset launcher\n5. exit\n\n";
                int choice2;
                cin >> choice2;
                switch (choice2){
                    case 1:
                        usrNameFile.close();
                        usrNameFile.open("./gwsf/usrName.gwsf", std::ios_base::trunc);
                        cout << "change username\n\n";
                        cout << "please enter your new username" << endl;
                        cin >> usrName;
                        usrNameFile << usrName;
                        cout << "username changed\n\n";
    
                        press_any_key();        
                        goto mainMenu;
                    case 2:
                        pathFile.close();
                        pathFile.open("./gwsf/path.gwsf", std::ios_base::trunc);
                        cout << "change path\n\n";
                        cout << "please enter the path to the Glassware programs folder" << endl;
                        cin >> path;
                        pathFile << path;
                        cout << "path changed\n\n";
    
                        press_any_key();
                        goto mainMenu;
                    case 3:
                        ageFile.close();
                        ageFile.open("./gwsf/age.gwsf", std::ios_base::trunc);
                        cout << "change age\n\n";
                        cout << "please enter your age" << endl;
                        cin >> age;
                        ageFile << age;
                        cout << "age changed\n\n";
    
                        press_any_key();
                        goto mainMenu;
                    case 4:
                    {
                        cout << "factory reset launcher\n\n";
                        cout << "are you sure you want to reset the launcher? (Y/n)" << endl;
                        string chioce4;
                        cin >> chioce4;
                        if (chioce4 == "Y" || chioce4 == "y"){
                            usrNameFile.close();
                            usrNameFile.open("./gwsf/usrName.gwsf", std::ios_base::trunc);
                            usrNameFile << "";
                            ageFile.close();
                            ageFile.open("./gwsf/age.gwsf", std::ios_base::trunc);
                            ageFile << "";
                            pathFile.close();
                            pathFile.open("./gwsf/path.gwsf", std::ios_base::trunc);
                            pathFile << "";
                            system("python3 changeHasOpen2.py");

                            cout << "factory reset complete\n\nrestart the launcher\n\n";
                        }
                        else {
                            cout << "factory reset cancelled\n\n";
                        }
                        press_any_key();
                        endProgram(0);
                    }
                    case 5:
                        goto mainMenu;
                    default:
                        cout << "invalid choice\n\n";
    
                        press_any_key();
                        goto mainMenu;
                }
            case 3:
                system("cls");
                cout << "help\n\n";
                cout << "send a message to the developer\n\n";
                press_any_key();
                goto mainMenu;
            case 4:
                system("cls");
                cout << "about\n\n";
                cout << "1. Glassware launcher\n2. Developer\n3. you\n4. Exit\n\n";
                int choice3;
                cin >> choice3;
                switch (choice3){
                    case 1:
                        cout << "Glassware launcher\n\n";
                        cout << "version "<< version <<"\n\n";
                        cout << "developed by Jacob O'Brien\n\n";
    
                        press_any_key();
                        
                        goto mainMenu;
                    case 2:
                        cout << "Developer\n\n";
                        cout << "name: Jacob O'Brien\n\n";
                        cout << "Github: jakeTheDev0000\n\n";   

                        press_any_key();
                        goto mainMenu;
                    case 3:
                        cout << "you\n\n";
                        cout << "name: " << usrName << endl;
                        cout << "age: " << age << endl;
                        cout << "path: " << path << endl;
    
                        press_any_key();
                        goto mainMenu;
                    case 4:
                        goto mainMenu;
                    default:
                        cout << "invalid choice\n\n";
    
                        press_any_key();
                        goto mainMenu;
                }
            case 5:
                break;
            default:
                cout << "invalid choice\n\n";
                press_any_key();
                goto mainMenu;
        }



    }
    else {
        logf("error with hasOpened");
        fixGWSF("hasOpened.gwsf");
    }


    cout << endl;
    endProgram(0);
    return 0;
}

void logf(string what){
    logFile << what;
}

void press_any_key()
{
    std::cout << "Press Enter to Continue";
    cin.ignore();
    cin.ignore();

}




