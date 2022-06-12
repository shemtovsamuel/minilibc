/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strrchr.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

char *(*my_strrchr)(const char *str, int c);

Test(strrchr, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "test";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strrchr = dlsym(handle, "strrchr");

	cr_assert(my_strrchr(str, 't') == strrchr(str, 't'));
    cr_assert(my_strrchr(str, 'x') == strrchr(str, 'x'));
    cr_assert(my_strrchr(str, 'a') == strrchr(str, 'a'));
    cr_assert(my_strrchr(str, ' ') == strrchr(str, ' '));
}

Test(strrchr, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strrchr = dlsym(handle, "strrchr");

	cr_assert(my_strrchr(str, 'A') == strrchr(str, 'A'));
}

Test(strrchr, test3)
{
    char	*str = "toto";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strrchr = dlsym(handle, "strrchr");

    cr_assert(my_strrchr(str, 't') == strrchr(str, 't'));
    cr_assert(my_strrchr(str, 'x') == strrchr(str, 'x'));
	cr_assert(my_strrchr(str, '\0') == strrchr(str, '\0'));
}
