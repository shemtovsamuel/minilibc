/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strncmp.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

int (*my_strncmp)(const char *str1, const char *str2, size_t n);

Test(strncmp, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "toto";
    char *str2 = "toto";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strncmp = dlsym(handle, "strncmp");

	cr_assert(my_strncmp(str1, str2, 3) == strncmp(str1, str2, 3));
    cr_assert(my_strncmp(str2, str1, 4) == strncmp(str2, str1, 4));
    cr_assert(my_strncmp(str2, str1, 0) == strncmp(str2, str1, 0));
    cr_assert(my_strncmp(str2, str2, 2) == strncmp(str2, str2, 2));
    cr_assert(my_strncmp(str1, str1, 3) == strncmp(str1, str1, 3));
}

Test(strncmp, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "toto";
    char *str2 = "";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strncmp = dlsym(handle, "strncmp");

	cr_assert(my_strncmp(str1, str2, 10) == strncmp(str1, str2, 10));
    cr_assert(my_strncmp(str2, str2, 3) == strncmp(str2, str2, 3));
    cr_assert(my_strncmp(str1, str1, 9) == strncmp(str1, str1, 9));
    cr_assert(my_strncmp(str1, str2, 1) == strncmp(str1, str2, 1));
}
