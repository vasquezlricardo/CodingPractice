#include <iostream>
#include <deque>

using namespace std;

template<typename T>
struct Stack
{

    void push(T const& e)
    {
        mValues.emplace_back(e);

        if(mValues.size() == 1)
        {
            /* If the stack was empty, the new element is the min one */
            mMinValues.emplace_back(e);
        }
        else
        {
            /* otherwise, we will add it to the min list only if it is lower than the last min registered. */

            if(e <= mMinValues.back())
                mMinValues.emplace_back(e);
        }
    }

    T pop()
    {
        if(mValues.size() > 0)
        {
            if(mValues.back() == mMinValues.back())
                mMinValues.pop_back();
            auto result = mValues.back();
            mValues.pop_back();
            return result;
        }
        return T();
    }

    T min() const
    {
        return mMinValues.back();
    }

    deque<T> mValues;
    deque<T> mMinValues;
};

int main()
{

    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(-1);

    cout << s.min() << endl;
    s.pop();

    cout << s.min() << endl;
    return 0;
}
