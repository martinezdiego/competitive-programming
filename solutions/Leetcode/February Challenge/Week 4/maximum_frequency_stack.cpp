class FreqStack {
private:
    unordered_map<int, int> freq;
    vector<vector<int> > v;
public:
    FreqStack() {
        v.push_back(vector<int>());
    }
    
    void push(int x) {
        freq[x]++;
        if (freq[x] == v.size()) v.push_back(vector<int>());
        v[freq[x]].push_back(x);
        
    }
    
    int pop() {
        int mx = v.back().back();
        v.back().pop_back();
        if (v.back().empty()) v.pop_back();
        freq[mx]--;
        return mx;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */ 
