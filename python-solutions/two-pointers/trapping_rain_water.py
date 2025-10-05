from typing import List

def trap(height: List[int]) -> int:
    """
    Computes how much water can be trapped after raining given the elevation map.
    
    Uses two pointers to traverse from both ends and keep track of the maximum height
    to the left and right of each position, accumulating water as possible.

    Args:
        height (List[int]): List of non-negative integers representing bar heights.
    
    Returns:
        int: Total units of water that can be trapped.
    """
    n = len(height)
    if n == 0:
        return 0  # No bars → no water

    left, right = 0, n - 1           # Two pointers at both ends 
    left_max, right_max = 0, 0        # Track the highest walls from both sides
    water = 0                         # Accumulate trapped water

    # Process the height array from both ends toward the center
    while left < right:
        if height[left] < height[right]:
            # If the left bar is lower
            if height[left] >= left_max:
                left_max = height[left]  # Update max on the left
            else:
                water += left_max - height[left]  # Water can be trapped above this bar
            left += 1
        else:
            # If the right bar is lower or equal
            if height[right] >= right_max:
                right_max = height[right]  # Update max on the right
            else:
                water += right_max - height[right]  # Water can be trapped above this bar
            right -= 1
    return water

def main():
    """
    Reads a list of bar heights from user input and prints the total trapped rain water.
    
    Prompts the user for space-separated heights, computes trapped water with trap(), 
    and prints the total.
    """
    # Read and parse input from the user
    height = list(map(int, input("Enter the heights of the bars (space-separated): ").split()))
    # Compute and print the trapped water
    print(trap(height))

if __name__ == "__main__":
    main()
