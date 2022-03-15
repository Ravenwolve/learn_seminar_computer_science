//---------------0 - "¨ëî÷êà"
void print(int N, int k = 0) {
    if (k != N - 1) {
        for (int j = k; j < N; j++, cout << endl) {
            for (int i = 1; i < 2 * N; i++) {
                if (i >= N - j + k && i <= N + j - k)
                    cout << '*';
                else cout << '-';
            }
        }
    }
}
void rec(int N, int k = 0) {
    if (k < N) {
        rec(N, k + 1);
        print(N, k);
    }
}
//---------------1
bool operator<(BBall Ball2) {
    return w < Ball2.w;
}
bool operator>(BBall Ball2) {
    return w > Ball2.w;
}
bool operator==(BBall Ball2) {
    return w == Ball2.w && color == Ball2.color;
}
//----------------2
//...
public:
    BBall(const BBall& other) {
        w = other.w;
        color = other.color;
        n++;
    }
    BBall operator=(const BBall& other) {
        return other;
    }
//...
//---------------3
class triangle {
    double a, b, c;
public:
    triangle() :a(0), b(0), c(0) {}
    triangle(double i, double j, double k) {
        if (i > 0 && j > 0 && k > 0 && i + j > k && i + k > j && j + k > i) {
            a = i;
            b = j;
            c = k;
        }
    }
    void show() {
        cout << a << '\t' << b << '\t' << c;
    }
};
int main() {
    setlocale(LC_ALL, "Russian");
    double* A = new double[3];
    for (int i = 0; i < 3; i++, cin >> A[i])
        cout << "Ââåäèòå ñòîðîíó " << i + 1 << ": ";
    triangle Trg(A[1], A[2], A[3]);
    Trg.show();
}
//----------------4
//...
double P() {
    return a + b + c;
}
double S() {
    return sqrt(P() / 2 * (P() / 2 - a) * (P() / 2 - b) * (P() / 2 - c));
}
bool operator!=(triangle B) {
    return (S() != B.S() || a != B.a && a != B.b && a != B.c);
}
bool operator==(triangle B) {
    return (S() == B.S() && (a == B.a || a == B.b || a == B.c) && (b == B.a || b == B.b || b == B.c));
}
//...
//-----------------5
class triangle {
    double a, b, c;
public:
    static int count;
    triangle() :a(0), b(0), c(0) {}
    triangle(double i, double j, double k) {
        if (i > 0 && j > 0 && k > 0 && i + j > k && i + k > j && j + k > i) {
            a = i;
            b = j;
            c = k;
            if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
                count++;
        }
    }
};
int triangle::count = 0;
