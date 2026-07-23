// We address this problem with the help of a data structure that keeps checking 
// whether the incoming element is larger than the already present elements. 
// This could be implemented with the help of a de-queue.
// When shifting our window, we push the new element in from the rear of our de-queue. 
// Following is a sample representation of our dequeue:
// Every time before entering a new element, we first need to check whether 
// the element present at the front is out of bounds of our present window size.
// If so, we need to pop that out. 
// Also, we need to check from the rear that the element present is smaller than the 
// incoming element. If yes, there’s no point storing them and hence we pop them out.
// Finally, the element present at the front would be our largest element.


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices that are outside the current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove all smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Once we've formed the first full window,
            // the front of the deque is the maximum
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};