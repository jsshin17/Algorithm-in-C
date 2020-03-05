#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fi;
ofstream fo;

typedef pair<int, int> pi;
typedef vector<int> vi;

const int MAX = 100;
vi e[MAX]; //The vector which contains adjancent vertexs
int d[MAX];
int visited[MAX], inside_tree[MAX];
vector<pi> ans; //Vector that contains the pair of vertexs, between which the dead-end sign locates at
vi tree_rep;
vi x;


void dfs(int v, int p = -1) {
    inside_tree[v] = 2;
    for (int i = 0; i < e[v].size(); i++) {
        if (e[v][i] != p)
            dfs(e[v][i], v);
    }
}

int main() {
    fi.open("testInput.txt");
    fo.open("testOutput.txt");
    int n, m;
    fi >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        fi >> v >> w;
        --v; --w;
        e[v].push_back(w); //e[v] stores the value w which is connected to v
        e[w].push_back(v); //As it is undirected node, the value v has to be stored on e[w], too.
        ++d[v]; ++d[w]; //the number of the vertexs connected to v or w
    }
    
    for (int i = 0; i < n; i++) {
        if (d[i] == 1)
            x.push_back(i); //q contains vertexs that are connected to others only once.
    }
    
    for (int cur = 0; cur < x.size(); cur++) {
        int v = x[cur];
        visited[v] = 1;
        bool if_any = false;
        for (int i = 0; i < e[v].size(); i++) {
            if (visited[e[v][i]]) continue;
            if_any = true;
            --d[e[v][i]];
            if (d[e[v][i]] == 1) x.push_back(e[v][i]);
        }
        if (!if_any) tree_rep.push_back(v);
    }
    for (int i = 0; i < tree_rep.size(); i++)
        dfs(tree_rep[i]);
    
    
    
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < e[v].size(); i++) {
            if (((!visited[v]) && (visited[e[v][i]])) || ((inside_tree[v]) && (e[v].size() == 1)))
                ans.push_back(std::make_pair(v, e[v][i]));
        }
    }
    
    sort(ans.begin(), ans.end()); //sort the output by v, instead of previous order by w
    
    fo << ans.size() << '\n';
    
    for (int i = 0; i < ans.size(); i++)
        fo << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    fi.close();
    fo.close();
}
