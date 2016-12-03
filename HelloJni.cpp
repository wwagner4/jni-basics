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
	const char* s1 = env->GetStringUTFChars(s, 0);
	printf("C s1 %s\n", s1);
	env->ReleaseStringUTFChars(s, s1);
}

JNIEXPORT void JNICALL Java_HelloJni_array(JNIEnv* env, jobject obj, jintArray a) {
	jint* ca = env->GetIntArrayElements(a, 0);
  jsize l = env->GetArrayLength(a);
	printf("C l %d\n", l);
  for (int i=0; i<l; i++) {
		printf("C i[%d] %d\n", i, ca[i]);
  }
}

JNIEXPORT void JNICALL Java_HelloJni_obj(JNIEnv* env, jobject, jobject obj) {
	jclass clazz = env->GetObjectClass(obj);
	
	// access integer value
	jfieldID fid1 = env->GetFieldID(clazz, "i", "I");
	jint i = env->GetIntField(obj, fid1);
  printf("C C.i %d\n", i);

	// access string
	jfieldID fid2 = env->GetFieldID(clazz, "s", "Ljava/lang/String;");
	jstring strObj = (jstring)env->GetObjectField(obj, fid2);
	const char* cs = env->GetStringUTFChars(strObj, 0);
	printf("C C.s %s\n", cs);
	env->ReleaseStringUTFChars(strObj, cs);
	
	// access integer array
	jfieldID fid3 = env->GetFieldID(clazz, "inta", "[I");
	jintArray a = (jintArray)env->GetObjectField(obj, fid3);
	jint* ca = env->GetIntArrayElements(a, 0);
  jsize l = env->GetArrayLength(a);
  for (int i=0; i<l; i++) {
		printf("C C.inta[%d] %d\n", i, ca[i]);
  }
	
}






