you might be thinking that GCD , check the prime number and find the fators of the is easy (it might be easy when use broot force approach)
but when you try to optimize it that time things will become complicated

optimal aproach for----> 
  -------->finding the factors of the given number<---------

as we know when be trying to find the factors of the number we run the loops for n times
example: n = 15
  1*15------(i * n/i)
  3*5
  ----------------->as you can see after some point of value i numbers starts repeating 
  5*3
  15*1

  so according to the obervation we can see that if run loops for sqrt(n) times
and in iteration check (i and n/i) --->we will get all the factors of n 

code--->

void print_divisors(int n) {
        vector<int> ans;
        
        for(int i = 1 ; i<=sqrt(n) ; i++){
            if(n%i == 0){
                ans.push_back(i);
                if(n/i != i){
                    ans.push_back(n/i);
                }
            }
        }
        
        sort(ans.begin() , ans.end());
        for(int i : ans){
            cout<<i<<" ";
        }
        
  }
--------------------------------------------------------------------------------------------------------------------

---->check weather the number is prime or not<-----
node---> this same concept we can also apply for prime number 
prime number = number that have only two factor(1 and number itself)

--------------------------------------------------------------------------------------------------------------------

optimal approach for -----> 
  ------------------------->find the gcd(greatest common factor of two number)<----------------------------

as per the maths thoerum 
gcd(a , b) ---> gcd(a-b , b)---> do this until  one of them become zero

with some modification 
gcd(a, b) ---> gcd(a%b , b)----> at the last the non-zero number will be our answer

code--->

class Solution {
  public:
    int gcd(int a, int b) {
        
        while(a>0 && b>0){
            if(a<b) b = b%a;
            else a = a%b;
        }
        
        if(a == 0) return b;
        
        return a;   
        
    }
};
