//factorial.java
 
import java.util.Scanner;
 
public class factorial
{
  native int fact(int num);
 
  static
  {
        System.loadLibrary("forfact");
  }
 
  public static void main(String args[])
  {
        
 
        factorial obj = new factorial();
 
        System.out.println(" > The factorial of 7 is "+obj.fact(7));
  }
}