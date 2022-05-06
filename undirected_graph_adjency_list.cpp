#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<int>graph2[n];//array of vector for adjency list

//In this we are consdering 0 based indexing we can also consider 1 based indexing according to our need
int main()
{
    //space scomp-O(Vertex+Edeges)
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
    
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

    }
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex "<<i<<"-->";
        for(int j=0;j<graph2[i].size();j++)
        {
            cout<<graph2[i][j]<<"  ";
        }
        cout<<endl;

    }
    return 0;
}

//disadvantege O(n) for finding is 2 nodes are connected or not
//But here we can store bigger graphs