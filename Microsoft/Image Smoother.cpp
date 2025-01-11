class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        int arri[8]={-1,-1,-1,1,1,1,0,0};
        int arrj[8]={-1,0,1,-1,0,1,-1,1};
        vector<vector<int>>img2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=1;
                int sum=0;
                for(int k=0;k<8;k++){
                    int i_ind=i+arri[k];
                    int j_ind=j+arrj[k];

                    if(i_ind>=0 && i_ind<n && j_ind>=0 && j_ind<m){
                        sum+=img[i_ind][j_ind];
                        num++;
                    }
                }
                sum+=img[i][j];
                int val=floor(sum/num);
                img2[i][j]=val;
            }
        }
        return img2;
    }
};