#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > mc;

void bfs(vector<int>vc[] )
{
    queue<int> Q;
    bool vis[10000];
    memset(vis,false,sizeof(vis));
    vector<int> tmp;
    for( int i = 0 ; i <= 400; i++ )
    {

        if(vc[i].size() > 0 and vis[i] == false )
        {

            Q.push(i) ;
            while(!Q.empty())
            {
                int x ;
                x = Q.front() ;
                Q.pop() ;
                vis[x] = true ;
                tmp.push_back(x) ;
                for( int j = 0 ; j < vc[x].size() ; j++ )
                {
                    if(vis[vc[x][j]] == false )
                    {
                        Q.push(vc[x][j]);
                        vis[vc[x][j]] = true ;
                    }
                }
            }
            mc.push_back(tmp) ;
            tmp.clear() ;

        }
    }
//cout<<mc.size()<<" "<<endl;
}
int main()
{
    vector<int> vc[100000] ;
    bool a[450][450] ;
    memset(a,false,sizeof(a));
    int n,m,p,i,j,u,v,pos=0;
    cin>>n>>m>>p;
    while(m--)
    {
        cin>>u>>v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    bfs(vc) ;
    cout<<mc.size()<<endl;
    for(i = 0 ; i < mc.size() ; i++ )
    {
        for( j = 0 ; j < mc[i].size(); j++ )
        {
            for( int it = j; it < mc[i].size(); it++ )
            {
                a[mc[i][j]][mc[i][it]] = true;
                a[mc[i][it]][mc[i][j]] = true;
            }
        }
    }
    for(i = 0 ; i < p ; i++ )
    {
        int k,l;
        cin>>k>>l;
        if(a[k][l] or a[l][k])
            cout<<"Lets que lets"<<endl;
        else
            cout<<"Deu ruim"<<endl;
    }

}
