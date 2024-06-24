class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), flipped = 0, res = 0;
        vector<int> fp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i >= K)
                flipped ^= fp[i - K];
            if (flipped == A[i]) {
                if (i + K > n)
                    return -1;
                fp[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};