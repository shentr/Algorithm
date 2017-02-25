// HDU5050
//http://acm.hdu.edu.cn/showproblem.php?pid=5050


import java.io.* ; 
import java.math.* ;
 import java.util.* ;
import java.text.* ;
 public class Main
 {
 public static void main(String[] args) 
{ 
Scanner cin=new Scanner (System.in) ;
 BigInteger A,B ;
 int t=cin.nextInt() ;
 for (int cas=1 ;cas<=t ;cas++) 
{ A=cin.nextBigInteger(2) ; 
B=cin.nextBigInteger(2) ; 
System.out.print("Case #"+cas+": ") ;
 System.out.println(A.gcd(B).toString(2)) ;
 }
 } 
}
