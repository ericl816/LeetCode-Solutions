class Solution {
public:

	int lead[110], rank[110];

	void init () {
		for (int i=0; i<110; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}

	int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	void Union (int x, int y) {
		int a = Find(x), b = Find(y);
		if (rank[a] > rank[b]) {
			lead[b] = a;
			rank[a] += rank[b];
		}
		else {
			lead[a] = b;
			rank[b] += rank[a];
		}
	}

	int getMinCostToConstruct (int numCities, int numRoads, int newRoads, vector<vector<int> > roadsAvailable, vector<vector<int> > newRoads) {
		set<pair<int, pair<int, int> > > edges;
		for (auto i : roadsAvailable) edges.insert(make_pair(0, make_pair(i[0], i[1])));
		for (auto i : newRoads) edges.insert(make_pair(i[2], make_pair(i[0], i[1])));
		priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
		for (auto i : edges) pq.push(i);
		init();
		int ans = 0, cities = 0;
		while (!pq.empty() && cities < numCities - 1) {
			pair<int, pair<int, int> > curr = pq.top();
			pq.pop();
			if (Merge(curr.second.first, curr.second.second)) {
				Union(curr.second.first, curr.second.second);
				ans += curr.first;
				cities++;
			}
		}
		return ans;
	}
};