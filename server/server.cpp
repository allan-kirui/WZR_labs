#define _WINSOCK_DEPRECATED_NO_WARNINGS
// server.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//
#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <iterator> 
#include <map>

#include "net.h"
using namespace std;

unsigned short sz = 100;

#define NUM_OF_CLIENTS 1

void receive_frame(unsigned long* IP, char* buffer) {
	unicast_net* client = new unicast_net(1002);  // wskaŸnik do obiektu klasy unicast_net

	int frame_size = client->reciv(buffer, IP, sz);   // oczekiwanie na nadejœcie ramki 
	printf("odebrano");
}
void send_frame(unsigned long list_of_clients[], int size, char* buffer) {
	for (int i = 0; i < size; i++) {
		unicast_net* sender = new unicast_net(1001);
		int frame_size = sender->send(buffer, list_of_clients[i], sz);
	}
}

int main()
{

	unsigned long list_of_clients[NUM_OF_CLIENTS] = { 3232235876 };
	char* buffer = new char[sz];
	while (true) {
		for (int i = 0; i < NUM_OF_CLIENTS; i++) {
			receive_frame(&list_of_clients[i], buffer);
			send_frame(list_of_clients, NUM_OF_CLIENTS, buffer);
		}
	}
	delete buffer;
}
