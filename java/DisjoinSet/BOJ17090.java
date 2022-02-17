import java.io.*;
import java.util.*;

public class BOJ17090 {

    static int[][] d={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
    static int[][] map;
    static int[][] visited;

    static int n,m;
    private static void initialize() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        map=new int[n][m];
        visited=new int[n][m];

        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            String nextToken = st.nextToken();
            for(int j=0;j<m;j++){
                switch(nextToken.charAt(j)){
                    case 'U':
                        map[i][j]=1;
                        break;
                    case 'R':
                        map[i][j]=2;
                        break;
                    case 'D':
                        map[i][j]=3;
                        break;
                    case 'L':
                        map[i][j]=4;
                        break;
                }
            }
        }
  
    }

    static int result=0;
    private static boolean dfs(int r, int c){
        if(r<0||r>=n||c<0||c>=m){
            return true;
        }

        int next_r=r+d[map[r][c]][0];
        int next_c=c+d[map[r][c]][1];
        if(visited[r][c]==0){
            visited[r][c]=1;
            if(dfs(next_r,next_c)){
                result++;
                visited[r][c]=2;
                return true;
            }
            else{
                visited[r][c]=3;
                return false;
            }
        }
        else if(visited[r][c]==1){
            return false;
        }
        else if(visited[r][c]==2){
            return true;
        }
        else if(visited[r][c]==3){
            return false;
        }

        return false;
    }
    
    private static void solve(){ 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0)
                    dfs(i,j);
            }
        }

        System.out.println(result);
    }  

    public static void main(String[] args) throws IOException{
        initialize();
        solve();
    }
}
