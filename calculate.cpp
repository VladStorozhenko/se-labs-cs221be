int calculate(int x, int n) {
	int sum, prod;

	sum = 0;
	prod = 1;
	if (x < 0) {
		for (int j = 2; j <= n - 2; j++) {
			prod *= (j + x);
		}
		return prod;
	}
	else {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				prod *= (x + i + j * j);
			}
			sum += prod;
			prod = 1;
		}
		return sum;
	}
}
