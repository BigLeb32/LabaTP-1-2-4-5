#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;

int main()
{
  time_t t;
  time(&t);

    int year=localtime(&t)->tm_year-100;
    int x,i;
    string  god,grup,god1,god2;
    cout<<"Vvedite nazvanie gruppi: ";
    cin>>grup;
    god1 = grup[3] ;
    god2 =  grup[4];
    god = god1+god2;
    x = atoi(god.c_str());
        if (x>year)
        {
            cout<<19<<x+6;
        }
        else
        {
            cout<<20<<x+6;
        }
}
