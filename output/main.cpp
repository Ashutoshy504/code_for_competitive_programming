/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Duc
 */

#include <iostream>
#include <fstream>

#define IO_USE_CSTDIO

#define C11

#ifdef SUBMIT
#define LOGLEVEL 0
#define NDEBUG
#else
#define LOGLEVEL 1
#endif

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <deque>
#include <climits>
#include <cfloat>
#include <bitset>

#ifdef C11

#include <array>
#include <type_traits>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#endif

#define LOG(l, x) if (l <= LOGLEVEL) cout << x << endl

#define int64 long long
#define repeat(x) for (auto repeat_var = 0; repeat_var < x; ++repeat_var)

#define for_inc(i, x) for (auto i = 0; i < x; ++i)
#define for_dec(i, x) for (auto i = x - 1; i >= 0; --i)
#define for_inc_range(i, x, y) for (auto i = x; i <= y; ++i)
#define for_dec_range(i, x, y) for (auto i = x; i >= y; --i)

#define countBit __builtin_popcount
#define countBit64 __builtin_popcountl

#define fill0(x) memset(x, 0, sizeof(x))
#define INT_INF ((int)2E9L)
#define INT64_INF ((int64)1E18L)
#define MOD 1000000007

using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            assert(false); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

string toYesNo(bool b) {
    return b ? "YES" : "NO";
}

#endif


#ifndef H_SCANNER
#define H_SCANNER

#ifdef IO_USE_CSTDIO

class Scanner {
    std::istream &in;

public:
    Scanner(std::istream &in) : in(in) {
    }

    Scanner &operator>>(int &result) {
        scanf("%d", &result);
        return *this;
    }
};

class Writer {
    std::ostream &out;

public:
    Writer(std::ostream &out) : out(out) {
    }

    Writer &operator<<(int value) {
        printf("%d", value);
        return *this;
    }

    Writer &operator<<(string &value) {
        printf("%s", value.c_str());
        return *this;
    }

    Writer &operator<<(const char *value) {
        printf("%s", value);
        return *this;
    }

    Writer &newline() {
        printf("\n");
        return *this;
    }
};

#else

class Scanner {
    std::istream &in;

public:
    Scanner(std::istream &in) : in(in) {
    }

    template <class T> Scanner& operator >> (T &result) {
        in >> result;
        return *this;
    }
};

class Writer {
    std::ostream &out;

public:
    Writer(std::ostream &out) : out(out) {
    }

    template <class T> Writer& operator << (T value) {
        out << value;
        return *this;
    }

    Writer& newline() {
        out << endl;
        return *this;
    }
};
#endif

#endif

class QualBoomerang {
public:
    int testNumber = 0;

    void solve(std::istream &inStream, std::ostream &outStream) {
        testNumber++;
        Scanner in(inStream);
        Writer out(outStream);
        int n;
        in >> n;
        vector<pair<int, int>> points;
        repeat(n) {
            int x, y;
            in >> x >> y;
            points.push_back(make_pair(x, y));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto &p = points[i];
            vector<int> dst;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    auto &p2 = points[j];
                    dst.push_back((p2.second - p.second) * (p2.second - p.second) +
                                  (p2.first - p.first) * (p2.first - p.first));
                }
            }
            sort(dst.begin(), dst.end());
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j == (n - 1) || (dst[j] != dst[j - 1])) {
                    ans = ans + (cnt * (cnt - 1) / 2);
                    cnt = 0;
                }
                cnt++;

            }
        }

        out << "Case #" << testNumber << ": " << ans;
        out.newline();
    }
};


int main() {
    QualBoomerang solver;
    std::ifstream in("qualboomerang.in");
    std::ofstream out("qualboomerang.out");
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        solver.solve(in, out);
    }

    return 0;
}
