#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "device.h"
using namespace std;


class deviceStorage {
private:
	string storageName;
	int currentStorageSize;
	vector <device*> devices;
public:
	deviceStorage(string storageName, int currentStorageSize): storageName(storageName), currentStorageSize(currentStorageSize)
	{
		currentStorageSize = 0;
	};
};

