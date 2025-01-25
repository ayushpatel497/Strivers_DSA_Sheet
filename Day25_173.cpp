int recursion(vector<int> &values, vector<int> &weights, int index, int capacity){
	if(index == 0){
		if(capacity >= weights[index]){
			return values[index];
		}
		return 0;
	}
	int include = 0;
	if(capacity >= weights[index]){
		include = values[index] + recursion(values, weights, index - 1, capacity - weights[index]);
	}
	int exclude = recursion(values, weights, index - 1, capacity);
	return max(include, exclude);
}

int memoization(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>>& dp){
	if(index == 0){
		if(capacity >= weights[0]){
			return values[0];
		}
		else{
			return 0;
		}
	}
	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}
	int include = 0;
	if(capacity >= weights[index]){
		include = values[index] + memoization(values, weights, index - 1, capacity - weights[index], dp);
	}
	int exclude = memoization(values, weights, index - 1, capacity, dp);
	return dp[index][capacity] = max(include, exclude);
}

int tabulation(vector<int> &values, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n, vector<int>(w + 1, 0));
	for(int capacity = weights[0]; capacity <= w; ++capacity){
		if(capacity >= weights[0]){
			dp[0][capacity] = values[0];
		}
		else{
			dp[0][capacity] = 0;
		}
	}

	for(int index = 1; index < n; ++index){
		for(int capacity = 0; capacity <= w; ++capacity){
			int include = 0;
			if(capacity >= weights[index]){
				include = values[index] + dp[index - 1][capacity - weights[index]];
			}
			int exclude = dp[index - 1][capacity];
			dp[index][capacity] = max(include, exclude);
		}
	}
	return dp[n - 1][w];
}

int spaceOptimized(vector<int> &values, vector<int> &weights, int n, int w){
	vector<int> prev(w + 1, 0);
	vector<int> curr(w + 1, 0);
	for(int capacity = weights[0]; capacity <= w; ++capacity){
		if(capacity >= weights[0]){
			prev[capacity] = values[0];
		}
		else{
			prev[capacity] = 0;
		}
	}

	for(int index = 1; index < n; ++index){
		for(int capacity = 0; capacity <= w; ++capacity){
			int include = 0;
			if(capacity >= weights[index]){
				include = values[index] + prev[capacity - weights[index]];
			}
			int exclude = prev[capacity];
			curr[capacity] = max(include, exclude);
		}
		prev = curr;
	}
	return prev[w];
}

int moreOptimized(vector<int> &values, vector<int> &weights, int n, int w){
	vector<int> curr(w + 1, 0);
	for(int capacity = weights[0]; capacity <= w; ++capacity){
		if(capacity >= weights[0]){
			curr[capacity] = values[0];
		}
		else{
			curr[capacity] = 0;
		}
	}

	for(int index = 1; index < n; ++index){
		for(int capacity = w; capacity >= 0; --capacity){
			int include = 0;
			if(capacity >= weights[index]){
				include = values[index] + curr[capacity - weights[index]];
			}
			int exclude = curr[capacity];
			curr[capacity] = max(include, exclude);
		}
	}
	return curr[w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Q. 0 1 Knapsack
	// Write your code here
	return recursion(values, weights, n - 1, w);
	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	return memoization(values, weights, n - 1, w, dp);
	return tabulation(values, weights, n, w);
	return spaceOptimized(values, weights, n, w);
	return moreOptimized(values, weights, n, w);
}