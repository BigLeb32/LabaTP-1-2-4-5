#include <iostream>
#include <vector>
using namespace std;

    enum Scale {Kelvin,
                Celsius,
                Fahrenheit
               };
    struct Temperature
    {
        double value;
        Scale scale;
    };

vector<double> Cels;
vector<double> Kelv;
vector<double> Far;

    istream& operator>> (istream& input, Temperature& data)
    {
        char symbol ;
        input >> data.value >>symbol ;


        switch (symbol)
        {
        case 'K':
            data.scale = Kelvin;
            break;
        case 'C':
            data.scale = Celsius;
            break;
        case 'F':
            data.scale = Fahrenheit;
            break;
        }
        if (symbol != 'K' || data.value < 0)
        {
            cout<<"sdffdd"
            input.setstate(ios_base::failbit);
        }

        return input;
    }



    ostream& operator << (ostream& output, const Temperature& data)
    {
        char symbol ;
        switch (data.scale)
        {
        case Kelvin:
            symbol = 'K';
            break;
        case Celsius:
            symbol = 'C';
            break;
        case Fahrenheit:
            symbol= 'F';
            break;
        }

        output << data.value << symbol;
        return output;
    }

double get_value_of_scale(const Temperature& data,const Scale& scale)//NEREALNAYA STROKA

{
    double x;
    char symbol;
    if (data.scale == Kelvin)
    {
        if (scale == Celsius)
        {

            x = data.value;
            x1=x - 273.15);
return




        }
    }
    return testvector
}

int main()
{
    Temperature data;
    cin>>data;
    cout << "You entered: " << data << '\n';
    /*Scale to = Celsius;
     Temperature converted { get_value_of_scale(data, to), to };
     cout << converted;*/
    cout<<func()<<func()
}
