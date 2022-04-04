#include <iostream>
#include <fstream>

#include "header.h"

using namespace std;

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

/* 
    TODO : FIX THE GWSF FILES

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
            system("clear");
        }
        else {
            system("clear");
            cout << "\n### python is not installed ###\nplease install python 3 or greater \n\n";
            endProgram(5);
        }

        cout << "welcome to the GlassWare launcher for the first time\nThis is the setup and you will only need todo this once\n" << endl;
        system("sleep 0.1");
        cout << "please enter your Name/GlassWare username -NO SPACES- (its fine if you dont have an GlassWare account just enter anything, ex. your first name)" << endl;
        logf("asked for username");
        cin >> usrName;
        usrNameFile << usrName;

        // age is not needed for now, but it may be needed for other programs
        cout << "please enter the year you were born" << endl;
        logf("asked for age");
        cin >> age;

        logf("checking age");
        if (age > 2012){
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

        // todo: make a python script to change the hasOpened file to 1, BECAUSE I CANT DO IT IN C++ :/

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
        usrNameFile.close();
        ageFile.close();
    }
    else if (hasOpened == 1){
    updateCheck:
        cout << "installation manager======>>>>>------\n\n";
        cout << "checking for updates...\n\n";
        system("sleep 1");
        if (system("python3 -V") == 0){
            // check if python file is in the same directory
            if (system("python3 checkForUpdates.py") == 0){
                cout << "update check complete\n\n";
            }
            else {
                fixGWSF("checkForUpdates.py");
            }
        }
        else {
            cout << "\n### python is not installed ###\nplease install python \n\n";
        }
        system("sleep 1 && clear");
    mainMenu:
        cout << "welcome back "<< usrName << endl;

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




