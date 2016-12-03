public class HelloJni {

  static {
    System.loadLibrary("HelloJni");
  }
  
  public static void main(String... args) {
  	HelloJni h = new HelloJni();
  	System.out.println("-------------------------------------");
  	System.out.println("J sayHello ->");
    h.sayHello();
  	System.out.println("J sayHello <-");
  	System.out.println("-------------------------------------");

  	System.out.println("J r ->");
    int r = h.r();
  	System.out.println("J r <- " + r);
  	System.out.println("-------------------------------------");

  	System.out.println("J a -> 555");
    h.a(555);
  	System.out.println("J a <- ");
  	System.out.println("-------------------------------------");
  }

  public native void sayHello();

  public native int r();
  
  public native void a(int a);
  
  
}
