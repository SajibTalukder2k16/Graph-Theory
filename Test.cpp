#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    int i;
    while(!test.empty())
    {
        cout<<test.front()<<endl;
        test.pop();

    }
}
