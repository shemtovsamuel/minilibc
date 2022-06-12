/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strchr.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

char *(*my_strchr)(const char *str, int c);

Test(strchr, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "test";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strchr = dlsym(handle, "strchr");

	cr_assert(my_strchr(str, 't') == strchr(str, 't'));
    cr_assert(my_strchr(str, 'x') == strchr(str, 'x'));
    cr_assert(my_strchr(str, 'a') == strchr(str, 'a'));
    cr_assert(my_strchr(str, ' ') == strchr(str, ' '));
}

Test(strchr, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strchr = dlsym(handle, "strchr");

	cr_assert(my_strchr(str, 'A') == strchr(str, 'A'));
}

Test(strchr, test3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "aaaazaazaaa";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strchr = dlsym(handle, "strchr");

	cr_assert(my_strchr(str, 'a') == strchr(str, 'a'));
    cr_assert(my_strchr(str, 'b') == strchr(str, 'b'));
}

Test(strchr, test4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "pppppppppppppppppppppppppppppppppppppp";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strchr = dlsym(handle, "strchr");

	cr_assert(my_strchr(str, 'p') == strchr(str, 'p'));
    cr_assert(my_strchr(str, 'o') == strchr(str, 'o'));
}

Test(strchr, test5)
{
    char	*str = "toto";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strchr = dlsym(handle, "strchr");

    cr_assert(my_strchr(str, 't') == strchr(str, 't'));
    cr_assert(my_strchr(str, 'x') == strchr(str, 'x'));
	cr_assert(my_strchr(str, '\0') == strchr(str, '\0'));
}