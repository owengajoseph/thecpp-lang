#include <iostream>
#include <vector>
#include <string>
// project includes
#include <cat.h>

using namespace std;
int main()
{
#ifndef NDEBUG
    vector<string> msg{"Debug", "Hello", "C++", "World", "from", "Vs Code", "Multi file c++ project"};
#else
    vector<string> msg{"Release", "Hello", "C++", "World", "from", "Vs Code", "Multi file c++ project"};
#endif

    for (const string &word : msg)
    {
        cout <<word<<" ";
    }
cout<<endl;
catspeak();   
}