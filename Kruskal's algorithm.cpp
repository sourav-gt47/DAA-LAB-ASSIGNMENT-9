#include<bits/stdc++.h>
using namespace std;
int n, m;

struct graph{
int a;  //leftmost point of edge
int b;  //rightmost point of edge
int weight; // weight of edge

};
graph arr[100];
int parent[100];


bool capacity(struct graph a , struct graph b )
{

return (a.weight < b.weight);


}
// find parent function

int find (int i){
while(parent[i] > 0){
    i = parent[i];
    
}
return i;
}

//find union function

void uni_on(int i , int j){

int count = parent[i] + parent[j];

if(parent[i] <= parent[j]){

parent[j] = i;
parent[i] = count;
}

else{
parent[i] = j;
parent[j] = count;

}

}





int main()
{
int sum=0;
cin>>n;
cin>>m;
graph arr[n];
int parent[m];
for(int i=1;i<=n; i++ ) parent[i] = -1;

for(int i=0; i<m; i++)
{
  cin>>arr[i].a>>arr[i].b>>arr[i].weight;
}

sort (arr, arr+m,capacity);


for(int i=0; i<m; i++){

int a = find(arr[i].a);
int b = find(arr[i].b);

if (a != b)
{
sum+= arr[i].weight;
uni_on(a , b);
cout<<char(a + 64)<<"--"<<char(b + 64)<<"  "<<arr[i].weight<<endl;
}

}

cout<<"Total profit::"<<sum<<endl;

    return 0;
}
