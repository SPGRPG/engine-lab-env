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
	static Memory* instance;
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;
	uint32_t CurrentUsage() { return totalAllocated - totalFreed; }
	
	
	Memory() {};
	~Memory() {};
public:
	Memory(const Memory&) = delete;
	Memory& operator=(const Memory&) = delete;
	static Memory* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Memory();
		}
		return instance;
	}
	
	
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
//Memory* Memory::instance = nullptr;
//extern Memory* main_memory;


