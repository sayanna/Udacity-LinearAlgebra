#include <iostream>
#include "vector-op.hpp"
using namespace std;

#define dbglog printf
#define msglog printf
#define errlog printf

static void _testProjection() {
	std::vector<double> v1 {3.039,1.879};
	std::vector<double> b1 {0.825,2.036};
	std::vector<double> v2 {-9.88,-3.264,-8.159};
	std::vector<double> b2 {-2.155,-9.353,-9.473};
	std::vector<double> v3 {3.009,-6.172,3.692,-2.51};
	std::vector<double> b3 {6.404,-9.144,2.759,8.718};

	printVector(v1);
	printVector(b1);
	msglog(" Parallel Projection = ");
	printVector(computeParallelProjection(v1,b1));


	printVector(v2);
	printVector(b2);
	msglog(" Orthogonal Projection = ");
	printVector(computeOrthogonalProjection(v2,b2));

	printVector(v3);
	printVector(b3);
	msglog(" Parallel Projection = ");
	printVector(computeParallelProjection(v3,b3));
	msglog(" Orthogonal Projection = ");
	printVector(computeOrthogonalProjection(v3,b3));
	msglog(" sum of Projections = ");
	printVector(addVectors(computeParallelProjection(v3,b3),computeOrthogonalProjection(v3,b3)));
}

static void _testOrthogonal() {
	std::vector<double> v1 {-7.579,-7.88};
	std::vector<double> w1 {22.737,23.64};
	std::vector<double> v2 {-2.029,9.97,4.172};
	std::vector<double> w2 {-9.231,-6.639,-7.245};
	std::vector<double> v3 {-2.328,-7.284,-1.214};
	std::vector<double> w3 {-1.821,1.072,-2.94};
	std::vector<double> v4 {2.118,4.827};
	std::vector<double> w4 {0,0};

	printVector(v1); printVector(w1);
	msglog("checkParallel = %d checkOrthogonal = %d\n",checkParallel(v1,w1),checkOrthogonal(v1,w1));
	printVector(v2); printVector(w2);
	msglog("checkParallel = %d checkOrthogonal = %d\n",checkParallel(v2,w2),checkOrthogonal(v2,w2));
	printVector(v3); printVector(w3);
	msglog("checkParallel = %d checkOrthogonal = %d\n",checkParallel(v3,w3),checkOrthogonal(v3,w3));
	printVector(v4); printVector(w4);
	msglog("checkParallel = %d checkOrthogonal = %d\n",checkParallel(v4,w4),checkOrthogonal(v4,w4));
}

static void _testAngle() {
	std::vector<double> v1 {3.183,-7.627};
	std::vector<double> v2 {-2.668,5.319};
	std::vector<double> v3 {7.35,0.221,5.188};
	std::vector<double> v4 {2.751,8.259,3.985};

	printVector(v1);
	printVector(v2);
	msglog("res = %f radians\n",computeAngleRad(v1,v2));

	printVector(v3);
	printVector(v4);
	msglog("res = %f radians\n",computeAngleDeg(v3,v4));
}

static void _testDotProduct() {
	std::vector<double> v1 {7.887,4.138};
	std::vector<double> v2 {-8.802,6.776};
	std::vector<double> v3 {-5.955,-4.904,-1.874};
	std::vector<double> v4 {-4.496,-8.755,7.103};

	printVector(v1);
	printVector(v2);
	msglog("res = %f\n",computeDotProduct(v1,v2));

	printVector(v3);
	printVector(v4);
	msglog("res = %f\n",computeDotProduct(v3,v4));
}

static void _testNormalizeVector() {
	std::vector<double> v1 {5.581,-2.136};
	std::vector<double> v2 {1.996,3.108,-4.554};

	std::vector<double> res1 = normalizeVector(v1);
	std::vector<double> res2 = normalizeVector(v2);

	printVector(v1);
	printVector(res1);
	printVector(v2);
	printVector(res2);
}

static void _testVectorMagnitude() {
	std::vector<double> v1 {-0.221,7.437};
	std::vector<double> v2 {8.813,-1.331,-6.247};

	printVector(v1);
	msglog("res = %f\n",computeVectorMagnitude(v1));

	printVector(v2);
	msglog("res = %f\n",computeVectorMagnitude(v2));
}

static void _testScaleVector() {
	std::vector<double> v {1.671,-1.012,-0.318};
	double scale = 7.41;

	std::vector<double> res = scaleVector(v,scale);

	printVector(v);
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
	msglog("testVectorMagnitude\n");
	msglog("testNormalizeVector\n");
	msglog("testDotProduct\n");
	msglog("testAngle\n");
	msglog("testOrthogonal\n");
	msglog("testProjection\n");
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

	} else if (command == "testVectorMagnitude") {
		_testVectorMagnitude();

	} else if (command == "testNormalizeVector") {
		_testNormalizeVector();

	} else if (command == "testDotProduct") {
		_testDotProduct();

	} else if (command == "testAngle") {
		_testAngle();

	} else if (command == "testOrthogonal") {
		_testOrthogonal();

	} else if (command == "testProjection") {
		_testProjection();

	} else {
		cout << "Invalid command\n";
		printUsage();
	}

	return 0;
}
