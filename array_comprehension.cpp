#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>vec[1000];
    int ara[100];
    int i,n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
        vec[ara[i]].push_back(i);
    }
    cout<<"Enter the number you wanted to check the location: ";
    cin>>n;
    int p=vec[n].size();
    i=0;
    while(i<p)
    {
        cout<<vec[n][i]<<"\t";
        i++;
    }

}
