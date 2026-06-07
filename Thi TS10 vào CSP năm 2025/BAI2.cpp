#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    long long i,j;

    vector<long long> prefixsum(n+5,0);
    for (i=1;i<=n;i++)
    {
        cin>>j;
        prefixsum[i]=prefixsum[i-1]+j;
    }
    //kiem tra tung cai a 1, n log n
    long long giatri;
    //ta nhan thay 1 dieu la quang duong chay luon >=0 => a[i]>=0 nen ap dung binary search duoc
    long long start,en,mid;
    bool kt;
    long long best=0;
    for (i=1;i<=n;i++)
    {
        giatri=prefixsum[i];//day la a;
        //chat nhi phan de tim kiem 1 gia tri prefixsum nao do
        start=i+1;en=n;//cái này là để chắc ăn hiệu rpefixsum sẽ không bao giờ bị âm
        kt=false;
        long long hieu;
        while (start<=en)//chat nhi phan de lay quang duong ma b se chay
        {
            mid=start+(en-start)/2;
            hieu=prefixsum[mid]-prefixsum[i];//hieu chinh la quang duong b chay
            if (hieu>=prefixsum[i])
            {
                if (prefixsum[n]-prefixsum[mid]>=hieu)//quang duong c se chay
                {
                    kt=true;
                    break;
                }
                else
                {
                    en=mid-1;//thu hep pham vi cho thang c co quang duong lon hon
                }
            }
            else
            {
                start=mid+1;
            }
        }
        if (kt==true)
        {
            best=i;
        }
    }
    cout<<prefixsum[best];


    return 0;
}
