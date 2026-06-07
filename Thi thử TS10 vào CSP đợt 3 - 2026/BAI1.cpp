#include<bits/stdc++.h>
using namespace std;

struct thongtin
{
    long long bt;
    long long tg;
};
bool cmp(thongtin x,thongtin y)
{
    if (x.bt!=y.bt)
    {
        return x.bt<y.bt;//thằng làm được nhiều bài tập hơn nằm bên phải
        /*
        nếu như mà bài tập của thằng x làm đc ít hơn thằng y
        thì giữ nguyên vị tri (đang sắp xếp tăng dần)
        nêu ko thì -> false là phải đổi chỗ 2 thằng cho nhau (y<x)
        */
    }
    //trường hợp bằng nhau:
    return x.tg>y.tg;
    /*
    tương tự,
    nếu như thời gian thằng x lớn hơn thằng y thì đổi chỗ (true)
    nếu false là chuẩn thứ tự rồi, cùng làm đc số bài nhưng thời gian nhiều hơn thì ở thứ hạng thấp hơn
    */

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,k;
    cin>>n>>k;
    long long i,j;
    vector<thongtin> a;
    a.reserve(n+5);
    a.push_back({0,0});
    for (i=1;i<=n;i++)
    {
        a.push_back({0,0});
        cin>>a[i].bt>>a[i].tg;
    }
    sort(a.begin()+1,a.end(),cmp);
    k=n-k+1;//tráo index vì đang sắp xếp tăng lên
    thongtin tieuchi=a[k];
    long long dem=0;
    for (i=1;i<=n;i++)
    {
        if (a[i].bt==tieuchi.bt&&a[i].tg==tieuchi.tg)
        {
            dem+=1;
        }
    }
    cout<<dem;

    //full ac 100%


    return 0;
}
