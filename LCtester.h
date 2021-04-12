#include <functional>
#include <tuple>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

class Utils {
public:
static std::vector<std::string> split_top(const std::string str) {
        vector<string> ans;
        auto it = str.begin();
        stack<char> st;
        while (it != str.end()) {
            if (*it == '[' || *it == '"') 
                st.push(*it);
            else if (*it == ']' || *it == '"') {
                if (*it == st.top())
                    st.pop();
                else {
                    cerr << *it << " not match stack top " << st.top << endl;
                }
            }
            if (st.size() == 0) {
                auto e = std::find(it, str.cend(), ',');
                ans.emplace_back(it, e);
                if (e == str.cend())
                    break;
                it = e + 1;
            } else {
                it++;
            }
        }
        return ans;
    }
};

template <typename _Res, typename... _ArgTypes>
class Tester {
private:
    template <typename T> struct type {};

    std::function<_Res(_ArgTypes...)> _F;
    std::tuple<_ArgTypes...> params;
    std::string path;
    std::vector<std::string> in_s, out_s;
    std::vector<std::vector<std::string>> in_sp;
public:
    Tester(const std::string& path): path(path) {
        using namespace std;
        string test_case_path = path.substr(0, path.find_last_of('.')) + ".txt";
        ifstream test_case(test_case_path);
        string buff;
        
        while (test_case >> buff) {
            if (buff.size() == 0)
                continue;
            in_s.emplace_back(buff);
            in_sp.emplace_back(Utils::split_top(buff));
            if (test_case >> buff)
                out_s.emplace_back(buff);
            else
                break;
        }
        cout << "Load " << in_s.size() << " test cases from " << test_case_path << endl;
        if (in_s.size() != out_s.size()) {
            cout << "test cases are not paired." << endl;
            in_s.clear();
            out_s.clear();
        }
    }

    template<typename... Args>
    void make_all_param(int test_case, Args... args) {
        params = make_tuple(make_param(in_sp[args], type<typename tuple_element<args, params>>())...);
    }

    void test() {
        for (int i = 0; i < sizeof...(_ArgTypes); i++) {

        }
    }

    // template <typename T>
    // int make_param(std::string::iterator& it, const std::string::iterator end, type<T>) {
    //     T::unimplemented_function;
    //     return 0;
    // }

    std::string make_param(std::string& str, type<std::string> t) {
        return make_param(str.begin(), str.end(), t);
    }

    std::string make_param(
        std::string::iterator& it, 
        const std::string::iterator end, 
        type<std::string> t)
    {
        if (*it != '"')
            throw("try to parse string but not starts with \"");
        *it++;
        std::string::iterator s = it;
        while (it != end && *it != '"')
            it++;
        if (it == end)
            throw("string meets end but no \"");
        return std::string(s, it);
    }
};

#define TEST Tester(__FILE__)
