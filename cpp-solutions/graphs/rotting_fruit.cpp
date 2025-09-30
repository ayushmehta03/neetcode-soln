class Solution {
public:

   // These vectors represent the change needed to go to 4 directions: UP, DOWN, LEFT, RIGHT

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};


    void logState(tuple<int, int, int> &state) {

		int currX = get<0>(state);
		int currY = get<1>(state);
		int currTime = get<2>(state);
		cout<<"Current cell: ("<<currX<<", "<<currY<<"), Current time: "<<currTime<<"\n";

    }


    int orangesRotting(vector<vector<int>>& grid) {

	/*
		The problem tells us a few things:
			0 -> cell is empty
			1 -> cell has a fresh fruit
			2 -> cell has a rotten fruit

			It says that, every minute, every cell adjacent (vertically or horizontally) to a rotten fruit
			will become rotten.
			And we want to find the minium time such that all fruits are rotten or (-1) if its not possible.

		This problem can be framed as a graph problem. If we consider every cell to be a node in a graph, such that
		every cell vertically or horizontally adjacent to it has an edge with that node.
		Then we find that we have an undirected - unweighted graph.
		And we want to find the shortest path from the rotten fruits to the fresh fruits, changing state of
		every fresh fruit to rotten as we visit it.
		The "maximum" shortest path we find will be the minimum time required for all fruits to be rotten.

		Since we have an undirected unweighted graph, the breadth first search algorithm will guarantee
		the shortest path.

		Node: There can be multiple rotten fruits initially, so our bfs will be a "multisource bfs".

	*/

        int minTime = 0;

        int n = grid.size(); int m = grid[0].size();

	// Use visited[][] matrix to avoid revisiting cells.
	// Initially all are unvisited.
        vector<vector<bool>> visited(n, vector<bool>(m, false));


	/* State representation: At every point in our bfs, we need to carry this much information with us:
		(current_row, current_col, minimum minutes taken to reach this cell)

		Tuples are a great way to store the state.
	*/
        queue<tuple<int, int, int>> rottingQueue; // (currX, currY, steps)

	// Find our sources (initially rotten fruits) and visit them.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = true;
                    rottingQueue.emplace(i, j, 0);
                }
            }
        }

	// We have all of our sources ready, we can begin our BFS traversal.

        while(!rottingQueue.empty()) {
            auto currState = rottingQueue.front(); rottingQueue.pop();

            // You can also log the states to understand better how the bfs is working. (Uncomment the line below)
	    	// logState(currState);
	    // Get our current position
            int curr_row = get<0>(currState); int curr_col = get<1>(currState);

            int curr_minutes = get<2>(currState);

	    // Update our answer as discussed above.

            minTime = max(minTime, curr_minutes);

	    // Discover all 4 directions

            for(int k = 0; k < 4; k++) {
                int new_row = curr_row + dx[k]; int new_col = curr_col + dy[k];

		// skip if the new cell is not in bounds.
                if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) {
                    continue;
                }
		// skip if the new cell has been visited previously or is not a fresh fruit
                if(visited[new_row][new_col] || grid[new_row][new_col] != 1) {
                    continue;
                }
		// visit the new cell
                visited[new_row][new_col] = true;
		// mark as "rotten"
                grid[new_row][new_col] = 2;

		// finally, add to our bfs and add the 1 minute that has been elapsed.
                rottingQueue.emplace(new_row, new_col, curr_minutes + 1);
            }
        }


	// At the end we check if there are still anew_col fresh fruits left. if there are then its impossible and we return -1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minTime;
    }
};
