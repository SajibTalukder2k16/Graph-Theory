#include<bits/stdc++.h>
using namespace std;
#define maxx 1000000
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector<int>vec_node[node+1];
    vector<int>vec_cost[node+1];
    int i,j,n1,n2,cost;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2>>cost;
        vec_node[n1].push_back(n2);
        vec_cost[n1].push_back(cost);
    }
    int source_node,destination_node;
    cin>>source_node;
    queue<int>dijkstra;
    dijkstra.push(source_node);
    int distance[node+1];
    for(i=1;i<=node;i++)
        distance[i]=maxx;
    distance[source_node]=0;
    int x,k;
    for(k=0;k<node;k++)
    {
        x=dijkstra.front();
        for(i=0;i<vec_node[x].size();i++)
        {
            if(distance[x]+vec_cost[x][i]<distance[vec_node[x][i]])
            {
                distance[vec_node[x][i]]=distance[x]+vec_cost[x][i];
                dijkstra.push(vec_node[x][i]);
                ///cout<<vec_node[x][i]<<" "<<distance[vec_node[x][i]]<<endl;
            }
        }
        dijkstra.pop();
    }
    cout<<"Enter destination node: ";
    cin>>destination_node;
    x=dijkstra.front();
    for(i=0;i<vec_node[x].size();i++)
    {
        if(distance[x]+vec_cost[x][i]<distance[vec_node[x][i]])
        {
            cout<<"Negative cycle"<<endl;
            return 0;
        }
    }

    cout<<distance[destination_node]<<endl;
}
