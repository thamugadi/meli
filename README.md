# mel
32-bit hobby kernel.

![Screenshot](https://imgur.com/fRMQ87i)

It aims to implement the basic features of a kernel: paging, usermode, basic syscalls, scheduling.


For the moment there is little interaction that is possible. I will try to implement a shell when the rest is a bit more developed.


The memory is subdivided in this way for programs loaded in user mode:


|Memory region  | Address
|---------------|------------
|Kernel code    | ``0x00100000``
|Kernel data    | ``0x00200000``
|Kernel stack   | ``0x00800000``
|User data      | ``0x10000000``
|User code      | ``0x20000000``
|User stack     | ``0x28000000``

