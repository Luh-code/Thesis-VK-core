#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include <iostream>

// Credit to TheCherno (https://www.youtube.com/channel/UCQ-W1KE9EYfdxhL6S4twUNw) for the memory management code shown here

struct MemoryMetrics
{
    size_t totalAllocated = 0;
    size_t totalFreed = 0;
    size_t currentUsage() { return totalAllocated - totalFreed; }
};

static MemoryMetrics memoryMetrics;

void* operator new(size_t size)
{
    memoryMetrics.totalAllocated += size;
    //std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void operator delete(void* p, size_t size)
{
    memoryMetrics.totalFreed+=size;
    //std::cout << "Deleting " << size << " bytes\n";
    free(p);
}

static void printMemoryUsage()
{
    std::cout << "Current Heap Memory Usage: " << memoryMetrics.currentUsage() << " Bytes\n";
}

// ----------------------------------------------------

// Vulkan memory allocation



#endif // MEMORY_H