

#include<bits/stdc++.h>
int n,k;
int ts[500007],fa[500007],ws[500007];
int main(){
	scanf("%d%d",&n,&k);
	int r=n-k;
	for(int i=0;i<k;++i)ts[i]=0,ws[i]=1;
	int a=0;
	for(int i=2;i<=r;++i,a=(a+1)%k){
		++ts[a];
		fa[i]=ws[a];
		ws[a]=i;
	}
	for(int i=r+1;i<=n;++i,a=(a+1)%k)fa[i]=ws[a];
	int mx=0,se=0;
	for(int i=0;i<k;++i){
		if(ts[i]>=mx)se=mx,mx=ts[i];
		else if(ts[i]>se)se=ts[i];
	}
	printf("%d\n",mx+se+2);
	for(int i=2;i<=n;++i)printf("%d %d\n",i,fa[i]);
	return 0;
}