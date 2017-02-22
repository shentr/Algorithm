// 4764 ( Stone )
//acm.hdu.edu.cn/showproblem.php?pid=4764


import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n,k;
        while(sc.hasNext()){
            n=sc.nextInt();
            k=sc.nextInt();
            if(n==0&&k==0)
                break;
            if(n%(k+1)==1)
                System.out.println("Jiang");
            else
                System.out.println("Tang");
        }
    }
}