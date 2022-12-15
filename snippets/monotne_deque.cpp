struct monotone_deque{
    deque<int>dp;
    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if(!dq.empty() && dq.front()==x){
            dq.pop_front();
        }
    }
    int getmin(){
        if(!dq.empty()){
            return dq.front();
        }else{
            return 0;
        }
    }
};