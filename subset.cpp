#include<bits/stdc++.h>

struct subset {
    int parent;
    int rank;
    subset() {parent = -1; rank = 0;}
};
int n;

int find(int s, vector<subset> &sets) {
    while(sets[s].parent != -1) {
        s = sets[s].parent;
    }
    return s;
}


void join(int a, int b, vector<subset> &sets) {
    int pa = find(a, sets), pb = find(b, sets);
    if(sets[pa].rank > sets[pb].rank) {
        sets[pb].parent = pa;
    } else if(sets[pa].rank < sets[pb].rank) {
        sets[pa].parent = pb;
    } else {
        sets[pa].rank++;
        sets[pb].parent = pa;
    }
}
