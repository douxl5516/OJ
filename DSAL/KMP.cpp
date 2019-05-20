//https://www.cnblogs.com/zhangtianq/p/5839909.html

#include <bits/stdc++.h>

using namespace std;

int violentMatch(const char *text, const char *pattern) {
        int tlen = strlen(text);
        int plen = strlen(pattern);
        int i = 0;
        int j = 0;
        while (i < tlen && j < plen) {
                if (text[i] == pattern[j]) {
                        i++;
                        j++;
                } else {
                        i = i - j + 1;
                        j = 0;
                }
                if (j == plen) {
                        return i - j;
                }
        }
        return -1;
}

void getNext(const char *s, int *next) {
        int len = strlen(s);
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < len; i++) {
                while (j != -1 && s[i] != s[j + 1]) {
                        j = next[j];
                }
                if (s[i] == s[j + 1]) {
                        j++;
                }
                next[i] = j;
        }
}

int kmpMatch(const char *text, const char *pattern) {
        int tlen = strlen(text);
        int plen = strlen(pattern);
        int j = -1;
        int next[tlen];
        getNext(text, next);
        for (int i = 0; i < tlen; i++) {
                while (j != -1 && text[i] != pattern[j + 1]) {
                        j = next[j];
                }
                if (text[i] == pattern[j + 1]) {
                        j++;
                }
                if (j == plen - 1) {
                        return i - j;
                }
        }
        return -1;
}

int main() {
        string text, pattern;
        cin >> text >> pattern;
        cout << violentMatch(text.c_str(), pattern.c_str()) << endl;
        cout << kmpMatch(text.c_str(), pattern.c_str()) << endl;
        return 0;
}
