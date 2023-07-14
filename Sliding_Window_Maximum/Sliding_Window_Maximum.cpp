class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // init deque
        deque<int> order;
        // init answer
        vector<int> answer;
        int windowStart = 0;
        // for all elements
        for(int i = 0 ; i < n; i++){

            // remove all the smaller elements if exists from the deque
            // what if deque is empty
            while(!order.empty() && nums[i] > nums[order.back()]){
                order.pop_back();
                
            }
            // add me to last (push_back)
            order.push_back(i);

            int windowSize = i - windowStart + 1;

            // if window size == k (wE - wS +1 )    
            if(windowSize == k){
                // front is maximum get it!
                int maxi = nums[order.front()];
                // send it to answer
                answer.push_back(maxi);
            }else{
                continue;
            }
            // now !
            // shift the window  wS++
            windowStart++;
            // remove all the indexes that are smaller than wS
            while(!order.empty() &&  windowStart > order.front()){
                order.pop_front();
            }

            // finally proceed to next using wE++;
        }
        // return answer
        return answer;
    }
};
