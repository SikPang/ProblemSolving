class Solution {
public:
    int kthGrammar(int n, int k) {
        int cur = 0;
        int start = 0;
        int end = 1 << (n-1);

        while (end - start > 1)
        {
            if (k <= (start+end)/2)
            {
                if (cur == 0)
                    cur = 0;
                else
                    cur = 1;
                end = (start+end)/2;
            }
            else
            {
                if (cur == 0)
                    cur = 1;
                else
                    cur = 0;
                start = (start+end)/2;
            }
        }
        return cur;
    }
};