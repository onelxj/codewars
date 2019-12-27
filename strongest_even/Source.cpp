//Нужно ускорить программу, на тестах даёт timed out


int strongest_even(int n, int m) {
    	int max_div = 0;
	int even = 0;
	for (int k = m; k >= n; k--) {
		
		if (k % 2 == 0) {
			int temp_max_div = 0;
			int temp_k = k;
			while (temp_k % 2 == 0) {
				temp_k /= 2;
				temp_max_div++;
			}
			if (temp_max_div > max_div) {
				max_div = temp_max_div;
				even = k;
			}
		}
	}

	return even;
}
