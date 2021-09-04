#include <iostream>
using namespace std;

// Graph and it's requirements for implementing kruskal's algorithm
class graph
{
    int nodes[100];     // for storing nodes
    int cost[100][100]; // for storing cost matrix
    int node_count;
    int k = 0;
    int linear_cost[100];
    int source[100];
    int destination[100];

public:
    graph();
    void swap(int &, int &);
    void sort();
    void ordering();
    void kruskals();
    int find(int[], int);
};

//taking input through a constructor
graph::graph()
{
    cout << "Enter number of nodes: ";
    cin >> node_count;
    cout << "Enter nodes: ";
    for (int i = 0; i < node_count; ++i)
    {
        cin >> nodes[i];
    }
    cout << "Enter cost matrix ( use 999 for infinite ) : \n\n   ";
    for (int i = 0; i < node_count; ++i)
    {
        cout << nodes[i] << "   ";
    }
    for (int i = 0; i < node_count; ++i)
    {
        cout << "\n"
             << nodes[i] << "  ";
        for (int j = 0; j < node_count; ++j)
        {
            cin >> cost[i][j];
        }
    }
    //for reference, nodes and cost matrix
    cout << "Nodes: ";
    for (int i = 0; i < node_count; ++i)
    {
        cout << nodes[i] << " ";
    }
    cout << "\nGraph's Cost Matrix: \n\n    ";
    for (int i = 0; i < node_count; ++i)
    {
        cout << nodes[i] << "    ";
    }
    for (int i = 0; i < node_count; ++i)
    {
        cout << "\n"
             << nodes[i] << "   ";
        for (int j = 0; j < node_count; ++j)
        {
            if (cost[i][j] < 10)
            {
                cout << cost[i][j] << "    ";
            }
            else if (cost[i][j] < 100)
            {
                cout << cost[i][j] << "   ";
            }
            else
            {
                cout << cost[i][j] << "  ";
            }
        }
        cout << "\n";
    }
}

//seperating the required vertices / nodes
void graph::ordering()
{
    for (int i = 0; i < node_count; ++i)
    {
        for (int j = i + 1; j < node_count; ++j)
        {
            if (cost[i][j] != 999 && cost[i][j] != 0)
            {
                linear_cost[k] = cost[i][j];
                source[k] = i;
                destination[k] = j;
                k = k + 1;
            }
        }
    }
    sort();
}

//swapping which is a part of bubble sort
void graph::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//using bubble sort for sorting the required nodes based on their edge weights in ascending order
void graph::sort()
{
    for (int i = 0; i < k; i++)
    {
        bool s = true;
        for (int j = 0; j < (k - i - 1); j++)
        {
            if (linear_cost[j] > linear_cost[j + 1])
            {
                swap(linear_cost[j], linear_cost[j + 1]);
                swap(source[j], source[j + 1]);
                swap(destination[j], destination[j + 1]);
                s = false;
            }
        }
        if (s)
        {
            break;
        }
    }
    kruskals();
}

//for finding the parent of that particular nodes
int graph::find(int parent[], int x)
{
    if (parent[x] < 0)
    {
        return x;
    }
    return find(parent, parent[x]);
}

//kruskals algo implementation
void graph::kruskals()
{
    //for reference, sorted weights
    cout<<"\nRequired Sorted nodes: \n";
    for (int i = 0; i < k; ++i)
    {
        cout << linear_cost[i] << " " << source[i] << " " << destination[i] << "\n";
    }
    int min_spanning_tree[node_count][node_count]; //min. spanning tree's cost matrix
    //initialising min. spanning tree's cost matrix with 0s
    for (int i = 0; i < node_count; ++i)
    {
        for (int j = 0; j < node_count; ++j)
        {
            min_spanning_tree[i][j] = 0;
        }
    }
    int count = 0, sum = 0, k = 0;
    int parent[node_count]; //parent array storing the parent of each node
    for (int i = 0; i < node_count; ++i)
    {
        parent[i] = -1; //initially they are parents of themselves
    }
    while (count < node_count - 1)
    {
        int parent_src = find(parent, source[k]);      //getting the parent of source
        int parent_des = find(parent, destination[k]); //getting the parent of destination
        if (parent_src != parent_des)
        {
            sum += linear_cost[k];
            parent[parent_src] = parent_des;
            parent[source[k]] = parent_des;
            count++;
            //construction of min. spanning tree's cost matrix
            min_spanning_tree[source[k]][destination[k]] += linear_cost[k];
            min_spanning_tree[destination[k]][source[k]] += linear_cost[k];
        }
        k++;
    }
    //for the remaining fill up in the MST's cost matrix
    for (int i = 0; i < node_count; ++i)
    {
        for (int j = 0; j < node_count; ++j)
        {
            if (min_spanning_tree[i][j] == 0 && i != j)
            {
                min_spanning_tree[i][j] = 999;
            }
        }
    }
    cout << "\nMinimum Spanning Tree Cost Matrix: \n\n    ";
    for (int i = 0; i < node_count; ++i)
    {
        cout << nodes[i] << "    ";
    }
    for (int i = 0; i < node_count; ++i)
    {
        cout << "\n"
             << nodes[i] << "   ";
        for (int j = 0; j < node_count; ++j)
        {
            if (min_spanning_tree[i][j] < 10)
            {
                cout << min_spanning_tree[i][j] << "    ";
            }
            else if (min_spanning_tree[i][j] < 100)
            {
                cout << min_spanning_tree[i][j] << "   ";
            }
            else
            {
                cout << min_spanning_tree[i][j] << "  ";
            }
        }
    }
    cout << "\n\nMinimum cost: " << sum;
}

int main()
{
    graph g;
    g.ordering();
}