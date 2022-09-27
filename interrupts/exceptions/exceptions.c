void exception_handler(int ex)
{
        char buf[4];
        itoa(ex, buf);
	kprint("An exception has occured.\n",12);
        kprint("exception ", 14);
        kprint(buf, 14);
        kprint("\n", 14);
        while(1);

}
