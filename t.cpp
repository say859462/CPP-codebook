#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
typedef struct {
	int col, row, value;
}term;
int compare(ll x, ll y) {
	if (x == y)return 0;
	else if (x < y)return -1;
	else return 1;
}
bool cmp(term a, term b) {
	if (a.row == b.row)return a.col < b.col;
	return a.row < b.row;
}
int n1, m1, n2, m2, x;
int main() {
	int operation;
	term a[10000];
	term b[10000];
	cin >> operation;
	char l, m, r, equal;
	int rr, cc, val;
	int mx_col = 0;
	int mx_row = 0;
	a[0].value = operation;
	for (int i = 1; i <= operation; i++) {
		cin >> l >> a[i].row >> m >> a[i].col >> r >> equal >> a[i].value;
		mx_col = max(mx_col, a[i].col);
		mx_row = max(mx_row, a[i].row);
	}
	sort(a + 1, a + 1 + operation, cmp);
	for (int i = 1; i <= operation; i++)cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	//for (int i = 1; i <= operation; i++)cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	int cur = 1;
	for (int i = 1; i <= mx_col; i++) {
		for (int j = 1; j <= operation; j++) {
			if (i == a[j].col) {
				b[cur].row = a[j].col;
				b[cur].col = a[j].row;
				b[cur].value = a[j].value;
				cur++;
			}
		}
	}
	//for (int i = 1; i <= operation; i++)cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
	b[0].value = operation;
	int i, j;
	int column=1, row = a[1].row;
	int sum = 0;	
	int totald = 0;
	int row_begin = 1;
	a[a[0].value + 1].row = mx_row;
	b[b[0].value + 1].col = mx_row;
	term ans[10005];
	for (i = 1; i <= a[0].value;) {
		column = b[1].row;
		for (j = 1; j <= b[0].value + 1;) {
			if (row != a[i].row) {//超過欲計算row 代表這次的col計算完成，換到下個col，並使當前row回歸
				if (sum) {
					ans[++totald].value = sum;
					ans[totald].row = row;
					ans[totald].col = column;
					sum = 0;
				}
				i = row_begin;
				while (b[j].row == column)j++;
				column = b[j].row;
			}
			else if (column != b[j].row) {
				if (sum) {
					ans[++totald].value = sum;
					ans[totald].row = row;
					ans[totald].col = column;
					sum = 0;
				}
				i = row_begin;
				column = b[j].row;
			}
			else switch (compare(a[i].col, b[j].col)) {
			case -1://若a[i].col<bt[j].col 
				i++;
				break;
			case 0:
				sum += (a[i].value * b[j].value);
				i++;
				j++;
				break;
			case 1:
				j++;
			}
		}
		while (a[i].row == row)i++;
		row_begin = i;
		row = a[i].row;
	}
	//for (int i = 1; i <= operation; i++)cout << ans[i].row << " " << ans[i].col << " " << ans[i].value << endl;




	return 0;
}
