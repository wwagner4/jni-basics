#include <jni.h>
#include <stdio.h>
#include "HelloJni.h"

JNIEXPORT void JNICALL Java_HelloJni_sayHello(JNIEnv *, jobject){
	printf("C Hello from cpp\n");
}

JNIEXPORT jint JNICALL Java_HelloJni_r (JNIEnv *, jobject) {
	printf("C r\n");
	return 111;	
}	

JNIEXPORT void JNICALL Java_HelloJni_a(JNIEnv *, jobject, jint a) {
	printf("C a %d\n", a);
}




