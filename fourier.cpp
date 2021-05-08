#include <bits/stdc++.h>
using namespace std;

//fourier function with sine and cosine
vector<float> fourier(vector<float> x,string curve,float scalingFactor, float shiftFactor){
  int n=x.size();
  vector<float> ans(n);
  if(curve == "cosine"){


    for(int i=0;i<n;i++){
      ans[i]=cos((scalingFactor*x[i])+shiftFactor);           //cos(wx+a)
    }
  }else{//sine

        for(int i=0;i<n;i++){
            ans[i]=sin((scalingFactor*x[i])+shiftFactor);   //sin(wx+a)
        }
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
  int size=0,scaleF=0,shiftF=0;
  string curve;
  cout<<"enter size = \n";
  cin>>size;
  vector<float> x(size);
  vector<float> y(size);
  cout<<"\nEnter the x-axis values:\n";                    //Input x-values
    for (int i=0;i<size;i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";                  //Input y-values
    for (int i=0;i<size;i++)
        cin>>y[i];
    cout<<"\nenter curve : cosine or sin ? \n";
    cin>>curve;                                            //input sine or cosine
    cout<<"\nenter scaleF =\n";
    cin>>scaleF;                                           //input for scale factor
    cout<<"\nenter shiftF =\n";
    cin>>shiftF;                                           //input for shoft factor
    vector<float> ans=fourier(x,curve,scaleF,shiftF);
    MSE_error(ans,y);
    return 0;
}
