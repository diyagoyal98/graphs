//directed graph

#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int>graph[n];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<"Vertex "<<i<<"-->";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;

    }
    
}