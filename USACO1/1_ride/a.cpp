/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: lyndon91
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */


#include <stdio.h>
#include <ctype.h>

int hash(char *s)
{
    int i, h;

    h = 1;
    for(i=0; s[i] && isalpha(s[i]); i++)
        h = ((s[i]-'A'+1)*h) % 47;
    return h;
}

void main(void)
{
    FILE *in, *out;
    char comet[100], group[100];  /* bigger than necessary, room for newline */

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    fgets(comet, sizeof comet, in);
    fgets(group, sizeof group, in);

    if(hash(comet) == hash(group))
        fprintf(out, "GO\n");
    else
        fprintf(out, "STAY\n");
    exit (0);
}


