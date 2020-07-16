class FreqStack {
public:
    FreqStack() {
        
    }
    map<int, int> freq;
    vector<int> stack;
    
    void push(int x) {
        if(freq.count(x)==0)
        {
            freq.insert({x, 1});
        }
        else
        {
            freq[x]+=1;
        }
        stack.push_back(x);
    }
    
    int pop() {
        // freq, value 
        pair<int, int> maxFreq = {0, -1};
        int index = 0;
        for(int i = 0; i<stack.size(); ++i)
        {
            if(freq[stack[i]]>=maxFreq.first)
            {
                maxFreq.first = freq[stack[i]];
                maxFreq.second = stack[i];
                index = i;
            }
        }
        stack.erase(stack.begin() + index);
        freq[maxFreq.second] -= 1;
        
     
        return maxFreq.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */