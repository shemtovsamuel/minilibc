/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_memmove.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

void *(*my_memmove)(void *dest, const void *src, size_t n);

Test(memmove, test_memmove1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("toto");
	char *str2 = strdup("tata");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memmove = dlsym(handle, "memmove");

	cr_assert(my_memmove(str, str2, 4) == memmove(str, str2, 4));
}

/*
Test(memmove, test_memmove2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("");
	char *str2 = strdup("test");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memmove = dlsym(handle, "memmove");

	cr_assert(my_memmove(str, str2, 5) == memmove(str, str2, 5));
}

Test(memmove, test_memmove3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = strdup("totototototototototo");
	char *str2 = strdup("titi");

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_memmove = dlsym(handle, "memmove");

	cr_assert(my_memmove(str, str2, 9) == memmove(str, str2, 9));
}
*/