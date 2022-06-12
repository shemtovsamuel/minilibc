/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_memcpy.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

void *(*my_memcpy)(void *dest, const void *src, size_t n);

Test(memcpy, test_memcpy1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("test");
	char *str2 = strdup("");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memcpy = dlsym(handle, "memcpy");

	cr_assert(my_memcpy(str, str2, 5) == memcpy(str, str2, 5));
}

Test(memcpy, test_memcpy2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("");
	char *str2 = strdup("test");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memcpy = dlsym(handle, "memcpy");

	cr_assert(my_memcpy(str, str2, 5) == memcpy(str, str2, 5));
}
