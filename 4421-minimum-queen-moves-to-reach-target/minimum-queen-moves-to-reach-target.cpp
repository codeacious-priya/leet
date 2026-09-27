class Solution {
public:
    int solve(int sr,int sc,int tr,int tc){
        // base case
        if(sr==tr && sc==tc)return 0;
         //case 3=dia
        if((sr+sc==tr+tc)){
            return 1;
        }
        if(sr>8||sc>8||tc>8||tr>8) return 0;

        // case i=row
        int row=1+solve(tr,sc,tr,tc);
        //case 2=col
        int col=1+solve(sr,tc,tr,tc);
        
        return min(row,col);
       


    }
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0];int sc=source[1];int tr=target[0];int tc=target[1];
        if(sr==tr && sc==tc)return 0;
        if(sr==tr||sc==tc||abs(sr-tr)==abs(sc-tc)) return 1;

        return 2;
    }
};