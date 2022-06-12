/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strcspn.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

size_t (*my_strcspn)(const char *str1, const char *str2);

Test(strcspn, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("toto");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }

    my_strcspn = dlsym(handle, "strcspn");

	cr_assert(my_strcspn(str, "t") == strcspn(str, "t"));
    cr_assert(my_strcspn(str, "st") == strcspn(str, "st"));
    cr_assert(my_strcspn(str, "") == strcspn(str, ""));
    cr_assert(my_strcspn(str, "tartiflette") == strcspn(str, "tartiflette"));
}
