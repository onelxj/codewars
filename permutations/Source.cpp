#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long double fact(int N)
{
    if(N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * fact(N - 1); // делаем рекурсию.
}

bool in_data(string s, vector<string> d) {
	for (auto c : d) {
		if (c == s) return true;
	}
	return false;
}

vector<string> permutations(string s) {
   string temp = s;
	vector<string> data;
	vector<int> duplicates;
	for (int i = 0; i < s.size(); i++) {
		int t = 0;
		for (int j = i + 1; j < s.size(); j++) {
			if (s[i] == s[j]) t++;
		}
		if (t) duplicates.push_back(t+1);
	}
	int sum = 0;
	for (auto d : duplicates) sum += d;
	if (!sum) sum = 1;
	for (int i = 0; i < fact(s.size()) / sum; i++) {
			if (!in_data(temp, data))
			data.push_back(temp);
		next_permutation(temp.begin(), temp.end());
	}
	return data;
}
