#include<bits/stdc++.h>

using namespace std;

bool check(const vector<int> &vec, int k) {
	if(k == 1)
		return true;

	int gap = vec[1] - vec[0];

	for (int i = 1; i < vec.size(); ++i) {
		if(i % k == 0) {
			gap = vec[i + 1] - vec[i];
			continue;
		}

		if(vec[i] - vec[i-1] != gap) {
			return false;
		}
	}

	return true;
}

int main() {
	vector<int> heights = {161, 162, 163, 164, 164, 166, 168, 170, 164, 167, 170, 173};
	sort(heights.begin(), heights.end());

	int n = heights.size();

	int k = n / 2;

	for (int i = k; i >= 1; --i) {
		if(n % i != 0) 
			continue;
		
		if(check(heights, i)) {
			k = i;
			break;
		}
	}

	if(k == 0)
		k = 1;

	printf("lenth:  %d\n", k);

	for (int i = 0; i < n / k; ++i) {
		printf("[");
		for (int j = 0; j < k; ++j) {
			printf("%d", heights[j + i * k]);
			if(j != k - 1) {
				printf(", ");
			}
		}
			printf("]\n");
	}
	return 0;
}