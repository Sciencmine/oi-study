#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef long long ll; 
#define scope 			if (true)
#define mian 			main
#define uns 			unsigned
#define reg 			register
#define likely(x) 		__builtin_expect(!!(x), 1)
#define unlikely(x) 	__builtin_expect(!!(x), 0)

enum {
	Inf = 0x3f3f3f3f
};

inline void ios_sync(const bool __sync = false);
inline void open_file(const std::string name = "test");
inline void open_test(const std::string name = "test");

struct Pile {
	int val;
	
	const Pile operator+ (const Pile & rhs) {
		Pile s;
		s.val = val + rhs.val;
		return s;
	}
	
	friend bool operator< (const Pile & lhs, const Pile & rhs) {
		return lhs.val > rhs.val;
	}
	
	friend istream & operator>> (istream & is, Pile & rhs) {
		return is >> rhs.val;
	}
};

priority_queue<Pile> pq; 

int main(){
	ios_sync();
	
	int n, sum = 0;
	cin >> n;
	
	Pile p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		pq.push(p);
	}
	
	while (pq.size() > 1) {
		Pile a = pq.top();
		pq.pop();
		Pile b = pq.top();
		pq.pop();
		Pile s = a + b;
		pq.push(s);
		sum += a.val + b.val;
	}
	
	cout << sum << endl;
	
	return 0;
}

void ios_sync(const bool __sync) {
	std::ios::sync_with_stdio(__sync);
}

void open_file(const std::string name) {
	freopen((name + ".in").c_str (), "r", stdin);
	freopen((name + ".out").c_str (), "w", stdout);
}

void open_test(const std::string name) {
	freopen((name + ".in").c_str (), "r", stdin);
}

