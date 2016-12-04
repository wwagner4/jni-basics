#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "HelloJni.h"


// Utillity function to output the java class 'D'
void showD(JNIEnv* env, jobject obj) {
  jclass clazz = env->GetObjectClass(obj);
  
  // access integer value
  {
    jfieldID fid1 = env->GetFieldID(clazz, "i", "I");
    jint i = env->GetIntField(obj, fid1);
    printf("   C D.i %d\n", i);
  }

}
// Utillity function to output the java class 'C'
void showC(JNIEnv* env, jobject obj) {
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
  if (a != NULL) {
    jint* ca = env->GetIntArrayElements(a, 0);
    jsize l = env->GetArrayLength(a);
    printf("l=%d\n", l);
    for (int i=0; i<l; i++) {
      printf("C C.inta[%d] %d\n", i, ca[i]);
    }
  } else {
    printf("C C.inta null\n");
  }
  
  // acces object array. No nullcheck
  {
    jfieldID fid4 = env->GetFieldID(clazz, "da", "[LD;");
    jobjectArray joa = (jobjectArray)env->GetObjectField(obj, fid4);
      
    jsize l = env->GetArrayLength(joa);
    printf("l=%d\n", l);
    for (int i=0; i<l; i++) {
      jobject oae = env->GetObjectArrayElement(joa, i);
      showD(env, oae);
    }
  }
}

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
  if (s != NULL) {
    const char* s1 = env->GetStringUTFChars(s, 0);
    printf("C s1 %s\n", s1);
    env->ReleaseStringUTFChars(s, s1);
  } else {
    printf("C s1 null\n");
  }
}

JNIEXPORT void JNICALL Java_HelloJni_array(JNIEnv* env, jobject obj, jintArray a) {
  if (a != NULL) {
    jint* ca = env->GetIntArrayElements(a, 0);
    jsize l = env->GetArrayLength(a);
    printf("C l %d\n", l);
    for (int i=0; i<l; i++) {
      printf("C a[%d] %d\n", i, ca[i]);
    }
  } else {
    printf("C a null\n");
  }
}

JNIEXPORT void JNICALL Java_HelloJni_obj(JNIEnv* env, jobject, jobject obj) {
  showC(env, obj);
}

JNIEXPORT void JNICALL Java_HelloJni_l(JNIEnv* env, jobject, jobject lobj) {
  printf("C l %p\n", lobj);
  jclass clazz = env->GetObjectClass(lobj);
  jmethodID sizeMid = env->GetMethodID(clazz, "size", "()I");
  jmethodID getMid = env->GetMethodID(clazz, "get", "(I)Ljava/lang/Object;");
  jint size = env->CallIntMethod(lobj, sizeMid);
  printf("C l size=%d\n", size);
  for (int i=0; i<size; i++) {
    jobject dObj = env->CallObjectMethod(lobj, getMid, i);
    printf("C l dObj=%p\n", dObj);
  }  
}

JNIEXPORT void JNICALL Java_HelloJni_lp(JNIEnv* env, jobject, jobject lObj) {
  printf("C lp %p\n", lObj);
  jclass clazz = env->GetObjectClass(lObj);
  jmethodID sizeMid = env->GetMethodID(clazz, "size", "()I");
  jmethodID getMid = env->GetMethodID(clazz, "get", "(I)Ljava/lang/Object;");
  jint size = env->CallIntMethod(lObj, sizeMid);
  printf("C l size=%d\n", size);
  for (int i=0; i<size; i++) {
    jobject dObj = env->CallObjectMethod(lObj, getMid, i);
    jclass iClazz = env->GetObjectClass(dObj);
    jmethodID descMid = env->GetMethodID(iClazz, "desc", "()Ljava/lang/String;");

    jstring strObj = (jstring)env->CallObjectMethod(dObj, descMid);
    const char* cs = env->GetStringUTFChars(strObj, 0);
    printf("C l I.desc %s\n", cs);
    env->ReleaseStringUTFChars(strObj, cs);
  }  
}
