#include<bits/stdc++.h>
using namespace std;
int pr[100];
class nod
{
public:
    int node1,node2,cost;
    /**bool operator()(nod &p,nod &q)
    {
        return p.cost>q.cost;
    }**/
friend class compare;
};
class compare
{
public:
    bool operator()(nod &p,nod &q)
    {
        return p.cost<q.cost;
    }
};

vector<nod>vec;
int find(int r)
{
    if(pr[r]==r)
        return r;
    else
        find(pr[r]);
}
int krushkal_mst(int n)
{
    sort(vec.begin(),vec.end(),compare());
    int i;
    ///for(i=0;i<vec.size();i++)
       /// cout<<vec[i].node1<<" "<<vec[i].node2<<" "<<vec[i].cost<<endl;
    for(i=1;i<=n;i++)
        pr[i]=i;
    /**int count=0,s=0;
    cout<<vec.size()<<endl;
    for(i=0;i<vec.size();i++)
    {
        int n1=find(vec[i].node1);
        int n2=find(vec[i].node2);
        cout<<vec[i].node1<<" "<<vec[i].node2<<" "<<vec[i].cost<<endl;
        if(n1!=n2)
        {
            pr[n1]=n2;;
            count++;
            s+=vec[i].cost;
            cout<<s<<" "<<count<<endl;
            //if(count==n)
                //break;
        }**/
        int count = 0, s = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        int u = find(vec[i].node1);
        int v = find(vec[i].node2);
        if (u != v) {
            pr[u] = v;
            count++;
            s += vec[i].cost;
            cout<<count<<" "<<n<<endl;
            if (count == n - 1)
                break;
        }
    }
        return s;
    }

int main()
{
    int node,edge;
    cin>>node>>edge;
    int i;
    nod pp;
    for(i=0;i<edge;i++)
    {
        cin>>pp.node1>>pp.node2>>pp.cost;
        vec.push_back(pp);
    }
    cout<<krushkal_mst(node);
}
