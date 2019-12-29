int FindOutlier(std::vector<int> arr)
{
  int count_even = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] % 2 == 0)count_even++;
	}
	if (count_even >= 2) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 2 != 0)return arr[i];
		}
	}
	else
	{
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 2 == 0)return arr[i];
		}
	}
}
