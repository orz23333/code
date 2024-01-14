#include "my_vector.h"

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    print_vec(v);

    v.pop_back();
    print_vec(v);

    // 边遍历，边删除出现报错
    // for (vector<int>::iterator cur = v.begin(); cur < v.end(); cur++) {
    //     if (*cur / 2 == 0) {
    //         v.insert(cur, 22);
    //     }

    //     if (*cur == 5) {
    //         v.insert(cur, 3, 233);
    //     }

    //     if (*cur == 9) {
    //         v.erase(cur);
    //     }
    // }
    print_vec(v);

    v.erase(v.begin(), --v.end());
    print_vec(v);

    v.clear();
    print_vec(v);
}