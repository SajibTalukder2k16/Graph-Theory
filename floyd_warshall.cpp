#include<bits/stdc++.h>
using namespace std;
#define maxx 10000
//int matrix[maxx][maxx];
int Next[maxx][maxx];
vector<pair<int,int>>vec_check;
pair<int,int>pr;
vector<int>rem;
void find_path(int i,int j)
{
    if(i!=j)
    {
        cout<<i<<" ";
        int k=i;
        i=Next[i][j];
        vec_check.push_back(make_pair(k,i));
        find_path(i,j);
        return;
    }
    cout<<j<<endl;
}
void find_path_x(int i,int j)
{
    if(i!=j)
    {
        ///cout<<i<<" ";
        rem.push_back(i);
        ///int k=i;
        i=Next[i][j];
        ///vec_check.push_back(make_pair(k,i));
        find_path_x(i,j);
        return;
    }
    rem.push_back(j);
    ///cout<<j<<endl;
    return;
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    int matrix[node+1][node+1];
    ///int next[node+1][node+1];
    int i,j,k,n1,n2,cost;
    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
        {
             if(i==j)
                matrix[i][j]=0;
             else
                matrix[i][j]=maxx;
        }
    }
    int ara1[edge+1],ara2[edge+1],aracost[edge+1];
    for(i=1;i<=edge;i++)
    {
        cin>>n1>>n2>>cost;
        matrix[n1][n2]=cost;
        ara1[i]=n1;
        ara2[i]=n2;
        aracost[i]=cost;

        Next[n1][n2]=n2;
    }
    for(k=1;k<=node;k++)
    {
        for(i=1;i<=node;i++)
        {
            for(j=1;j<=node;j++)
            {
                if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                    {
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
                        Next[i][j]=Next[i][k];
                    }
            }
        }
    }
    int source_node,desired_node;
    cout<<"Enter source node: ";
    cin>>source_node;
    cout<<"Enter desired node: ";
    cin>>desired_node;
    if(matrix[source_node][desired_node]==maxx)
        cout<<"No way "<<endl;
    else
    {
        cout<<"Distance : "<<matrix[source_node][desired_node]<<endl;
        find_path(source_node,desired_node);
    }
    int minn=maxx;
    memset(Next,0,sizeof(Next));
    memset(matrix,0,sizeof(matrix));
    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
        {
             if(i==j)
                matrix[i][j]=0;
             else
                matrix[i][j]=maxx;
        }
    }
    for(i=1;i<=edge;i++)
    {

        n1=ara1[i];
        n2=ara2[i];
        cost=aracost[i];
        matrix[n1][n2]=cost;
        ///cout<<n1<<" "<<n2<<" "<<cost<<endl;
        Next[n1][n2]=n2;
    }
    int m,p,q;
    int xxx;
    for(m=0;m<vec_check.size();m++)
    {
        p=vec_check[m].first;
        q=vec_check[m].second;
        ///cout<<p<<" "<<q<<endl;
        ///cout<<matrix[p][q]<<endl;
        if(matrix[p][q]!=maxx)
        {
            xxx=matrix[p][q];
            matrix[p][q]=maxx;
        }
        ///cout<<matrix[p][q]<<endl;
        ///cout<<p<<" "<<q<<endl;
        for(k=1;k<=node;k++)
        {
            for(i=1;i<=node;i++)
            {
                for(j=1;j<=node;j++)
                {
                    ///if((i!=p && k!=q)||(k!=i && j!=q)||(i!=p && j!=q)){
                    if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                        {
                            matrix[i][j]=matrix[i][k]+matrix[k][j];
                            Next[i][j]=Next[i][k];
                            ///cout<<"aha: "<<p<<" "<<q<<endl;
                            ///cout<<"tumi: "<<i<<" "<<j<<endl;
                        }
                    //}
                }
            }
        }
        ///cout<<matrix[p][q]<<endl;
        ///cout<<"Count : "<<m<<endl;
        ///cout<<"Size: "<<vec_check.size()<<endl;
        if(matrix[source_node][desired_node]==maxx)
            cout<<"No way "<<endl;
        else
        {
            ///cout<<"Distance : "<<matrix[source_node][desired_node]<<endl;
            if(minn>matrix[source_node][desired_node])
            {minn=matrix[source_node][desired_node];
                rem.clear();
                find_path_x(source_node,desired_node);}
        }
        matrix[p][q]=xxx;
    memset(Next,0,sizeof(Next));
    memset(matrix,0,sizeof(matrix));
    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
        {
             if(i==j)
                matrix[i][j]=0;
             else
                matrix[i][j]=maxx;
        }
    }
    for(i=1;i<=edge;i++)
    {

        n1=ara1[i];
        n2=ara2[i];
        cost=aracost[i];
        matrix[n1][n2]=cost;
        ///cout<<n1<<" "<<n2<<" "<<cost<<endl;
        Next[n1][n2]=n2;
    }
        ///vec_check.clear();
    }
    /**if(matrix[source_node][desired_node]==maxx)
        cout<<"No way "<<endl;
    else
    {
        cout<<"Distance : "<<matrix[source_node][desired_node]<<endl;
        find_path(source_node,desired_node);
    }**/
    cout<<minn<<endl;
    for(i=0;i<rem.size();i++)
        cout<<rem[i]<<" ";
    cout<<endl;


}

