#include <bits/stdc++.h>
using namespace std;

vector<float> gaussian(vector<float> x){
  //mean
  float mean = 0;
  for(int i=0;i<x.size();i++){
    mean+=x[i];
  }
  mean=mean/x.size();
  //standard deviation
  float sd=0 ;
  for(int i=0;i<x.size();i++){
    sd+=pow((x[i]-mean),2);
  }
  sd=sd/x.size();
  sd=sqrt(sd);
  //gaussian
  //f(x)= (1/root(2*pi))*e^-((x-mean)^2/(2*(sd^2))
  float pi = 3.141593;
  //float firstterm = (1/(sd*sqrt(2*pi)));
  vector<float> ans(x.size());
  for(int i=0;i<x.size();i++){
      float z = pow((x[i]-mean)/sd,2);;
      ans[i]=(exp(-.5*z));
  }
  return ans;
}

//calculating the fit of predicted curve with actual values
void MSE_error(vector<float> pred_y,vector<float> act_y){
  float error=0;
  for(int i=0;i<pred_y.size();i++){
    error+=pow(pred_y[i]-act_y[i],2);                       //MSE = 1/N *(summation(pred_y-actual_y)^2)
  }
  error=error/pred_y.size();
  cout<<"\nMSE_error = "<<error<<endl;
}

int main(){
  int size=0;
  cout<<"enter size = \n";
  cin>>size;
  vector<float> x;
  vector<float> y;
  cout<<"\nEnter the x-axis values:\n";                   //Input x-values
  for (int i=0;i<size;i++)
      cin>>x[i];
  cout<<"\nEnter the y-axis values:\n";                  //Input y-values
  for (int i=0;i<size;i++)
      cin>>y[i];
  vector<float> ans=gaussian(x);
  MSE_error(ans,y);                                      //comparing the fit of predicted curve with actual curve
  cout<<endl;
  return 0;
}
