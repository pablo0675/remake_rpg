#include "my_rpg.h"
#include <unistd.h>

int main(int ac, char **av, char **env)
{
    write(1, "Hello World\n", 12);
    return 0;
}
