#include "JniUtil.h"
#include <stdio.h>
#include <string.h>
#include <float.h>

jstring JniUtil::cToJstring(JNIEnv *env, const char* tmpstr) {
	jclass Class_string;
	jmethodID mid_String;
	jbyteArray bytes;
	jstring codetype, jstr;
	Class_string = env->FindClass("java/lang/String");//获取class
													  //先将gbk字符串转为java里的string格式
	mid_String = env->GetMethodID(Class_string, "<init>", "([BLjava/lang/String;)V");
	bytes = env->NewByteArray(strlen(tmpstr));
	env->SetByteArrayRegion(bytes, 0, strlen(tmpstr), (jbyte*)tmpstr);
	codetype = env->NewStringUTF("gbk");
	jstr = (jstring)env->NewObject(Class_string, mid_String, bytes, codetype);

	env->DeleteLocalRef(Class_string);
	env->DeleteLocalRef(bytes);
	env->DeleteLocalRef(codetype);
	return jstr;
}

const char* JniUtil::getStringByMap(JNIEnv *env, jobject jmap, const char* key) {
	jclass class_map = env->GetObjectClass(jmap);
	jmethodID mid_get = env->GetMethodID(class_map, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
	jstring jkey = env->NewStringUTF(key);
	jstring jvalue = (jstring)env->CallObjectMethod(jmap, mid_get, jkey);
	const char * str = "";
	if (jvalue != NULL) {
		jboolean copyflag = false;
		str = env->GetStringUTFChars(jvalue, &copyflag);
	}

	env->DeleteLocalRef(class_map);
	env->DeleteLocalRef(jkey);
	return str;
}
const char JniUtil::getCharByMap(JNIEnv *env, jobject jmap, const char* key) {
	const char* tmp = this->getStringByMap(env, jmap, key);
	char result = '\0';
	if (tmp != NULL&&strlen(tmp)>0) {
		result = tmp[0];
	}
	return result;
}
const double JniUtil::getDoubleByMap(JNIEnv *env, jobject jmap, const char* key) {
	jclass class_map = env->GetObjectClass(jmap);
	jmethodID mid_get = env->GetMethodID(class_map, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
	jstring jkey = env->NewStringUTF(key);
	jobject jvalue = env->CallObjectMethod(jmap, mid_get, jkey);
	double result = 0;
	if (jvalue != NULL) {
		jclass class_double = env->FindClass("java/lang/Double");
		jmethodID mid_double = env->GetMethodID(class_double, "doubleValue", "()D");
		result = env->CallDoubleMethod(jvalue, mid_double);
		env->DeleteLocalRef(class_double);
	}
	env->DeleteLocalRef(class_map);
	env->DeleteLocalRef(jkey);
	if (jvalue != NULL) {
		env->DeleteLocalRef(jvalue);
	}
	return result;
}
const int JniUtil::getIntByMap(JNIEnv *env, jobject jmap, const char* key) {
	jclass class_map = env->GetObjectClass(jmap);
	jmethodID mid_get = env->GetMethodID(class_map, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
	jstring jkey = env->NewStringUTF(key);
	jobject jvalue = env->CallObjectMethod(jmap, mid_get, jkey);
	int result = 0;
	if (jvalue != NULL) {
		jclass class_int = env->FindClass("java/lang/Integer");
		jmethodID mid_int = env->GetMethodID(class_int, "intValue", "()I");
		result = env->CallIntMethod(jvalue, mid_int);
		env->DeleteLocalRef(class_int);
	}
	env->DeleteLocalRef(class_map);
	env->DeleteLocalRef(jkey);
	if (jvalue != NULL) {
		env->DeleteLocalRef(jvalue);
	}
	return result;
}
void JniUtil::print(JNIEnv *env, jobject jniTemplate, const char* msg) {
	jclass class_jniTemplet = env->GetObjectClass(jniTemplate);
	if (class_jniTemplet == NULL) {
		printf("class_jniTemplet is null\n");
		return;
	}
	jmethodID mid_ncOnResponse = env->GetStaticMethodID(class_jniTemplet, "jcPrint", "(Ljava/lang/String;)V");
	jstring jmsg = cToJstring(env, msg);
	env->CallStaticVoidMethod(class_jniTemplet, mid_ncOnResponse, jmsg);

	env->DeleteLocalRef(class_jniTemplet);
	env->DeleteLocalRef(jmsg);
}

void JniUtil::print(JavaVM *vm, jobject jniTemplate, const char* msg) {
	JNIEnv* env = NULL;
	jint result = vm->AttachCurrentThread((void**)&env, NULL);
	print(env, jniTemplate, msg);
	vm->DetachCurrentThread();
}

void JniUtil::jcOnEventMsg(JNIEnv* env, jobject jniTemplate, jstring jeventType, jobject jmap) {
	jclass class_qdpJniTemplate = env->GetObjectClass(jniTemplate);
	if (class_qdpJniTemplate == NULL) {
		printf("class_jniTemplet is null");
		return;
	}
	jmethodID mid_jcOnEventMsg = env->GetStaticMethodID(class_qdpJniTemplate, "jcOnEventMsg", "(Ljava/lang/String;Ljava/util/Map;)V");
	env->CallStaticVoidMethod(class_qdpJniTemplate, mid_jcOnEventMsg, jeventType, jmap);

	env->DeleteLocalRef(class_qdpJniTemplate);
}
void JniUtil::jcOnEventMsg(JavaVM *vm, jobject jniTemplate, jstring jeventType, jobject jresMap) {
	JNIEnv* env = NULL;
	jint result = vm->AttachCurrentThread((void**)&env, NULL);
	jcOnEventMsg(env, jniTemplate, jeventType, jresMap);
	vm->DetachCurrentThread();
}
void JniUtil::jcOnResponse(JNIEnv* env, jobject jniTemplate, jobject jresMap, int errorID, const char* errorMsg, int nRequestID, bool bIsLast) {

	jclass class_jniTemplet = env->GetObjectClass(jniTemplate);
	jmethodID mid_ncOnResponse = env->GetStaticMethodID(class_jniTemplet, "jcOnResponse", "(Ljava/util/Map;ILjava/lang/String;IZ)V");

	jint jerrorID = errorID;
	jstring jerrorMsg = JniUtil::cToJstring(env, errorMsg);
	jint jnRequestID = nRequestID;
	jboolean jbIsLast = bIsLast;
	env->CallStaticVoidMethod(class_jniTemplet, mid_ncOnResponse, jresMap, jerrorID, jerrorMsg, jnRequestID, jbIsLast);

	env->DeleteLocalRef(class_jniTemplet);
	env->DeleteLocalRef(jerrorMsg);

}
void JniUtil::jcOnResponse(JavaVM *vm, jobject jniTemplate, jobject jresMap, int errorID, const char* errorMsg, int nRequestID, bool bIsLast) {
	JNIEnv* env = NULL;
	jint result = vm->AttachCurrentThread((void**)&env, NULL);
	jcOnResponse(env, jniTemplate, jresMap, errorID, errorMsg, nRequestID, bIsLast);
	vm->DetachCurrentThread();
}
jobject JniUtil::newHashMap(JNIEnv* env) {
	jclass class_hashMap = env->FindClass("java/util/HashMap");
	jmethodID mid_hashMap = env->GetMethodID(class_hashMap, "<init>", "()V");
	jobject obj = env->NewObject(class_hashMap, mid_hashMap);

	env->DeleteLocalRef(class_hashMap);
	return obj;
}
void JniUtil::mapPut(JNIEnv* env, jobject jmap, const char* key, const char* value) {
	jclass class_hashMap = env->GetObjectClass(jmap);
	jmethodID mid_put = env->GetMethodID(class_hashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jobject j_key = env->NewStringUTF(key);
	jobject j_value = NULL;
	if (value != NULL) {
		j_value = env->NewStringUTF(value);
	}
	env->CallVoidMethod(jmap, mid_put, j_key, j_value);

	env->DeleteLocalRef(class_hashMap);
	env->DeleteLocalRef(j_key);
	if (j_value != NULL) {
		env->DeleteLocalRef(j_value);
	}
}
void JniUtil::mapPut(JNIEnv* env, jobject jmap, const char* key, char value) {
	char buff[10];
	const char *tmpstr = buff;
	if (value != NULL) {
		sprintf(buff, "%c", value);
	}
	else {
		tmpstr = NULL;
	}
	this->mapPut(env, jmap, key, tmpstr);
}
void JniUtil::mapPut(JNIEnv* env, jobject jmap, const char* key, int value) {
	jclass class_hashMap = env->GetObjectClass(jmap);
	jmethodID mid_put = env->GetMethodID(class_hashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jobject j_key = env->NewStringUTF(key);
	jint j_value = value;
	jclass class_integer = env->FindClass("java/lang/Integer");
	jmethodID mid_integer = env->GetMethodID(class_integer, "<init>", "(I)V");
	jobject j_integer = env->NewObject(class_integer, mid_integer, j_value);

	env->CallVoidMethod(jmap, mid_put, j_key, j_integer);

	env->DeleteLocalRef(class_hashMap);
	env->DeleteLocalRef(j_key);
	env->DeleteLocalRef(class_integer);
	env->DeleteLocalRef(j_integer);
}
void JniUtil::mapPut(JNIEnv* env, jobject jmap, const char* key, jlong value) {
	jclass class_hashMap = env->GetObjectClass(jmap);
	jmethodID mid_put = env->GetMethodID(class_hashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jobject j_key = env->NewStringUTF(key);
	jlong j_value = value;
	jclass class_long = env->FindClass("java/lang/Long");
	jmethodID mid_long = env->GetMethodID(class_long, "<init>", "(J)V");
	jobject j_long = env->NewObject(class_long, mid_long, j_value);

	env->CallVoidMethod(jmap, mid_put, j_key, j_long);

	env->DeleteLocalRef(class_hashMap);
	env->DeleteLocalRef(j_key);
	env->DeleteLocalRef(class_long);
	env->DeleteLocalRef(j_long);
}
void JniUtil::mapPut(JNIEnv* env, jobject jmap, const char* key, double value) {
	jclass class_hashMap = env->GetObjectClass(jmap);
	jmethodID mid_put = env->GetMethodID(class_hashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jobject j_key = env->NewStringUTF(key);
	jdouble j_value = value;
	jclass class_double = env->FindClass("java/lang/Double");
	jmethodID mid_double = env->GetMethodID(class_double, "<init>", "(D)V");
	jobject j_double = NULL;
	if (DBL_MAX != value) {
		j_double = env->NewObject(class_double, mid_double, j_value);
	}
	env->CallVoidMethod(jmap, mid_put, j_key, j_double);

	env->DeleteLocalRef(class_hashMap);
	env->DeleteLocalRef(j_key);
	env->DeleteLocalRef(class_double);
	if (j_double != NULL) {
		env->DeleteLocalRef(j_double);
	}
}

jobject JniUtil::initClassHelper(JNIEnv *env, const char *path) {
	jclass cls = env->FindClass(path);
	if (!cls) {
		printf("initClassHelper: failed to get %s class reference", path);
		return NULL;
	}
	jmethodID constr = env->GetMethodID(cls, "<init>", "()V");
	if (!constr) {
		printf("initClassHelper: failed to get %s constructor", path);
		return NULL;
	}
	jobject obj = env->NewObject(cls, constr);
	if (!obj) {
		printf("initClassHelper: failed to create a %s object", path);
		return NULL;
	}
	return env->NewGlobalRef(obj);
}