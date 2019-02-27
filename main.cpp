#include <iostream>
#include "vector-op.hpp"
using namespace std;

#define dbglog printf
#define msglog printf
#define errlog printf

static void _testScaleVector() {
	mathVector v1(1.671,-1.012,-0.318);
	double scale = 7.41;

	mathVector res = scaleVector(v1,scale);

	msglog("v1 = [%f,%f,%f]\n",v1.x,v1.y,v1.z);
	msglog("scale = %f\n",scale);
	msglog("res = [%f,%f,%f]\n",res.x,res.y,res.z);
}

static void _testSubVectors() {
	mathVector v1(7.119,8.215);
	mathVector v2(-8.223,0.878);

	mathVector res = substractVectors(v1,v2);

	msglog("v1 = [%f,%f]\n",v1.x,v1.y);
	msglog("v2 = [%f,%f]\n",v2.x,v2.y);
	msglog("res = [%f,%f]\n",res.x,res.y);
}

static void _testAddVectors() {
	mathVector v1(8.218,-9.341);
	mathVector v2(-1.129,2.111);

	mathVector res = addVectors(v1,v2);

	msglog("v1 = [%f,%f]\n",v1.x,v1.y);
	msglog("v2 = [%f,%f]\n",v2.x,v2.y);
	msglog("res = [%f,%f]\n",res.x,res.y);
}

static void printUsage() {
	msglog("Usage : ./test <command>\n");
	msglog("testAddVectors\n");
	msglog("testSubVectors\n");
	msglog("testScaleVector\n");
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printUsage();
		return 0;
	}

	string command = argv[1];

	if (command == "testAddVectors") {
		_testAddVectors();
	} else if (command == "testSubVectors") {
		_testSubVectors();
	} else if (command == "testScaleVector") {
		_testScaleVector();
	} else {
		cout << "Invalid command\n";
		printUsage();
	}

	return 0;
}
