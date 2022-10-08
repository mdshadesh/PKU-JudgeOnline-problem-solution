import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    String s = cin.next();
	    BigDecimal base = new BigDecimal(0.125);
	    BigDecimal ret = new BigDecimal(0);
	    for(int i = 2; i < s.length(); i++){
		BigDecimal c = new BigDecimal((int)(s.charAt(i) - '0'));
		ret = ret.add(c.multiply(base));
		base = base.divide(new BigDecimal(8));
	    }
	    System.out.println(s + " [8] = " + ret + " [10]");
	}
    }
}
