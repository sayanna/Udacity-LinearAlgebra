#include <iostream>
#include "vector-op.hpp"
using namespace std;

#define dbglog printf
#define msglog printf
#define errlog printf

static void _testScaleVector() {
	std::vector<double> v1 {1.671,-1.012,-0.318};
	double scale = 7.41;

	std::vector<double> res = scaleVector(v1,scale);

	printVector(v1);
	msglog("scale = %f\n",scale);
	printVector(res);
}

static void _testSubVectors() {
	std::vector<double> v1{7.119,8.215};
	std::vector<double> v2{-8.223,0.878};

	std::vector<double> res = substractVectors(v1,v2);

	printVector(v1);
	printVector(v2);
	printVector(res);
}

static void _testAddVectors() {
	std::vector<double> v1{8.218,-9.341};
	std::vector<double> v2{-1.129,2.111};

	std::vector<double> res = addVectors(v1,v2);

	printVector(v1);
	printVector(v2);
	printVector(res);
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
