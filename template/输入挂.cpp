#include<stdio.h>

inline bool scan_d(int &num) {
        char in;
        bool IsN = false;
        in = getchar();
        if (in == EOF) return false;
        while (in != '-' && (in < '0' || in > '9')) in = getchar();
        if (in == '-') {
                IsN = true;
                num = 0;
        }
        else num = in - '0';
        while (in = getchar(), in >= '0' && in <= '9') {
                num *= 10, num += in - '0';
        }
        if (IsN) num = -num;
        return true;
}

inline bool scan_lf(double &num) {
        char in;
        double Dec = 0.1;
        bool IsN = false, IsD = false;
        in = getchar();
        if (in == EOF) return false;
        while (in != '-' && in != '.' && (in < '0' || in > '9'))
                in = getchar();
        if (in == '-') {
                IsN = true;
                num = 0;
        }
        else if (in == '.') {
                IsD = true;
                num = 0;
        }
        else num = in - '0';
        if (!IsD) {
                while (in = getchar(), in >= '0' && in <= '9') {
                        num *= 10;
                        num += in - '0';
                }
        }
        if (in != '.') {
                if (IsN) num = -num;
                return true;
        } else {
                while (in = getchar(), in >= '0' && in <= '9') {
                        num += Dec * (in - '0');
                        Dec *= 0.1;
                }
        }
        if (IsN) num = -num;
        return true;
}

int main() {
        int a;
        scan_d(a);
        printf("%d", a);
}


//适用于正整数

template<class T>
inline void scan_d(T &ret) {
        char c;
        ret = 0;
        while ((c = getchar()) < '0' || c > '9');
        while (c >= '0' && c <= '9') {
                ret = ret * 10 + (c - '0'), c = getchar();
        }
}

//适用于正负整数

template<class T>
inline bool scan_d(T &ret) {
        char c;
        int sgn;
        if (c = getchar(), c == EOF) {
                return 0; //EOF
        }
        while (c != '-' && (c < '0' || c > '9')) {
                c = getchar();
        }
        sgn = (c == '-') ? -1 : 1;
        ret = (c == '-') ? 0 : (c - '0');
        while (c = getchar(), c >= '0' && c <= '9') {
                ret = ret * 10 + (c - '0');
        }
        ret *= sgn;
        return 1;
}

template<class T>
inline void print_d(T x) {
        if (x > 9) {
                print_d(x / 10);
        }
        putchar(x % 10 + '0');
}

//仅适合纯数字输入输出

int Scan() {   //  输入外挂
        int res = 0, flag = 0;
        char ch;
        if ((ch = getchar()) == '-') {
                flag = 1;
        } else if (ch >= '0' && ch <= '9') {
                res = ch - '0';
        }
        while ((ch = getchar()) >= '0' && ch <= '9') {
                res = res * 10 + (ch - '0');
        }
        return flag ? -res : res;
}

void Out(int a) {   //  输出外挂
        if (a < 0) {
                putchar('-');
                a = -a;
        }
        if (a >= 10) {
                Out(a / 10);
        }
        putchar(a % 10 + '0');
}

int main() {
        int T, n;
        scanf("%d", &T);
        while (T--) {
                n = Scan();
                Out(n);
                printf("\n");
        }
        return 0;
}

适用于正负数(int, long long, float, double)

template<class T>
bool scan_d(T &ret) {
        char c;
        int sgn;
        T bit = 0.1;
        if (c = getchar(), c == EOF) {
                return 0;
        }
        while (c! = '-' && c != '.' && (c < '0' || c > '9'))
        {
                c = getchar();
        }
        sgn = (c == '-') ? -1 : 1;
        ret = (c == '-') ? 0 : (c - '0');
        while (c = getchar(), c >= '0' && c <= '9') {
                ret = ret * 10 + (c - '0');
        }
        if (c == ' ' || c == '\n') {
                ret *= sgn;
                return 1;
        }
        while (c = getchar(), c >= '0' && c <= '9') {
                ret += (c - '0') * bit, bit /= 10;
        }
        ret *= sgn;
        return 1;
}

template<class T>
inline void print_d(int x) {
        if (x > 9) {
                print_d(x / 10);
        }
        putchar(x % 10 + '0');
}

套装

char buf[MAXIN], *ps = buf, *pe = buf + 1;

inline void rnext() {
        if (++ps == pe) {
                pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
        }
        return;
}

template<class T>
inline bool in(T &ans) {
        ans = 0;
        T f = 1;
        if (ps == pe) {
                return false;
        }
        do {
                rnext();
                if ('-' == *ps) {
                        f = -1;
                }
        } while (!isdigit(*ps) && ps != pe);
        if (ps == pe) {
                return false;
        }
        do {
                ans = (ans << 1) + (ans << 3) + *ps - 48;
                rnext();
        } while (isdigit(*ps) && ps != pe);
        ans *= f;
        return true;
}

char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;

inline void write() {
        fwrite(bufout, sizeof(char), pout - bufout, stdout);
        pout = bufout;
        return;
}

inline void out_char(char c) {
        *(pout++) = c;
        if (pout == pend) {
                write();
        }
        return;
}

inline void out_str(char *s) {
        while (*s) {
                *(pout++) = *(s++);
                if (pout == pend) {
                        write();
                }
        }
        return;
}

template<class T>
inline void out_int(T x) {
        if (!x) {
                out_char('0');
                return;
        }
        if (x < 0) {
                x = -x, out_char('-');
        }
        int len = 0;
        while (x) {
                outtmp[len++] = x % 10 + 48;
                x /= 10;
        }
        outtmp[len] = 0;
        for (int i = 0, j = len - 1; i < j; i++, j--) {
                swap(outtmp[i], outtmp[j]);
        }
        out_str(outtmp);
        return;
}


其他

        上面那个输入正负整数的有点难用
。
再附一个：

void in(int &m) {
        char ch;
        int flag = 0;
        while ((ch = getchar()) < '0' || ch > '9') {
                if (ch == '-') {
                        flag = 1;
                }
        }
        for (m = 0; ch >= '0' && ch <= '9'; ch = getchar()) {
                m = m * 10 + ch - '0';
        }
        if (flag) {
                m *= -1;
        }
}

暂时遇见这么多，先这样吧，也没有找到其他更稀奇的外挂，等遇见了再做进一步的补充吧！
更加高效的输入输出外挂

struct FastIO {
    static const int S = 100 << 1;

    int wpos;
    char wbuf[S];

    FastIO() : wpos(0) {}

    inline int xchar() {
            static char buf[S];
            static int len = 0, pos = 0;

            if (pos == len) {
                    pos = 0;
                    len = (int) fread(buf, 1, S, stdin);
            }
            if (pos == len) {
                    return -1;
            }

            return buf[pos++];
    }

    inline int xint() {
            int s = 1, c = xchar(), x = 0;
            while (c <= 32) {
                    c = xchar();
            }
            if (c == '-') {
                    s = -1;
                    c = xchar();
            }
            for (; '0' <= c && c <= '9'; c = xchar()) {
                    x = x * 10 + c - '0';
            }

            return x * s;
    }

    ~FastIO() {
            if (wpos) {
                    fwrite(wbuf, 1, wpos, stdout);
                    wpos = 0;
            }
    }
} io;


2017.8.29
添加 FastIO
strtok和sscanf结合输入

/*
 *  空格作为分隔输入,读取一行的整数
 */
        gets(buf);

int v;
char *p = strtok(but, " ");
while (p)
{
sscanf(p,
"%d", &v);
p = strtok(NULL, " ");
}
