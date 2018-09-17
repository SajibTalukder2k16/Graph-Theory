#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cout<<"Enter node: ";
    cin>>node;
    cout<<"Enter edge: ";
    cin>>edge;
    vector<int>edges[node+1];
    vector<int>costs[node+1];
    int i,j,k,node1,node2;
    int indegree[node+1]={0};
    for(i=0;i<edge;i++)
    {
        cin>>node1>>node2;
        edges[node1].push_back(node2);
        indegree[node2]++;
        costs[node1].push_back(1);
        /*if(node1!=node2){edges[node2].push_back(node1);
        costs[node2].push_back(1);}*/
    }

    for(i=1;i<=node;i++)
    {
       /// if(edges[i].size()!=0)
        //{
            cout<<"node: "<<i<<"\t";
            cout<<"indegree: "<<indegree[i]<<"\t"<<"outdegree: "<<edges[i].size()<<endl;
            /**for(j=0;j<edges[i].size();j++)
            {
                cout<<edges[i][j]<<"\t";
            }
            cout<<endl;**/
        //}
    }
}
