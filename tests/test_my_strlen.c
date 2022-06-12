/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

size_t (*my_strlen)(const char *str);

Test (strlen, test_strlen1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "Hello, World !";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strlen = dlsym(handle, "strlen");

    cr_assert(my_strlen(str) == strlen(str));
}

Test (strlen, test_strlen2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strlen = dlsym(handle, "strlen");

    cr_assert(my_strlen(str) == strlen(str));
}
