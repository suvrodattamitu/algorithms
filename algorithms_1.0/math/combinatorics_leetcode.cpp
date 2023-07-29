//https://leetcode.com/contest/weekly-contest-309/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
const int MOD = 1000000007;

struct mod_int {
	int val;

	mod_int(long long v = 0) {
		if (v < 0)
			v = v % MOD + MOD;

		if (v >= MOD)
			v %= MOD;

		val = v;
	}

	static int mod_inv(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const {
		return val;
	}

	mod_int& operator+=(const mod_int& other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}

	mod_int& operator-=(const mod_int& other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		return x % m;
	}

	mod_int& operator*=(const mod_int& other) {
		val = fast_mod((uint64_t)val * other.val);
		return *this;
	}

	mod_int& operator/=(const mod_int& other) {
		return *this *= other.inv();
	}

	friend mod_int operator+(const mod_int& a, const mod_int& b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int& a, const mod_int& b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int& a, const mod_int& b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int& a, const mod_int& b) { return mod_int(a) /= b; }

	mod_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	mod_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	mod_int operator++(int) { mod_int before = *this; ++* this; return before; }
	mod_int operator--(int) { mod_int before = *this; --* this; return before; }

	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	bool operator==(const mod_int& other) const { return val == other.val; }
	bool operator!=(const mod_int& other) const { return val != other.val; }

	mod_int inv() const {
		return mod_inv(val);
	}

	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1)
				result *= a;

			a *= a;
			p >>= 1;
		}

		return result;
	}

	friend ostream& operator<<(ostream& stream, const mod_int& m) {
		return stream << m.val;
	}
};

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
	inv.assign(maximum + 1, 1);

	// Make sure MOD is prime, which is necessary for the inverse algorithm below.
	for (int p = 2; p * p <= MOD; p++)
		assert(MOD % p != 0);

	for (int i = 2; i <= maximum; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i);

	factorial.resize(maximum + 1);
	inv_factorial.resize(maximum + 1);
	factorial[0] = inv_factorial[0] = 1;

	for (int i = 1; i <= maximum; i++) {
		factorial[i] = i * factorial[i - 1];
		inv_factorial[i] = inv[i] * inv_factorial[i - 1];
	}
}

mod_int choose(long long n, long long r) {
	if (r < 0 || r > n)
		return 0;

	return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
	assert(0 <= r && r <= n);
	return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
	if (k < 0 || k > n)
		return 0;

	return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
	assert(0 <= k && k <= n);
	return inv_factorial[n] * factorial[n - k];
}

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int len = abs(startPos - endPos);
        if ((k + len) % 2 == 1) return 0;
        int a = (k + len) / 2;
        prepare_factorials(1111);
        return (int)choose(k, a); // nCk
    }
};