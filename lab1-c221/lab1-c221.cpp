// Практическое занятие 1
//std::forward, std::ref, variadic функции, folds


#include <vector>
#include <utility>
#include <string>
#include <type_traits>
#include <iostream>

using namespace std;

template<typename T> void fV(vector<T>& v) {
    for (auto& x : v) { ++x; }
}

template<typename U, typename T> void InsertUnique(vector<U>& v, T&& last)
{
    //U* d = dynamic_cast<U&>(last);
    if (is_convertible_v<U, T>)
    {
        T d = static_cast<T>(last);
        cout << d << endl;
        //if (find(v.begin(), v.end(), d) == v.end())
        //{
        //    cout << d<<endl;
        //    //v.push_back(d);
        //}
    }
}
template<typename U, typename T, typename... Types> void InsertUnique(vector<U>& v, T&& current, Types&&... rest)
{
    InsertUnique(v, forward<Types>(rest)...);
    InsertUnique(v, current);
}

int main()
{
    int a = 1, b = 2, c = 3;
    vector v = { ref(a),ref(b),ref(c) };
    fV(v); //в результате вызова fV a,b,c должны измениться!!!

    vector v1{ 4,7, 1 };
    InsertUnique(v1, 1.1, string("qwerty"), 5.2);
}
