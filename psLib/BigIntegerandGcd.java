
import java.math.BigInteger;
import java.util.Scanner;

//uva 10814

public class BigIntegerandGcd {


    public static void main(String [] args)
    {

        Scanner input=new Scanner(System.in);

        int t=input.nextInt();
        while(t--!=0)
        {
            BigInteger a=input.nextBigInteger();
            char ch=input.next().charAt(0);
            BigInteger b= input.nextBigInteger();
            BigInteger xx;
            xx=a.gcd(b);
            System.out.println(a.divide(xx).toString()+" "+ch+" "+b.divide(xx).toString());
        }


    }




}
