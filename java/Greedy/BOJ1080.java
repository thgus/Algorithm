import java.util.*;

public class BOJ1080 {

    static final int part_matrix_len=3;
    static int n,m;
    static boolean[][] arr;

    private static void initialize(){
        Scanner scan = new Scanner(System.in);
        n=scan.nextInt();
        m=scan.nextInt();
        char[][] temp=new char[n][m];
        arr=new boolean[n][m];

        String str;
        for(int i=0;i<n;i++){
            str=scan.next();
            for(int j=0;j<m;j++){
                temp[i][j]=str.charAt(j);
            }
        }

        for(int i=0;i<n;i++){
            str=scan.next();
            for(int j=0;j<m;j++){
                arr[i][j]=(str.charAt(j)==temp[i][j])?true:false;
            }
        }

        temp=null;
        scan.close();
    }

    private static void reverse_matrix(int start_y,int start_x){
        for(int i=start_y;i<start_y+part_matrix_len;i++){
            for(int j=start_x;j<start_x+part_matrix_len;j++){
                arr[i][j]=(arr[i][j])?false:true;
            }
        }
    }

    private static void solve(){
        int reverse_num=0;

        if(n-part_matrix_len>=0||m-part_matrix_len>=0){
            for(int i=0;i<=n-part_matrix_len;i++){
                for(int j=0;j<=m-part_matrix_len;j++){
                    if(!arr[i][j]){
                        reverse_num++;
                        reverse_matrix(i, j);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!arr[i][j]){
                    System.out.print("-1");
                    return;
                }
            }
        }

        System.out.print(reverse_num);
        
    }  

    public static void main(String[] args){
        initialize();
        solve();
    }
}
