void merge(int i, int j, int mid) {
	int l = i;
	int r = mid + 1;
	int k = i;
	while (l <= mid && r <= j) {
		if (nums[l] < nums[r]) {
			temp[k++] = nums[l++];
		}
		else {
			ans += mid-l+1;
			temp[k++] = nums[r++];
		}
	}
	while (l <= mid) {
		temp[k++] = nums[l++];
	}
	while (r <= j) {
		temp[k++] = nums[r++];
	}
	for (int a = i; a <= j; a++) {
		nums[a] = temp[a];
	}
}
void mergesort(int i, int j) {
	if (i < j) {
		int mid = (i + j) / 2;
		mergesort(i, mid);
		mergesort(mid + 1, j);
		merge(i, j, mid);
	}
}
