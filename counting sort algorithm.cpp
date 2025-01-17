//counting sort algorithm
class Solution {
public:
    int maxIceCream(vector<int>& costs) {
       // int cnt=0,sum=0;
        int freq[100008]={0};
        set<int>st;
        for(int i=0; i<costs.size(); i++)
        {
            freq[costs[i]]++;
            st.insert(costs[i]);
        }
        for(auto it:st)
        {
           // cout<<it<<"  : "<<freq[it]<<endl;
           for(int i=0; i<freq[it]; i++)
           {
              cout<<it<<" ";
           }
        }
        return 0;
    }
};
