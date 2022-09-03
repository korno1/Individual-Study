#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define DUMMY 0
#define INF 1e9 // use this to represent the infinity

using namespace std;

int V[101];

class MinHeap{
private:
    struct Index{
        int cost; int i;
        Index(int cost, int i){ this->cost = cost; this->i = i; }
    };

    vector<int> array;     // array:   heap_index -> node
    vector<Index> indices; // indices: node -> (cost, heap index)

    int PARENT(int i){ return i / 2; }
    int LEFT(int i){ return 2 * i; }
    int RIGHT(int i){ return 2 * i + 1; }

    // i: heap_index, array[i] is node, and its cost is key
    int key(int i){ return indices[array[i]].cost; }

    void swap(int i , int j){ // i, j: heap_index
        std::swap(array[i], array[j]);
        indices[array[i]] = Index(key(i), i);
        indices[array[j]] = Index(key(j), j);
    }
public:
    MinHeap(int n){
        array.push_back(DUMMY);
        for(int i = 0; i <= n; i++)
            indices.push_back(Index(DUMMY, DUMMY));
    }

    // return true if this queue is empty
    bool empty(){ return array.size() - 1 == 0; }

    // return true if node is in this queue
    bool has(int node){ return indices[node].i != DUMMY; }

    void insert(int cost, int node){
        array.push_back(node);
        int i = array.size() - 1; // index of node in the heap array
        indices[node] = Index(cost, i);
        //up-heap
        while(i != 1 && key(i) < key(PARENT(i))){
            this->swap(i, PARENT(i));
            i = PARENT(i);
        }
    }

    // return node having the smallest cost (or distance)
    int remove(){
        int u = array[1];
        indices[u] = Index(DUMMY, DUMMY);

        array[1] = array[array.size() - 1];
        indices[array[1]] = Index(key(1), 1);

        array.pop_back(); // size - 1

        int i = 1;
        int n = array.size() - 1;

        while(i <= n){ // down-heap
            int smallest = i;
            if(LEFT(i) <= n && key(LEFT(i)) < key(smallest))  smallest = LEFT(i);
            if(RIGHT(i) <= n && key(RIGHT(i)) < key(smallest)) smallest = RIGHT(i);

            if(smallest != i){
                this->swap(i, smallest);
                i = smallest;
            }else break;
        }

        return u;
    }

    void decrease_key(int node, int new_cost){
        int i = indices[node].i;
        if(key(i) > new_cost){
            indices[node] = Index(new_cost, i);
            // up-heap
            while(i > 1 && key(i) < key(PARENT(i))){
                this->swap(i, PARENT(i));
                i = PARENT(i);
            }
        }
    }
};

class Graph{
private:
    struct Node{
        int v; int w;
        Node(int v, int w): v(v), w(w) { }
        bool operator < (const Node& node) const { return this->v < node.v; }
    };

    vector<vector<Node>> adj_list; 
    int n;                         
public:
    Graph(int n): n(n){
        adj_list = vector<vector<Node>>(n+1, vector<Node>());
    }

    void insert_edge(int u, int v, int w){
        adj_list[u].push_back(Node(v, w));
        adj_list[v].push_back(Node(u, w));
    }

    void sort_neighbors(){
        for(auto& neighbors : adj_list)
            std::sort(neighbors.begin(), neighbors.end());
    }

    void dijkstra(int s){ 
        MinHeap Q(n+1);
        int d[n+1];

        for(int j=1; j<=n; j++){
            d[j] = INF;
            Q.insert(d[j], j);
        }

        d[s] = 0;
        Q.decrease_key(s, s);
        Q.insert(d[s], s);
        
        while(!Q.empty()){
            int u = Q.remove();
            for(Node v : adj_list[u]){
                if(Q.has(v.v) && d[u]+v.w < d[v.v]){
                    d[v.v] = d[u] + v.w;
                    Q.decrease_key(v.v, d[v.v]);
                }
            }
        }

        for(int j=1; j<=n; j++){
            if(d[j]==INF) cout<<"INF"<<endl;
            else cout<<d[j]<<endl;
        }
    }


};

int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int n; // # of nodes
    int m; // # of edges
    int s; // index of a sequence to be printed
    cin >> n >> m >> s;

    Graph graph(n);

    for(int j = 0; j < m; j++){
        int x, y, z;
        cin >> x >> y >> z;
        graph.insert_edge(x, y, z);
    }

    // to guarantee that neighbors of a node are iterated in the increasing order
    graph.sort_neighbors();

    graph.dijkstra(s);
  

    return 0;
}