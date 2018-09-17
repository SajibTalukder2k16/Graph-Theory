#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,edges;
    cin>>n>>edges;
    vector<int>vec_edges[n+1];
    vector<int>vec_cost[n+1];
    int x,y,z,i,j;
    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        vec_edges[x].push_back(y);
        vec_edges[y].push_back(x);
        vec_cost[x].push_back(1);
        vec_cost[y].push_back(1);


    }
    cout<<" Enter the base node: ";
    int pp,qq;
    cin>>pp;
    queue<int>bfs_queue;
    bfs_queue.push(pp);
    cout<<"Enter wanted node: ";
    cin>>qq;
    int count=0;
    int ara[1000]={0};
    ara[pp]=1;
    int level[n+1]={0};
    level[pp]=0;
    while(bfs_queue.front()!=qq)
    {
        x=bfs_queue.front();
        for(i=0;i<vec_edges[x].size();i++)
        {
            if(ara[vec_edges[x][i]]==0)
            {
                bfs_queue.push(vec_edges[x][i]);
                level[vec_edges[x][i]]=level[bfs_queue.front()]+1;
                ara[vec_edges[x][i]]=1;
            }
        }

        cout<<bfs_queue.front()<<"\t";
        bfs_queue.pop();


    }
    cout<<endl<<"Count : "<<level[bfs_queue.front()]<<endl;


}
