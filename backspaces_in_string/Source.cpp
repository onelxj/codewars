std::string cleanString(const std::string &s) {    
	std::string str = s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '#') {
			if (i!=0) {
				if (i < 1) i = 1;
				str.erase(str.begin() + i - 1, str.begin() + i + 1);
				i -= 2;
			}
			else
			{
				str.erase(str.begin() + i);
				i--;
			}
		}
		
	}

	return str;
}
