import java.util.*;
import java.io.*;
import java.math.*;

public class BOJ1480 {

    static int n,m,c;
    static int[] jewelry;
    static int[][][] dp;

    private static void initialize() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());

        jewelry=new int[n];
        dp=new int[m][1<<n][c+1];

        for(int i=0;i<m;i++){
            for(int j=0;j<1<<n;j++){
                for(int k=0;k<c+1;k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            jewelry[i]=Integer.parseInt(st.nextToken());
        }
    }
    
    private static int dfs(int bag_num, int jewelry_bit, int remaining_size){
        if(bag_num==m || jewelry_bit==(1<<n)-1){
            return 0;
        }

        if(dp[bag_num][jewelry_bit][remaining_size]!=-1){
            return dp[bag_num][jewelry_bit][remaining_size];
        }

        for(int i=0;i<n;i++){
            if((jewelry_bit&(1<<i))>0)  continue;

            if(remaining_size>=jewelry[i]){
                dp[bag_num][jewelry_bit][remaining_size]=Math.max(dp[bag_num][jewelry_bit][remaining_size],dfs(bag_num,jewelry_bit|(1<<i),remaining_size-jewelry[i])+1);
            }
            else{
                dp[bag_num][jewelry_bit][remaining_size]=Math.max(dp[bag_num][jewelry_bit][remaining_size],dfs(bag_num+1,jewelry_bit,c));
            }
        }

        return dp[bag_num][jewelry_bit][remaining_size];
    }  

    public static void main(String[] args) throws IOException{
        initialize();
        dfs(0,0,c);
        System.out.println(dp[0][0][c]);
    }
}
