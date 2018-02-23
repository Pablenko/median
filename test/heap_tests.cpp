#include <gtest/gtest.h>

#include "heap.hpp"

TEST(heap_tests, heap_size)
{
	min_heap h(10);

	EXPECT_EQ(0, h.size());

	h.insert(1);
	h.insert(2);

	EXPECT_EQ(2, h.size());

	h.pop();

	EXPECT_EQ(1, h.size());
}

TEST(heap_tests, min_heap)
{
	min_heap h(10);

	h.insert(1);
	h.insert(2);
	h.insert(3);

	EXPECT_EQ(1, h.top());
}

TEST(heap_tests, max_heap)
{
	max_heap h(10);

	h.insert(1);
	h.insert(2);
	h.insert(3);

	EXPECT_EQ(3, h.top());
}

TEST(heap_tests, pop)
{
	max_heap h(10);

	h.insert(1);
	h.insert(2);
	h.insert(3);

	EXPECT_EQ(3, h.pop());
	EXPECT_EQ(2, h.top());
}

TEST(heap_tests, pop_1_elem)
{
	max_heap h(10);

	h.insert(1);

	EXPECT_EQ(1, h.pop());
	EXPECT_EQ(0, h.size());
}

TEST(heap_tests, maintain_size)
{
	max_heap h(1);

	h.insert(1);
	h.insert(2);

	EXPECT_EQ(1, h.size());
	EXPECT_EQ(1, h.top());
}
