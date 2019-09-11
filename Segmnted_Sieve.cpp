#include<bits/stdc++.h>
using namespace std;
void myfileopen()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

#define sz 100001
int MX =1000001;


bool numbers[1000001];
bool arr[sz+1];
vector<int>prime;
vector<long long>new_prime;

void sieve(){
	int sqrtn=sqrt(MX);
	prime.push_back(2);
	for(int i=4;i<=MX;i+=2)
		numbers[i]=true;
	for(int i=3;i<=sqrtn;i+=2){
		if(numbers[i]==0){
			for(int j=i*i;j<=MX;j+=2*i){
				numbers[j]=true;
			}
		}
	}
	
	for(int i=3;i<=MX;i+=2){
		if(numbers[i]==0)
			prime.push_back(i);
	}
}




void Segmented_Sieve(long long a,long long b){
	if(a<=1) a=2;
	long long sqrtn=sqrt(b);
	for(long long  i=0;i<=prime.size() && prime[i]<=sqrtn;i++){
		long long p=prime[i];
		long long j=p*p;
		if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
		for(;j<=b;j+=p){
			arr[j-a]=true;
		}
	}
	for(long long i=a;i<=b;i++){
		if(arr[i-a]==0)
			new_prime.push_back(i);
	}

}

int main()
{
	myfileopen();
	sieve();
	long long a,b;
	cin>>a>>b;
	Segmented_Sieve(a,b);
	for(int i=0;i<new_prime.size();i++){
		cout<<new_prime[i]<<endl;
	}



	return 0;
}