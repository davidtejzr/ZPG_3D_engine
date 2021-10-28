#pragma once
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	void insertObject(Object* object);
	Object* getObject(int id);
private:
	std::vector<Object*>* _objects;
};

