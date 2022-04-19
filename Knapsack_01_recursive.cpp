#include<bits/stdc++.h>
using namespace std;


int knapsack(int W, int weight[], int profit[], int n )
{  // edge case
  if( n==0 || W==0)
    return 0;
// if nth item is more than knapsack weight W , can't include the item in dp[][]
  else if( weight[n-1] > W)
    return knapsack(W , weight, profit, n-1);
// if nth item is less than knapsack weight W , can be include the item in dp[][] 
  else
    return max (profit[n-1] + knapsack(W - weight[n-1], weight, profit, n-1), 
          knapsack(W, weight,profit,n-1));

}



int main(){
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


cout<< "Max profit::" << knapsack(W, capacity,profit, n) <<endl;
return 0;
}

