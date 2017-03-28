libtraderJni.so: JniSystem.o JniUtil.o TraderJniApi.o TraderJniClient.o TraderJniSpi.o TraderJniTemplate.o	
	g++ -shared -Wl,-Bsymbolic -O3 -m64 -o libtraderJni.so JniSystem.o JniUtil.o TraderJniApi.o TraderJniClient.o TraderJniSpi.o TraderJniTemplate.o -L./lib/ -lQTuserapi -lpthread -lrt

JniSystem.o:  ./include/linux/JniSystem.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi ./include/linux/JniSystem.cpp

JniUtil.o:  JniUtil.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi JniUtil.cpp

TraderJniApi.o:  TraderJniApi.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi TraderJniApi.cpp

TraderJniClient.o:  TraderJniClient.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi TraderJniClient.cpp

TraderJniSpi.o:  TraderJniSpi.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi TraderJniSpi.cpp

TraderJniTemplate.o:  TraderJniTemplate.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lQTuserapi TraderJniTemplate.cpp


clean :
	rm JniSystem.o JniUtil.o TraderJniApi.o TraderJniClient.o TraderJniSpi.o TraderJniTemplate.o libtraderJni.so
