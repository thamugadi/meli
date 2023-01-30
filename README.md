# mel
32-bit hobby kernel.
todo:

- memory allocation
- syscalls

Memory is divided as following:


|Memory region  | Address
|---------------|------------
|Kernel code    | ``0x00100000``
|Kernel data    | ``0x00200000``
|Kernel stack   | ``0x00800000``
|User data      | ``0x10000000``
|User code      | ``0x20000000``
|User stack     | ``0x28000000``

