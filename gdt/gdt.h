struct GDT
{
        unsigned short limit_0_15;
        unsigned short base_0_15;
        unsigned char base_16_23;
        unsigned char access;
        unsigned char granularity;  
        unsigned char base_24_31;  
} __attribute__((packed));
        
struct GDT_PTR
{
        unsigned short gdt_size;    
        struct GDT* gdt_addr;
} __attribute__((packed));  
        

