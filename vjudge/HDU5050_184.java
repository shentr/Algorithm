// HDU5050
//http://acm.hdu.edu.cn/showproblem.php?pid=5050



import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
	Scanner cin=new Scanner(System.in);	
	int t;
	BigInteger A,B,ans;
	t=cin.nextInt();
	for(int i=1;i<=t;i++)
	{
		A=cin.nextBigInteger(2);
		B=cin.nextBigInteger(2);
		System.out.print("Case #"+i+": ") ;
		 System.out.println(A.gcd(B).toString(2)) ;

	}
	
	}

}
