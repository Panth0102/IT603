#include <iostream>
#include <vector>
using namespace std;

class NumberArray {
    vector<int> arr;
public:
    void input(int n) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    NumberArray& operator=(const NumberArray& other) {
        if (this != &other) {
            arr = other.arr;
        }
        return *this;
    }
    friend vector<int> twoSum(const NumberArray& obj, int target);
};

vector<int> twoSum(const NumberArray& obj, int target) {
    for (int i = 0; i < obj.arr.size(); i++) {
        for (int j = i + 1; j < obj.arr.size(); j++) {
            if (obj.arr[i] + obj.arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    int n, target;
    cin >> n;
    NumberArray obj;
    obj.input(n);
    cin >> target;
    vector<int> result = twoSum(obj, target);
    cout << result[0] << " " << result[1];
    return 0;
}
