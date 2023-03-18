class BrowserHistory {
public:
    int e;
    vector<string> v;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        e = 0;
    }
    
    void visit(string url) {
        int sz = v.size()-1;
        while(sz > e){
            v.pop_back();
            sz--;
        }
        e++;
        v.push_back(url);
    }
    
    string back(int steps) {
        e -= steps;
        if(e < 0){
            e = 0;
        }
        return v[e];
    }
    
    string forward(int steps) {
        e += steps;
        if(e >= v.size()){
            e = v.size()-1;
        }
        return v[e];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
