#ifndef _JniUtil_H_
#define _JniUtil_H_
#include <jni.h>

class JniUtil
{
	public:
		virtual jstring cToJstring(JNIEnv *env,const char* tmpstr);
		virtual const char* getStringByMap(JNIEnv *env,jobject jmap,const char* key);
		virtual const char getCharByMap(JNIEnv *env,jobject jmap,const char* key);
		virtual const double getDoubleByMap(JNIEnv *env,jobject jmap,const char* key);
		virtual const int getIntByMap(JNIEnv *env,jobject jmap,const char* key);

		virtual void print(JNIEnv *env,jobject jniTemplate,const char* msg);
		virtual void print(JavaVM *vm,jobject jniTemplate,const char* msg);
		virtual void jcOnEventMsg(JNIEnv* env,jobject jniTemplate,jstring jeventType,jobject jmap);
		virtual void jcOnEventMsg(JavaVM *vm,jobject jniTemplate,jstring jeventType,jobject jmap);
		virtual void jcOnResponse(JNIEnv* env,jobject jniTemplate,jobject jresMap,int errorID,const char* errorMsg,int nRequestID,bool bIsLast);
		virtual void jcOnResponse(JavaVM *vm,jobject jniTemplate,jobject jresMap,int errorID,const char* errorMsg,int nRequestID,bool bIsLast);

		virtual jobject newHashMap(JNIEnv* env);
		virtual void mapPut(JNIEnv* env,jobject jmap,const char* key,const char* value);
		virtual void mapPut(JNIEnv* env,jobject jmap,const char* key,char value);
		virtual void mapPut(JNIEnv* env,jobject jmap,const char* key,int value);		
		virtual void mapPut(JNIEnv* env,jobject jmap,const char* key,jlong value);
		virtual void mapPut(JNIEnv* env,jobject jmap,const char* key,double value);		

		virtual jobject initClassHelper(JNIEnv *env, const char *path);
};
#endif