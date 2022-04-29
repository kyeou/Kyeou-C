import java.io.*;

public class HelloWorldJNI {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) throws IOException {
        
        HelloWorldJNI a =  new HelloWorldJNI; 
          File file = new File("outfilename");
    System.out.println(file.length());
    FileWriter fw = new FileWriter(file.getAbsoluteFile());
    BufferedWriter bw = new BufferedWriter(fw);
    //bw.write(content);
    bw.close();
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native String sayHello();
}

//https://chandruscm.wordpress.com/2015/08/10/how-to-use-jni-java-native-interface-with-cc/
//https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html