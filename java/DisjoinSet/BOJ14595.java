import java.util.*;
import java.io.*;

public class BOJ14595 {

    static int n,m;
    static int[] parent;
    static int[] union_end_room;
    static int last_room;

    private static int find_parent(int i){
        if(parent[i]==i){
            return i;
        }
        else{
            return find_parent(parent[i]);
        }
    }

    static void print_arr(int[] arr){
        System.out.println();
        for(int i=1;i<=n;i++){
            System.out.print(arr[i]+" ");
        }
    }

    private static void solve(int start, int end){
        int cur_p=find_parent(start);
        for(int i=union_end_room[cur_p]+1;i<=end;i=union_end_room[i]+1){
            union_end_room[cur_p]=union_end_room[i];
            parent[i]=cur_p;
            last_room--;
        }
    }

    private static void initialize() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());

        st=new StringTokenizer(br.readLine());
        m=Integer.parseInt(st.nextToken());

        last_room=n;
        parent=new int[n+1];
        union_end_room=new int[n+1];
        for(int i=0;i<=n;i++){
            parent[i]=i;
            union_end_room[i]=i;
        }

        int start, end;
        while((m--)>0){
            st=new StringTokenizer(br.readLine());
            start=Integer.parseInt(st.nextToken());
            end=Integer.parseInt(st.nextToken());

            solve(start,end);              
        }
        
    }  

    public static void main(String[] args) throws IOException{
        initialize();

        System.out.println(last_room);
    }
}
