libs = -lmosquitto

client.o: ./mqtt/client.hpp ./mqtt/client.cpp
	g++ -c ./mqtt/client.cpp -o ./bin/client.o $(libs)

pub_client.o: ./mqtt/pub_client.hpp ./mqtt/pub_client.cpp
	g++ -c ./mqtt/pub_client.cpp -o ./bin/pub_client.o $(libs)

sub_client.o: ./mqtt/sub_client.hpp ./mqtt/sub_client.cpp
	g++ -c ./mqtt/sub_client.cpp -o ./bin/sub_client.o $(libs)

mqtt_pub: client.o pub_client.o mqtt_pub.cpp
	g++ mqtt_pub.cpp -o mqtt_pub ./bin/client.o ./bin/pub_client.o $(libs)

mqtt_sub: client.o sub_client.o mqtt_sub.cpp
	g++ mqtt_sub.cpp -o mqtt_sub ./bin/client.o ./bin/sub_client.o $(libs)

.PHONY: all
all: mqtt_pub mqtt_sub