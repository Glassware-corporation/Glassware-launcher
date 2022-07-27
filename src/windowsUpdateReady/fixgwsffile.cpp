#include "header.h"
#include <iostream>

using namespace std;

//! THIS CODE BASE IS DEPACATED
//! THERE WILL BE A NEW VERSION, CALLED MessyCodeLauncher aka MCL

//! ANYTHING HERE IS UNABLE TO BE USED. GOOD LUCK IF YOUR GOING TO USE THIS

void endProgram(int exitCode);

void fixGWSF(string whatFile){
        cout << "something went worng with the file '"<< whatFile <<"' \n\nentering recovering mode... \n";
        // check if python is installed
        if (system("python3 -V") == 0){
            // check if python file is in the same directory
            if (system("python3 gwsf/fixGWSFfiles.py") == 0){
                cout << "recovering complete \n\n";
            }
            else {
                cout << "recovering failed \n\n";
            }
        }
        else {
            cout << "\n### python is not installed ###\nplease install python \n\n";
        }
        // system("python3 gwsf/fixGWSFfiles.py");

        endProgram(0);
}