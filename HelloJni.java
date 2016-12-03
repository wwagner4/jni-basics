import java.util.Arrays;

public class HelloJni {

  static {
    System.loadLibrary("HelloJni");
  }
  
  public static void main(String... args) {
  	HelloJni h = new HelloJni();
  	System.out.println("-------------------------------------");
  	
  	{
	  	System.out.println("J sayHello ->");
	    h.sayHello();
	  	System.out.println("J sayHello <-");
	  	System.out.println("-------------------------------------");
		}
		{
	  	System.out.println("J r ->");
	    int r = h.r();
	  	System.out.println("J r <- " + r);
	  	System.out.println("-------------------------------------");
		}
		{
			int i = 333;
	  	System.out.println("J a -> " + i);
	    h.a(i);
	  	System.out.println("J a <- ");
	  	System.out.println("-------------------------------------");
		}
		{
			String str = "Es war einmal und ist nicht mehr";
	  	System.out.println("J s -> " + str);
	    h.s(str);
	  	System.out.println("J s <- ");
	  	System.out.println("-------------------------------------");
		}
		{
			int[] array = {2, 4, 6, 8};
	  	System.out.println("J array -> " + Arrays.toString(array));
	    h.array(array);
	  	System.out.println("J array <- ");
	  	System.out.println("-------------------------------------");
		}
  }

  public native void sayHello();

  public native int r();
  
  public native void a(int a);

  public native void s(String a);

  public native void array(int[] a);

  
}
