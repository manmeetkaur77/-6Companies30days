class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int nobulls=0;
        
        vector<int>vis1(10,0);
        vector<int>vis2(10,0);
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])
            {
                nobulls++;
            }
            else{
                vis1[secret[i]-'0']++;
                vis2[guess[i]-'0']++;
            }
        }
        int nocows=0;
        for(int i=0;i<=9;i++){
            nocows+=min(vis1[i],vis2[i]);
        }
        for(int i=0;i<=9;i++){
            cout<<vis1[i]<<" "<<vis2[i]<<endl;
        }

        cout<<nobulls<<" "<<nocows;
        string ans="";
        ans=ans+to_string(nobulls);
        ans+='A';
        ans=ans+to_string(nocows);
        ans+='B';
        return ans;

    }
};