longest array subsequence-->find the sequence in which each element is exactly increased by one.

  broot force-->
use nested loop check for the element the sequence is present or not if at any point we couldn't able to find the nxt number of the sequence then means the sequence is done
and we have to start next new squence.
and at the end return the size of the longest one.

  class Solution {
public:

    bool presentCheck(vector<int>&nums , int num){
        for(int i = 0 ; i < nums.size() ; i++){
            if(num == nums[i]) return true;
        }

        return false;
    }//function to check the presence of the next sequence of the nunber by using linear search 
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int ans = INT_MIN;
        for(int i = 0 ; i<size ; i++){
            int num = nums[i]+1;
            int count = 1;
            while(presentCheck(nums , num)){//run the look until the sequence break and the count size 
                count++;
                num +=1;
            }

            ans = max(ans , count);//updating the max length of the sequence

        }

        return ans;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

  better approach-->
  first we have to sort the array and then maintain the previous pointer check the that number is comes after increased by one value exactly 
if not refresh the counter and prev pointer.

  class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int size = arr.size();
        sort(arr.begin() , arr.end());//first step--> sort the array
        int crr = INT_MIN;
        int ans = 0;
        int count = 1;
        for(int i = 0 ; i<size ;i++){
            if(crr == arr[i]-1){//check the sequence
                crr = arr[i];
                count++;
            }
            else if(crr != arr[i]){// if sequence the break start with the new sequence
                crr = arr[i];
                count = 1;
            }
            
            ans = max(ans , count);
        }
        
        return ans;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

  optimize approach--> in this we going to use unordered_map--->initialized with the whole array and find the first member of every sequence and start counting from it only(because we don't have to wast the time to count form every element of the array)

  code:--->
  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> s;//set inwhih 

        for(int i = 0 ; i<size ; i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int ele : s){
            if(s.find(ele-1) == s.end()){
                int count = 1;
                int num = ele+1;
                while(s.find(num) != s.end()){
                    num++;
                    count++;
                }
                ans = max(ans , count);
            }

        }
        return ans;
    }
};
