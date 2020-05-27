/*
LANG: C++
TASK: probe1d
*/
#include <cstdio>
#include "probelib.h"

int main()
{
    int end = probe_init() - 1;
    int start = 0;
    while (1)
    {
        if (start == end)
        {
            probe_answer(start);
            return 0;
        }
        else
        {
            int mid = (end + start) / 2;
            if (probe_check(start,mid))
                end = mid;
            else
                start = mid + 1;
        }
    }
}