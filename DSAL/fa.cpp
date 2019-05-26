#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long
using namespace std;

const int Maxn=7000;

inline LL sqr(LL x){return x*x;}

struct CircleNode{
	int x,y,r;
	CircleNode(){}
	inline void read(){
		scanf("%d%d%d",&x,&y,&r);
	}
};
CircleNode cl[Maxn+5];
int n;

int fa[Maxn+5];
inline void initFather(){
	for (int i=0;i<=Maxn;i++) fa[i]=i;
}

int getFather(int x){
	return fa[x]=(fa[x]==x?x:getFather(fa[x]));
}

inline bool mergeFather(int x,int y){
	int fx=getFather(x),fy=getFather(y);
	if (fx==fy) return false;
	if (fx>fy) fa[fx]=fy; else fa[fy]=fx;
	return true;
}

int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);

	//Init
	initFather();
	//Input
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cl[i].read();
	//Solve
	int ans=n;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (sqr(cl[i].x-cl[j].x)+sqr(cl[i].y-cl[j].y) <= sqr(cl[i].r+cl[j].r)){
				if (mergeFather(i,j)) ans--;
			}
	//Output
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
