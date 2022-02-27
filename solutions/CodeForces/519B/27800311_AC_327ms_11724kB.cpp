
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000000]; int b[1000000]; int c[1000000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n-2;i++)
    {
        cin>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n-1);
    sort(c,c+n-2);

    int an;
   // bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            an=a[i];
            break;
           // flag=false;
        }
    }
//    if(flag)
//    {
//        an=a[n-1];
//    }
    int bn;
   // bool flagb = true;
    for(int i=0;i<n-1;i++)
    {
        if(b[i]!=c[i])
        {
            bn=b[i];
            break;
            //flagb=false;
        }
    }
//    if(flagb)
//    {
//        bn=b[n-2];
//    }

    cout<<an<<endl<<bn;

    return 0;
}
