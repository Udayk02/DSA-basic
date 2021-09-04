#include<iostream>
using namespace std;
class kruskal
{
    int min_val = 0, src, dest;
    int edge_count = 0;
    public:
    int cost_mat[100][100];
    char nodes[100];
    int status[100];
    int minspan_mat[100][100];
    void minspan_tree(int);
    void print(int);
};

void kruskal :: minspan_tree(int n)
{
    int tmp_mat[100][100], t, l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                minspan_mat[i][j] = 0;
            }
            else
            {
                minspan_mat[i][j] = 10000;
            }
            tmp_mat[i][j] = 0;
        }
    }
    while (edge_count < n-1 && min_val != 10000)
    {
        t = 0;
        min_val = 10000;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (cost_mat[i][j] < min_val)
                    {
                        min_val = cost_mat[i][j];
                        src = i;
                        dest = j;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            l = 0;
            for (int j = 0; j < n; j++)
            {
                if (tmp_mat[i][j] == 0)
                {
                    l++;
                }
            }
            if (l == n)
            {
                tmp_mat[i][src] = 1;
                tmp_mat[i][dest] = 1;
                t = 1;
                break;
            }
            if ((tmp_mat[i][src] == 1 && tmp_mat[i][dest] == 0)  || (tmp_mat[i][src] == 0 && tmp_mat[i][dest] == 1))
            {
                tmp_mat[i][src] = 1;
                tmp_mat[i][dest] = 1;
                t = 1;
                break;
            }
            if (tmp_mat[i][src] == 1 && tmp_mat[i][dest] == 1)
            {
                t = 0;
                break;
            }
        }
        if (t == 1)
        {
            status[src] = status[dest] = 1;
            minspan_mat[src][dest] = min_val;
            minspan_mat[dest][src] = min_val;
            edge_count++;
            cost_mat[src][dest] = 10000;
            cost_mat[dest][src] = 10000;
        }
        else
        {
            cost_mat[src][dest] = 10000;
            cost_mat[dest][src] = 10000;
        }
    }
}

void kruskal :: print(int n)
{
    int sum = 0;
    cout << "\n---MINIMUM SPANNING TREE___COST MATRIX---::\n\n";
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << nodes[i] << "      ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n" << nodes[i] << " ";
        for (int j = 0; j < n; j++)
        {
            
            if (minspan_mat[i][j] < 10)
            {
                cout << minspan_mat[i][j] << "      ";
            }
            else if (minspan_mat[i][j] < 100)
            {
                cout << minspan_mat[i][j] << "     ";
            }
            else if (minspan_mat[i][j] < 1000)
            {
                cout << minspan_mat[i][j] << "    ";
            }
            else if (minspan_mat[i][j] < 10000)
            {
                cout << minspan_mat[i][j] << "   ";
            }
            else if (minspan_mat[i][j] == 10000)
            {
                cout << minspan_mat[i][j] << "  ";
            }

            if (minspan_mat[i][j] != 10000)
            {
                sum = sum + minspan_mat[i][j];
            }
        }
    }
    cout << "\n\nMINIMUM SPAN : " << sum/2;
}

int main()
{
    cout << "\n----IMPLEMENTING KRUSKAL'S ALGORITHM----\n\n";
    kruskal k1;
    int n;
    cout << "ENTER NO. OF NODES : ";
    cin >> n;
    cout << "\nENTER NODES :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nENTER NODE " << i+1 << " : ";
        cin >> k1.nodes[i];
        k1.status[i] = 0;
    }
    cout << "\nENTER COST MATRIX :\n\n";
    cout << "\n('''ENTER ''10000'' FOR INFINITE DISTANCE''')\n\n";
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << k1.nodes[i] << "      ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n" << k1.nodes[i] << " ";
        for (int j = 0; j < n; j++)
        {
            cin >> k1.cost_mat[i][j];
        }
    }
    k1.minspan_tree(n);
    k1.print(n);
}