#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class storage;

class device 
{
private:
	string name;
	set<device*> connectedDevices;
	storage* storage;
	~device() {
		cout << "deleted " << name << endl;	//ta bort alla connected?
	}
	public:
		device(string name) : name(name) {};
		device() {};

		string getName() { return name; };

		void creatNewDevice(string name);
		void connectDevice(device* device); //skicka in devicen som du vill connetcta med?
		void printAllDevices();
		void deleteDevice(device* device);
		void findDevice(string name);
		
};



class menu {
public:
	menu() {};	//konstruktor
	void meny();

};
