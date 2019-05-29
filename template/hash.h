/*==================================================*\
  | 字符串 Hash
  | 注意：mod选择足够大的质数（至少大于字符串个数）
\*==================================================*/
unsigned int hasha(char *url, int mod){
unsigned int n = 0;
  char *b = (char *) &n;
  for (int i = 0; url[i]; ++i) b[i % 4] ^= url[i];
  return n % mod;
}
unsigned int hashb(char *url, int mod){
unsigned int h = 0, g;
  while (*url) {
  h = (h << 4) + *url++;
  g = h & 0xF0000000;
  if (g) h ^= g >> 24;
  h &= ~g;
  }
  return h % mod;
}
int hashc(char *p, int prime = 25013){
  unsigned int h=0, g;
  for ( ; *p; ++p) {
  h = (h<<4) + *p;
  if(g = h & 0xf0000000) {
  h = h ^ (g >> 24);
  h = h ^ g;
  }
  }
  return h % prime;
}

class GeneralHashFunctionLibrary
{/*RSHash*/
    public long RSHash(String str)
    {
        int b = 378551;
        int a = 63689;
        long hash = 0;
        for(int i = 0; i < str.length(); i++)
        {
            hash = hash * a + str.charAt(i);
            a = a * b;
         }
         return hash;
     }
    /*JSHash*/
    public long JSHash(String str)
    {
        long hash = 1315423911;
        for(int i = 0; i < str.length(); i++)
            hash ^= ((hash << 5) + str.charAt(i) + (hash >> 2));
        return hash;
    }
    /*PJWHash*/
    public long PJWHash(String str)
    {
        long BitsInUnsignedInt = (long)(4 * 8);
        long ThreeQuarters = (long)((BitsInUnsignedInt * 3) / 4);
        long OneEighth = (long)(BitsInUnsignedInt / 8);
        long HighBits = (long)(0xFFFFFFFF)<<(BitsInUnsignedInt-OneEighth);
        long hash = 0;
        long test = 0;
        for(int i = 0; i < str.length(); i++)
        {
            hash = (hash << OneEighth) + str.charAt(i);
            if((test = hash & HighBits) != 0)
                hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
        return hash;
    }
    /*ELFHash*/
    public long ELFHash(String str)
    {
        long hash = 0;
        long x = 0;
        for(int i = 0; i < str.length(); i++)
        {
            hash = (hash << 4) + str.charAt(i);
            if(( x = hash & 0xF0000000L) != 0)
            hash ^= ( x >> 24);
            hash &= ~x;
        }
        return hash;
    }
    /*BKDRHash*/
    public long BKDRHash(String str)
    {
        long seed = 131;//31131131313131131313etc..
        long hash = 0;
        for(int i = 0; i < str.length(); i++)
        hash = (hash * seed) + str.charAt(i);
        return hash;
    }
    /*SDBMHash*/
    public long SDBMHash(String str)
    {
        long hash = 0;
        for(int i = 0; i < str.length(); i++)
        hash = str.charAt(i) + (hash << 6) + (hash << 16) - hash;
        return hash;
    }
    /*DJBHash*/
    public long DJBHash(String str)
    {
        long hash = 5381;
        for(int i = 0; i < str.length(); i++)
        hash = ((hash << 5) + hash) + str.charAt(i);
        return hash;
    }
    /*DEKHash*/
    public long DEKHash(String str)
    {
        long hash = str.length();
        for(int i = 0; i < str.length(); i++)
            hash = ((hash << 5) ^ (hash >> 27)) ^ str.charAt(i);
        return hash;
    }
    /*BPHash*/
    public long BPHash(String str)
    {
        long hash=0;
        for(int i = 0;i < str.length(); i++)
        hash = hash << 7 ^ str.charAt(i);
        return hash;
    }
    /*FNVHash*/
    public long FNVHash(String str)
    {
        long fnv_prime = 0x811C9DC5;
        long hash = 0;
        for(int i = 0; i < str.length(); i++)
    {
        hash *= fnv_prime;
        hash ^= str.charAt(i);
    }
        return hash;
    }
    /*APHash*/
    long APHash(String str)
    {
        long hash = 0xAAAAAAAA;
        for(int i = 0; i < str.length(); i++)
        {
            if((i & 1) == 0)
                hash ^=((hash << 7) ^ str.charAt(i) ^ (hash >> 3));
            else
                hash ^= (~((hash << 11) ^ str.charAt(i) ^ (hash >> 5)));
        }
        return hash;
    }
}

int hash(int x){ return x % P; }

void makenull() { for(int i=0;i<P;i++) h[i]=EMP; }

int loc(int x) {
	int ori=hash(x);
	int i=0;
	while( i < P && h[(ori+i)%P] != x && h[(ori+i)%P] != EMP)  i++;

	return (ori+i)%P;
}
void insert(int x) {
	int pos=loc(x);
	h[pos]=x;
}

int find(int x){
	int pos=loc(x);
	return h[pos]==x;
}
