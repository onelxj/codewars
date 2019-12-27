#include <vector>
#include <utility>

using namespace std;

bool is_in(vector<int> v, int k) { // return true if k in v, else return false;
	for (auto& c : v) {
		if (k == c) return true;
	}
	return false;
}

int sum_intervals(vector<pair<int, int>> intervals) {
  vector<int> repeat;
	for (int i = 0; i < intervals.size(); i++) {
		for (int j = intervals[i].first; j < intervals[i].second; j++) {
			if (!is_in(repeat, j)) repeat.push_back(j); //addding elements from interval, if no such element yet
		}
	}
	return repeat.size();
}
