#include <string>

using namespace std;

string add(string a, string b) {
  a = string(max(a.size(), b.size()) + 1 - a.size(), '0') + a;
  b = string(a.size() - b.size(), '0') + b;
  for (int i = a.size() - 1, carry = 0; i >= 0; --i){
    int sum = a[i] + b[i] - 96 + carry;
    carry = sum / 10;
    a[i] = sum % 10 + '0';
  }
  int pos = a.find_first_not_of('0');
  return 0 <= pos? a.substr(pos): a.substr(0,1);
}