#include "config.h"
#include "Memory_ass.h"
std::mutex mtx;

void* operator new(size_t size)
{
	mtx.lock();
	Memory::GetInstance().setAllocated(size);
	mtx.unlock();
	return malloc(size);
}
void operator delete(void* memory, size_t size)
{
	mtx.lock();
	Memory::GetInstance().setFreed(size);
	mtx.unlock();
	free(memory);
	
}
void* operator new[](size_t size)
{
	mtx.lock();
	Memory::GetInstance().setAllocated(size);
	mtx.unlock();
	return malloc(size);
}
void operator delete[](void* memory, size_t size)
{
	mtx.lock();
	Memory::GetInstance().setFreed(size);
	mtx.unlock();
	free(memory);
}