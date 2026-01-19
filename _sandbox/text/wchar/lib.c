#define _XOPEN_SOURCE_EXTENDED
#include <locale.h>
#include <wchar.h>
#include <errno.h>
#include <string.h>

void minilib_init_locale()
{
    setlocale(LC_ALL, "");
}

struct locale_category_def {
    const char* name;
    int category;
} locale_category_defs[] = {
    { "LC_ALL", LC_ALL },
    { "LC_COLLATE", LC_COLLATE },
    { "LC_CTYPE", LC_CTYPE },
    { "LC_MESSAGES", LC_MESSAGES },     // POSIX.1
    { "LC_MONETARY", LC_MONETARY },
    { "LC_NUMERIC", LC_NUMERIC },
    { "LC_TIME", LC_TIME },
};

int _find_category(const char* name) {
    for (int i = 0; i < sizeof(locale_category_defs) / sizeof(locale_category_defs[0]); i++) {
        if (strcmp(locale_category_defs[i].name, name) == 0) {
            return locale_category_defs[i].category;
        }
    }
    errno = EINVAL;
    return -1;
}

const char* minilib_set_locale(const char* category_name, const char* value)
{
    errno = 0;

    int category = _find_category(category_name);

    if (errno != 0) {
        return NULL;
    }

    char* ret = setlocale(category, value);
    if (ret == NULL) {
        //errno = EINVAL;
        return NULL;
    }
    return ret;
}
