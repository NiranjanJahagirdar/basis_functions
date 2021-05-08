#include <bits/stdc++.h>
using namespace std;

vector<float> wavelet(vector<float> x,vector<float> y,int sigma,int scaleF,int shiftF){
  vector<float> ans(x.size());
  for(int i=0;i<x.size();i++){
    float temp = cos((scaleF*x[i])+shiftF);
    ans[i] = temp*exp(-x[i]/(2*pow(sigma,2)));                      //cos(wx+a)*e^(-x/2sigma^2)
  }
  return ans;
}

void MSE_error(vector<float> pred_y,vector<float> act_y){
  float error=0;
  for(int i=0;i<pred_y.size();i++){
    error+=pow(pred_y[i]-act_y[i],2);
  }
  error=error/pred_y.size();
  cout<<"\nMSE_error = "<<error<<endl;
}

int main(){
  int size,scaleF,shiftF,sigma;
  cout<<"enter size = \n";
  cin>>size;
  vector<float> x(size);
  vector<float> y(size);
  cout<<"\nEnter the x-axis values:\n";                //Input x-values
    for (int i=0;i<size;i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";                //Input y-values
    for (int i=0;i<size;i++)
        cin>>y[i];
    cout<<"\nenter sigma =\n";
    cin>>sigma;
    cout<<"\nenter scaleF =\n";
    cin>>scaleF;
    cout<<"\nenter shiftF =\n";
    cin>>shiftF;
    vector<float> ans=wavelet(x,y,sigma,scaleF,shiftF);
    MSE_error(ans,y);
    return 0;
}
