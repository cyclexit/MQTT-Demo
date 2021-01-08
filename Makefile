libs = -lmosquitto

mqtt_pub: ./bin/client.o ./bin/pub_client.o mqtt_pub.cpp
	g++ mqtt_pub.cpp -o mqtt_pub ./bin/client.o ./bin/pub_client.o $(libs)

client.o: ./mqtt/client.hpp ./mqtt/client.cpp
	g++ -c ./mqtt/client.cpp -o ./bin/client.o $(libs)

pub_client.o: ./mqtt/pub_client.hpp ./mqtt/pub_client.cpp
	g++ -c ./mqtt/pub_client.cpp -o ./bin/pub_client.o $(libs)

.PHONY: clean
clean:
	rm mqtt_pub
	rm bin/