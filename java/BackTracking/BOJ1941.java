package BackTracking;

import java.util.*;

public class BOJ1941 {
    public static final int MAX=5;

    static boolean[][] arr=new boolean[MAX][MAX];
    static int n;

    private static void initialize(){
        Scanner scan = new Scanner(System.in);

        String str;
        for(int i=0;i<MAX;i++){
            str=scan.next();
            for(int j=0;j<MAX;j++){
                arr[i][j]=(str.charAt(j)=='Y')?false:true;
            }
        } 

        scan.close();
    }

    static int result=0;
    static boolean[][] isUse;

    static boolean dominate_s(){
        int s_num=0;
        int y_num=0;

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                if(isUse[i][j]){
                    if(arr[i][j]){
                        s_num++;
                    }
                    else{
                        y_num++;
                    }
                }
            }
        }

        if(s_num>y_num){
            return true;
        }
        else{
            return false;
        }

    }

    static boolean isNear(int start){
        int len=0;
        int[][] d={{-1,0},{1,0},{0,1},{0,-1}};
        boolean[][] isVisited=new boolean[MAX][MAX];
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                isVisited[i][j]=false;
            }
        }

        Queue<Integer> que=new LinkedList<>();
        que.add(start);
        isVisited[start/MAX][start%MAX]=true;

        while(!que.isEmpty()){
            int cur=que.poll();
            len++;

            for(int i=0;i<4;i++){
                int next_y=cur/MAX+d[i][0];
                int next_x=cur%MAX+d[i][1];

                if(next_y>=0&&next_y<MAX&&next_x>=0&&next_x<MAX&&!isVisited[next_y][next_x]){
                    isVisited[next_y][next_x]=true;
                    if(isUse[next_y][next_x]){
                        que.add(next_y*MAX+next_x);
                    }
                }
            }
        }

        if(len==7){
            return true;
        }
        else{
            return false;
        }
    }

    private static void dfs(int index, int len){
        if(len==7){
            if(dominate_s() && isNear(index))
                result++;
            return;
        }

        for(int i=index;i<MAX*MAX;i++){
            int y=i/MAX;
            int x=i%MAX;

            if(isUse[y][x]) continue;

            isUse[y][x]=true;
            dfs(i,len+1);
            isUse[y][x]=false;
        }
    }

    private static void solve(){
        isUse=new boolean[MAX][MAX];
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                isUse[i][j]=false;
            }
        }

        dfs(0,0);
        System.out.println(result);
    }  

    public static void main(String[] args){
        initialize();
        solve();
    }
}
