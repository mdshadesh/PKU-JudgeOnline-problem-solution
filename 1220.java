import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;


public class Main{
	public static void main (String[] args) throws java.lang.Exception
  {
    // your code goes here
    Scanner cin = new Scanner(System.in);
    int N = cin.nextInt();
    for(int i = 0; i < N; i++){
      int bf = cin.nextInt();
      int bt = cin.nextInt();
      String s = cin.next();
	
      BigInteger r = new BigInteger("0");
	
      for(int j = 0; j < s.length(); j++){
	char a = s.charAt(j);
	int x;
	if(a <= '9') x = (int)(a - '0');
	else if('A' <= a && a <= 'Z') x = (int)(a - 'A' + 10);
	else x = (int)(a + 36 - 'a');
	r = r.multiply(BigInteger.valueOf(bf));
	r = r.add(BigInteger.valueOf(x));
      }
      System.out.printf("%d %s\n", bf, s);
      System.out.printf("%d ", bt);
      String str = new String("");
      while(r.compareTo(BigInteger.valueOf(0)) > 0){
	BigInteger q = r.remainder(BigInteger.valueOf(bt));
	r = r.divide(BigInteger.valueOf(bt));
	int a = q.intValue();
	char y;
	if(a <= 9) y = (char)(a + '0');
	else if(a < 36) y = (char)(a - 10 + 'A');
	else y = (char)(a - 36 + 'a');
	//System.out.print(y);
	str += y;
      }
      String rts = new StringBuilder(str).reverse().toString();
      if(s.equals("0"))
	System.out.print("0\n\n");
      else
	System.out.printf("%s\n\n", rts);
    }
  }
}
  
