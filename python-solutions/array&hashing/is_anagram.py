def is_anagram(s: str, t: str) -> bool:
    """Check if two strings are anagrams of each other.

    An anagram is a word or phrase formed by rearranging the letters of a
    different word or phrase, typically using all the original letters
    exactly once. This function assumes strings contain only lowercase
    English letters.

    Args:
        s (str): The first string.
        t (str): The second string.

    Returns:
        bool: True if 's' is an anagram of 't', False otherwise.
    """
    if len(s) != len(t):
        return False

    # Initialize a frequency array for 26 lowercase English letters.
    # Each index corresponds to a letter (e.g., 0 for 'a', 1 for 'b').
    count = [0] * 26

    # Increment counts for characters in the first string 's'.
    for char in s:
        count[ord(char) - ord('a')] += 1

    # Decrement counts for characters in the second string 't'.
    # If a character's count becomes zero before it's fully matched,
    # or if an unmatched character is found, they are not anagrams.
    for char in t:
        if count[ord(char) - ord('a')] == 0:
            return False
        count[ord(char) - ord('a')] -= 1

    # If all characters are matched (all counts return to zero), they are anagrams.
    return True

a = input("Enter the first string: ")
b = input("Enter the second string: ")

if is_anagram(a, b):
    print("Yes, both are anagrams.")
else:
    print("No, they are not anagrams.")
