class Solution {
public:
    int solve(int sr,int sc,int tr,int tc){
        // base case
        if(sr==tr && sc==tc)return 0;
         //case 3=dia
       // Check both diagonals:
        if (abs(sr - tr) == abs(sc - tc)) {
            return 1;
        }
        if(sr>8||sc>8||tc>8||tr>8) return 0;

        // case i=row
        int row=2;
        if(sr!=tr){
           row =1+solve(tr,sc,tr,tc);
        }
      
        //case 2=col
        int col=2;
        if(sc!=tc){
           col=1+solve(sr,tc,tr,tc);
        }
      
        
        return min(row,col);
       


    }
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0];int sc=source[1];int tr=target[0];int tc=target[1];
        return solve(sr,sc,tr,tc);
    }
};