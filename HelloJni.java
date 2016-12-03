public class HelloJni {

  static {
  	System.out.println("libpath:" + System.getProperty("java.library.path"));
    System.loadLibrary("HelloJni");
  }
  
  public static void main(String... args) {
  	HelloJni h = new HelloJni();
  	System.out.println("J sayHello ->");
    h.sayHello();
  	System.out.println("J sayHello <-");

  	System.out.println("J sayHello ->");
    int r = h.r();
  	System.out.println("J sayHello <- " + r);
  }

  public native void sayHello();

  public native int r();
  
  
}
