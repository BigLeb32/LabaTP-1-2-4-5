#include <iostream>
#include <vector>
using namespace std;

 enum Scale   {
                Kelvin,
                Celsius,
                Fahrenheit
                };
    struct Temperature
                {
                double value;
                char scale;
                };

istream& operator>> (istream& input, Temperature& data )
{
input >> data.value >> data.scale;

if (data.scale != 'K' || data.value < 0) {
input.setstate(ios_base::failbit);
}

return input;
}

ostream& operator << (ostream& output, const Temperature& data)
{
output << data.value << data.scale;
return output;
}






int main()

{   int i=0;
    double t=0;
    string s,e;



               Temperature data;

if (!(cin>>data)) {
   cout << "Incorrect temperature input!";
}

cout<<data;

     /* data.value = 100;
      data.scale ='C';
cout<<data.scale;
    vector<double> Cels;
    vector<double> Kelv;
    vector<double> Far;
    while (t == 0)  //Пока t=0 программа будет выполнятся
    {
      cout<< "\nEnter the scale(Fahrenheit - F,Celsius - C,Kelvin - K): ";
      cin >> s;
     if (s[0]=='F' || s[0]=='C' || s[0]=='K')
     {

     } else {
          cout << "You must enter only F,C,K \n";
          continue;
            cin.clear();
            cin.sync();

            }
      cout<< "Enter the temperature: ";
      cin >> t;


         if (t<=-273.15 || cin.fail())
     {
            cout << "You must enter a number not less than -273.15 \n";
            continue;
            cin.clear();
            cin.sync();
            //t=0;

     }

      else {
         cout<< "Complete the entry and exit(Y or N(or any other letter)): ";
      cin >> e;
      if (e[0]=='y') {e[0]='Y';}

        if (e[0] !='Y'  ){

         switch(s[0]) {
             case 'C' :
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
            switch(s[0]) {
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
    */}

