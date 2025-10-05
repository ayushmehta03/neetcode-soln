from typing import List

def ThreeSum(nums: List[int]) -> List[List[int]]:
    """
    Finds all unique triplets in the given list that sum up to zero.

    The function sorts the list, then uses a for loop and two pointers to
    identify all unique triplets [nums[i], nums[j], nums[k]] such that 
    nums[i] + nums[j] + nums[k] == 0.

    Args:
        nums (List[int]): A list of integers.

    Returns:
        List[List[int]]: A list of unique triplets, each of which sums to zero.
    """
    nums.sort()                   # Sort the list to simplify duplicate handling and pointer logic
    ans = []                      # List to store the result triplets
    n = len(nums)                 # Length of the list

    for i in range(n):
        # Skip duplicate elements to avoid duplicate triplets
        if i > 0 and nums[i] == nums[i-1]:
            continue

        j = i + 1                 # Left pointer, starting just after 'i'
        k = n - 1                 # Right pointer, starting at the end of the list

        while j < k:
            total = nums[i] + nums[j] + nums[k]   # Calculate current sum

            if total < 0:
                # If the sum is less than zero, move the left pointer to the right
                j += 1
            elif total > 0:
                # If the sum is greater than zero, move the right pointer to the left
                k -= 1
            else:
                # A triplet found, add to the answer
                ans.append([nums[i], nums[j], nums[k]])

                # Skip duplicates for the left pointer
                while j < k and nums[j] == nums[j+1]:
                    j += 1
                # Skip duplicates for the right pointer
                while j < k and nums[k] == nums[k-1]:
                    k -= 1

                # Move both pointers to keep searching
                j += 1
                k -= 1
    return ans

def main():
    """
    Reads a list of integers from user input and prints all unique triplets that sum to zero.

    Prompts the user for space-separated integers, computes triplets using ThreeSum,
    and prints the resulting list of triplets.
    """
    # Prompt user for input, split it into a list of integers
    arr = list(map(int, input("Enter the values for the list separated by space: ").split()))
    # Find and print all unique triplets that sum to zero
    print(ThreeSum(arr))

if __name__ == "__main__":
    main()
