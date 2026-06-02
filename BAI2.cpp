#include<bits/stdc++.h>
using namespace std;
/*
bài này là 1 bài thử thách tư duy cực kì ảo dù dễ
về cơ bản thì phân thành hệ nhị phân sẽ trực quan hơn nhiều damn
gọi a và b là số tiền hôm qua và số tiền nạp hôm nay
để ý, số tiền cuối ngày hôm nay là 2*(a+b)  =  x và luôn CHẴN
LƯU Ý THÊM LÀ Ở ĐÂY ĐANG TÌM NHỮNG NGÀY MÀ BỤT NHÂN ĐÔI, KHÔNG PHẢI LÀ ĐANG CỐ TÌM NGÀY THỰC SỰ(CHỈ QUAN TÂM ĐẾN NGÀY BỤT NHÂN ĐÔI)

ta có x PHẢI LUÔN CHẴN
-> khi backtrack, ta thấy x/2 là 1 số lẻ thì x= x/2-1 luôn ms đúng điều kiện



*/
long long Solve(long long n,long long k)
{
    long long dem=0;
    long long i,j;
    for (i=k;i>=1;i--)//ta đi đến cuối của ngày đầu tiên luôn
    {
        if (n==0)
            break;
        if (n%2==1)
        {
            dem+=1;
            n-=1;
        }
        else
        {
            n/=2;
            if (n%2==1)
            {
                dem+=1;
                n-=1;
            }
            //ta phải rút n về vì đang đi tìm theo NGÀY BỤT NHÂN ĐÔI tức là phải luôn chẵn
        }
    }

    return dem+n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    long long gt1,gt2,gt;
    while (t>0&&t--)
    {
        cin>>gt1>>gt2;
        gt=Solve(gt1,gt2);
        cout<<gt<<"\n";
    }



    return 0;
}
