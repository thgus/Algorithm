import java.sql.Struct;
import java.util.*;

public class BOJ2133 {

    static int n;

    static int[][] dp;
    private static int dfs(int n, int bit){
        if(n==0){
            if(bit==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(n<0){
            return 0;
        }

        if(dp[n][bit]!=-1)   return dp[n][bit];
        dp[n][bit]=0;

        switch(bit){
            case 0:
                dp[n][bit]+=dfs(n-1,1)+dfs(n-1,2)+dfs(n-2,0);
                break;
            case 1:
                dp[n][bit]+=dfs(n-2,1)+dfs(n-1,0);
                break;
            case 2:
                dp[n][bit]+=dfs(n-2,2)+dfs(n-1,0);
                break;
        }

        return dp[n][bit];
    }  

    public static void main(String[] args){
        dp=new int[n+1][3];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=-1;
            }
        }

        Scanner scan = new Scanner(System.in);
        n=scan.nextInt();
        scan.close();

        System.out.print(dfs(n,0));
    }
}
