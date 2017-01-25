#include <iostream>
#include <stdio.h>
#include <bitset>
#include <cmath>

using namespace std;

int praefix = 255;
int ip[4] = {0,0,0,0};
int sub = 0x0;
unsigned int ip_bin = 0;
unsigned int netz_ip = 0;
unsigned int host_ip = 0;
char klasse = 'A';

int out() {
	cout << "Netzwerkmaske 		: "	<< bitset<sizeof(sub)*8> (sub) << "\n";
	cout << "IP Adresse 		: "	<< bitset <sizeof(ip_bin)*8> (ip_bin) << "\n";
	cout << "Netzwerkaddresse 	: "	<< bitset<sizeof(netz_ip)*8> (netz_ip) << "\n";
	cout << "Hostadresse 		: "	<< bitset<sizeof(host_ip)*8> (host_ip) << "\n\n";
	cout << "Es ist ein Klasse " << klasse << " Netzwerk\n";
	system("pause");
	return 0;	
}

int in(){
	cout << "Bitte geben sie die IP - Adresse nacheinander bei der entsprechenden Aufforderung ein!\n";
	for (int i = 0; i < 4; i++) {
		cout << "Bitte das " << i+1 << " Byte eingeben : " ;
		cin >> ip[i];
		ip_bin = ip_bin << 8;
		ip_bin = ip_bin | ip[i];
	}
	cout << "Bitte das praefix eingeben : ";
	cin >> praefix;
	for (int i = 0; i < 32 - praefix; i++){
		sub = sub << 1;
		sub += 1; 
	}
	sub = ~sub;
	return 0;
}

int main() {
	in();
	netz_ip = ip_bin & sub;
	host_ip = ip_bin & ~sub;
	cout << (netz_ip);
	if ( (netz_ip >> 24 < 128) && (netz_ip >> 24 > 0 ) ){
		klasse = 'A';
	}else if ( (netz_ip >> 24 < 192) && (netz_ip >> 24 >= 128) ){
		klasse = 'B';
	}else if ( (netz_ip >> 24 < 224)  && (netz_ip >> 24 >= 192)  ){
		klasse = 'C';
	}else if ( (netz_ip >> 24 < 240 ) && (netz_ip >> 24 >= 224 ) ){
		klasse = 'D';
	}else if ( (netz_ip >> 24 < 256 ) && (netz_ip >> 24 >= 240 ) ){
		klasse = 'E';
	}
	out();
	return 0;
}
