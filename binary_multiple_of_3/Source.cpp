#include <string>
#include <vector>
#include <math.h>
using namespace std;

const std::string multiple_of_3_regex = "";
bool solution(std::string& s){
  	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			s.erase(i);
			i--;
		}
	}
	vector<int> bin;
	for (int i = 0; i < s.size(); i++) {
		string temp;
		temp += s[i];
		bin.push_back(stoi(temp));
	}
	unsigned long long num = 0;
	int p = 0;
	for (int i = bin.size() - 1; i >= 0; i--) {
		if (bin[i]) num += pow(2,p);
		p++;
	}
	if (!num) return false;
	if (num % 3 == 0) return true;
	return false;
}
