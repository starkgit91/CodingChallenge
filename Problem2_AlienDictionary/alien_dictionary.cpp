// C++ implementation for Alien Dictionary
#include <bits/stdc++.h>
using namespace std;
string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;

    for (auto& word : words)
        for (char c : word)
            indegree[c] = 0;

    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i], w2 = words[i + 1];
        for (int j = 0; j < min(w1.size(), w2.size()); j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]].count(w2[j])) {
                    graph[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
        
    }

    queue<char> q;
    for (auto it : indegree){
        char c = it.first;
        int deg = it.second;
        if (deg == 0){q.push(c);}
    }

    string res;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        res += c;
        for (char nei : graph[c])
            if (--indegree[nei] == 0)
                q.push(nei);
    }

    return res.size() == indegree.size() ? res : "";
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Alien Dictionary Order: " << alienOrder(words) << endl;
    return 0;
}


