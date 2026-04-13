#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void median() {
    int m, n;

    cin >> m;
    vector<int> num1(m);
    for (int i = 0; i < m; i++) {
        cin >> num1[i];
    }

    cin >> n;
    vector<int> num2(n);
    for (int i = 0; i < n; i++) {
        cin >> num2[i];
    }

    // declaire merge array
    vector<int> merge;
    merge.reserve(m + n);

    // merge 2 arrays
    int i = 0, j = 0;
    while (i < m && j < n) {
        if(num1[i] < num2[j]) {
            merge.push_back(num1[i]);
            i++;
        } else {
            merge.push_back(num2[j]);
            j++;
        }
    }
    while (i < m) {
        merge.push_back(num1[i]);
        i++;
    }
    while (j < n) {
        merge.push_back(num2[j]);
        j++;
    }
    
    // count median
    // m + n is even
    if ((m + n) % 2 == 0) {
        double m1 = merge[((m+n)/2)-1];
        double m2 = merge[(m+n)/2];
        cout << (m1 + m2) / 2.0 << endl;
    } else {
        double m = merge[((m+n)/2)+1];
        cout << m << endl;
    }
}
int main() {
    int k;
    cin >> k;
    while (k--) {
        median();
    }
}