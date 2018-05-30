/* Problem C - Round #273 - Div. 2
 * http://codeforces.com/problemset/problem/478/Cy
 *
 * SOLUTION OVERVIEW
 * The ideia is to take two balloons from the biggest color and 1 balloon from
 * the highest one between the two others left. From this, there are two
 * possibilities for the total number of set tables:
 *
 *  1) The number will be limited by the sum of the two lowest colors. For that,
 *     we need to have twice or more balloons of the biggest color than the sum
 *     of the two lowest colors.
 *
 *  2) The number will be equal to (r+g+b)/3. For that, note that at some point,
 *     maxcolor <= max(the two others). At this point, the difference between the
 *     biggest and lowest color will be <= 1 which only leads us to that groups
 *     of colors rgb, resulting in (r+g+b)%3 balloons wasted. Thus, we can give
 *     the answer as (r+g+b)/3
 *
 * For giving the correct answer, we get the minimum between these two situations.
 *
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll r, g, b;
  cin >> r >> g >> b;

  ll
    mn = min({r, g, b}),
    mx = max({r, g, b}),
    md = ((r+g+b) - mn) - mx;

  cout << min((r+g+b)/3, mn+md) << endl;

  return 0;
}
