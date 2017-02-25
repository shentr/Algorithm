// HDU1023
//http://acm.hdu.edu.cn/showproblem.php?pid=1023


import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n;
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			n=sc.nextInt();
			BigInteger ans=BigInteger.valueOf(1);
			for(int i=1;i<=n;i++){
				ans=ans.multiply(BigInteger.valueOf(4*i-2));
				ans=ans.divide(BigInteger.valueOf(i+1));
			}
			System.out.println(ans);
		}
	}
}