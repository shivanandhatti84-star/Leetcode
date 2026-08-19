class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        if(st[0]==']'||st[0]=='}'||st[0]==')') return false;
        for(int i=0;i<st.size();i++){
            if(st[i]=='['||st[i]=='{'||st[i]=='('){
                s.push(st[i]);
            }
            else{
                if(s.empty()) return false;
                char x=s.top();  
                if((x=='('&&st[i]==')')||(x=='['&&st[i]==']')||(x=='{'&&st[i]=='}')){
                    s.pop();
                    continue;
                }
                else{
                    return false;
                }

            }
        }
        if(!s.empty()) return false;
        return true;
    }
};