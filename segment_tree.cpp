#include<bits/stdc++.h>

struct SegmentTree {
    int n;
    vector<int> tree;


    int getMid(int start, int end) {
        return start + (end - start)/2;
    }

    void constructUtil(int start, int end, int segNode, vector<int> &arr) {
        if(start == end) {

        }
        int mid = getMid(start, end);
        constructUtil(start, mid, segNode * 2 + 1, arr);
        constructUtil(mid+1, end, segNode *2 + 2, arr);
    }

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        int height = (int)(ceil(log2(n)));

        int max_size = 2*(int)pow(2, height) - 1;
        tree.resize(max_size);
    }

    void updateRangeUtil(int start, int end, int rangeStart, int rangeEnd, int segNode, int val) {
        if(start > rangeEnd || end < rangeStart) return;
        if(start <= rangeStart && rangeEnd <= end) {
            tree[segNode] += val;
            return;
        }
        int mid = getMid(rangeStart, rangeEnd);
        updateRangeUtil(start, end, rangeStart, mid, segNode * 2 + 1, val);
        updateRangeUtil(start, end, mid+1, rangeEnd, segNode * 2 + 2, val);
    }

    void updateRange(int start, int end, int val) {
        updateRangeUtil(start, end, 0, n - 1, 0, val);
    }


    void getRangeUtil(int start, int end , int rangeStart, int rangeEnd, int segNode) {
        if(start > rangeEnd || end < rangeStart) return;
        if(rangeEnd <= start && end <= rangeEnd) {

            return;
        }
        int mid = getMid(rangeStart, rangeEnd);

            getRangeUtil(start, mid, rangeStart, mid, segNode*2 + 1);
            getRangeUtil(mid+1, end, mid+1, rangeEnd, segNode*2 + 2);

    }

    void getRange(int start, int end) {
        getRangeUtil(start, end, 0, n - 1, 0);
    }

};


