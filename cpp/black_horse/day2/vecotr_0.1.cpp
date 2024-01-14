#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int>& v)
{
    for (vector<int>::iterator cur = v.begin(); cur < v.end(); cur++) {
        cout << *cur << endl;
    }
}

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    // 方式一
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);

    // 方式二
    vector<int> v1(v.begin(), v.end());
    printVector(v1);

    // 方式三
    vector<int> v2(v1);
    printVector(v2);

    // 方式四
    vector<int> v3(10, 100);
    printVector(v3);
}