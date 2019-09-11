#include<bits/stdc++.h>
using namespace std;
void myfileopen()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
#define MAX 10000000


bool numbers[MAX+1];
vector<int>prime;

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

///checking number is prime or not .
bool check_prime(int n){
	return numbers[n];
}


int main()
{
	myfileopen();
	sieve();
	int n;
	cin>>n;
	if(!check_prime(n))
		cout<<"Prime"<<endl;
	else
		cout<<"Not Prime"<<endl;
	


	
	return 0;
}