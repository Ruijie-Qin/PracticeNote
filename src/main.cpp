#include <iostream>
#include "testMakefile.h"
using namespace std;

int main()
{
    TestMakeFile test(1,2);
    cout << test.calcSum() << endl;
    return 0;
}