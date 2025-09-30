class Solution {
public:
    int climbStairs(int n) {
        // this problem is the same as finding the n'th fibonacci number.
	// we know that if n == 1 then there is exactly 1 way to reach the top
	// and if n == 2 then there are exactly 2 ways to reach the top, which is (1 + 1) and (2) -> (can also be seen in examples)

	// it is said that at every point, we can either take 1 step or 2 steps.
	// this gives us the recursive relation, numWays[i] = numWays[i - 1] + numWays[i - 2]
	// where numWays[i] = number of ways you can reach the i'th stair
	// its essentially saying, if i know in how many ways i can climb til i - 1 and i - 2, then i can
	// find my current solution by adding both ways.

	int numWays[n + 1];
	// Base cases
	numWays[1] = 1;
	numWays[2] = 2;

	// Calculating via recurrence relation
	for(int i = 3; i <= n; i++) {
		numWays[i] = numWays[i - 1] + numWays[i - 2];
	}

	return numWays[n];


    }
	// Time complexity: O(n)
	// Space complexity: O(n)

};
