import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Main {

    public static void main (String[] args) {
        Scanner cin=new Scanner(System.in);
        while(cin.hasNextBigDecimal())
        {
            BigDecimal a = cin.nextBigDecimal();
            a=a.pow(cin.nextInt()).stripTrailingZeros();
            String b=a.toPlainString();
            if( b.substring(0,2).startsWith("0."))
                b=b.substring(1);
            System.out.println(b);
        }       
}   
}
