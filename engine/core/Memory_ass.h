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

class Memory
{
private:
	static Memory* instance;
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;
	uint32_t CurrentUsage() { return totalAllocated - totalFreed; };
	
	
	Memory()=default;
	
public:
	Memory(const Memory&) = delete;
	//Memory& operator=(const Memory&) = delete;
	static Memory &GetInstance()

	{
		static Memory instance;
		return instance;
	}
	
	
	void setAllocated(const uint32_t& allocated)
	{
		totalAllocated += allocated;
		
	}
	void setFreed(const uint32_t& freed)
	{
		totalFreed += freed;
	}
	void PrintMemoryUsage()
	{
		std::cout << "total allocated: " << totalAllocated << " bytes\n";
		std::cout << "total freed: " << totalFreed << " bytes\n";
		std::cout << "Current Memory Usage: " << CurrentUsage() << " bytes\n";
	}

};





