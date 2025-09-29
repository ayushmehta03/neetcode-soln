
# NeetCode 150 Solutions 🚀

Welcome to the **NeetCode 150 Solutions Repository**!  
This repo is a community effort to collect **clean, structured, and multi-language solutions** for the [NeetCode 150](https://neetcode.io/practice) problems.  

Whether you’re solving in **Python, Java, C, Go, Kotlin, or any other language**, your contributions are welcome! 🙌  

---

## 📂 Repository Structure

The repo follows a **language → topic → solution** format:

├── Python/ │   ├── Arrays/ │   │   └── two_sum.py │   ├── DP/ │   │   └── longest_increasing_subsequence.py │ ├── Java/ │   ├── Arrays/ │   │   └── TwoSum.java │   ├── DP/ │   │   └── LIS.java │ ├── C/ │   ├── Arrays/ │   │   └── two_sum.c │   ├── DP/ │   │   └── lis.c

- **Language folder** → Name after the programming language (`Python`, `Java`, `C`, `Go`, `Kotlin`, etc.)  
- **Topic folder** → Organize solutions into categories like:  
  - `Arrays`  
  - `DP` (Dynamic Programming)  
  - `Graphs`  
  - `Trees`  
  - `Strings`  
  - `Backtracking`  
  - `Greedy`  
- **Solution file** → Use clear descriptive names like `two_sum.py`, `TwoSum.java`, `lis.c`  

---

## 📝 Contribution Guidelines

1. **Write Clean & Optimal Code**  
   - Keep it simple, efficient, and readable.  
   - Avoid unnecessary complexity.  

2. **Add Comments**  
   - Briefly explain your approach at the top.  
   - Use inline comments where needed.  

3. **Follow Naming Conventions**  
   - Python, C, Go → `snake_case` → `two_sum.py`  
   - Java, Kotlin → `CamelCase` → `TwoSum.java`  

4. **Avoid Duplicates**  
   - Check if the problem is already solved in that language.  
   - If you add a different approach, explain it clearly in comments.  

5. **Stick to the Folder Structure**  
   - Always follow `Language/Topic/solution_file` format.  
   - Don’t put files in the root directory.  

---

## ⚡ How to Contribute

1. **Fork** this repo  
2. **Create a new branch** for your contribution  
   ```bash
   git checkout -b add-two-sum-python

3. Add your solution in the correct folder


4. Commit changes with a meaningful message

git commit -m "Add Python solution for Two Sum"


5. Push to your fork and open a Pull Request 🎉




---

🌟 Example

If you’re adding a Python solution for Two Sum (Arrays problem), create:

Python/Arrays/two_sum.py

Inside two_sum.py:

# Problem: Two Sum
# Approach: Hash Map
# Time Complexity: O(n)
# Space Complexity: O(n)

def twoSum(nums, target):
    num_map = {}
    for i, num in enumerate(nums):
        if target - num in num_map:
            return [num_map[target - num], i]
        num_map[num] = i


---

🙌 Final Notes

Let’s keep this repo organized and beginner-friendly.

Every contribution, big or small, is appreciated ❤️

Star ⭐ this repo to support the project!



---

