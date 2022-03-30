#include <iostream>
#include <fstream>

using namespace std;

// define all files here
fstream hasOpenedFile("gwsf/hasOpened.gwsf", fstream::out | fstream::app);
int hasOpened;

// define all functions here
void endProgram(int exitCode);

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
        cout << "Something went wrong.\nfixing automaticly...\n\n";
        // write 0 to hasOpened.jsf
        hasOpenedFile << "0";
        cout << "fixed... please restart the program.\n";
        endProgram(2);
    }

    cout << endl;
    endProgram(0);
    return 0;
}

void endProgram(int exitCode) {
    hasOpenedFile.close();

    exit(exitCode);
}
