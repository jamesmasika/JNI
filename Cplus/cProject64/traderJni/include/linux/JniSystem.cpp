#include "JniSystem.h"
#include <unistd.h>

void JniSystem::jniSleep(int seconds){
	sleep(seconds);//��ͣseconds��
}