#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>vec_node[n+1];
    vector<int>vec_cost[n+1];
    int i,j,x,y;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        vec_node[x].push_back(y);
        vec_cost[x].push_back(1);
        if(x!=y)
        {
            vec_node[y].push_back(x);
            vec_cost[y].push_back(1);
        }
    }
    int source_node,desired_node;
    cin>>source_node;
    cin>>desired_node;
    int level[n+1]={0};
    int visited[n+1]={0};
    level[source_node]=0;
    queue<int>bfs;
    bfs.push(source_node);
    while(bfs.front()!=desired_node)
    {
        int tt=bfs.front();
        for(i=0;i<vec_node[tt].size();i++)
        {
            if(visited[vec_node[tt][i]]==0)
            {
                bfs.push(vec_node[tt][i]);
                level[vec_node[tt][i]]=level[tt]+1;
                visited[vec_node[tt][i]]=1;
            }
        }
        bfs.pop();

    }
    cout<<level[desired_node]<<endl;
}
