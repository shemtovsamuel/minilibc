/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strcmp.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

int (*my_strcmp)(const char *str1, const char *str2);

Test(strcmp, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "toto";
    char *str2 = "toto";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strcmp = dlsym(handle, "strcmp");

	cr_assert(my_strcmp(str1, str2) == strcmp(str1, str2));
    cr_assert(my_strcmp(str2, str1) == strcmp(str2, str1));
    cr_assert(my_strcmp(str2, str2) == strcmp(str2, str2));
    cr_assert(my_strcmp(str1, str1) == strcmp(str1, str1));
}

Test(strcmp, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "toto";
    char *str2 = "";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strcmp = dlsym(handle, "strcmp");

	cr_assert(my_strcmp(str1, str2) == strcmp(str1, str2));
    cr_assert(my_strcmp(str2, str1) == strcmp(str2, str1));
    cr_assert(my_strcmp(str2, str2) == strcmp(str2, str2));
    cr_assert(my_strcmp(str1, str1) == strcmp(str1, str1));
}
