#include<bits/stdc++.h>
using namespace std;
void myfileopen()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
#define MAX 1000000


bool numbers[MAX+1];
vector<int>prime;
vector<int>factors;

///Finding all prime numbers using sieve .
void sieve(){
	int sqrtn=sqrt(MAX);
	prime.push_back(2);
	for(int i=4;i<=MAX;i+=2)
		numbers[i]=true;
	for(int i=3;i<=sqrtn;i+=2){
		if(numbers[i]==0){
			for(int j=i*i;j<=MAX;j+=2*i){
				numbers[j]=true;
			}
		}
	}
	
	for(int i=3;i<=MAX;i+=2){
		if(numbers[i]==0)
			prime.push_back(i);
	}
}

void factorization(int n){
	int sqrtn=sqrt(n);
	for(int i=0;i<prime.size() && prime[i]<=sqrtn;i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				n/=prime[i];
				factors.push_back(prime[i]);
			}
			sqrtn=sqrt(n);
		}
	}
	if(n!=1)
		factors.push_back(n);
}


int main()
{
	myfileopen();
	sieve();
	int n;
	cin>>n;
	factorization(n);

	for(int i=0;i<factors.size();i++){
		cout<<factors[i]<<endl;
	}
	


	
	return 0;
}