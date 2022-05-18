
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int base[2] = { 269, 307 };
const int mod[2] = { 100005277, 1000008277 };
const int MAX = 28647705;

int n;
char s[MAX + 10];
pair<int, int> Tmp[MAX + 10];

bool Checking(int len) {
	int Hash[2] = { 0, 0 };
	int Power[2] = { 1, 1 };

	for (int i = 0; i < len; ++i) {
		Power[0] = (1LL * Power[0] * base[0]) % mod[0];
		Power[1] = (1LL * Power[1] * base[1]) % mod[1];

		Hash[0] = (1LL * Hash[0] * base[0] + s[i] + 1) % mod[0];
		Hash[1] = (1LL * Hash[1] * base[1] + s[i] + 1) % mod[1];
	}

	Tmp[0] = {Hash[0], Hash[1]};
	for (int i = len; i < n; ++i) {
		Hash[0] = (1LL * Hash[0] * base[0] - (1LL * s[i - len] + 1) * Power[0] % mod[0] + 1LL * mod[0] * mod[0] + s[i] + 1) % mod[0];
		Hash[1] = (1LL * Hash[1] * base[1] - (1LL * s[i - len] + 1) * Power[1] % mod[1] + 1LL * mod[1] * mod[1] + s[i] + 1) % mod[1];

		Tmp[i-len+1] = {Hash[0], Hash[1]};
	}

	sort(Tmp, Tmp+n-len);
	for(int i = 0; i < n - len - 1; ++i)
    if (Tmp[i] == Tmp[i+1]) return true;

	return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fgets(s, MAX, stdin); n = strlen(s);

	int l = 1, r = n-1, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (Checking(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	cout << ans;

	return 0;
}