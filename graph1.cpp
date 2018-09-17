#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    cout<<"Enter number of node: ";
    cin>>node;
    int matrix[node][node]={0};
    int edge;
    cout<<"Enter number of edge: ";
    cin>>edge;
    int i,j,x,y,cost;
    for(i=0;i<edge;i++)
    {
        cin>>x>>y>>cost;
        matrix[x-1][y-1]=cost;
        matrix[y-1][x-1]=cost;
    }
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}
