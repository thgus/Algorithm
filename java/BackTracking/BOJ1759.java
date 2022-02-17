package BackTracking;

import java.io.*;
import java.util.*;

class BOJ1759{
    public static int L,C;
    public static boolean visit[];
    public static char arr[];
    public static char arr2[];
    public static boolean isPassword(char []array){
        int mouem=0;
        int zauem=0;
        for(int i=0;i<array.length;i++){
            char ch = array[i];
            if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
                mouem++;
            }
            else{
                zauem++;
            }
            System.out.print(ch);
        }
        System.out.print(" "+mouem+" "+zauem);
        if(mouem>=1&&zauem>=2)
            return true;
        else
            return false;
    }
    public static void backTracking(int depth,int start){
        if(depth==L){
            if(isPassword(arr2)){
                for(int i=0;i<L;i++)
                    System.out.print(arr2[i]);
                System.out.println();
            }
        }
        else{
            for(int i=start;i<C;i++){
               if(!visit[i]) {
                   arr2[depth] = arr[i];
                   visit[i]=true;
                   backTracking(depth + 1,i+1);
                   visit[i]=false;
                   arr2[depth]=0;
               }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        L=Integer.parseInt(st.nextToken());
        C=Integer.parseInt(st.nextToken());
        visit = new boolean[C];
        arr = new char[C];
        arr2 = new char[L];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<C;i++){
            String s = st.nextToken();
            arr[i]= s.charAt(0);
        }
        Arrays.sort(arr);
        backTracking(0,0);
        br.close();
    }

}