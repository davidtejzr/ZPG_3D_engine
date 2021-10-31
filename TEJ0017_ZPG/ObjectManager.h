#pragma once
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Object.h"

class ObjectManager
{
public:
	static ObjectManager* getInstance();
	void insertObject(Object* object);
	Object* getObject(int id);
private:
	ObjectManager();
	static ObjectManager* _instance;
	std::vector<Object*>* _objects;
};

