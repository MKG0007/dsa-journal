Dutch National Flag Algorithem :-
  it is the well none method use to sort the array contain three types of nunbers.
  step1-
  define the pointers :- low , mid , high
  from 0 to low-1 --> n1;
  from low to mid-1 --> n2;
  from mid to high --> contains un-sorted part of the array
  from high+1 to n-1 --> n3;

  code:-
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        //intially low = mid because from start whole array unsorted
        int low = 0;
        int mid = 0;
        int high = size - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {//swaping with low (assuming that the low pointing to '1'
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

time_complexity-->O(n)
