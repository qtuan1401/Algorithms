struct SegmentTree {
    int val, lazy;
    SegmentTree *left, *right;
    SegmentTree() {
        left = right = NULL;
        val = 0;
        lazy = -1; // default value
    }
    
    void extend() {
        if (left != NULL)
            return ;
        left = new SegmentTree();
        right = new SegmentTree();
    }
    
    void update(int l, int r, int u, int v, int nVal) {
        if (lazy != -1) {
            val = (r - l + 1) * lazy;
            if (l != r) {
                extend();
                left -> lazy = lazy;
                right -> lazy = lazy;
            }
            lazy = -1;
        }
        if (v < l || r < u)
            return ;
        if (u <= l && r <= v) {
            val = nVal * (r - l + 1);
            if (l != r) {
                extend();
                left -> lazy = nVal;
                right -> lazy = nVal;
            }
            return ;
        }
        int mid = (l + r) / 2;
        extend();
        left -> update(l, mid, u, v, nVal);
        right -> update(mid + 1, r, u, v, nVal);
        val = left -> val + right -> val;
    }
    
    int get(int l, int r, int u, int v) {
        if (v < l || r < u)
            return 0;
        if (lazy != -1) {
            val = (r - l + 1) * lazy;
            if (l != r) {
                extend();
                left -> lazy = lazy;
                right -> lazy = lazy;
            }
            lazy = -1;
        }
        if (u <= l && r <= v)
            return val;
        int mid = (l + r) / 2;
        extend();
        return left -> get(l, mid, u, v) + right -> get(mid + 1, r, u, v);
    }
};

class RangeModule {
private:
    int n;
    SegmentTree* sg;
    
public:
    RangeModule() {
        n = 1e9;
        sg = new SegmentTree();
    }
    
    void addRange(int left, int right) {
        sg -> update(1, n, left, right - 1, 1);
        /* cout << "add: " << left << " " << right << endl;
        for (int i = 1; i <= 20; i++)
            cout << "[" << i << ": " << sg -> get(1, n, i, i) << "] ";
        cout << endl; */
    }
    
    bool queryRange(int left, int right) {
        return sg -> get(1, n, left, right - 1) == (right - left);
    }
    
    void removeRange(int left, int right) {
        sg -> update(1, n, left, right - 1, 0);
        /* cout << "remove: " << left << " " << right << endl;
        for (int i = 1; i <= 20; i++)
            cout << "[" << i << ": " << sg -> get(1, n, i, i) << "] ";
        cout << endl; */
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */