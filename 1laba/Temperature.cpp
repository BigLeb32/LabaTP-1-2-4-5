#include <iostream>
#include <vector>
using namespace std;

int main()

{   int i=0;
    double t=0;
    char s,e;
    vector<double> Cels;
    vector<double> Kelv;
    vector<double> Far;
    while (t == 0)
    {
      cout<< "Enter the scale(Fahrenheit - F,Celsius - C,Kelvin - K): ";
      cin >> s;
     if (s=='F' || s=='C' || s=='K') {

     } else {
          cout << "You must enter only F,C,K \n";
          continue;
            cin.clear();
            cin.sync();
            s=0;
     }
      cout<< "Enter the temperature: ";
      cin >> t;


     if (t<=-273.15 || cin.fail()) {
            cout << "You must enter a number not less than -273.15 \n";
            cin.clear();
            cin.sync();
            t=0;

     } else {
         cout<< "Complete the entry and exit(Y or N): ";
      cin >> e;

        if (e !='Y'){

         switch(s) {
             case 'C':
        Far.push_back (t*9/5+32);
        Kelv.push_back (t+273.15);
        Cels.push_back (t);
         t=0;
         i++;
         break;
             case 'F':
         Cels.push_back ((t-32)/1.8);
         Kelv.push_back(5*(t - 32)/9 + 273.15);
         Far.push_back(t);
         t=0;
         i++;
         break;
             case 'K':
         Cels.push_back (t - 273.15);
         Far.push_back ((t -273.15)/5 + 32);
         Kelv.push_back (t);
         t=0;
         i++;
         break;
         }
        }
         else
            {
            switch(s) {
             case 'C':
        Far.push_back (t*9/5+32);
        Kelv.push_back (t+273.15);
        Cels.push_back (t);
         t=0;
         i++;
         break;
             case 'F':
         Cels.push_back ((t-32)/1.8);
         Kelv.push_back  (5*(t - 32)/9 + 273.15);
         Far.push_back (t);
         t=0;
         i++;
         break;
             case 'K':
         Cels.push_back (t - 273.15);
         Far.push_back (9*(t -273.15)/5 + 32);
         Kelv.push_back (t);
         t=0;
         i++;
         break;
         }
  cout<<"Celsius"<<" "<<"Fahrenheit"<<" "<<"Kelvin"<<"\n";
  for (int i = 0; i < Cels.size(); i++ ){
  cout<<Cels[i]<<" | | "<<Far[i]<<" | | "<<Kelv[i]<<"\n";
  }
  exit(0);

            }
         }
     }


    }

