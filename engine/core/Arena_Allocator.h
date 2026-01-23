#pragma once
#include <cstddef>
#include <new>
#include <memory>
#include <iostream>
#include <string>
class Arena {

private:
    char* buffer_;           // Start of the allocated memory block
    std::size_t capacity_;   // Total size of the block
    std::size_t offset_;     // Current allocation offset
public:
    // Constructor: allocate a raw memory block of given size
    explicit Arena(std::size_t size)
        : buffer_(static_cast<char*>(::operator new(size))),
        capacity_(size), offset_(0) {
    }

    // Destructor: free the memory block
    ~Arena() {
        ::operator delete(buffer_);
    }

    // Allocate memory of `size` bytes with specified `alignment`
    void* allocate(std::size_t size, std::size_t alignment) {
        char* current_ptr = buffer_ + offset_;
        std::size_t space = capacity_ - offset_;
        void* aligned_ptr = current_ptr;

        // Align the ptr to the specified alignment
        if (std::align(alignment, size, aligned_ptr, space) == nullptr) {
            throw std::bad_alloc();
        }

        // Bump the offset of the arena
        offset_ = static_cast<char*>(aligned_ptr) - buffer_ + size;

        return aligned_ptr;
    }

    // Reset arena to reuse the memory block from the start
    void reset() {
        offset_ = 0;
    }
    void provide_capacity()
    {
		std::cout << "Arena capacity: " << capacity_ << " bytes\n";
    }
    void print_offset()
    {
		std::cout << "Arena current offset: " << offset_ << " bytes\n";
    }
    void print_remaining_space()
    {
		std::cout << "Arena remaining space: " << (capacity_ - offset_) << " bytes\n";
    }
    void print_block_adress()
    {
        std::cout << "Arena current block adress: " << &buffer_ << " \n";
    }


    // Non-copyable, non-movable type
    Arena(const Arena&) = delete;
    Arena(Arena&&) = delete;


};
struct random_class
{
    int x;
    int y;
};