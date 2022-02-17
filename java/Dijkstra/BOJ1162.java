import java.util.*;
import java.io.*;
import java.math.*;

class Node implements Comparable<Node>{
    int city_num;
    long step;
    int pavement_num;

    Node(int _city_num, long _step, int _pavement_num){
        this.city_num=_city_num;
        this.step=_step;
        this.pavement_num=_pavement_num;
    }

    @Override
    public int compareTo(Node n){
        if(this.step<n.step){
            return -1;
        }
        else if(this.step>n.step){
            return 1;
        }
        else{
            return 0;
        }
    }
}
class Edge{
    int next_city_num;
    int cost;

    Edge(int _next_city_num, int _cost){
        this.next_city_num=_next_city_num;
        this.cost=_cost;
    }
}

public class BOJ1162 {

    static int n,m,k;
    static ArrayList<ArrayList<Edge>> road=new ArrayList<>();

    private static void initialize()  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        k=Integer.parseInt(st.nextToken());

        for(int i=0;i<=n;i++){
            road.add(new ArrayList<>());
        }

        int c1,c2,time;
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());

            c1=Integer.parseInt(st.nextToken());
            c2=Integer.parseInt(st.nextToken());
            time=Integer.parseInt(st.nextToken());
            
            road.get(c1).add(new Edge(c2,time));
            road.get(c2).add(new Edge(c1,time));
        }
    }

    private static void solve(){
        PriorityQueue<Node> que=new PriorityQueue<Node>();
        long[][] distance=new long[n+1][k+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                distance[i][j]=Long.MAX_VALUE;
            }
        }

        que.add(new Node(1,0,0));
        distance[1][0]=0;

        long min_len=Long.MAX_VALUE;

        while(!que.isEmpty()){
            Node cur=que.poll();

            if(distance[cur.city_num][cur.pavement_num]<cur.step)   continue;

            if(cur.city_num==n){
                min_len=cur.step;
                break;
            }

            for(Edge e:road.get(cur.city_num)){
                int next_city_num=e.next_city_num;
                long next_cost=e.cost;

                if(cur.pavement_num+1<=k&&distance[next_city_num][cur.pavement_num+1]>cur.step){
                    distance[next_city_num][cur.pavement_num+1]=cur.step;
                    que.add(new Node(next_city_num,cur.step,cur.pavement_num+1));
                }
                if(distance[next_city_num][cur.pavement_num]>cur.step+next_cost){
                    distance[next_city_num][cur.pavement_num]=cur.step+next_cost;
                    que.add(new Node(next_city_num,cur.step+next_cost,cur.pavement_num));
                }
            }
        }

        System.out.println(min_len);

    }  

    public static void main(String[] args) throws IOException{
        initialize();
        solve();
    }
}
