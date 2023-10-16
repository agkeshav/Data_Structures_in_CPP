#include <bits/stdc++.h>
using namespace std;

// segment tree for finding the maximum for given ranges
int seg[4 * 100005];
void build(int ind, int low, int high, vector<int> &v)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, v);
    build(2 * ind + 2, mid + 1, high, v);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return INT_MIN;

    int mid = low + (high - low) / 2;
    int left = query(ind, low, mid, l, r);
    int right = query(ind, mid + 1, high, l, r);
    return max(left, right);
}
void pointUpdate(int ind, int low, int high, int node, int val)
{
    if (low == high)
    {
        seg[ind] = max(seg[ind], val);
        return;
    }
    else
    {
        int mid = low + (high - low) / 2;
        if (node >= low && node <= mid)
        {
            pointUpdate(2 * ind + 1, low, mid, node, val);
        }
        else
        {
            pointUpdate(2 * ind + 2, mid + 1, high, node, val);
        }
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
}
// l->r ->range to increase the value with val
void rangeUpdate(int ind, int low, int high, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {

        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
        return 0;

    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }
    int mid = low + (high - low) / 2;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    build(0, 0, n - 1, v);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = query(0, 0, n - 1, l, r);
        cout << ans << endl;
    }
    return 0;
}