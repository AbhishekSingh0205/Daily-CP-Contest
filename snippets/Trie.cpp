#include<bits/stdc++.h>
using namespace std;
// Trie Template Snippet Starts
class Vertex{
    public:
        int isEnd;
        vector<int>next;
        Vertex(int k){
            isEnd=0;
            next.resize(k,-1);
        }
};
class Trie{
    public:
        int K;
        vector<Vertex>nodes;
        Trie(int k){
            K=k;
            nodes.push_back(Vertex(K));
        }
        void add(string s){
            // 
            int cur=0;
            for(auto c:s){
                if(nodes[cur].next[c-'a']==-1){
                    nodes[cur].next[c-'a']=nodes.size();
                    nodes.push_back(Vertex(K));
                }
                cur=nodes[cur].next[c-'a'];
            }
            nodes[cur].isEnd++;
        }
        // lst is just temporary and s is also temporary
        // t.print(0,temp,tmp2)
        void print(int x, vector<bool> &lst, string &s)
        {
            for(int i=0; i<((int)lst.size())-1; i++)
            {
                if(lst[i]) cout<<"   ";
                else cout<<"|  ";
            }
            if(!lst.empty()) cout<<"|--";

            cout<<x<<' '<<s<<' '<<nodes[x].isEnd<<'\n';

            int mx = -1;
            for(int i=0; i<K; i++)
                if(nodes[x].next[i] != -1)
                    mx = i;
            
            lst.push_back(false);
            for(int i=0; i<K; i++)
            {
                if(nodes[x].next[i] != -1)
                {
                    s.push_back('a' + i);
                    if(i == mx) lst.back() = true;

                    print(nodes[x].next[i], lst, s);

                    s.pop_back();
                }
            }
            lst.pop_back();
            return;
        }
};
// Trie Template Ends