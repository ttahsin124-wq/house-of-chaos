
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long currentTime = 0;

        for (int i = 0; i < m; i++) {
            currentTime = max(currentTime, (long long)i);
            while (!busy.empty() && busy.top().first <= currentTime) {

                int serverIndex = busy.top().second;
                busy.pop();

                available.push({servers[serverIndex], serverIndex});
            }
            if (available.empty()) {

                currentTime = busy.top().first;

                while (!busy.empty() && busy.top().first <= currentTime) {

                    int serverIndex = busy.top().second;
                    busy.pop();

                    available.push({servers[serverIndex], serverIndex});
                }
            }

            int serverIndex = available.top().second;

            available.pop();
            ans[i] = serverIndex;
            long long finishTime = currentTime + tasks[i];

            busy.push({finishTime, serverIndex});
        }

        return ans;
    }
};
