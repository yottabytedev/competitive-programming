// Data structure to store graph edges
struct Edge {
	int src, dest;
};

// Class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// stores indegree of a vertex
	vector<int> indegree;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// initialize indegree
		vector<int> temp(N, 0);
		indegree = temp;

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			// add an edge from source to destination
			adjList[edge.src].push_back(edge.dest);

			// increment in-degree of destination vertex by 1
			indegree[edge.dest]++;
		}
	}
};

// performs Topological Sort on a given DAG
bool doTopologicalSort(Graph const &graph, vector<int> &L, int N)
{
	vector<int> indegree = graph.indegree;

	// Set of all nodes with no incoming edges
	vector<int> S;
	for (int i = 0; i < N; i++) {
		if (!indegree[i]) {
			S.push_back(i);
		}
	}

	while (!S.empty())
	{
		// remove a node n from S
		int n = S.back();
		S.pop_back();

		// add n to tail of L
		L.push_back(n);

		for (int m : graph.adjList[n])
		{
			// remove edge from n to m from the graph
			indegree[m] -= 1;

			// if m has no other incoming edges then
			// insert m into S
			if (!indegree[m]) {
				S.push_back(m);
			}
		}
	}

	// if graph has edges then graph has at least one cycle
	for (int i = 0; i < N; i++) {
		if (indegree[i]) {
			return false;
		}
	}

	return true;
}

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
//         int vertices = 0;
//         vector<bool> visited(n,false);
        
//         for(int i=0;i<p.size();i++) {
//             if (!visited[p[i][0]]) {
//                 visited[p[i][0]] = true;
//                 vertices++;
//             }
//         }
        
//         vector<int> output;
//         Graph g(vertices);
        
        vector<Edge> edges;
        
        for (int i = 0; i< p.size(); i++) {
            struct Edge temp;
            temp.src = p[i][1];
            temp.dest = p[i][0];
            edges.push_back(temp);
        }
        // Number of nodes in the graph
        int N = n;

        // create a graph from edges
        Graph graph(edges, N);

        // Empty list that will contain the sorted elements
        vector<int> L;
        vector<int> empty;
        // Perform Topological Sort
        if (doTopologicalSort(graph, L, N))
            {
                return L;
            } else {
                return empty;
            }
        }
};