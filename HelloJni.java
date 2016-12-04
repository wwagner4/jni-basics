import java.util.Arrays;
import java.util.*;

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
			int[] array = {111, 222, 333};
			System.out.println("J array -> " + Arrays.toString(array));
			h.array(array);
			System.out.println("J array <- ");
			System.out.println("-------------------------------------");
		}
		{
			C obj = new C();
			System.out.println("J obj -> " + obj);
			h.obj(obj);
			System.out.println("J obj <- ");
			System.out.println("-------------------------------------");
		}
		{
			List<D> l = new ArrayList<>();
			l.add(new D(100));
			l.add(new D(101));
			l.add(new D(102));
			System.out.println("J l -> " + l);
			h.l(l);
			System.out.println("J l <- ");
			System.out.println("-------------------------------------");
		}
	}

	// Write 'Hello' to stdout
	public native void sayHello();

	// Return an integer value
	public native int r();
	
	// Read an integer parameter and write it to stdout
	public native void a(int a);

	// Read a string parameter and write it to std out
	public native void s(String a);

	// Read an array of integers and write it to stdout
	public native void array(int[] a);

	// Read the members of C and write them to stdout
	public native void obj(C obj);

	// Read a list of objects
	public native void l(List<D> l);

	
}

class C {

	private int i = 100;
	private String s = "String in java class C";
	private int[] inta = {100, 200};
	private D[] da = {new D(3), new D(2), new D(1)};

	public String toString() {
		return "C[i=" + i + " s='"+ s + "' inta=" + Arrays.toString(inta) + 
			" da=" + Arrays.toString(da) + "]";
	}
}	

class D {
	int i;
	
	D(int i) {
		this.i = i;
	}
	
	public String toString() {
		return "D[i=" + i + "]";
	}
		
}