/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strstr.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

char *(*my_strstr)(const char *str1, const char *str2);

Test(strstr, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("hello, my name is Samuel");
	char *str2 = strdup("is");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}


Test(strstr, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("toto");
	char *str2 = strdup("");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}

Test(strstr, test3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("bobobobobobobobobobo");
	char *str2 = strdup("o");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}

Test(strstr, test4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("");
	char *str2 = strdup("");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}

Test(strstr, test5)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("cornichon");
	char *str2 = strdup("clavier");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}

Test(strstr, test6)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = strdup("pomme de terre");
	char *str2 = strdup("terre");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strstr = dlsym(handle, "strstr");

    cr_assert(my_strstr(str1, str2) == strstr(str1, str2));
    cr_assert(my_strstr(str1, str1) == strstr(str1, str1));
}