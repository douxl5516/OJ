/*
    |16/11/06ztx|
*/

struct Trie{
    int cnt;
    Trie *next[maxn];
    Trie(){
        cnt = 0;
        memset(next,0,sizeof(next));
    }
};

Trie *root;

void Insert(char *word)  {
    Trie *tem = root;
    while(*word != '\0')  {
        int x = *word - 'a';
        if(tem->next[x] == NULL)
            tem->next[x] = new Trie;
        tem = tem->next[x];
        tem->cnt++;
        word++;
    }
}

int Search(char *word)  {
    Trie *tem = root;
    for(int i=0;word[i]!='\0';i++)  {
        int x = word[i]-'a';
        if(tem->next[x] == NULL)
            return 0;
        tem = tem->next[x];
    }
    return tem->cnt;
}

void Delete(char *word,int t) {
    Trie *tem = root;
    for(int i=0;word[i]!='\0';i++)  {
        int x = word[i]-'a';
        tem = tem->next[x];
        (tem->cnt)-=t;
    }
    for(int i=0;i<maxn;i++)
        tem->next[i] = NULL;
}

int main() {
    int n;
    char str1[50];
    char str2[50];
    while(scanf("%d",&n)!=EOF)  {
        root = new Trie;
        while(n--)  {
            scanf("%s %s",str1,str2);
            if(str1[0]=='i') {
                Insert(str2);
            }else if(str1[0] == 's')  {
                if(Search(str2))
                    printf("Yes\n");
                else
                    printf("No\n");
            }else  {
                int t = Search(str2);
                if(t)
                    Delete(str2,t);
            } } }
    return 0;
}
