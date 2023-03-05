class Solution {
public:
    int minJumps(vector<int>& arr) {
        int sz=arr.size(), jumps = 0;
        if(sz == 1){
            return 0;
        }
        unordered_map<int, vector<int>> u;
        for(int i=0; i<sz; i++){
            u[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        while(q.size()){
            jumps++;
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                if(curr-1 >= 0 && u.find(arr[curr-1]) != u.end()){
                    q.push(curr-1);
                }
                if(curr+1 < sz && u.find(arr[curr+1]) != u.end()){
                    if(curr+1 == sz-1){
                        return jumps;
                    }
                    q.push(curr+1);
                }
                if(u.find(arr[curr]) != u.end()){
                    for(auto x : u[arr[curr]]){
                        if(x != curr){
                            if(x == sz-1){
                                return jumps; 
                            }
                            q.push(x);
                        }
                    }
                }
                u.erase(arr[curr]);
            }
        }
        return jumps;
    }
};
