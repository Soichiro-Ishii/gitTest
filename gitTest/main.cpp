#include<iostream>
#include<string>
using namespace std;

int main() {
	uint64_t max;
	std::string o;
	cout << "どこまで表示しますか?:";
	cin >> max;
	for (uint64_t i = 0; i <= max; i++) {
		o += to_string(i) + "は";
		bool isEven = (i % 2) == 0;
		o += isEven ? "偶数です。" : "奇数です。";
		o += '\n';
	}
	cout << o;
	cout << "なんか押したら終わるよ:";
	system("pause>0");
}