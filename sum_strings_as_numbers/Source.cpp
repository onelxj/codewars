#include <vector>
#include <string>
#include <utility>
using namespace std;

int get_int(string s) {
	vector<pair<int, int>> data = { {48,0},{49,1},{50,2},{51,3},{52,4},{53,5},{54,6},{55,7},{56,8}, {57,9} };
	int p = 1, val = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		p *= 10;
	}
	for (int i = 0; i < s.size(); i++) {
		int k = (int)s[i];
		for (int j = 0; j < data.size(); j++) {
			if (data[j].first == k) {
				val += p * data[j].second;
			}
		}
		p /= 10;
	}
	return val;
}

std::string sum_strings(std::string a, std::string b) {
	vector<string> res;
	int diff = a.size() - b.size();
	if (diff > 0) {
		while (a.size() != b.size()) {
			string temp;
			temp += a[0];
			res.push_back(temp);
			a.erase(a.begin() + 0);
		}
	}
	else
	{
		while (a.size() != b.size()) {
			string temp;
			temp += b[0];
			res.push_back(temp);
			b.erase(b.begin() + 0);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		string val1, val2, temp;
		val1 += a[i];
		val2 += b[i];
		temp += to_string(get_int(val1) + get_int(val2));
		res.push_back(temp);
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		string temp;
		temp += res[i];
		if (get_int(temp) >= 10) {
			if (i != 0) {
				res[i] = to_string(get_int(res[i]) - 10);
				res[i - 1] = to_string(get_int(res[i-1]) + 1);
			}
			else
			{
				res[i] = to_string(get_int(res[i]) - 10);
				vector<string> temp_v = { "1" };
				for (int f = 0; f < res.size(); f++)
					temp_v.push_back(res[f]);
				res = temp_v;
			}
		}
	}
	if (res[0] == "0" && res.size() > 1) {
		res.erase(res.begin() + 0);
	}
	string result;
	for (auto c : res) result += c;
	return result;
}
