class Solution {
public:
    vector<int> topo_sort(vector<vector<int>>& g, vector<int>degree)
    {
        queue<int>q;
        vector<int>ans;
        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for (auto nbr : g[u])
            {
                degree[nbr]--;
                if (degree[nbr] == 0)
                    q.push(nbr);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool is_cyclic(vector<vector<int>>& g, int s, vector<int>& visited, vector<int>& stck)
    {
        visited[s] = 1;
        stck[s] = 1;

        for (auto nbr : g[s])
        {
            if (visited[nbr] == 0)
            {
                if (is_cyclic(g, nbr, visited, stck) == true)
                    return true;
            }
            else if (stck[nbr] == 1)
                return true;
        }

        stck[s] = 0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        vector<vector<int>>g(n);
        vector<int>visited(n);
        vector<int>stck(n);
        vector<int>degree(n);
        vector<int>ans;
        for (int i = 0; i < pre.size(); i++)
            g[pre[i][0]].push_back(pre[i][1]);

        for (int i = 0; i < n; i++)
        {
            for (auto nbr : g[i])
                degree[nbr]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (is_cyclic(g, i, visited, stck) == true)
                    return ans;
            }
        }

        return topo_sort(g, degree);



    }
};