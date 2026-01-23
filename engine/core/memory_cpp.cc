#include "config.h"
#include "Memory_ass.h"
void* operator new(size_t size)
{
	Memory::GetInstance().setAllocated(size);
	return malloc(size);
}
void operator delete(void* memory, size_t size)
{
	Memory::GetInstance().setFreed(size);
	free(memory);

}
void* operator new[](size_t size)
{
	Memory::GetInstance().setAllocated(size);
	return malloc(size);
}
void operator delete[](void* memory, size_t size)
{
	Memory::GetInstance().setFreed(size);
	free(memory);

}