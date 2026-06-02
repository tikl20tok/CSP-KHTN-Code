#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    long long m,n;
    cin>>m>>n;
    long long i,j;
    vector<vector<long long>> a(m+5,vector<long long>(n+5,0));
    vector<vector<long long>> toidatren(m+5,vector<long long>(n+5,0)),toidaduoi(m+5,vector<long long>(n+5,0)),toidatrai(m+5,vector<long long>(n+5,0)),toidangang(m+5,vector<long long>(n+5,0)),toidadoc(m+5,vector<long long>(n+5,0)),toidaphai(m+5,vector<long long>(n+5,0));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            toidatren[i][j]=a[i][j];
            toidaduoi[i][j]=a[i][j];
            toidatrai[i][j]=a[i][j];
            toidaphai[i][j]=a[i][j];
        }
    }

    //lưu ý, bài này ta không lấy chính nó ra để só sánh mà lấy thằng bên cạnh
    //-> điều này đồng nghĩa với việc là lấy bên cạnh nó, không phải là g

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            toidatren[i][j]=max(toidatren[i][j],toidatren[i-1][j]);
            toidatrai[i][j]=max(toidatrai[i][j],toidatrai[i][j-1]);
        }
    }

    for(i=m;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            toidaphai[i][j]=max(toidaphai[i][j],toidaphai[i][j+1]);
            toidaduoi[i][j]=max(toidaduoi[i][j],toidaduoi[i+1][j]);
        }
    }
    long long dem=0;
/*

{
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<toidatren[j][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<toidaduoi[j][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<toidatrai[j][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<toidaphai[j][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

*/


    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if (a[i][j]<toidatren[i][j]
                && a[i][j]<toidaduoi[i][j]
                && a[i][j]<toidatrai[i][j]
                && a[i][j]<toidaphai[i][j])//bị toàn tòa nhà xung quanh cao hơn thì đếm
            {
                dem++;
            }
        }
    }

    cout<<dem;




    return 0;
}
