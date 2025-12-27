#include<iostream>
#include"judgeEven.h"

int main() {
	uint64_t num;
	std::cout << "‚È‚ñ‚©”š“ü‚ê‚Ä:";
	std::cin >> num;
	bool o = judgeEven(num);
	std::cout << o << std::endl;
	std::cout << "‚È‚ñ‚©‰Ÿ‚µ‚½‚çI‚í‚é‚æ:";
	system("pause>0");
}