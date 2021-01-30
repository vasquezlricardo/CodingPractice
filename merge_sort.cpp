#include <vector>
#include <iostream>
#include <string>

using namespace std;

void rec_m_sort(vector<int>& v, int beg, int end)
{
    if(end - beg < 2)
        return;

    int mid = (beg + end) / 2;

    /* Sorting the two halves */
    rec_m_sort(v, beg, mid);
    rec_m_sort(v, mid, end);

    /* Merging the two halves */

    while(beg != mid)
    {
        if(v[beg] > v[mid])
        {
            std::swap(v[beg], v[mid]);
            ++beg;
        }
    }
}

void implace_merge_sort(vector<int>& v)
{
    return rec_m_sort(v, 0, v.size());
}
int main()
{

    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; ++i)
        cin >> numbers[i];

    implace_merge_sort(numbers);

    for(auto n : numbers)
        cout << n << endl;
    return 0;
}
