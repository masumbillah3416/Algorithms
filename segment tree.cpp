#include<bits/stdc++.h>
using namespace std;
#define mx 20
int arr[mx];
int tree[mx*3];
void myfileopen()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
void init(int node,int b,int e)
{
	if(b==e){
		tree[node]=arr[b];
		return ;
	}
	int left =node*2;
	int right =node*2+1;
	int mid=(b+e)/2;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
	if(b>j || i>e)
		return 0;
	if(i<=b && j>=e)
		return  tree[node];
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(left,b,mid,i,j);
	int p2=query(right,mid+1,e,i,j);
	return p1+p2;

}
void update(int node,int b,int e,int i,int new_data)
{
	if(b>i || e<i)
		return ;
	if(b>=i && e<=i){
		tree[node]=new_data;
		return;
	}
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;
	update(left,b,mid,i,new_data);
	update(right,mid+1,e,i,new_data);
	tree[node]=tree[left]+tree[right];
}
int main()
{
	myfileopen();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	init(1,1,n);
	update(1,1,n,6,6);
	cout<<query(1,1,n,6,6);

	return 0;
}