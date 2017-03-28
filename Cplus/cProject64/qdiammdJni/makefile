libqdiammdJni.so:  JniSystem.o JniUtil.o QdiamMDClient.o QdiamMDHandler.o QdiamMDJniTemplate.o
	g++ -shared -Wl,-Bsymbolic -O3 -m64 -o libqdiammdJni.so JniSystem.o JniUtil.o QdiamMDClient.o QdiamMDHandler.o QdiamMDJniTemplate.o -L./lib/ -lqdammdapi -lpthread -lrt

JniSystem.o:  ./include/linux/JniSystem.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lqdammdapi ./include/linux/JniSystem.cpp

JniUtil.o:  JniUtil.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdammdapi JniUtil.cpp

QdiamMDClient.o:  QdiamMDClient.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdammdapi  QdiamMDClient.cpp

QdiamMDHandler.o:  QdiamMDHandler.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdammdapi QdiamMDHandler.cpp

QdiamMDJniTemplate.o:  QdiamMDJniTemplate.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdammdapi QdiamMDJniTemplate.cpp


clean :
	rm JniSystem.o JniUtil.o QdiamMDJniTemplate.o QdiamMDClient.o QdiamMDHandler.o libqdiammdJni.so
