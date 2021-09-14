#include "defines.h"

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec) {
    out << "[";
    for (int i = 0; i < vec.size(); i++) {
        auto& x = vec[i];
        if (i == vec.size() - 1) {
            out << x;
        } else {
            out << x << ", ";
        }
    }
    out << "]";
    return out;
}

template<typename T>
struct Test {
    using Func = T (*)(const char *, const char **);
    static void test(Func func, const char *input, T output) {
        std::cout << "test T=" << typeid(T).name() << " input=" << input << " output=" << func(input, &input) << " expect=" << output;
        std::cout << " next_char=" << *input << std::endl;
    }
};


int main() {
    Test<int>::test(getInt, "100a", 100);
    Test<int>::test(getInt, "-100b", -100);
    Test<int>::test(getInt, "  100c", 100);
    Test<int>::test(getInt, " -  100d", -100);

    Test<vector<int>>::test(getVectorOfInt, "[]a", {});
    Test<vector<int>>::test(getVectorOfInt, "[1]a", {1});
    Test<vector<int>>::test(getVectorOfInt, "[1,2  ,  - 3]a", {1, 2, -3});

    Test<vector<vector<int>>>::test(getVectorOfVectorOfInt, "[]a", {});
    Test<vector<vector<int>>>::test(getVectorOfVectorOfInt, "[[]]a", {{}});
    Test<vector<vector<int>>>::test(getVectorOfVectorOfInt, "[[1], [1, 2, 3]]a", {{1}, {1, 2, 3}});
    Test<vector<vector<int>>>::test(getVectorOfVectorOfInt, "[[-1], [1, 2, 3], []]a", {{-1}, {1, 2, 3}, {}});
}