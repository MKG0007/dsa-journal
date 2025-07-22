three basic methods to sort the arrary:-

  selection sort:- in this method we find the smallest element of the array in each iteration and place it on left side of the one by one 

    void selectionSort(vector<int> &arr) {
        // code here
        int size = arr.size();
        for(int i = 0 ; i<size-1 ; i++){
            int small_index = i;//crr index of the iteration
          //cosiddering that the crr element is smallest one in the array
            for(int j = i+1 ; j<size ; j++){
                if(arr[small_index] > arr[j]){//updating the small_index 
                    small_index = j;
                }
            }
            swap(arr[small_index] , arr[i]);//after inner loop completes 
          // we have the smallest element of the array of this iteration
          
        }
    }
-------------------------------------------------------------------------------------------------------------------------------------------------------------------->

bubble sort:- in this method we place the largest element on the right side of the array in every iteration.

      void bubbleSort(vector<int>& arr) {
        int size = arr.size();
        
        for(int i = 0 ; i<size-1 ; i++){
            bool check = true;// check if array is alredy sorted
            for(int j = 1 ; j<size-i ; j++){
                if(arr[j]<arr[j-1]){//placing larger element at the last
                    
                swap(arr[j] , arr[j-1]);
                check = false;
                }
            }
            if(check){
                break;
            }
        }
    }
---------------------------------------------------------------------------------------------------------------------------------------------------------------------->

insertion sort:- in this method we take the element and place it into it correct place (by checking the left side of the array every iteration)

    void insertionSort(vector<int>& arr) {
        
        int size = arr.size();
        
        for(int i = 0 ; i<size ; i++){
            
            int j = i;//taken the current iteration element 
            
            while(j>0 && arr[j-1] > arr[j]){// if previous elements are not greater than current element 
            //then shift the element on the right side and place the current element  into its right position
                swap(arr[j-1] , arr[j]);
                j--;
            }
            
        }
    }
