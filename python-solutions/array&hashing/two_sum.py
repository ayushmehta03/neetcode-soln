def two_sum(nums: list[int], target: int) -> list[int]:
    """Return indices of two numbers in nums that add up to target.

    The first valid pair encountered during a single left-to-right pass is
    returned. If no such pair exists, an empty list is returned.

    Parameters:
        nums (list[int]): A list of integers.
        target (int): The target sum.

    Returns:
        list[int]: A two-element list of indices [i, j] with i < j, or an
        empty list if no pair exists.

    Examples:
        >>> two_sum([2, 7, 11, 15], 9)
        [0, 1]
        >>> two_sum([3, 2, 4], 6)
        [1, 2]
        >>> two_sum([3, 3], 6)
        [0, 1]

    Time Complexity:
        O(n) time and O(n) space.
    """
    hash_map: dict[int, int] = {}

    for i, n in enumerate(nums):
        diff = target - n
        if diff in hash_map:
            return [hash_map[diff], i]
        hash_map[n] = i

    return []


def main() -> None:
    """Run a simple CLI to collect input and print the result.

    Prompts the user for a space-separated list of integers and a target
    integer, then prints the indices of a pair that sums to the target, if
    one exists.
    """
    nums_input = input("Enter numbers separated by spaces: ")
    nums = list(map(int, nums_input.split()))
    target = int(input("Enter the target: "))

    result = two_sum(nums, target)
    if result:
        print(result)
    else:
        print("No two elements with the target sum were found.")


if __name__ == "__main__":
    main()