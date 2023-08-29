#include <iostream>
using namespace std;
struct node
{
    unsigned int dist[20];
    unsigned int from[20];
} rt[10];

int main()
{
    int dmat[20][20], n, i, j, k, count = 0;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the cost matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> dmat[i][j];
            dmat[i][i] = 0;
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
    
    for (i = 0; i < n; i++)
    {
        cout << "\n\nState value for router " << i + 1 << " is:\n";
        for (j = 0; j < n; j++)
        {
            cout << "\n\tnode " << j + 1 << " via " << rt[i].from[j] + 1 << " Distance " << rt[i].dist[j];
        }
        cout << "\n\n";
    }
    return 0;
}