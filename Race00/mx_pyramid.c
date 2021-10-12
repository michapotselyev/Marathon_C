void mx_printchar(char);

void mx_pyramid(int n)
{
    int space = n;
    int aside = n;
    int bottom_edge = n / 2;
    int front_edge = 2 * n - 3;
    int in_space = front_edge;
    
    if(n < 1 || n % 2 != 0)
    {
        return;
    }
    else
    {
        //START OF PYRAMID
        for(int i = 1;  i < space; i++)
        {
            mx_printchar(' ');
        }
        mx_printchar('/');
        mx_printchar('\\');
        mx_printchar('\n');

        for(int i = 0; aside - 1 != 0; i++)
        {
            for(int k = 2; k < aside; k++)
            {
                mx_printchar(' '); 
            }
            mx_printchar('/');
            if(aside == 2)
            {
                for(int k = -1; k < i + (in_space - (in_space - i)); k++)
                {
                    mx_printchar('_');
                }
            }
            else
            {
                for(int k = -1; k < i + (in_space - (in_space - i)); k++)
                {
                    mx_printchar(' ');
                }
            }
            mx_printchar('\\');
            if(space >= (n / 2) + 2)
            {
                for(int k = -1; k < i - k + (in_space - (in_space - i)); k++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('\\');
            }
            else
            {
                for(int k = 0; k < bottom_edge * 2 - i - 2 ; k++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('|');
            }
            mx_printchar('\n');
            aside--;
            space--;
        }
        //END OF PYRAMID
    }
}

