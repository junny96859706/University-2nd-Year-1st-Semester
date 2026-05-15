#include <iostream>
#include <string>
using namespace std;

#include "Abstractpoint.h"

AbstractPoint::AbstractPoint(string name, int lowRatio,int highRatio) {
	this->name = name;
	this->lowRatio = lowRatio;
	this->highRatio = highRatio;
}