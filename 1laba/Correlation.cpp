#include<iostream>
#include<conio.h>
#include<math.h>
#include <vector>
using namespace std;
int main()
{

  int i,n;
  vector<float> x(10);
  vector<float> y(10);
  float sx=0,sy=0,sxy=0,sxx=0,syy=0,mx,my,sdx,sdy,cxy,r,vx,vy;
    cout<<"Enter the no. of pairs : ";
    cin>>n;
  for(i=0;i<n;++i)
{
    cout<<"Enter X"<<i+1<<": ";
    cin>>x[i];}

   for(i=0;i<n;++i)
{
    cout<<"Enter Y"<<i+1<<": ";
    cin>>y[i];}

     for(i=0;i<n;++i){
        sx+=x[i];
    sxx+=(x[i]*x[i]);
    sy+=y[i];
    syy+=(y[i]*y[i]);
    sxy+=(x[i]*y[i]);
}
    mx=sx/n;
    my=sy/n;
    vx=(sxx/n)-(mx*mx);
    vy=(syy/n)-(my*my);
    sdx=sqrt(vx);
    sdy=sqrt(vy);
    cxy=(sxy/n)-(mx*my);
    r=cxy/(sdx*sdy);
    cout<<"Correlation coefficient : "<<r;

}
