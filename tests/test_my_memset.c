/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_memset.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

void *(*my_memset)(void *ptr, int value, size_t n);

Test(memset, test_memset)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = malloc(100);

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memset = dlsym(handle, "memset");

    cr_assert(my_memset(str, '0', 100) == memset(str, '0', 100));
    free(str);
}