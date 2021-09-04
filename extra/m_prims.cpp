//prims

#include<iostream>
using namespace std;


class prims{
    int n;//number of vertices
    int v[100];//verices
    int visited[100];//if vertex visited
    int cost[100][100];
    int count=0;
    public:
    prims();
    int min_cost;
    void min_span();

};
prims::prims(){
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter "<<n<<" vertices :";
    for(int i=0;i<n;i++){
        cin>>v[i];
        visited[i]=0;
    }
    cout<<"Enter cost matrix :";
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            cin>>cost[i][j];
        }
    }
    min_cost=0;
    // cout<<min_cost;
    visited[0] = 1;
    min_span();

    cout<<min_cost;
}
void prims::min_span(){
    int row,col;
    int min=999;

    for(int i=0;i<n;i++){
        if(visited[i]==1){
           for(int j=0;j<n;j++){
               if(visited[j]==0){
                   if(cost[i][j]<min){
                   min=cost[i][j];          //getting minimum value from whole visited vertices
                   row=i;
                   col=j;
                }
               } 
            }     
        }
    }
    if(min<999)
        min_cost+=min;                 
    //cout<<min_cost<<" "<<count<<endl;
    visited[row]=1;           // making the verices visited
    visited[col]=1;
    count++;
    if(count<n - 1){
        min_span();
    }
}
int main(){
    prims p;
}