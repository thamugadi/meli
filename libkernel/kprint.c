#define SCREEN_LINES 25
#define LINE_SIZE 80

char *video_ram = (char*)0xB8000;

int screen_count = SCREEN_LINES;
int line_count = LINE_SIZE;

void kprint(char *text, char color)
{
        while (*text)
        {
                if (*text != '\n') 
                {
                        *video_ram = *text; 
                }

                video_ram++;
                *video_ram = color; 

                if (*text != '\n') 
                {
                        *video_ram++; 
                }
                else 
                {
                        video_ram += line_count*2 +1;
                        line_count = LINE_SIZE;
                        screen_count--;
                }

                text++;
                line_count--; 

                if (!screen_count) 
                {
                        free_vram();
                        video_ram = 0xB8000;
                        screen_count = SCREEN_LINES;
                }

                if (line_count < 0)
                {
                        line_count = LINE_SIZE;
                }
        }
}

void kbackline (void)
{
        video_ram += line_count*2+1;
        line_count = LINE_SIZE;
        screen_count--;
}

void knextpage()
{
        int l = 0;
        while (l < SCREEN_LINES)
        {
                kprint("\n", 0);
                l++;
        }
}
void free_vram()
{
        int video_ram_tmp = 0xB8000;
        while (video_ram_tmp++ < 0xBFFFF) *(unsigned char*)video_ram_tmp = 0x00; 
}
