#pragma once
#include <cstdint>
#include <cstdlib>
#include <iostream>
struct AllocationMetrics
{
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;
	uint32_t CurrentUsage() { return totalAllocated - totalFreed; }
	
};
static AllocationMetrics s_AllocationMetrics;
void* operator new(size_t size,AllocationMetrics s_AllocationMetrics)
{
	s_AllocationMetrics.totalAllocated += size;
	return malloc(size);
}
void operator delete(void* memory, size_t size,AllocationMetrics s_AllocationMetrics)
{
	s_AllocationMetrics.totalFreed += size;
	free(memory);
}

static void PrintMemoryUsage()
{
	std::cout << "Current Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}


