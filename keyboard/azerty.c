#define M -0x20*maj
char azerty2c(int keycode, int maj)
{
	switch(keycode)
	{
    		case 0x1E : return 'q'M; break;
    		case 0x30 : return 'b'M; break; 
    		case 0x2E : return 'c'M; break; 
    		case 0x20 : return 'd'M; break; 
    		case 0x12 : return 'e'M; break;
    		case 0x21 : return 'f'M; break;
    		case 0x22 : return 'g'M; break;
    		case 0x23 : return 'h'M; break;
    		case 0x17 : return 'i'M; break;
    		case 0x24 : return 'j'M; break;
    		case 0x25 : return 'k'M; break;
    		case 0x26 : return 'l'M; break; 
    		case 0x27 : return 'm'M; break;
    		case 0x31 : return 'n'M; break;
    		case 0x18 : return 'o'M; break;
    		case 0x19 : return 'p'M; break;
    		case 0x10 : return 'a'M; break;
    		case 0x13 : return 'r'M; break;
    		case 0x1F : return 's'M; break;
    		case 0x14 : return 't'M; break;
    		case 0x16 : return 'u'M; break;
    		case 0x2F : return 'v'M; break;
    		case 0x11 : return 'z'M; break;
    		case 0x2D : return 'x'M; break;
    		case 0x15 : return 'y'M; break;
    		case 0x2C : return 'w'M; break;
    		case 0x39 : return ' '; break;
		
    		case 0x02 : return '1'; break;
    		case 0x03 : return '2'; break;
    		case 0x04 : return '3'; break;
    		case 0x05 : return '4'; break;
    		case 0x06 : return '5'; break;
    		case 0x07 : return '6'; break;
    		case 0x08 : return '7'; break;
    		case 0x09 : return '8'; break;
    		case 0x0A : return '9'; break;
    		case 0x0B : return '0'; break;
    		case 0x32 : return ','; break;

    		case 0x3B : return '['; break;
    		case 0x44 : return ']'; break;
	}

}
