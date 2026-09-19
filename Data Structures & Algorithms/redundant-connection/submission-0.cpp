class Solution {
public:
    bool connectedNoCycle(vector<vector<int>>& g) {
        int start = 1;

        queue<pair<int, int>> q;
        q.push({start, -1});

        vector<bool> visited(g.size(), false);
        visited[start] = true;

        while (!q.empty()) {
            auto [cur, parent] = q.front();
            q.pop();

            for (int next : g[cur]) {
                if (next == parent)
                    continue;

                if (visited[next])
                    return false;

                visited[next] = true;
                q.push({next, cur});
            }
        }

        for (int i = 1; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].erase(
                find(graph[a].begin(), graph[a].end(), b)
            );

            graph[b].erase(
                find(graph[b].begin(), graph[b].end(), a)
            );

            if (connectedNoCycle(graph))
                return edges[i];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        return {};
    }
};