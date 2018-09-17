#include<bits/stdc++.h>
using namespace std;
#define maxx 10000000000000
int parent[1000005];
class compare
{
public:
    bool operator()(const pair<long long int,long long int> &p,const pair<long long int,long long int> &q)
    {
        return p.second>q.second;
    }
};
void get_parent(int node)
{
    ///cout<<node<<" "<<parent[node]<<endl;
    if(parent[node]!=1)
        get_parent(parent[node]);
    else
        cout<<parent[node]<<" ";
    cout<<node<<" ";
    return;
}
int main()
{


    long long int node,edge;
    cin>>node>>edge;
    vector<long long int>vec_node[node+1];
    vector<long long int>vec_cost[node+1];
    int i,j,n1,n2,cost;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2>>cost;
        vec_node[n1].push_back(n2);
        //vec_node[n2].push_back(n1);
        vec_cost[n1].push_back(cost);
        //vec_cost[n2].push_back(cost);
    }
    int source_node,destination_node;
    source_node=1;
    cin>>source_node;
    long long int distance[node+1];
    for(i=1;i<=node;i++)
        distance[i]=maxx;

    distance[source_node]=0;
    pair<long long int,long long int>par;
    pair<long long int,long long int>tr;
    for(i=1;i<=node;i++)
        parent[i]=i;
    ///parent[1]=1;
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,compare>priority_dijkstra;
    ///priority_queue<pair<int,int>,vector<pair<int,int>>,compare>prio;
    par=make_pair(source_node,distance[source_node]);
    priority_dijkstra.push(par);
    ///prio.push(par);
    int count=0;
    while(!priority_dijkstra.empty())
    {
         par=priority_dijkstra.top();
         long long int p1=par.first;
         long long int p2=par.second;
         long long int len=vec_node[p1].size();
         for(i=0;i<len;i++)
         {
             if(distance[p1]+vec_cost[p1][i]<distance[vec_node[p1][i]])
             {
                 distance[vec_node[p1][i]]=distance[p1]+vec_cost[p1][i];
                 tr=make_pair(vec_node[p1][i],distance[vec_node[p1][i]]);
                 parent[vec_node[p1][i]]=p1;
                 ///cout<<"ha ha"<<vec_node[p1][i]<<" "<<p1<<endl;
                 priority_dijkstra.push(tr);
                 //prio.push(tr);
                 ///count++;
                 ///cout<<"distance: "<<vec_node[p1][i]<<" "<<distance[vec_node[p1][i]]<<endl;
             }
         }
         ///count++;
         priority_dijkstra.pop();
         /**if(par.first==node)
         {
             break;
         }**/
    }
    int dd;
    cin>>dd;
    cout<<distance[dd]<<endl;
    if(distance[node]>=maxx)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    get_parent(node);

    /**for(i=0;i<prio.size();i++)
    {
        par=prio.top();
        cout<<par.first<<" "<<par.second<<endl;
        prio.pop();
    }**/
    ///cout<<count<<endl;
   /** for(i=1;i<=node;i++)
        cout<<distance[i]<<"\t"<<i<<endl;
    cout<<endl;**/

}
