#include <iostream>
#include <vector>
using namespace std;

enum Scale
{
    Kelvin,
    Celsius,
    Fahrenheit
};

struct Temperature
{
    double value;
    Scale scale;


};

char symbol;
int i=0;
vector<double>Temp;
vector<char>symbolvect;


/*
vector<double> input(unsigned int N)
{
    int i;
    vector<double>v(N);
    for(i=0; i<N; ++i)
    {
        cout<<"Enter "<<i+1<<": ";
        cin>>v[i];
    }
    return v;
}
*/
double get_mean(const vector<double>& v)
{
    int i;
    float sv=0;
    for(i=0; i<v.size(); ++i)
    {
        sv+=v[i];
    }
    sv=sv/v.size();
    return sv;
}
double get_stdev (const vector<double >& v,double sv)
{
    int i;
    float svv,vv;
    for(i=0; i<v.size(); ++i)
    {
        svv+=(v[i]*v[i]);
    }
    vv=(svv/v.size())-(sv*sv);
    return vv;
}





double convert(const Temperature& data,const Scale& scale)
{
    switch (data.scale)
    {
    case Kelvin:
        if (scale == Kelvin) return data.value;
        else if (scale == Celsius) return data.value - 273.15;
        else if (scale == Fahrenheit) return data.value -(273.15)/5 + 32;
        break;
    case Celsius:
        if (scale == Celsius) return data.value;
        else if (scale == Kelvin) return data.value*9/5+32;
        else if (scale == Fahrenheit) return (data.value+273.15);
        break;
    case Fahrenheit:
        if (scale == Fahrenheit) return data.value;
        else if (scale == Kelvin) return (data.value-32)/1.8;
        else if (scale == Fahrenheit) return 5*(data.value - 32)/9 + 273.15;
        break;
    }
}

bool operator==(const Temperature& data,const Temperature&zero)
{
    double dk = convert(data, Kelvin);
    double zk = convert(zero, Kelvin);
    return dk == zk;
}

bool operator<(const Temperature& data,const Temperature&zero)
{
    double dk = convert(data, Kelvin);
    double zk = convert(zero, Kelvin);
    return dk < zk;
}



double get_value_of_scale(const Temperature& data,const Scale& scale)
{
    Temp.push_back(data.value);
    switch (data.scale)
    {
    case Kelvin:
        Temp.push_back (data.value- 273.15);
        Temp.push_back ((data.value -273.15)/5 + 32);
        break;
    case Celsius:
        Temp.push_back (data.value*9/5+32);
        Temp.push_back (data.value+273.15);
        break;
    case Fahrenheit:
        Temp.push_back ((data.value-32)/1.8);
        Temp.push_back(5*(data.value - 32)/9 + 273.15);
        break;
    }
}

istream& operator>> (istream& input, Temperature& data)
{
    const Temperature AZ
    {
        0, Kelvin
    };

again:
    cout<< "Enter temperature: ";
    input >> data.value;
    if (input.fail())
    {
        cout << "Enter any NUMBERS!!!\n";
        input.clear();
        input.sync();
        goto again;
    }
again2:
    cout<<"Enter scale(F,C,K): ";
    input >> symbol;
    if (symbol == 'K'||symbol == 'F'|| symbol == 'C')
    {}
    else
    {
        cout<<"You must enter only F,C,K \n";
        goto again2;
        input.setstate(ios_base::failbit);
    }
    symbolvect.push_back(symbol);
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



    if (data < AZ)
    {
        cout<<" You must enter number not less then zero!\n";
        goto again;
    }

    return input;
}

ostream& operator << (ostream& output, const Temperature& data)
{
    char  symbol2,symbol3;
    switch (data.scale)
    {
    case Kelvin:
        symbolvect.push_back('C');
        symbolvect.push_back('F');
        break;
    case Celsius:
        symbolvect.push_back('F');
        symbolvect.push_back('K');
        break;
    case Fahrenheit:
        symbolvect.push_back('C');
        symbolvect.push_back('K');
        break;
    }
    get_value_of_scale(data,data.scale);

    output << Temp[i] << symbolvect[i]<<" || "<<
           Temp[i+1]<<symbolvect[i+1]<<" || "<<
           Temp[i+2]<<symbolvect[i+2];
    i+=3;
    return output;
}

int main()
{
    int N;
    float mx,my,sx,sy;
    string otv;
    vector<double>x(3);
    vector<double>y(3);
    Temperature data;
newiter:
    cin>>data;
    cout<<data<<"\n\n"<<"Do you want to continue?(Y/N) or bring all values(B)?:"<<"  ";
    cin>>otv;
    if (otv=="Y")
    {
        goto newiter;
    }
    else if (otv=="B")

    {
        //if (Temp.size()==6)

        for (i = 0; i<3; ++i)
        {
            x[i]=Temp[i];
        }
        for (i = 3; i<6; ++i)
        {

            y[i-3]=Temp[i];
        }

        mx = get_mean(x);
        my = get_mean(y);
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<endl;
        sx=get_stdev(x,mx);
        sy=get_stdev(y,my);
        double sum = 0;
        for (unsigned int i = 0; i< N; ++i)
        {
            sum += (x[i]-mx)*(y[i]-my);
        }
        double covariance = sum / (N-1);
        double correlation = covariance /(sx*sy);
        cout<<"mx = "<<mx<<endl;
        cout<<"my = "<<my<<endl;
        cout<<"sx = "<<sx<<endl;
        cout<<"sy = "<<sy<<endl;
        cout<<"Covariance = "<<covariance<<endl;
        cout<<"Correlation = "<<correlation<<endl;;
        i=0;
        do
        {
            cout<<Temp[i] << symbolvect[i]<<" || "<<Temp[i+1]<<
                symbolvect[i+1]<<" || "<<Temp[i+2]<<symbolvect[i+2]<<endl;
            i=i+3;
        }
        while (i<Temp.size());


    }

}
