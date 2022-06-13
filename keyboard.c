unsigned char read_keyboard()
{
        unsigned char read;
        do {
                read = input(0x64);
        } while (!(read & 1));
        read = input(0x60); 
        return read;
}

unsigned char read_wait(){
        char read;
        while (1)
        {
                read = input(0x60);
                if (read > 0) return read;
        }
}
