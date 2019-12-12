#include "testMakefile.h"

TestMakeFile::TestMakeFile(int _a, int _b)
{
    a = _a;
    b = _b;
}

int TestMakeFile::calcSum()
{
    return a + b;
}