#include<iostream>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;
struct PhanSo 
{
    int tu,mau;
    char k;
    void operator = (int x)
    {
        tu = x;
        mau = 1;
    }
};
istream& operator >> (istream& in, PhanSo &a);
ostream& operator << (ostream& out, PhanSo a);
PhanSo RutGon (PhanSo &a);
bool operator < (PhanSo a, PhanSo b);
bool operator > (PhanSo a, PhanSo b);
bool operator == (PhanSo a, PhanSo b);
PhanSo operator + (PhanSo a, PhanSo b);
template <class T>
struct Mang 
{
    int sl;
    T ptu[100];
    T& operator [] (int i)
    {
        return ptu[i];
    }
    void operator = (Mang<T> a)
    {
        sl = a.sl;
        for (int i= 0; i<a.sl; i++)
        {
            ptu[i] = a[i];
        }
    }
};
template <class T>
istream& operator >> (istream& in,Mang<T> &a);
template <class T>
ostream& operator << (ostream& out, Mang<T> a);
template<class T>
T Tongptu (Mang<T> a);
template<class T>
T TimMax (Mang<T> a);
template <class T>
void SapXep (Mang<T> &a,char x);
template <class T>
Mang<T> operator + (Mang<T> a, Mang<T> b);

int main()
{
    char x;
    cin>>x;
    if(x=='I')
    {
        Mang<int> a,b,tong;
        cin>>a>>b;
        tong = a + b;
        cout<<a<<endl;
        cout<<"MAX 1 = "<<TimMax<int>(a)<<endl;
        cout<<"SUM 1 = "<<Tongptu<int>(a)<<endl;
        SapXep(a,'<');
        
        for (int i= 0; i<a.sl; i++)
        {
            if(a[i]%2 == 0)
                cout<<a[i]<<" ";
        }
        for (int i=0; i<a.sl; i++)
        {
            if(a[i]%2 != 0)
                cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<b<<endl;
        cout<<"MAX 2 = "<<TimMax<int>(b)<<endl;
        cout<<"SUM 2 = "<<Tongptu<int>(b)<<endl;
        SapXep(b,'>');
        for (int i=0; i<b.sl; i++)
        {
            if(b[i]%2 != 0)
                cout<<b[i]<<" ";
        }
        for (int i=0; i<b.sl; i++)
        {
            if(b[i]%2 == 0)
                cout<<b[i]<<" ";
        }
        cout<<endl;
        cout<<tong;
        
        
    }
    if(x=='F')
    {
        Mang<PhanSo> a,b,tong;
        cin>>a>>b;
        tong = a + b;
        cout<<a<<endl;
        cout<<"MAX 1 = "<<TimMax<PhanSo>(a)<<endl;
        cout<<"SUM 1 = "<<Tongptu<PhanSo>(a)<<endl;
        SapXep(a,'<');
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<"MAX 2 = "<<TimMax<PhanSo>(b)<<endl;
        cout<<"SUM 2 = "<<Tongptu<PhanSo>(b)<<endl;
        SapXep(b,'>');
        cout<<b<<endl;
        cout<<tong;
        
        
    }

    
    return 0;

}
istream& operator >> (istream& in, PhanSo &a)
{
   cin>>a.tu>>a.k>>a.mau;		
	return in;
}
ostream& operator << (ostream& out, PhanSo a)
{
    a = RutGon(a);
    if(a.mau == 1) out<<a.tu;
    else if(a.tu == 0) out<<0;
    else out<<a.tu<<"/"<<a.mau;
    return out;
}
PhanSo RutGon (PhanSo &a)
{
    int uc =__gcd(a.tu,a.mau);
    a.tu /= uc;
    a.mau /= uc;
    return a;
}
bool operator < (PhanSo a, PhanSo b)
{
    return (a.tu*b.mau < a.mau*b.tu);
}
bool operator > (PhanSo a, PhanSo b)
{
    return (a.tu*b.mau > a.mau*b.tu);
}
bool operator == (PhanSo a, PhanSo b)
{
     return (a.tu*b.mau == a.mau*b.tu);
}
PhanSo operator + (PhanSo a, PhanSo b)
{
    PhanSo kq; 
    kq.tu = a.tu*b.mau + a.mau*b.tu;
    kq.mau = a.mau*b.mau;
    return RutGon(kq);
}
template <class T>
istream& operator >> (istream& in,Mang<T> &a)
{
    in>>a.sl;
    for (int i=0;i<a.sl;i++)
    {
        in>>a[i];
    }
    return in;
}
template <class T>
ostream& operator << (ostream& out, Mang<T> a)
{
    for (int i=0;i<a.sl;i++)
    {
        out<<a[i]<<" ";
    }
    return out;
}
template<class T>
T Tongptu (Mang<T> a)
{
    T tong ;
    tong = 0;
    for (int i = 0; i<a.sl; i++)
    {
        tong = tong + a[i];
    }
    return tong;
}
template<class T>
T TimMax (Mang<T> a)
{
    T max = a[0];
    for (int i =0 ; i<a.sl; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
template <class T>
void SapXep (Mang<T> &a, char x)
{
    cin>>x;
    if(x =='<')
    {
        for (int i =0; i<a.sl ;i++)
        {
            for(int j =i+1; j<a.sl; j++)
            {
                if(a[i] > a[j])
                {
                    T temp  = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    if(x == '>')
    {
        for (int i =0; i<a.sl ;i++)
        {
            for(int j =i+1; j<a.sl; j++)
            {
                if(a[i] < a[j])
                {
                    T temp  = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }   
            }
        }
    }
}
template <class T>
Mang<T> operator + (Mang<T> a, Mang<T> b)
{
    Mang<T> kq;
    if(a.sl >= b.sl)
    {
        kq.sl = a.sl;
        for (int i = 0 ; i < b.sl; i++ )
        {
            kq[i] = a[i] + b[i];
        }
        for (int i = b.sl ; i < a.sl; i++)
        {
            kq[i] = a[i];
        }
    }
    else 
    {
        kq.sl = b.sl;
        for (int i = 0 ; i < a.sl; i++ )
        {
            kq[i] = a[i] + b[i];
        }
        for (int i = a.sl ; i < b.sl; i++)
        {
            kq[i] = b[i];
        }
    }
    return kq;
}
