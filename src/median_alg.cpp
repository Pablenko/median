#include <sstream>

#include "heap.hpp"
#include "median_alg.hpp"

static float calculate_current_median(min_heap& min_h, max_heap& max_h)
{
    if(min_h.size() == 0 and max_h.size() == 0)
    {
        return 0.0f;
    }
    else if(min_h.size() > max_h.size())
    {
        return static_cast<float>(min_h.top());
    }
    else if(min_h.size() < max_h.size())
    {
        return static_cast<float>(max_h.top());
    }
    else
    {
        return (static_cast<float>(min_h.top()) + static_cast<float>(max_h.top())) / 2.f;
    }
}

static void balance_heaps(min_heap& min_h, max_heap& max_h)
{
    if(min_h.size() > (max_h.size() + 1))
    {
        max_h.insert(min_h.pop());
        return;
    }
    if(max_h.size() > (min_h.size() + 1))
    {
        min_h.insert(max_h.pop());
    }
}

static void update_heaps(min_heap& min_h, max_heap& max_h, int value)
{
    if(min_h.size() == 0 and max_h.size() == 0)
    {
        min_h.insert(value);
    }
    else if(min_h.size() == 1 and max_h.size() == 0)
    {
        if(min_h.top() > value)
        {
            max_h.insert(value);
        }
        else
        {
            max_h.insert(min_h.pop());
            min_h.insert(value);
        }
    }
    else
    {
        float current_median = calculate_current_median(min_h, max_h);
        float f_value = static_cast<float>(value);

        if(current_median > f_value)
        {
            max_h.insert(value);
        }
        else if(current_median < f_value)
        {
            min_h.insert(value);
        }
        else
        {
            if(min_h.size() < max_h.size())
            {
                min_h.insert(value);
            }
            else
            {
                max_h.insert(value);
            }
        }
        balance_heaps(min_h, max_h);
    }
}

unsigned int median(const std::string& input, float* out)
{
    const char break_marker = 'm';
    const char end_marker = 'q';

    unsigned int results_size = 0;
    max_heap max_h(100);
    min_heap min_h(100);
    std::istringstream ss(input);

    while(ss)
    {
        if(ss.peek() == end_marker)
        {
            break;
        }
        else if(ss.peek() == break_marker)
        {
            out[results_size++] = calculate_current_median(min_h, max_h);
            ss.get();
        }
        else
        {
            int current_value = 0;
            ss >> current_value;
            update_heaps(min_h, max_h, current_value);
        }
    }
    return results_size;
}
