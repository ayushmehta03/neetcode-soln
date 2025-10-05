# Two Sum 2 Input Array is sorted

from typing import List

def twoSum(numbers: List[int], target: int) -> List[int]:
    """
    Finds two numbers in a sorted list that add up to the target value.
    
    Uses a two-pointer technique to find the indices (1-indexed) of two numbers 
    adding up to 'target' in a sorted list 'numbers'.
    
    Args:
        numbers (List[int]): A sorted list of integers.
        target (int): The target sum to find.
    
    Returns:
        List[int]: A list containing the indices (1-indexed) of the two numbers.
    """
    i = 0                   # Left pointer
    j = len(numbers) - 1    # Right pointer

    # Loop until the pointers meet
    while i < j:
        current_sum = numbers[i] + numbers[j]  # Sum of elements at pointers

        # If the sum matches the target, return 1-based indices
        if current_sum == target:
            return [i + 1, j + 1]
        # If the sum is too large, move the right pointer left
        elif current_sum > target:
            j -= 1
        # If the sum is too small, move the left pointer right
        else:
            i += 1
    # If no solution is found (though the problem generally assumes always found)
    return []

def main():
    """
    Reads a sorted list of integers and a target from user input and 
    prints the 1-based indices of two numbers that sum to the target.
    """
    # Read space-separated integers from the user
    nums = list(map(int, input("Enter the values for the list space-separated: ").split()))
    target = int(input("Enter the target value to be found: "))

    # Call twoSum and print the result
    print(twoSum(nums, target))

if __name__ == "__main__":
    main()
