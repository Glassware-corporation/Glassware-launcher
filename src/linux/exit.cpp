#include <iostream>
#include "header.h"

using namespace std;

void endProgram(int exitCode) {
    cout << "\n\nexit code: " << exitCode << endl;
    // system("pause");
    exit(exitCode);
}