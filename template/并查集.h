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
