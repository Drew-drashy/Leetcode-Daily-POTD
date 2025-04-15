class BIT {
    vector<int> tree;
    int size;
public:
    BIT(int n) {
        size = n + 2;
        tree.resize(size, 0);
    }
    
    void update(int index, int delta) {
        for (++index; index < size; index += index & -index)
            tree[index] += delta;
    }
    
    int query(int index) {
        int sum = 0;
        for (++index; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }
    
    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }

        vector<int> indexMapped(n);
        for (int i = 0; i < n; i++) {
            indexMapped[i] = pos2[nums1[i]];
        }

        vector<int> left(n, 0), right(n, 0);
        BIT bitL(n), bitR(n);

        // count of left smaller elements
        for (int i = 0; i < n; i++) {
            left[i] = bitL.query(indexMapped[i] - 1);
            bitL.update(indexMapped[i], 1);
        }

        // count of right larger elements
        for (int i = n - 1; i >= 0; i--) {
            right[i] = bitR.query(n - 1) - bitR.query(indexMapped[i]);
            bitR.update(indexMapped[i], 1);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)left[i] * right[i];
        }

        return res;
    }
};
