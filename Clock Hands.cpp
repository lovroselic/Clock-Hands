// https://www.codeabbey.com/index/task_view/clock-hands
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Clock Hands v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	/***********************/


	vector<string> data = splitString(raw_data[1], " ");
	//printVector(data);

	vector<string> solution;

	const long double HL = 6.0;
	const long double ML = 9.0;
	const long double X = 10.0;
	const long double Y = 10.0;

	for (auto c : data) {
		vector<int> clock = splitToInt(c, ":");
		int hour = clock[0];
		int minute = clock[1];
		cout << hour << " : " << minute << endl;

		long double minuteAngle = to_radians(minute / 60.0 * 360.0);
		long double hourAngle = to_radians(((hour % 12) / 12.0 * 360.0) + ((1 / 12.0 * 360.0) * (minute / 60.0)));

		long double hourX = X + sin(hourAngle) * HL;
		long double hourY = Y + cos(hourAngle) * HL;
		cout << "hour x,y " << hourX << " " << hourY << endl;
		solution.push_back(FloatToString(hourX));
		solution.push_back(FloatToString(hourY));

		long double minX = X + sin(minuteAngle) * ML;
		long double minY = Y + cos(minuteAngle) * ML;
		cout << "min x,y " << minX << " " << minY << endl;
		solution.push_back(FloatToString(minX));
		solution.push_back(FloatToString(minY));
	}

	cout << "\nSolution: " << joinVector(solution, " ") << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

