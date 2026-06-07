#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> prefixsum(1000000+5,0);

long long n;

struct thongtin
{
    bool found;
    long long pos;
};//lần lượt là vị trí
thongtin binary1(long long start,long long en,long long gt)//chặt nhị phân lấy phần tử gần nhất <= giá trị
{
    thongtin k1;
    k1.found=false;
    k1.pos=0;
    while (start<=en)
    {
        long long mids=start+(en-start)/2;
        if (a[mids]<=gt)
        {
            k1.found=true;
            k1.pos=max(k1.pos,mids);//cái này luôn đưa phần tử gần nhất nên không phải lo
            start=mids+1;//thử tăng lên xem phần tử tiếp theo có thỏa mãn <=mid không
        }
        else
        {
            en=mids-1;//hạ đi để tìm cái nhỏ hơn
        }
    }
    //LƯU Ý: việc này vd có 5 5 5 mà gt là 5 thì sẽ lấy index 3, là phần tử xa nhất thỏa mãn nên vô cùng an tâm
    return k1;
}
bool isValid(long long sumdoan,long long gt1,long long gt2)//kiểm tra xem có đủ khả năng bù trừ vào hay không
{
    long long kc=abs(gt1-gt2);
    long long tongdoanconlai=prefixsum[n]-sumdoan;
    if (kc<=tongdoanconlai)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    bài này có dấu hiệu của sự bù trừ nên dùng trung bình cộng sẽ cho ra kết quả tốt nhất
    cùng với đó là kết hợp với sliding windows và chặt nhị phân
    */
    long long m;
    cin>>n>>m;
    long long i,j;
    //thủ tục nhập xuất
    a.reserve(n+5);
    a.push_back(0);
    for (i=1;i<=n;i++)
    {
        cin>>j;
        a.push_back(j);
    }

    sort(a.begin()+1,a.end());//việc dãy sắp xếp cho ra khoảng cách nhỏ nhất

    //lay prefixsum
    for (i=1;i<=n;i++)
    {
        prefixsum[i]=prefixsum[i-1]+a[i];
    }

    long long best=2e18;//đây là kết quả tốt nhất

    for (i=1;i<=n-m+1;i++)
    {
        long long vtmoi=i+m-1;//so luong phan tu va o vi tri moi
        long long tongdoan=prefixsum[vtmoi]-prefixsum[i-1];
        long long mid=tongdoan/m;//lay trung binh

        long long kc1,kc2;
        long long sl1,sl2;//số lượng phần tử <=mid hay > mid
        thongtin inform;
        //xet truong hop 1
        mid=tongdoan/m;
        inform=binary1(i,vtmoi,mid);
        if (inform.found==false)//nếu không tìm thấy phần tử nào <=mid
        {
            //điều này có nghĩa là toàn bộ phần tử luôn >mid
            //-> công thức bù trừ vào là: tongdoan-mid*m
            if (isValid(tongdoan,best,0)==true)
            {
                best=min(best,tongdoan-mid*m);
            }
        }
        else
        {
            //nếu CÓ tồn tại giá trị <=mid
            sl1=inform.pos-i+1;
            sl2=m-sl1;
            kc1=mid*sl1-(prefixsum[inform.pos]-prefixsum[i-1]);//cho đoạn <=mid
            kc2=(prefixsum[vtmoi]-prefixsum[inform.pos])-mid*sl2;//cho đoạn có giá trị >=mid

            //ta lưu ý là 2 thằng này có sự bù trừ nên tối ưu là max 1 trong 2 thằng
            
            if (isValid(tongdoan,kc1,kc2)==true)
            {
                best=min(best,max(kc1,kc2));
            }
        }

        //xet truong hop 1
        mid=tongdoan/m+1;
        inform=binary1(i,vtmoi,mid);
        if (inform.found==false)//nếu không tìm thấy phần tử nào <=mid
        {
            //điều này có nghĩa là toàn bộ phần tử luôn >mid
            //-> công thức bù trừ vào là: tongdoan-mid*m
            if (isValid(tongdoan,best,0)==true)
            {
                best=min(best,tongdoan-mid*m);
            }
        }
        else
        {
            //nếu CÓ tồn tại giá trị <=mid
            sl1=inform.pos-i+1;
            sl2=m-sl1;
            kc1=mid*sl1-(prefixsum[inform.pos]-prefixsum[i-1]);//cho đoạn <=mid
            kc2=(prefixsum[vtmoi]-prefixsum[inform.pos])-mid*sl2;//cho đoạn có giá trị >=mid

            //ta lưu ý là 2 thằng này có sự bù trừ nên tối ưu là max 1 trong 2 thằng
            
            if (isValid(tongdoan,kc1,kc2)==true)
            {
                best=min(best,max(kc1,kc2));
            }
        }
        
    }
    cout<<best;






    return 0;
}
