#include<stdio.h>

int main(){
    int k,n;
    scanf("%d%d",&k,&n);

    int len[10005];
    int max=0;
    for(int i=0;i<k;i++){
        scanf("%d",&len[i]);

        if(max<len[i]){
            max=len[i];
        }
    }

    long long start=1;
    long long end=max;

    long long result=0;

    //반례) 1 1 100
    //while(start<end)
    while(start<=end){
        long long middle=(start+end)/2;

        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=len[i]/middle;
        }

        if(sum<n){
            //end=middle;
            end=middle-1;
        }
        else{
            start=middle+1;
            if(result<middle){
                result=middle;
            }
        }

    }

    printf("%lld",result);
    return 0;
}