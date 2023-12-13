#include "device.h"

void device::creatNewDevice(string name)
{
	device *d= new device(name);


}

void device::deleteDevice(device* device) { //TODO: check if name already exists
	return;
}

static bool isInSet(string name) {
	for (auto d : connectedDevices) {
		if (d->getName() == name) {
			return true;
		}
	
}

void device::findDevice(string name) {
	return;
}

void device::connectDevice(device* device) {
	return;
}

void device::printAllDevices(){
	return;
}

void menu::meny() {
	device* d = new device();
	int choice;
	string name;

	cout << "1. Create new device" << endl;
	cout << "2. Connect device" << endl;
	cout << "3. Delete device" << endl;
	cout << "4. Print all devices" << endl;
	cout << "5. Delete device" << endl;
	cout << "6. Exit" << endl;
	cin >> choice;

	switch (choice)
	{
	case(1):
	{
		string name;
		cout << "Enter name of device: ";
		cin >> name;
		d->creatNewDevice(name);
		menu();
		break;
	}
	
	case(2):
	{
		break;
	}
	case(3):
	{
		break;
	}
	case(4):
	{
		d->printAllDevices();
		menu();
		break;
	}
	case(5):
	{
		break;
	}

	}
}