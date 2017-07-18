#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    fraction a,b,s,p;
    do
    {
        cout << "enter first fraction: \n";
        try
        {
            cin>>a;
        }
        catch(const char* s)
        {
            cerr<<s;
        }
    }
    while(a.getDenominateur() == 0);
    do
    {
        cout << "enter second fraction: \n";
        try
        {
            cin>>b;
        }
        catch(const char* s)
        {
            cerr<<s;
        }
    }
    while(b.getDenominateur() == 0);
    s = a + b;
    cout<< a <<" + "<< b <<" = "<< s <<endl;
    p = a * b ;
    cout<< a <<" * "<< b <<" = "<< p;
}
