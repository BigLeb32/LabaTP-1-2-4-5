#include <iostream>
#include <vector>
#include<math.h>
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
        else if (scale == Kelvin) return 5*(data.value - 32)/9 + 273.15;
        else if (scale == Celsius) return (data.value-32)/1.8;
        break;
    }
}

istream& operator>> (istream& input, Temperature& data)
{
    double out;
    cout<< "Enter temperature and scale: ";
    input >> data.value>>symbol;
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

    return input;
}





vector<double> input(unsigned int N)
{
    Temperature data;
    int i;
    vector<double>v(N);
    for(i=0; i<N; ++i)
    {
        cout<<"Enter "<<i+1<<": ";
        cin>>data;
        v[i]=convert(data,Kelvin);
    }
    return v;
}

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
    float svv=0,vv=0;
    for(i=0; i<v.size(); ++i)
    {
        svv+=(v[i]-sv)*(v[i]-sv);
    }
    svv = svv/(v.size()-1);
    return svv;
}




int main()
{
    int N,i;
    float mx,my,sx,sy;
    cout<<"Enter number of scales: ";
    cin>>N;
    vector<double>x=input(N);
    vector<double>y=input(N);

    mx = get_mean(x);
    my = get_mean(y);
    sx=get_stdev(x,mx);
    sy=get_stdev(y,my);
    cout<<"sredn x"<<mx<<" sredn y"<<my<<endl;
    cout<<"disp x"<<sx<<" disp y"<<sy<<endl;
    double sum = 0;
    for (unsigned int i = 0; i< N; ++i)
    {
        sum += (x[i]-mx)*(y[i]-my);
    }
    cout<<"sum "<<sum<<endl;
    double covariance = sum / (x.size()-1);
    double correlation = covariance / sqrt(sx*sy);

    for (unsigned int i = 0; i< x.size(); ++i)
    {
        cout<<x[i] << " || "<<y[i]<<endl;
    }
    cout<<"Covariance = "<<covariance<<endl;
    cout<<"Correlation = "<<correlation;



}
