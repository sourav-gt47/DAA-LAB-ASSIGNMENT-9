#include<iostream>
using namespace std;
int max(int a , int b){

return ( a > b? a : b );

}

int knapsack(int W , int profit[], int capacity[],int n){
//W--> weight in column with capacity[]
//n->in row with profit[]
int dp[n+1][W+1];
for(int i=0;i<=n;i++){

for(int j=0;j<=W;j++){


if(i == 0 || j==0)
   dp[i][j]=0;
    
else if(capacity[i-1] <= W)
   dp[i][j] = max(profit[i-1] + dp[i-1][j-capacity[i-1]] , dp[i-1][j]);

else
   dp[i][j] = dp[i-1][j];   
  

}


}

return dp[n][W];

}

int main()
{ 
    int W , n;
   cout<<"Enter W::";
   cin>>W;
  cout<<"Enter the size of profit array::";
  cin>>n;
  int profit[n];
  cout<<"Enter profits:: ";
  
  for(int i=0;i<n;i++)
  cin>>profit[i];

  int capacity[n];
  cout<<"Enter capacities:: ";
  
  for(int i=0;i<n;i++)
  cin>>capacity[i];


cout<< knapsack(W, profit,capacity,n) <<endl;
return 0;

}