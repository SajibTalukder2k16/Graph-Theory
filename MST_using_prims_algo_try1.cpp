#include<bits/stdc++.h>
using namespace std;
vector<int>vec_node[100];
vector<int>vec_cost[100];
vector<int>prims;
int sum=0;
int counted[100]={0};
pair<int,int>pr;
int counting=1;
class compare
{
public:
    bool operator()(const pair<int,int> &p,const pair<int,int> &q)
    {
        return p.second>q.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,compare>prio;
void mst(int source,int node)
{
    counted[source]=1;
    prims.push_back(source);
    int len=vec_node[source].size();
    int i;
    for(i=0;i<len;i++)
    {
        int t1=vec_node[source][i];
        int t2=vec_cost[source][i];
        if(counted[t1]==0){
        pr=make_pair(t1,t2);
        prio.push(pr);}
    }
    while(!prio.empty()){
        if(counting==node)
            return;
    pr=prio.top();
    if(counted[pr.first]!=1)
    {
        sum+=pr.second;
        prio.pop();
        counting++;
        ///cout<<"Iamcounted"<<pr.first<<" "<<pr.second<<endl;
        ///cout<<counting<<" "<<node<<endl;
        mst(pr.first,node);
    }

    else
    {cout<<"Iamnot"<<pr.first<<" "<<pr.second<<endl;
    prio.pop();
    }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    int i,n1,n2,cost;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2>>cost;
        vec_node[n1].push_back(n2);
        vec_node[n2].push_back(n1);
        vec_cost[n1].push_back(cost);
        vec_cost[n2].push_back(cost);
    }
    int source;
    cout<<"Enter source: ";
    cin>>source;
    mst(source,node);
    for(i=0;i<prims.size();i++)
    {
        cout<<prims[i]<<"\t";
    }
    cout<<endl;
    cout<<"cost: "<<sum<<endl;
}
