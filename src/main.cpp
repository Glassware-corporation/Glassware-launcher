#include <iostream>
#include <fstream>

#include "header.h"

using namespace std;

// define all files here
fstream hasOpenedFile("./gwsf/hasOpened.gwsf");
int hasOpened;


int main() {
    hasOpenedFile >> hasOpened;

    if (hasOpened == 0){
        hasOpenedFile << 1;
        cout << "welcome" << endl;
        
    }
    else if (hasOpened == 1){
        cout << "welcome back" << endl;
    }
    else {
        fixGWSF("hasOpened.gwsf");
    }

    cout << endl;
    endProgram(0);
    return 0;
}


