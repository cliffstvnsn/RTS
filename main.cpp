#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<string, int> aboveBelow(const vector<int>& list, int comparison) {
        unordered_map<string, int> result = { {"above", 0}, {"below", 0} };
        for (int num : list) {
            if (num > comparison) {
                result["above"]++;
            } else if (num < comparison) {
                result["below"]++;
            }
        }
        return result;
    }

    string stringRotation(const string& original, int rotation) {
        int len = original.length();
        if (len == 0) return "";
        rotation = rotation % len; // Handle rotation larger than string length
        return original.substr(len - rotation) + original.substr(0, len - rotation);
    }
};

int main() {
    Solution sol;
    vector<int> list;
    int comparison;
    string original;
    int rotation;

    // Input for aboveBelow function
    cout << "Enter the size of the list: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < size; ++i) {
        int element;
        cin >> element;
        list.push_back(element);
    }
    cout << "Enter the comparison value: ";
    cin >> comparison;

    auto result = sol.aboveBelow(list, comparison);
    cout << "above: " << result["above"] << ", below: " << result["below"] << endl;

    // Input for stringRotation function
    cout << "Enter the original string: ";
    cin >> original;
    cout << "Enter the rotation amount: ";
    cin >> rotation;

    string rotated = sol.stringRotation(original, rotation);
    cout << "Rotated string: " << rotated << endl;

    return 0;
}
