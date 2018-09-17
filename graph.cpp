#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,edges;
    cout<<"Enter no. of node: ";
    cin>>n;
    cout<<"Enter no. of edges:  ";
    cin>>edges;
    vector<int>vec_edges[n+1];
    vector<int>vec_cost[n+1];
    int indegree[n+1]={0};
    int outdegree[n+1]={0};
    int i,x,y,j;
    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        vec_edges[x].push_back(y);
        indegree[y]++;
        outdegree[x]++;
        ///vec_edges[y].push_back(x);
        vec_cost[x].push_back(1);
        //vec_cost[y].push_back(1);
    }
    int p;
    /**cout<<"Enter the node no to know which node is connected with it: ";
    cin>>p;
    int size=vec_edges[p].size();
    for(i=0;i<size;i++)
    {
        cout<<vec_edges[p][i]<<"\t";
    }**/
    for(i=1;i<=n;i++)
    {
        p=vec_edges[i].size();
        cout<<"Node: "<<i<<endl;
        cout<<"Indegree:  "<<indegree[i]<<"   "<<"Outdegree :  " <<outdegree[i]<<endl;
        /**for(j=0;j<p;j++)
        {
            cout<<vec_edges[i][j]<<"\t";
        }
        cout<<endl;**/
    }
}
