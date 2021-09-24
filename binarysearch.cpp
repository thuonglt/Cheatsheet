#include<bits/stdc++.h>

int bin_search(int val, vector<int> &arr) {
    int start = 0, end = arr.size();
    while(start < end) {
        int mid = (start + end) / 2 + 1;
        if(arr[mid] > val) {
            end = mid-1;
        } else {
            start = mid;
        }
    }
    return start;
}
