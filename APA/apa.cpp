#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_LEN = 1000;

void clear(vector<int> &a) {
    for (int i = 0; i < MAX_LEN; i++) {
        a[i] = 0;
    }
}

bool read(vector<int> &a) {
    cout << "Input a large number(type \"quit\" to exit): ";
    string s;
    cin >> s;
    if (s == "quit") {
        return true;
    }
    clear(a);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        a[n - i - 1] = s[i] - '0';
    }
    return false;
}

void print(const string msg, vector<int> &a) {
    int i;
    for (i = MAX_LEN - 1; i >= 1; i--) {
        if (a[i] != 0) {
            break;
        }
    }
    cout << msg;
    for (; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

// 高精度-高精度加法
void add(vector<int> &a, vector<int> &b, vector<int> &c) {
    clear(c);

    for (int i = 0; i < MAX_LEN - 1; i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i + 1]++;
            c[i] -= 10;
        }
    }
}

bool larger(vector<int> &a, vector<int> &b) {
    int la, lb;
    for (la = MAX_LEN; la > 0; la--) {
        if (a[la - 1] != 0) {
            break;
        }
    }
    for (lb = MAX_LEN; lb > 0; lb--) {
        if (b[lb - 1] != 0) {
            break;
        }
    }
    if (la != lb) {
        return la > lb;
    }
    for (--la; la >= 0; la--) {
        if (a[la] != b[la]) {
            return a[la] > b[la];
        }
    }
    return true;
}

// 高精度-高精度减法
bool sub(vector<int> &a, vector<int> &b, vector<int> &c) {
    if (!larger(a, b)) {
        sub(b, a, c);
        return true;
    }
    clear(c);

    for (int i = 0; i < MAX_LEN - 1; i++) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            c[i + 1]--;
            c[i] += 10;
        }
    }
    return false;
}

// 高精度-单精度乘法
void mul_short(vector<int> &a, vector<int> &b, vector<int> &c) {
    clear(c);

    for (int i = 0; i < MAX_LEN - 1; i++) {
        c[i] += a[i] * b[i];
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

// 高精度-高精度乘法
void mul(vector<int> &a, vector<int> &b, vector<int> &c) {
    clear(c);

    for (int i = 0; i < MAX_LEN - 1; i++) {
        for (int j = 0; j <= i; j++) {
            c[i] += a[j] * b[i - j];
        }
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

// 被除数a以下标last_dg为最低位，是否可以再减去除数b而保持非负
// lb是除数b的长度，避免反复计算
bool can_sub(vector<int> &a, vector<int> &b, int last_dg, int lb) {
    if (a[last_dg + lb] != 0) {
        return true;
    }
    for (int i = lb - 1; i >= 0; i--) {
        if (a[last_dg + i] != b[last_dg + i]) {
            return a[last_dg + i] > b[last_dg + i];
        }
    }
    return true;
}

// 高精度-高精度除法
// c为商，d为余数
void div(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
    clear(c);
    clear(d);

    // la: a的长度（不包括前导零）
    // lb: b的长度（不包括前导零）
    int la, lb;
    for (la = MAX_LEN; la > 0; la--) {
        if (a[la - 1] != 0) {
            break;
        }
    }
    for (lb = MAX_LEN; lb > 0; lb--) {
        if (b[lb - 1] != 0) {
            break;
        }
    }
    if (lb == 0) {
        cout << "除数不能为0" << endl;
        return;
    }

    for (int i = 0; i < la; i++) {
        d[i] = a[i];
    }
    for (int i = la - lb; i >= 0; i--) {
        while (can_sub(d, b, i, lb)) {
            for (int j = 0; j < lb; j++) {
                d[i + j] -= b[j];
                if (d[i + j] < 0) {
                    d[i + j] += 10;
                    d[i + j + 1]--;
                }
            }
            c[i]++;
        }
    }
}

int main() {
    vector<int> a(MAX_LEN), b(MAX_LEN);
    vector<int> c(MAX_LEN), d(MAX_LEN);

    while (true) {
        if (read(a)) {
            break;
        }
        if (read(b)) {
            break;
        }
        add(a, b, c);
        print("Add result: ", c);
        print(sub(a, b, c) ? "Sub result: -" : "Sub result: ", c);
        mul(a, b, c);
        print("Mul result: ", c);
        div(a, b, c, d);
        print("Div result: ", c);
    }

    return 0;
}