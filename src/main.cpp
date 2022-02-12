#include <iostream>
#include <iomanip>

using namespace std;

double b1(double dist) {
	auto km = static_cast<int>(dist);

	auto ret = double{ 0 };
	if (km <= 5) {
		ret = 4;
	}
	else if (km <= 10) {
		ret = 7;
	}
	else if (km <= 20) {
		ret = 12;
	}
	else if (km <= 30) {
		ret = 17;
	}
	else {
		ret = km * 0.57;
	}

	return ret;
}

double b2(double dist) {
	auto km = static_cast<int>(dist);

	auto ret = double{ 0 };
	if (km <= 2) {
		ret = 0.90 + km * 0.90;
	}
	else if (km <= 5) {
		ret = 1 + km * 0.85;
	}
	else if (km <= 20) {
		ret = 1.25 + km * 0.80;
	}
	else if (km <= 40) {
		ret = 3.25 + km * 0.70;
	}
	else {
		ret = 9.25 + km * 0.55;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x, y;
	cin >> x >> y;
	auto distX = x / 1000.0;
	auto distY = y / 1000.0;

	auto xb1 = b1(distX);
	auto xb2 = b2(distX);

	auto yb1 = b1(distY);
	auto yb2 = b2(distY);

	auto xb = xb1 < xb2 ? xb1 : xb2;
	auto yb = yb1 < yb2 ? yb1 : yb2;

	cout << fixed << setprecision(2) << xb + yb;

	return 0;
}