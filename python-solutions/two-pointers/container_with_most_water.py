from typing import List

def maxArea(height: List[int]) -> int:
    """
    Calculate the maximum amount of water a container can store from a list of heights.
    
    The function uses a two-pointer approach to find the biggest area of water 
    contained between two lines represented by elements in the given list.
    
    Args:
        height (List[int]): A list of integers representing heights of lines.
    
    Returns:
        int: The maximum area of water that can be contained.
    """
    n = len(height)             # Get the number of elements in the list
    width = n - 1               # Initial width between the farthest lines
    max_water = 0               # Variable to store the maximum water found
    i, j = 0, n - 1             # Initialize two pointers at the start and end

    # Move the pointers towards each other
    while (i < j):
        min_height = min(height[i], height[j])     # The height is limited by the shorter line
        max_water = max(max_water, min_height * width)    # Update max_water if current area is larger
        width -= 1                                 # Decrement the width as the pointers get closer

        # Move the pointer at the shorter line
        if (height[i] <= height[j]):
            i += 1
        else:
            j -= 1
    return max_water

def main():
    """
    Reads a list of heights from user input and prints the maximum water area.
    
    Prompts the user to enter space-separated integers, computes the answer 
    using maxArea, and prints the result.
    """
    # Prompt user for input and split it into a list of integers
    height = list(map(int, input("Enter the values for the list separated by space: ").split()))
    # Call maxArea with the user's input and print the result
    print(maxArea(height))
    
if __name__ == "__main__":
    main()
