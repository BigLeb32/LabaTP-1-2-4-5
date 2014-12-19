#include<iostream>
#include<conio.h>
#include<math.h>
#include <vector>
using namespace std;

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
    /*cout<<"!!"<<sv*sv<<endl;
    cout<<"!!!"<<(svv/(v.size()))<<endl;;
    vv
    vv=(svv/(v.size()))-(sv*sv);*/
    return svv;
}



int main()
{
    int N;
    float mx=0,my=0,sx=0,sy=0;
    cout<<"Enter number of pairs: ";
    cin>>N;
    vector<double>x=input(N);
    vector<double>y=input(N);
    mx = get_mean(x);
    my = get_mean(y);
    sx=get_stdev(x,mx);
    sy=get_stdev(y,my);

    double sum = 0;
    for (unsigned int i = 0; i< N; ++i)
    {
        sum += (x[i]-mx)*(y[i]-my);
    }
    double covariance = sum / (N-1);
    double correlation = covariance / sqrt(sx*sy);
    cout<<"sredn "<<mx<<" "<<my<<endl;
    cout<< "sredn "<<sx<<" "<<sy<<endl;
    cout<<"covariance: "<<covariance << '\n';
    cout<<"correlation: "<<correlation;
}


