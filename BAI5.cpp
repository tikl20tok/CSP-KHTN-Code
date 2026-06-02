#include<bits/stdc++.h>
using namespace std;

/*
bản chất cốt lõi của bài này căng:
ta gọi tổng W là tổng trọng lượng của tất cả viên gạch phía trên a và b
với phần tử a b chả hạn vậy
trương hợp 1: a ở trên b ở dưới (b gánh a)
-> sa >= W
-> sb >= W + wa -> sb-wa >= W
trường hợp 2: b ở trên a ở dưới (a gánh b)
-> sa >= W + wb -> sa-wb >= W
-> sb >= W
từ đó ta có thể suy ra được rằng:
với mỗi trường hợp cần:
TH1: min(sa, sb-wa) >= W
TH2: min(sb, sa-wb) >= W

bây giờ ta có 2 phương án chọn trong hàm sort là 2 cái trên
ta nhận thấy là với cai min kia ấy, thằng tốt hơn là thằng có cái min lớn hơn, vì nó sẽ gánh tốt những viên gạch sau nữa
giả sử TH1 được chọn, ta sẽ có:
min(sa, sb-wa) > min(sb, sa-wb)
-> min(sa + wa+wb, sb-wa + wa+wb) > min(sb + wa+wb, sa-wb + wa+wb)
-> min(sa + wa+wb, sb + wb) > min(sb + wa+wb, sa + wa)
ta nhận thấy hai vế bên trái của thằng min nó bằng nhau, nên ta sẽ so sánh hai vế bên phải của thằng min
-> sb + wb > sa + wa
tương tự với TH2, ta sẽ có:
-> sa + wa > sb + wb

còn nếu bằng nhau thì khỏi phải nói rồi, ta có thể chọn thằng nào cũng được vì nó sẽ gánh tốt những viên gạch sau nữa
sau đó áp dụng DP để giải bài toán;

Nhận xét chung: Subtask 1 là bitmask, Subtask 2 là DP Knapsack, Subtask 3 Regret Greedy(chọn cái RG này nlogn)
NÓI CHUNG BÀI NÀY BIẾN ĐỔI CÔNG THỨC ẢO PHẾT ĐẤY;

Regret Greedy: chọn thằng nào có cái min lớn hơn, vì nó sẽ gánh tốt những viên gạch sau nữa
ta đang duyệt từ đỉnh tháp xuống dưới đế
-> sort tăng dần đang cho thằng kém lên trên mảng, thằng mạnh dưới mảng để tiện duyệt xuôi



*/
struct thongtin
{
    long long w,s;
};

bool cmp(thongtin a, thongtin b)
{
    return a.s + a.w < b.s + b.w;
}//cho sắp xếp tăng dần




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    long long n;
    cin>>n;
    vector<thongtin> a(n+5,{0,0});
    long long i,j;
    for (i=1;i<=n;i++)
    {
        cin>>a[i].w>>a[i].s;
    }

    sort(a.begin()+1,a.begin()+n+1,cmp);

    /*
    giờ đến đoạn regret greedy thì siêu dễ rồi.
    với mỗi cái trong priority queue, ta sẽ có 2 lựa chọn:
    nếu như mà ok thì cứ cho vào priority queue (max heap) đã
    nếu như mà ko đc thì check để thay thế

    điều kiện: tổng của priority queue <= s của thằng hiện tại
    nếu thằng hiện tại mà gánh được thằng kia thì cứ cho vào priority queue
    nếu thằng hiện tại mà gánh ko được thằng kia thì check để thay thế
    */
    priority_queue<long long> pq;
    long long sum=0;
    for (i=1;i<=n;i++)
    {
        if (pq.empty())
        {
            pq.push(a[i].w);
            sum+=a[i].w;
        }
        else
        {
            if (a[i].s >= sum)
            {
                pq.push(a[i].w);
                sum+=a[i].w;
            }
            else
            {
                if (pq.top() > a[i].w)//nếu khối lượng thằng đầu gay go quá thì vứt cmn đi
                {
                    sum-=pq.top();
                    pq.pop();
                    pq.push(a[i].w);
                    sum+=a[i].w;
                }
            }
        }
    }
    cout<<pq.size();






    return 0;
}
