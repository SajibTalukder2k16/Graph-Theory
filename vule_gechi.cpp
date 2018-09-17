#include<bits/stdc++.h>
using namespace std;
vector<int>vec_node[100];
vector<int>vec_cost[100];
vector<int>prims;
int counted[100][100]={0};
pair<int,int>pr;
pair<pair<int,int>,int>qr;
int counting=0;
class compare
{
public:
    bool operator()(const pair<pair<int,int>,int> &p,const pair<pair<int,int>,int> &q)
    {
        return p.second>q.second;
    }
};
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare>prio;
void mst(int first,int second,int node)
{
    counted[first][second]=1;
    prims.push_back(second);
    int len=vec_node[second].size();
    int i;
    for(i=0;i<len;i++)
    {
        int t1=vec_node[second][i];
        int t2=vec_cost[second][i];
        if(counted[first][second]==0){
        pr=make_pair(source,t1);
        prio.push(pr,t2);}
    }
    ///if(counting==node)
        ///return ;
    pr=prio.top();
    ///cout<<pr.first<<" "<<pr.second<<endl;
    if(counted[pr.first.first][pr.first.second]==1)
    {
        cout<<"Iamnot"<<pr.first.first<<" "<<pr.first.second<<endl;
        prio.pop();
        pr=prio.top();
        ///cout<<pr.first<<"first"<<endl;
        mst(pr.first.first,pr.first.second,node);
    }
    else if(counted[pr.first]!=1)
    {
        prio.pop();
        ///counting++;
        ///counted[pr.first]=1;
        cout<<"Iamcounted"<<pr.first.first<<" "<<pr.first.second<<endl;
        mst(pr.first.first,pr.first.second,node);
    }
    /**else
    {
        prio.pop();

        pr=prio.top();
        mst(pr.first,node);

    }**/



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
}
