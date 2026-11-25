
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        s.push_back(0);

        int N = n + 1;

        vector<int> p(N), c(N);
        int maxVal = *max_element(s.begin(), s.end());

        vector<int> cnt(max(N, maxVal + 1), 0);

        for (int x : s) {
            cnt[x]++;
        }

        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = N - 1; i >= 0; i--) {
            p[--cnt[s[i]]] = i;
        }
        int classes = 1;

        c[p[0]] = 0;

        for (int i = 1; i < N; i++) {
            if (s[p[i]] != s[p[i - 1]]) {
                classes++;
            }

            c[p[i]] = classes - 1;
        }

        vector<int> pn(N), cn(N);

        for (int len = 1; len < N; len *= 2) {
            for (int i = 0; i < N; i++) {
                pn[i] = p[i] - len;

                if (pn[i] < 0) {
                    pn[i] += N;
                }
            }

        
            cnt.assign(classes, 0);

            for (int i = 0; i < N; i++) {
                cnt[c[pn[i]]]++;
            }

            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }

            for (int i = N - 1; i >= 0; i--) {
                p[--cnt[c[pn[i]]]] = pn[i];
            }
            cn[p[0]] = 0;
            int newClasses = 1;

            for (int i = 1; i < N; i++) {

                pair<int, int> curr = {
                    c[p[i]],
                    c[(p[i] + len) % N]
                };

                pair<int, int> prev = {
                    c[p[i - 1]],
                    c[(p[i - 1] + len) % N]
                };

                if (curr != prev) {
                    newClasses++;
                }

                cn[p[i]] = newClasses - 1;
            }

            c.swap(cn);
            classes = newClasses;
        }
        vector<int> sa;

        for (int x : p) {
            if (x != n) {
                sa.push_back(x);
            }
        }

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[sa[i]] = i;
        }

        vector<int> lcp(n, 0);

        int k = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == n - 1) {
                k = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + k < n &&
                   j + k < n &&
                   nums[i + k] == nums[j + k]) {
                k++;
            }

            lcp[r] = k;

            if (k > 0) {
                k--;
            }
        }
        int ans = n;

        for (int i = 0; i < n; i++) {

            int r = rank[i];

            int maxLCP = 0;

            if (r > 0) {
                maxLCP = max(maxLCP, lcp[r - 1]);
            }
            if (r < n - 1) {
                maxLCP = max(maxLCP, lcp[r]);
            }

            int requiredLength = maxLCP + 1;

            if (requiredLength <= n - i) {
                ans = min(ans, requiredLength);
            }
        }

        return ans;
    }
};
