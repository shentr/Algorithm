// HDU1316
//http://acm.hdu.edu.cn/showproblem.php?pid=1316



import java.io.*;    
import java.math.BigInteger;    
import java.util.*;  

public class Main {

	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		BigInteger a[]=new BigInteger[10500];
		a[1]=BigInteger.ONE;
		a[2]=BigInteger.valueOf(2);
		for(int i=3; i<10500; i++)
		a[i]=a[i-1].add(a[i-2]);
		int sum;
		while(cin.hasNextBigInteger()){
			sum=0;
			BigInteger x=cin.nextBigInteger();
			BigInteger y=cin.nextBigInteger();
			if(x.equals(BigInteger.ZERO)&&y.equals(BigInteger.ZERO))
				break;
			for(int i=1;i<10500; i++){
				if(a[i].compareTo(x)>=0&&a[i].compareTo(y)<=0)
				sum++;
			}
			System.out.println(sum);
		}
	}

}
