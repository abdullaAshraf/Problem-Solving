/*
 Author: Abdulla Ashraf
 Idea:
 -http://mathforum.org/dr.math/faq/formulas/faq.irreg.tetrahedron.html
 -https://github.com/hussienibrahiem95/CompetitiveProgramming/blob/master/SPOJ/PIR.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;

const int MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e9;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

const int N = 5;

// calculate Determinant of any matrix
void getCofactor(double mat[N][N], double temp[N][N], double p, double q,
		double n) {
	int i = 0, j = 0;
	// Looping for each element of the matrix
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			//  Copying into temporary matrix only those element
			//  which are not in given row and column
			if (row != p && col != q) {
				temp[i][j++] = mat[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}
double determinantOfMatrix(double mat[N][N], int n) {
	double D = 0; // Initialize result
	//  Base case : if matrix contains single element
	if (n == 1)
		return mat[0][0];
	double temp[N][N]; // To store cofactors
	int sign = 1;  // To store sign multiplier
	// Iterate for each element of first row
	for (int f = 0; f < n; f++) {
		// Getting Cofactor of mat[0][f]
		getCofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
		// terms are to be added with alternate sign
		sign = -sign;
	}
	return D;
}
double mat[5][5];

int main() {
	int t;
	cin >> t;
	while (t--) {
		double ab, ac, ad, bc, bd, cd;
		cin >> ab >> ac >> ad >> bc >> bd >> cd;
		for (int i = 0; i < 6; i++) {
			mat[4][i] = mat[i][4] = 1;
			mat[i][i] = 0;
		}
		mat[0][1] = mat[1][0] = ad * ad;
		mat[0][2] = mat[2][0] = ac * ac;
		mat[0][3] = mat[3][0] = ab * ab;
		mat[1][2] = mat[2][1] = cd * cd;
		mat[1][3] = mat[3][1] = bd * bd;
		mat[2][3] = mat[3][2] = bc * bc;

		cout << fixed << setprecision(4) << sqrt(determinantOfMatrix(mat, 5) / 288.0) << endl;
	}
}
