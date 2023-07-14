#include <bits/stdc++.h>

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f;
const int linf = 0x3f3f3f3f3f3f3f3fll;

string n2s(char c, int i) {
  if (((i == 1) && (c == '1' || c == '2' || c == '5' || c == '8')) ||
      ((i == 2) && ((c == '2') || (c == '6') || (c == '9')))) {
    return "*.";
  } else if (((i == 1) && (c == '3' || c == '4' || c == '6' || c == '7')) ||
             ((i == 2) && (c == '7' || c == '8' || c == '0'))) {
    return "**";
  } else if (((i == 1) && (c == '9' || c == '0')) ||
             ((i == 2) && (c == '4' || c == '5'))) {
    return ".*";
  } else {
    return "..";
  }
}

string s2n(string lin1, string lin2) {
  string num;
  for (int i = 0; i < lin1.size(); i += 3) {
    if (lin1[i] == '*' && lin1[i + 1] == '.' && lin2[i] == '.' &&
        lin2[i + 1] == '.')
      num += '1';
    if (lin1[i] == '*' && lin1[i + 1] == '.' && lin2[i] == '*' &&
        lin2[i + 1] == '.')
      num += '2';
    if (lin1[i] == '*' && lin1[i + 1] == '*' && lin2[i] == '.' &&
        lin2[i + 1] == '.')
      num += '3';
    if (lin1[i] == '*' && lin1[i + 1] == '*' && lin2[i] == '.' &&
        lin2[i + 1] == '*')
      num += '4';
    if (lin1[i] == '*' && lin1[i + 1] == '.' && lin2[i] == '.' &&
        lin2[i + 1] == '*')
      num += '5';
    if (lin1[i] == '*' && lin1[i + 1] == '*' && lin2[i] == '*' &&
        lin2[i + 1] == '.')
      num += '6';
    if (lin1[i] == '*' && lin1[i + 1] == '*' && lin2[i] == '*' &&
        lin2[i + 1] == '*')
      num += '7';
    if (lin1[i] == '*' && lin1[i + 1] == '.' && lin2[i] == '*' &&
        lin2[i + 1] == '*')
      num += '8';
    if (lin1[i] == '.' && lin1[i + 1] == '*' && lin2[i] == '*' &&
        lin2[i + 1] == '.')
      num += '9';
    if (lin1[i] == '.' && lin1[i + 1] == '*' && lin2[i] == '*' &&
        lin2[i + 1] == '*')
      num += '0';
  }
  return num;
}

int main() {
  _ int d;
  char c;
  string num, lin1, lin2, lin3;
  while (1) {
    cin >> d;
    if (!d)
      break;

    cin >> c;

    if (c == 'S') {
      cin >> num;
      lin1 = "";
      lin2 = "";
      lin3 = "";
      for (int i = 0; i < num.size(); i++) {

        lin1 += n2s(num[i], 1);
        lin2 += n2s(num[i], 2);
        lin3 += n2s(num[i], 3);
        if (i != num.size() - 1) {
          lin1 += " ";
          lin2 += " ";
          lin3 += " ";
        }
      }
      cout << lin1 << endl << lin2 << endl << lin3 << endl;
    } else {
      getline(cin, lin1);
      getline(cin, lin1);
      getline(cin, lin2);
      getline(cin, lin3);
      num = s2n(lin1, lin2);
      cout << num << endl;
    }
  }
  return (0);
}
