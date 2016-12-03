#include <jni.h>
#include <stdio.h>
#include "HelloJni.h"

JNIEXPORT void JNICALL Java_HelloJni_sayHello(JNIEnv *, jobject){
	printf("Hello from cpp\n");
	return;
}

