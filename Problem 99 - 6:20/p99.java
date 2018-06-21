/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4].
 * Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */

import java.io.*;
import java.util.*;

public class p99 {
    
    // return length of longest consecutive sequence
    public static int findLongestConsecutiveSequence(int arr[]) {
        HashSet<Integer> hS = new HashSet<Integer>();
        int length = 0;
        
        // hash array elements
        for (int i = 0; i < arr.length; i++) {
            hS.add(arr[i]);
        }
        
        // check each sequence from the start, then update optimal length
        for (int j = 0; j < arr.length; j++) {
            
            // check if current element is starting element of sequence
            if (!hS.contains(arr[j] - 1)) {
                
                // check for following elements
                int k = arr[j];
                while (hS.contains(k)) {
                    k++;
                }
                
                // update optimal length
                if (length < k - arr[j]) {
                    length = k - arr[j];
                }
            }
        }
        
        return length;
    }
    
    public static void main(String[] args) {
        int arr[] = {1, 9, 3, 10, 4, 20, 2};
        System.out.println("Length of longest consecutive sequence is " + findLongestConsecutiveSequence(arr));
    }
}

