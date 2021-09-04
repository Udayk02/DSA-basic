#include <iostream>
using namespace std;

class graph
{
    int nodes[100];
    int cost[100][100];
    int node_count;

public:
    graph();
    void prims();
};

graph::graph()
{
    cout << "Enter number of nodes: ";
    cin >> node_count;
    cout << "Enter nodes: ";
    for (int i = 0; i < node_count; ++i)
    {
        cin >> nodes[i];
    }
    cout << "Enter cost matrix ( use 999 for infinite ) : ";
    for (int i = 0; i < node_count; ++i)
    {
        for (int j = 0; j < node_count; ++j)
        {
            cin >> cost[i][j];
        }
    }
}

void graph::prims(){
    int visited[node_count];
    int i = 0, j = 1, sum = 0 ,count = 1;
    for(int i = 0;i<node_count;++i){
        visited[i] = 0;
    }
    int min = cost[0][1];
    for(int x = 0;x<node_count;++x){
        for(int y = x+1;y<node_count;++y){
            if((min>cost[x][y])&&x!=y){
                min = cost[x][y];
                i = x; j = y;
            }
        }
    }
    visited[i] = visited[j] = 1;
    sum += min;
    while(count<node_count-1){
        i = 0, j = 1;
        min = cost[0][1];
        for(int x = 0;x<node_count;++x){
            for(int y = x+1;y<node_count;++y){
                if(min>cost[x][y]&&x!=y)
                {
                    if((visited[x]==1&&visited[y]==0)||(visited[x]==0&&visited[y]==1)){
                        min = cost[x][y];
                        i = x; j = y;
                    }
                }
            }
        }
        if(visited[i]==1){
            visited[j] = 1;
        }
        else{
            visited[i] = 1;
        }
        sum += min;
        count++;
    }
    cout<<"min cost: "<<sum;
}

int main(){
    graph g;
    g.prims();
}