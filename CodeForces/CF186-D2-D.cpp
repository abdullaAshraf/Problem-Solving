#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	double s, a, b, c;
	cin >> s >> a >> b >> c;
	double t = a + b + c;
	if (a == b && a == c && !a)
		cout << "0.0 0.0 0.0";
	else
		cout << fixed << setprecision(15) << a * s / t << " " << b * s / t << " " << c * s / t;
	return 0;
}
