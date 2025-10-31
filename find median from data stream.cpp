/*The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.*/ 

/* *********************************************************approach 1 *****************************************************/ 
/* the intution is that we will use the min  heap and the max hea p and  we make sure that the max heap should be greater then the min heap size so whene ever 
we call for the median we  will check that  if the size of  both  queue are eual then get teh average of  the top elements of both queue ,other wise get the maxheap top as 
 the median.*/ 
 /* time complexity O(log(n))
    space complexity (n)
    leetcode link = https://leetcode.com/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-interview-150*/


    class MedianFinder {
public:
 priority_queue<int>leftmax_heap; // max at top.
 priority_queue<int , vector<int> , greater<int>>right_min_heap; // min at top .
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         
          if(leftmax_heap.empty() || leftmax_heap.top()>num)
          {
             leftmax_heap.push(num);
          } 
           else
           {
             right_min_heap.push(num);
           } 


            // now to maintain the heap left hap . s should be greater .
            if(abs( (int)leftmax_heap.size() - (int)right_min_heap.size())>1) 
            {
                 right_min_heap. push(leftmax_heap.top());
                 leftmax_heap.pop();
            }
             else if (leftmax_heap.size() <right_min_heap.size() ){

                 leftmax_heap.push(right_min_heap.top());
                 right_min_heap.pop();
             }
    }
    
    double findMedian(){
         if(right_min_heap.size() == leftmax_heap.size())
         { 
             ///even size .
              double mean =(double)(leftmax_heap.top()+right_min_heap.top())/2;
               return mean;
         }
          else
          {
              // odd size .
               return leftmax_heap.top();
          }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */