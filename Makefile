all: libHelloJni.jnilib

clean:
	rm -f HelloJni.class  \
	rm -f HelloJni.h      \
	rm -f HelloJni.o      \
	rm -f libHelloJni.jnilib    \

run: all
	java -Djava.library.path=. HelloJni

HelloJni.h: HelloJni.class
	javah -jni HelloJni

HelloJni.class : HelloJni.java
	javac HelloJni.java
	
libHelloJni.jnilib: HelloJni.cpp HelloJni.h
	g++  -dynamiclib -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin \
		 -o libHelloJni.jnilib HelloJni.cpp  -framework JavaVM



