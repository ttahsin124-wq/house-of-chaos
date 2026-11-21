
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);
        vector<int> oldLast(n, -1);
        stack<pair<int, bool>> st;

        st.push({0, true});

        while (!st.empty()) {
            auto [u, entering] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (entering) {

                oldLast[u] = last[c];

                if (u != 0) {
                    if (last[c] != -1) {
                        newParent[u] = last[c];
                    }
                    else {
                        newParent[u] = parent[u];
                    }
                }

                last[c] = u;

                st.push({u, false});

                for (int i = adj[u].size() - 1; i >= 0; i--) {
                    st.push({adj[u][i], true});
                }
            }
            else {
                last[c] = oldLast[u];
            }
        }
        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        vector<int> order;

        stack<int> stk;
        stk.push(0);

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            order.push_back(u);

            for (int v : finalTree[u]) {
                stk.push(v);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (u != 0) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};
