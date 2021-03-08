#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

#define LEN 27

int serialCheck(char *serial)
{
    int pos = 12;
    if (strncmp(serial + pos, "1337", 4) == 0) {
        pos += 5;
        if (strncmp(serial + pos, "dead", 4) == 0)
        {
            pos += 5;
            if (strncmp(serial + pos, "beef", 4) == 0) return 1;
            else return 0;
        }
        else return 0;
    }
	else return 0;
}


bool reg_matches(const char *str, const char *pattern)
{
    regex_t re;
    int ret;

    if (regcomp(&re, pattern, REG_EXTENDED) != 0)
        return false;

    ret = regexec(&re, str, (size_t) 0, NULL, 0);
    regfree(&re);

    if (ret == 0)
        return true;

    return false;
}

bool format(char *serial)
{
    static const char *pattern = "ShaastraCTF\\{.*{4}_.*{4}_.*{4}}";

    if (reg_matches(serial, pattern)) return 1;
    else return 0;
}

int main(int argc, char *argv[])
{
    char serial[LEN];

    printf("Please enter serial\n");

    fgets(serial, LEN+1, stdin);

    if (format(serial)) {
		if (serialCheck(serial))
	             printf("Serial is correct\n");
		else
	             printf("Incorrect serial\n");
    }
    else
        printf("The serial must be in the format of ShaastraCTF{XXXX_XXXX_XXXX}\n");
}
