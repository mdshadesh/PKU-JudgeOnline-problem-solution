import java.io.*;
import java.math.*;
import java.util.*;




class Main {

    public static void main(String[] args) {
	BigInteger comb[][] = new BigInteger[200][200];
	for(int i = 0; i < 101; i++){
	    for(int j = 0; j < 101; j++){
		comb[i][j] = new BigInteger("0");
	    }
	}

	comb[0][0] = new BigInteger("1");
	for(int i = 1; i < 101; i++){
	    comb[i][0] = new BigInteger("1");
	    for(int j = 1; j < 101; j++){
		//comb[i][j] = comb[i][j].add(comb[i - 1][j]);
		comb[i][j] = comb[i - 1][j].add(comb[i - 1][j - 1]);
	    }
	}

	Scanner scan=new Scanner(System.in);
	int a, b;
	while(true){
	    a = scan.nextInt();
	    b = scan.nextInt(); 
	    if(a == 0 && b == 0) break;
	    //a = a.multiply(b);
	    System.out.println(a + " things taken " + b + " at a time is "
			       + comb[a][b] + " exactly.");
	}
    }
}