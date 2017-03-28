libqdpmdJni.so:  JniSystem.o JniUtil.o QdpMDClient.o QdpMDHandler.o QdpMDJniTemplate.o
	g++ -shared -Wl,-Bsymbolic -O3 -m64 -o libqdpmdJni.so JniSystem.o JniUtil.o QdpMDClient.o QdpMDHandler.o QdpMDJniTemplate.o -L./lib/ -lqdpmdapi -lpthread -lrt

JniSystem.o:  ./include/linux/JniSystem.cpp
	g++ -c -fPIC -I./include/linux -L ./lib/ -lqdpmdapi ./include/linux/JniSystem.cpp

JniUtil.o:  JniUtil.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdpmdapi JniUtil.cpp

QdpMDClient.o:  QdpMDClient.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdpmdapi  QdpMDClient.cpp

QdpMDHandler.o:  QdpMDHandler.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdpmdapi QdpMDHandler.cpp

QdpMDJniTemplate.o:  QdpMDJniTemplate.cpp
	g++ -c -fPIC -I./include/linux -L./lib/ -lqdpmdapi QdpMDJniTemplate.cpp


clean :
	rm JniSystem.o JniUtil.o QdpMDJniTemplate.o QdpMDClient.o QdpMDHandler.o libqdpmdJni.so
