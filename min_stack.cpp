/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

/******************************approach 1 ************************* */

/* the intution is that we have to get the min  numberat each step to track
 so we will use the other stack which only store the min num till that number.
   and rest of the process of the stack is same  mean while pushing elemnt to stack
    we will see that id the curr num is smaller than the small stac kto pthen push
     that num to the small stack other wise repush the min stack top . */
/*leetcode link = https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150 */

class MinStack
{
private:
    stack<int> s;
    stack<int> mins;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        if (mins.empty() || val <= mins.top())
        {
            mins.push(val);
        }
        else
        {
            mins.push(mins.top());
        }
    }

    void pop()
    {

        s.pop();
        mins.pop();
    }
    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */