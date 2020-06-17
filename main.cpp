#include"testing_driver.h"
#include"MapHash.h"
#include"MapTree.h"
#include"file_driver_hash.h"
#include"file_driver.h"

using namespace std;

int main() {
	for(int windowSize = 1; windowSize <= 30; windowSize++){
		vector<double> times;
		for(int trial = 0; trial < 3; trial++){
			times.push_back(create_random_file("good_merchant.txt", "merchant_out.txt", windowSize));
		}
		double time_sum = 0;
		for(int i = 0; i < 3; i++)
			time_sum += times.at(i);
		cout << windowSize << "," << time_sum / 3 << endl;
	}
}
