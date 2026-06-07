#include<bits/stdc++.h>
using namespace std;
int snt[10+(long long)1e6];
//o day ta ap dung toi uu:
/*
0 danh dau luon la so nguyen to, lay luon
con khac 0 la so nguyen to lon nhat thoa man chia het cho no
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,q;
    cin>>n>>q;
    long long i,j;
    //dung sang lay snt
    for (i=0;i<=5+1e6;i++)
    {
        snt[i]=i;
    }
    //sang era
    snt[0]=1e8;
    snt[1]=1e8;
    snt[2]=2;
    for (i=2*2;i<=5+1e6;i+=2)
    {
        snt[i]=2;
    }
    //day la bien the cua sang era giup ta lay luon snt
    //dieu nay ve mat ban chat van la n log n nen ko n^2, cu yen tam
    for (i=3;i<=5+1e6;i+=2)
    {
        if (snt[i]==i)
            for (j=i;j<=5+1e6;j+=i)//chay tu i de dam bao ko sot boi cua 1 so
            {
                snt[j]=i;//danh dau lay uoc nguyen to lon nhat
            }
    }
    vector<int> laysan(1e6+10,0);
    for (i=2;i<=n;i++)
    {
        laysan[snt[i]]+=1;
    }
    //end
    //ta chuan bi 1 mang prefixsum de tra loi cho tat ca cau hoi
    vector<int> truyvan(n+5,0);
    for (i=2;i<=n;i++)
    {
        truyvan[i]=truyvan[i-1]+laysan[i];
    }
    long long x;
    while (q>0&&q--)
    {
        cin>>x;
        cout<<truyvan[x]<<"\n";
    }




    return 0;
}
