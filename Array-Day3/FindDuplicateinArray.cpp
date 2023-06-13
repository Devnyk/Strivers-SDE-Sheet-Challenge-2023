#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int prevSize = st.size();
        st.insert(arr[i]);
        if (st.size() == prevSize)
            return arr[i];
    }
    return -1;
}
