#include "defines.h"

class Complex {
    int real = 0;
    int imaginary = 0;

public:

    string to_str() const {
        stringstream ss;
        ss << real << "+" << imaginary << "i";
        return ss.str();
    }

    static Complex from_str(const string& str) {
        Complex ans;
        int plus = str.find('+');
        string real_str = str.substr(0, plus);
        string imag_str = str.substr(plus + 1, str.size() - 1);
        ans.real = stoi(real_str);
        ans.imaginary = stoi(imag_str);
        return ans;
    }

    Complex operator*(const Complex& ano) {
        Complex ans;
        ans.real = real * ano.real + imaginary * ano.imaginary * -1;
        ans.imaginary = real * ano.imaginary + imaginary * ano.real;
        return ans;
    }
};

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        return (Complex::from_str(num1) * Complex::from_str(num2)).to_str();
    }
};

int main() {
    Solution s;
    cout << s.complexNumberMultiply("1+-1i", "1+-1i") << endl;
}