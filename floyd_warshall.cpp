#include<bits/stdc++.h>
using namespace std;
#define maxx 10000
//int matrix[maxx][maxx];
int Next[maxx][maxx];
void find_path(int i,int j)
{
    if(i!=j)
    {
        cout<<i<<" ";
        i=Next[i][j];
        find_path(i,j);
        return;
    }
    cout<<j<<endl;
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    int matrix[node+1][node+1];
    ///int next[node+1][node+1];
    int i,j,k,n1,n2,cost;
    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
        {
             if(i==j)
                matrix[i][j]=0;
             else
                matrix[i][j]=maxx;
        }
    }
    for(i=1;i<=edge;i++)
    {
        cin>>n1>>n2>>cost;
        matrix[n1][n2]=cost;
        Next[n1][n2]=n2;
    }
    for(k=1;k<=node;k++)
    {
        for(i=1;i<=node;i++)
        {
            for(j=1;j<=node;j++)
            {
                if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                    {
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
                        Next[i][j]=Next[i][k];
                    }
            }
        }
    }
    int source_node,desired_node;
    cout<<"Enter source node: ";
    cin>>source_node;
    cout<<"Enter desired node: ";
    cin>>desired_node;
    cout<<"Distance : "<<matrix[source_node][desired_node]<<endl;
    if(matrix[source_node][desired_node]!=maxx)
        find_path(source_node,desired_node);
}
