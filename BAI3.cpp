#include<bits/stdc++.h>
using namespace std;
vector <long long> a(200000+5);
vector <long long> prefixmax(200000+5);
vector <long long> prefixsum(200000+5);

long long BinarySearch(long long gt,long long cuoicung)
{
    //ta đã có gt là số bậc cao nhất mà con robot có thể đi được
    //chặt nhị phân này sẽ trả lại chỉ số mảng prefixmax mà con robot hay nói đúng hơn là mức cao nhất robot có thể đạt được
    long long start=1,en=cuoicung,mid;
    long long best=0;//để lỡ ko tìm thì là ko đi được bậc nào
    //code chặt nhị phân này đã luôn cho ra vị trị xa nhất rồi
    while (start<=en)
    {
        mid=start+(en-start)/2;
        if (prefixmax[mid]<=gt)
        {
            best=mid;
            start=mid+1;
        }
        else
        {
            en=mid-1;
        }

    }
    return best;
}

void Solve(long long n,long long q)
{
    //ta đã có n và q rồi
    long long i,j;
    prefixmax[0]=0;
    prefixsum[0]=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        prefixmax[i]=max(prefixmax[i-1],a[i]);
        prefixsum[i]=prefixsum[i-1]+a[i];
    }
    long long robot;
    for (i=1;i<=q;i++)
    {
        cin>>robot;
        long long vitri=BinarySearch(robot,n);
        cout<<prefixsum[vitri]<<" ";
    }
    cout<<"\n";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    long long t;
    cin>>t;
    long long gt1,gt2;
    while (t>0&&t--)
    {
        cin>>gt1>>gt2;
        Solve(gt1,gt2);
    }

    //full ac 100%



    return 0;
}
