#include "config.h"
#include "Memory_ass.h"
void* operator new(size_t size)
{
	Memory::GetInstance().setAllocated(size);
	//std::cout << "freed " << size << " amount of bytes" << std::endl;
	return malloc(size);
}
void operator delete(void* memory, size_t size)
{
	Memory::GetInstance().setFreed(size);
	//std::cout << "freed " << size << " amount of bytes" << std::endl;
	free(memory);

}
void* operator new[](size_t size)
{
	Memory::GetInstance().setAllocated(size);
	//std::cout << "freed " << size << " amount of bytes" << std::endl;
	return malloc(size);
}
void operator delete[](void* memory, size_t size)
{
	Memory::GetInstance().setFreed(size);
	//std::cout << "freed " << size << " amount of bytes" << std::endl;
	free(memory);

}