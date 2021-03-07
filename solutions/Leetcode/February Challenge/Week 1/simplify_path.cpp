class Solution {
private:
    string remove_double_slashes(const string & s) {
        string ret;
        int N = s.size();
        for (int i = 0; i < N; ) {
            ret.push_back(s[i]);
            if (s[i] == '/') {
                while (i + 1 < N and s[i + 1] == '/') i ++;
                i++;
            }
            else i++;
        }
        return ret;
    }
    
    string remove_slash_dot_slash(const string & s) {
        string ret;
        int N = s.size();
        for (int i = 0; i < N; ) {
            ret.push_back(s[i]);
            if (ret.size() >= 2) {
                int sz = ret.size();
                if (ret[sz- 1] == '/' and ret[sz - 2] == '/')
                    ret.pop_back();
            }
            if (i + 2 < N) {
                if (s[i] == '/' and s[i + 1] == '.' and s[i + 2] == '/') {
                    while (s[i] == '/' and s[i + 1] == '.' and s[i + 2] == '/') i += 2;
                }
                else {
                    i++;
                }
            }
            else {
                i++;
            }
        }
        return ret;
    }
public:
    string simplifyPath(string path) {
        path = remove_double_slashes(path);
        path = remove_slash_dot_slash(path);
        deque<string> dir;
        int N = path.size();
        for (int i = 0; i < N; ) {
            if (path[i] == '/') {
                if (i + 1 < N ) {
                    if (path[i + 1] == '.') {
                        if (i + 2 < N) {
                            if (path[i + 2] == '.') {
                                if (i + 3 < N ) {
                                    if (path[i + 3] != '/') {
                                        int start = i + 1;
                                        i++;
                                        while (i < N and path[i] != '/') i++;
                                        int end = i - 1;
                                        dir.push_back(path.substr(start, end - start + 1));
                                    }
                                    else {
                                        if (!dir.empty()) dir.pop_back();
                                        i += 3;
                                    }
                                }
                                else {
                                    if (!dir.empty()) dir.pop_back();
                                    i += 3;
                                }
                            }
                            else {
                                int start = i + 1;
                                i++;
                                while (i < N and path[i] != '/') i++;
                                int end = i - 1;
                                dir.push_back(path.substr(start, end - start + 1));
                            }
                        }
                        else
                            i += 2;
                    }
                    else {
                        int start = i + 1;
                        i++;
                        while (i < N and path[i] != '/') i++;
                        int end = i - 1;
                        dir.push_back(path.substr(start, end - start + 1));
                    }
                }
                else
                    i++;
            }
        }
        string ans = "/";
        for (int i = 0; i < dir.size(); i++) {
            if (i) ans.push_back('/');
            ans.append(dir[i]);
        }
        return ans;
        
    }
};
