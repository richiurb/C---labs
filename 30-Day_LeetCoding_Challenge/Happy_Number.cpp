#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memory_n;

    bool isHappy(int n) {
        int saveSearch = binSearch(n);
        if (saveSearch == -1) {
            return false;
        }
        addElement(n, saveSearch);
        int b = 0;
        while (n > 0) {
            b += (n % 10) * (n % 10);
            n = n / 10;
        }
        if (b == 1) {
            return true;
        } else {
            return isHappy(b);
        }
    }

    int binSearch(int key) {
        int l = -1;
        int r = memory_n.size();
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (memory_n[m] < key) {
                l = m;
            } else {
                r = m;
                if (memory_n[m] == key) {
                    return -1;
                }
            }
        }
        return r;
    }

    void addElement(int n, int beginSort) {
        memory_n.push_back(n);
        for (int i = beginSort; i < memory_n.size(); ++i) {
            swap(memory_n[i], memory_n[memory_n.size() - 1]);
        }
    }
};