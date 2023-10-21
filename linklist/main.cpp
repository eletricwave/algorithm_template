#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init(void){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++; 
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

int main(void){


    return 0;
}