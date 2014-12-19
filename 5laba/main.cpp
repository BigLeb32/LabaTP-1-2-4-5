#include "sdt.h"
#include "svsp.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    LinkedList obj;
    double a;
    for(int i=0; i<100; i++)
    {
        for(int i=0; i<10000; i++)
        {
            a = randint(1,10);
            obj.push_back(a);
        }





        for(int i=0; i<5000; i++)
        {
            obj.erase(obj.find(5));
        }
        cout<<obj;

        return 0;
    }
}
