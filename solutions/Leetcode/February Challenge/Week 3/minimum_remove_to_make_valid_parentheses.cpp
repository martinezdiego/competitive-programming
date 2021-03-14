class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int N = s.size();
        stack<int> openstack;
        stack<int> closestack;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(')
                openstack.push(i);
            else if (s[i] == ')')
                closestack.push(i);
        }
        while (!openstack.empty() and !closestack.empty())
        {
            int openidx = openstack.top();
            int closeidx = closestack.top();
            if (openidx > closeidx) {
                s[openidx] = '*';
                openstack.pop();
            } 
            else {
                closestack.pop();
                openstack.pop();
            }
        }
        while (!openstack.empty()) {
            s[openstack.top()] = '*';
            openstack.pop();
        }
        while (!closestack.empty()) {
            s[closestack.top()] = '*';
            closestack.pop();
        }
        for (int i = 0; i < N; i++) {
            if (s[i] != '*') ans.push_back(s[i]);
        }
        return ans;
    }
}; 
