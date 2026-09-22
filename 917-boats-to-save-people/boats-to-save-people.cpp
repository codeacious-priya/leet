class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0;
        int j=n-1;
        int cnt=0;
       
       while(i<=j){
        int sum=people[i]+people[j];
        if(sum<=limit){
            i++;
            j--;
            cnt++;
        }
        else{
            j--;
            cnt++;
        }
       }
       return cnt;
    }
};