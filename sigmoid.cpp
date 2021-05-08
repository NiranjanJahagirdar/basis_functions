#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

vector<double> sigmoid(vector<double> x){
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
  //sigmoid
  int n=x.size();
  vector<double> ans(n);
  for(int i=0;i<n;i++){
      double z=(x[i]-mean)/sd;
      ans[i]=1/(1+exp(-z));
  }
  return ans;
}

//calculating the fit of predicted curve with actual values
void MSE_error(vector<double> pred_y,vector<double> act_y){
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
  vector<double> x;
  vector<double> y;
  cout<<"\nEnter the x-axis values:\n";                   //Input x-values
  for (int i=0;i<size;i++)
      cin>>x[i];
  cout<<"\nEnter the y-axis values:\n";                  //Input y-values
  for (int i=0;i<size;i++)
      cin>>y[i];
  vector<double> ans=sigmoid(x);
  MSE_error(ans,y);                                      //comparing the fit of predicted curve with actual curve
  cout<<endl;
  return 0;
}
