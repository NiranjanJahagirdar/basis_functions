#include <bits/stdc++.h>
using namespace std;

vector<float> polyfit(vector<float> x, vector<float> y, int degree){
    int N=x.size();

    vector<float> arr;                        // To store the values of x^0,X^1....
    for(int z=0;z<2*degree+1;z++)
      arr.push_back(0);                              //Initialising vector with 0

    for (int i=0;i<2*degree+1;i++)
    {
        for (int j=0;j<N;j++)
            arr[i]=arr[i]+pow(x[j],i);
    }

    float equ[degree+1][degree+2];
    vector<float> ans(degree+1);
                                                        //equ will be used to form final equations, ans will store final coefficients weights
    for (int i=0;i<=degree;i++)
        for (int j=0;j<=degree;j++)
            equ[i][j]=arr[i+j];

    vector<float> temp;
    for(int z=0;z<degree+1;z++)
      temp.push_back(0);                              //Initialising vector with 0

    for (int i=0;i<degree+1;i++)
    {
        for (int j=0;j<N;j++){
          temp[i]=temp[i]+pow(x[j],i)*y[j];
        }
        equ[i][degree+1]=temp[i];
    }


    degree++;

    for (int i=0;i<degree;i++)
        for (int k=i+1;k<degree;k++)
            if (equ[i][i]<equ[k][i])
                for (int j=0;j<=degree;j++)
                {
                    float temp1=equ[i][j];
                    equ[i][j]=equ[k][j];
                    equ[k][j]=temp1;
                }
    for (int i=0;i<degree-1;i++)
      for (int k=i+1;k<degree;k++)
      {
        float t=equ[k][i]/equ[i][i];
        for (int j=0;j<=degree;j++)
          equ[k][j]=equ[k][j]-t*equ[i][j];
      }
      for (int i=degree-1;i>=0;i--)
      {
        ans[i]=equ[i][degree];
        for (int j=0;j<degree;j++)
          if (j!=i)
            ans[i]=ans[i]-equ[i][j]*ans[j];
            ans[i]=ans[i]/equ[i][i];
      }

      return ans;
}


void spline(vector<float> x,vector<float> y,vector<float> knots,int degree){

  int count=0;
  float knot_previous=0;
  for(int i=0;i<x.size() && count<knots.size();i++){
    float knot_interval = knots[count++];
    //finding points belonging to given knot interval
    vector<float> temp_x;
    vector<float> temp_y;
    while(x[i]<=knot_interval){
      temp_x.push_back(x[i]);
      temp_y.push_back(y[i]);
      i++;
    }
    i--;
    //finding apropriate polynomial equation for give interval
    vector<float> polynomial_var = polyfit(temp_x,temp_y,degree);
    //printing curve equation for each interval
    cout<<endl;
    cout<<count<<") Equation for interval "<<knot_previous<<"<=X<="<<knot_interval<<endl;
    for(int k=0;k<polynomial_var.size();k++){
      cout<<polynomial_var[k]<<"X^"<<k<<" , ";
    }
    cout<<endl;
    knot_previous=knot_interval;
  }
}

int main(){
  int size,degree,num_knots;
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
    cout<<"\nenter degree =\n";
    cin>>degree;
    cout<<"\nenter number of knot intervals =\n";
    cin>>num_knots;
    cout<<"\nenter the knot values\n";
    vector<float> knots(num_knots);
    for(int i=0;i<num_knots;i++){
      cin>>knots[i];
    }
  spline(x,y,knots,degree);
  cout<<endl;
  return 0;
}
