# The Tale of Malloc

Dynamic memory allocation is the method for obtaining chunks of memory for loading and storing data during execution time of a program. The programmer informs a specific size of memory he wants and receives a reference to it. Also, obtained memory lives in the *heap*, outliving the lifetime of any other functions called along the program.

In the C language, `malloc` is the function responsible for dynamic memory allocation. As expected, it receives a specific number of bytes as an argument and returns a `void` pointer to the requested portion of memory or a `null` pointer, indicating an error due to insufficient available memory or some other issue.

However, `malloc` is a function from the C standard library, therefore a user space function, constrained to the process memory area, defined by the kernel. For accomplishing its goal, `malloc` must sweep this memory area, searching for an appropriate space and if it cannot obtain such space, it must interact with the kernel to properly extend the process heap space and obtain the desired memory. In order to fully comprehend this process, let's reexamine how the kernel assign a memory area to the process.

## Physical vs. Virtual Memory
Each process running in Linux sees an abstraction of the physical memory, implemented by the kernel, called **virtual memory**. Hence, the process memory is comprised in a limited range, the **virtual address space**, defined by the machine architecture. For exemple, in 32-bit machines, such size is always defined as 4GB, when in 64 bit processors such space varies according. Moreover, the kernel also reserve some portion of this space for his own use.

The translations between virtual and physical addresses happen along programs execution, aided by the process **page table**. For that, both virtual and physical memory are divided into blocks called **pages**, both having the same size and being in power of 2, for obvious simplicity reasons. In this manner, anytime a process tries to operate its memory, the computer processor will use the process' page table to correctly translate

The Linux kernel describe each process as a `task_struct` instance, a struct that contains several information information about each process running in the machine. One of these pieces of data is the `mm` field, a pointer to struct `mm_struct`, which describes
