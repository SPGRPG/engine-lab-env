#pragma once
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <mutex>
//struct AllocationMetrics
//{
//	
//	
//	
//};
//static AllocationMetrics s_AllocationMetrics;

struct Memory
{
private:
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;
	uint32_t CurrentUsage() { return totalAllocated - totalFreed; }
	
	
	Memory() {};
	~Memory() {};
public:
	
	
	void setAllocated(const uint32_t& allocated)
	{
		this->totalAllocated += allocated;
		
	}
	void setFreed(const uint32_t& freed)
	{
		this->totalFreed += freed;
	}
	void PrintMemoryUsage()
	{
		std::cout << "Current Memory Usage: " << CurrentUsage() << " bytes\n";
	}

};
extern Memory* main_memory;


