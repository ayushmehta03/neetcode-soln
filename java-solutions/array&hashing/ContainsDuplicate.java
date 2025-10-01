import java.util.Set;
import java.util.HashSet;

/* Approach: sets & set theory */
/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

public class ContainsDuplicate {
    public static boolean check(int nums[]) {
        // if array is empty or not given at all, return false
        if (nums.length == 0 || nums == null) {
            return false;
        }

        // create an empty set
        Set<Integer> set = new HashSet<>();
        
        // iterate over all elements and insert them into a set
        for (Integer num : nums) {
            set.add(num);
        }

        // check if the set size is less than an actual array size
        return set.size() < nums.length;
    }

    public static void main(String[] args) {
       // test data 1
       int[] nums1 = {1, 2, 3, 4, 5};
       System.out.println(check(nums1));
       
       // test data 2
       int[] nums2 = {2, 2, 3, 4, 5, 6, 1};
       System.out.println(check(nums2));

       // test data 3
       int[] nums3 = {10, 20, 30, 40, 50, 50, 50, 100};
       System.out.println(check(nums3));
    }
}