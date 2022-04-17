

public class HelloWorldJNI {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {
        new HelloWorldJNI().sayHello();
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native void sayHello();
}

//https://chandruscm.wordpress.com/2015/08/10/how-to-use-jni-java-native-interface-with-cc/
//https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html