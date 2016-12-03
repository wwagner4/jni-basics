public class HelloJni {

  static {
  	System.out.println("libpath:" + System.getProperty("java.library.path"));
    System.loadLibrary("HelloJni");
  }
  
  public static void main(String... args) {
    new HelloJni().sayHello();
  }

  public native void sayHello();
  
  
}
