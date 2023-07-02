#include <unordered_map>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    void buildGraph(unordered_map<string, vector<pair<string, double>>>& graph, const vector<vector<string>>& equations, const vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            const double val = values[i];

            graph[a].push_back({ b, val });
            graph[b].push_back({ a, 1.0 / val });
        }
    }

    double evaluateQuery(const string& start, const string& end, unordered_map<string, vector<pair<string, double>>>& graph, map<string, bool>& visited) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;

        if (start == end)
            return 1.0;

        visited[start] = true;

        for (const auto& neighbor : graph[start]) {
            if (!visited[neighbor.first]) {
                double subResult = evaluateQuery(neighbor.first, end, graph, visited);
                if (subResult != -1.0)
                    return subResult * neighbor.second;
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        buildGraph(graph, equations, values);

        vector<double> results;
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];

            map<string, bool> visited;
            double result = evaluateQuery(start, end, graph, visited);
            results.push_back(result);
        }

        return results;
    }
};

