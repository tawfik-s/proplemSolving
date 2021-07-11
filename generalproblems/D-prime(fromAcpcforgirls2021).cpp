#include<bits/stdc++.h>

//author rashida mohamed
/*
he need you to print the number of numbers in interval that is divisible by d and itself and 1 only 
input will contain d,l,r   d is the number l right hand r left hand;


input
3
2 1 5
4 13 15
3 7 10

output
1
0
1

*/

using namespace std;
int main(){
//	freopen("dprime.in","r",stdin);
	long long l,r,d,h,t;
	cin>>t;
	while(t--){
	cin>>d>>l>>r;
	h=d*d;
	bool c=0;
	if(d!=2){
	for(int i=2;i<=sqrt(d);i++){
		if(h%i==0){
			c=1;break;
		}
	}
}
	if(c){
		cout<<0<<'\n';
		continue;
	}
	if(h>=l&&h<=r){
		cout<<1<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
}
}