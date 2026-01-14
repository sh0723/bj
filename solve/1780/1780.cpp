#include <iostream>
using namespace std;

int arr[2187][2187];
int cnt[3];
int n;

void run(int y, int x, int n);
bool check(int y, int x, int n);

int main() {


  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  run(0, 0, n);
  cout << cnt[0] << endl << cnt[1] << endl << cnt[2] << endl;

  return 0;
}

void run(int y, int x, int n) {
  if (check(y, x, n)) {
    if (arr[y][x] == -1)
      cnt[0]++;
    else if (arr[y][x] == 0)
      cnt[1]++;
    else
      cnt[2]++;

    return;
  }

  for (int i=y; i < y+n; i+=n/3) {
    for (int j=x; j < x+n; j+=n/3) {
      run(i, j, n/3);
    }
  }

}

bool check(int y, int x, int n) {
  int comp = arr[y][x];
  for (int i=y; i<y+n; i++) {
    for (int j=x; j<x+n; j++) {
      if (arr[i][j] != comp)
        return false;
    }
  }

  return true;
}