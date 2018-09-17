#include<bits/stdc++.h>
using namespace std;
#define white 0
#define black 2
#define gray 1
#define null -1;
int timing=0;
int discovering_time[100];
int finishing_time[100];
int color[100];
int parent[100];
vector<int>vec_node[100];
int dfs_visit(int u)
{
    color[u]=gray;
    timing++;
    discovering_time[u]=timing;
    int len=vec_node[u].size();
    int i;
    ///cout<<"dfs_visit"<<endl;
    for(i=0;i<len;i++)
    {
        if(color[vec_node[u][i]]==white)
        {
            parent[vec_node[u][i]]=u;

            dfs_visit(vec_node[u][i]);
        }
    }
    color[u]=black;
    timing++;
    finishing_time[u]=timing;
    cout<<u<<"\t"<<discovering_time[u]<<"\t"<<finishing_time[u]<<endl;;
}
int dfs(int node)
{
    int i;
    for(i=1;i<=node;i++)
    {
        ///cout<<"dfs"<<endl;
        if(color[i]==white)
        {
            dfs_visit(i);
        }
    }

}
int main()
{
    int node,edge;
    cout<<"Enter no of node: ";
    cin>>node;
    cout<<"Enter no of edges: ";
    cin>>edge;
    ///color=new int[node+1];
    ///parent=new int[node+1];
    int i,n1,n2;
    for(i=1;i<=node;i++)
        color[i]=white;
    for(i=1;i<=node;i++)
        parent[i]=-1;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        vec_node[n1].push_back(n2);
        ///vec_node[n2].push_back(n1);
    }
    dfs(node);
}
