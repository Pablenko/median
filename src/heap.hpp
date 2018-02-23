#ifndef HEAP_HPP
#define HEAP_HPP

bool less(int a, int b)
{
	return a < b;
}

bool greater(int a, int b)
{
	return a > b;
}

template<bool compare(int, int)>
struct heap
{
	explicit heap(unsigned int capacity) : capacity(capacity), data(new int[capacity]), size_(0) {}

	~heap() { delete[] data; }

	void insert(int value)
	{
		if(size_ < capacity)
		{
			data[size_++] = value;
			heapify(0);
		}
	}

	int pop()
	{
		if(size_ > 0)
		{
			int popped = data[0];
			data[0] = data[size_ - 1];
			size_--;
			heapify(0);
			return popped;
		}
		else
		{
			return 0;
		}
	}

	int top() { return size_ > 0 ? data[0] : 0; }

	int size() { return size_; }

private:
	unsigned int parent(unsigned int i) { return (i-1)/2; }

	unsigned int left(unsigned int i) { return i*2 + 1; }

	unsigned int right(unsigned int i) { return i*2 + 2; }

	void heapify(unsigned int pos)
	{
        unsigned int l = left(pos);
        unsigned int r = right(pos);
        unsigned int change_pos = 0;

        if( (l <= size_ - 1) and compare(data[l], data[pos]) )
        {
        	change_pos = l;
        }
        else
        {
        	change_pos = pos;
        }

        if( (r <= size_ - 1) and compare(data[r], data[change_pos]) )
        {
        	change_pos = r;
        }

        if(change_pos != pos)
        {
            int temp = data[pos];
            data[pos] = data[change_pos];
            data[change_pos] = temp;
        	heapify(change_pos);
        }
	}

	const unsigned int capacity;
    int* data;
    unsigned int size_;
};

typedef heap<less> min_heap;

typedef heap<greater> max_heap;

#endif
