class Solution {
public:
    #define ll long long int
    long long countOfSubstrings(string word, int k) {

        int n=word.size();

        unordered_map<char,int>mp,mp1;

        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;

        int cons=0;

        ll res=0;

        int l=0,r=0;

        vector<int>c;

        for(int i=0;i<n;i++)
        {
            if(!mp.count(word[i])) c.push_back(i);
        }

        while(r<n)
        {
            if(mp.count(word[r]))
            {
                mp1[word[r]]++;
            }
            else{
                cons++;
            }

            while(mp1['a']>0 and mp1['e']>0 and mp1['i']>0 and mp1['o']>0 and mp1['u']>0 and cons>=k and l<r)
            {
                if(cons==k)
                {
                    int idx=upper_bound(begin(c),end(c),r)-begin(c);
                    int next;
                    if(idx<c.size())
                    next=c[idx];
                    else next=n;
                    //cout<<r<<" "<<next<<endl;
                    int cnt=next-r;
                    res+=cnt;
                }
    
                if(mp.count(word[l]))
                mp1[word[l]]--;
                else cons--;
                l++;
            }


            r++;

        }


     
        return res;








        
    }
};
