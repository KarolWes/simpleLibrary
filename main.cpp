#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdio>

#include "magazyn_lib.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "");

    system("color 0B");
    cout << "Hello there!" << endl;

   _sleep(1000);
    menu();

    return 0;
}
