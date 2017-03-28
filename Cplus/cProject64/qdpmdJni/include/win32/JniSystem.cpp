#include "JniSystem.h"
#include <windows.h>

void JniSystem::jniSleep(int seconds){
	Sleep(seconds*1000);//‘›Õ£seconds√Î
}