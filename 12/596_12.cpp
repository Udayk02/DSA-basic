#include<iostream>
#include<stdlib.h>
#include "596_12_queue.h"
#include "596_12_stack.h"
using namespace std;

class Graph{
    int n;
    int arr[100];
    int adj[100][100];
    public:
    Graph();
    void choose(int, int, int[]);
    void BFS(int, int, int[]);
    void DFS(int, int, int[]);
};

Graph::Graph(){
    int size;
    cout<<"Enter number of nodes: ";
    cin>>size;
    cout<<"\nEnter the nodes(integer nodes): ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the adjacency matrix: ";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d", &adj[i][j]);
        }
    }
    int start, visited[size];
    choose(size, start, visited);
}

void Graph::choose(int size, int start, int visited[]){
    int option;
    do{
        cout<<"\nEnter the starting node: ";
        cin>>start;
        for(int i=0;i<size;i++){
            visited[i] = 0;
        }
        cout<<"\n1. DFS\n2. BSF\n3. Exit\nChoose an option: ";
        cin>>option;
        switch(option){
            case 1:
                DFS(size, start, visited);
                break;
            case 2:
                BFS(size, start, visited);
                break;
            case 3:
                break;
            default:
                cout<<"Choose a valid option.";
                break;
        }
    } while(option!=3);
}

void Graph::BFS(int size, int start, int visited[]){
    Queue q;
    int i;
    printf("\nBFS: ");
    for(i=0;i<size;i++){
        if(arr[i]==start){
            printf("%d ", start);
            visited[i] = 1;
            break;
        }
    }
    if(i==size){
        printf("Starting node not found");
        choose(size, start, visited);
    }
    for(int j=0;j<size;j++){
        if(adj[i][j] == 1){
            q.insert(arr[j]);
            visited[j] = 1;
        }
    }
    while(!q.isEmpty()){
        int n = q.delete_();
        printf("%d ", n);
        for(i=0;i<size;i++){
            if(arr[i]==n)   break;
        }
        for(int j=0;j<size;j++){
            if(adj[i][j]==1&&visited[j]==0){
                q.insert(arr[j]);
                visited[j] = 1;
            }
        }
    }
}

void Graph::DFS(int size, int start, int visited[]){
    Stack s;
    int i;
    printf("\nDFS: ");
    for(i=0;i<size;i++){
        if(arr[i]==start){
            printf("%d ", start);
            visited[i] = 1;
            break;
        }
    }
    if(i==size){
        printf("Starting node not found");
        exit(0);
    }
    for(int j=0;j<size;j++){
        if(adj[i][j] == 1){
            s.push(arr[j]);
            visited[j] = 1;
        }
    }
    while(!s.isEmpty()){
        int n = s.pop();
        printf("%d ", n);
        for(i=0;i<size;i++){
            if(arr[i]==n)   break;
        }
        for(int j=0;j<size;j++){
            if(adj[i][j]==1&&visited[j]==0){
                s.push(arr[j]);
                visited[j] = 1;
            }
        }
    }
}

int main(){
    Graph g;
}