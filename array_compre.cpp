#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>mymap;
    int n,i;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int ara[n];
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    int assign=0,c=0;
    int compressed[n];
    int x;
    for(i=0;i<n;i++)
    {
        x=ara[i];
        if(mymap.find(x)==mymap.end())
        {
            cout<<x<<" is compressed by "<<assign<<endl;
            mymap[x]=assign;
            assign++;
        }
        int p=mymap[x];
        compressed[i]=p;
    }
    for(i=0;i<n;i++)
        cout<<compressed[i]<<"\t"<<endl;
}
