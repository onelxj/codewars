#include <string>
std::string duplicate_encoder(const std::string& word){
  std::string str = word;
	std::string res;
	for (int i = 0; i < str.size(); i++) {
		str[i] = (char)tolower(str[i]);
	}	
	for (int i = 0; i < str.size(); i++) {
		bool double_ = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[i] == str[j] && i != j) {
				double_ = true;
				break;
			}
		}

		if (double_)res += ")";
		else res += "(";
	}
	return res;
}
