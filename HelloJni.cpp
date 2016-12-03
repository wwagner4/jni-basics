#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "HelloJni.h"

JNIEXPORT void JNICALL Java_HelloJni_sayHello(JNIEnv* env, jobject obj){
	printf("C Hello from cpp\n");
}

JNIEXPORT jint JNICALL Java_HelloJni_r (JNIEnv* env, jobject obj) {
	printf("C r\n");
	return 111;	
}	

JNIEXPORT void JNICALL Java_HelloJni_a(JNIEnv* env, jobject obj, jint a) {
	printf("C a %d\n", a);
}

JNIEXPORT void JNICALL Java_HelloJni_s(JNIEnv* env, jobject, jstring s) {
	const char* s1 = env->GetStringUTFChars(s, NULL);
	printf("C s1 %s\n", s1);
}





