#include <iostream>
#include "converterjson.h"
#include "converterjson.cpp"

#include <vector>
#include <string>
using namespace std;

int main()
{
    ConverterJSON conv = ConverterJSON();
    conv.GetTextDocuments();
    //std::vector<std::string> str =conv.GetTextDocuments();

    cout << "Hello World!" << endl;
    return 0;
}
