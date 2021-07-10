#include<bits/stdc++.h>
// link : https://codeforces.com/group/gA8A93jony/contest/269931/problem/Ds
using namespace std;

typedef long long ll;

vector<int> arr;

void merge(int l,int m,int r)      //  6
{
    // m=l+(r-l)/2;            //    m is middle    if l=0 &&r=6  m=2  0,1,2,3,4,5
    int i,j,k;
    int n1=m-l+1;            // first subarray is arr[l..m]
    int n2=r-m;             // second sub array number of elements arr[m+1..r]
    int *L=new int [n1];     // the left sub array
    int *R=new int [n2];       // the right subarray
    // ليه استخدمنا الطريقة الي فوق في تعريف Array
    for(i=0; i<n1;i++)
        L[i]=arr[l+i];
    for(j=0; j<n2;j++)
        R[j]=arr[m+1+j];

    i=j=0;  //make them equal zero

    k=l;
    // start sorting
    while(i<n1 && j<n2)  // n1 is the size of first array  n2 the size of second array
    {
        if(L[i]<=R[j])      // في حالة عكس الشرط تتغير طريقة الترتيب
        {
            arr[k]=L[i++];

        }
        else
        {
            arr[k] =R[j++];

        }
        k++;
    }
    while (i<n1)
    {
        arr[k++]=L[i++];

    }
    while (j<n2)
    {
        arr[k++]=R[j++];
    }
}



void sort(int  begin,int  end)
{
    if(begin>=end)
        return ;

    int mid=begin+(end-begin)/2;
    sort(begin,mid);
    sort(mid+1,end);
    merge(begin,mid,end);

}


int main ()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int k;
    cin>>k;
    arr.resize(k);
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
    sort(0,k-1);
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;
}