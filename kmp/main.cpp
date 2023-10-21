#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

// s 为匹配串
// p 为模式串
int kmp(string s, string p){
    auto size1 = s.size(), size2 = p.size();
    int nex[size2];
    nex[0] = 0;
    for (int i = 1, j = 0; i < size2; i++){
        while (j && p[i] != p[j])
            j = nex[j - 1];
        if (p[i] == p[j])
            j++;
        nex[i] = j;
    }

    for (int i = 0, j = 0; i < size1; i++){
        while (j && s[i] != p[j]) j = nex[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == size2)
            return i - j + 1;
    }

    return -1;
}

int main(void){
    string s, p;
    cin >> s >> p;

    printf("%d\n", kmp(s, p));


    return 0;
}



