#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,edges;
    cin>>n;
    vector<int>vec_edges[n+1];
    vector<int>vec_cost[n+1];
    cin>>edges;
    int i,j,x,y;
    int visited[n+1];
    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        vec_edges[x].push_back(y);
        vec_cost[x].push_back(1);
    }
    int base_node;
    cin>>base_node;





}
