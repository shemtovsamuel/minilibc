/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strpbrk.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

char *(*my_strpbrk)(const char *str1, const char *str2);

Test(strpbrk, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "toto";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strpbrk = dlsym(handle, "strpbrk");

    cr_assert(my_strpbrk(str, str) == strpbrk(str, str));
	cr_assert(my_strpbrk(str, "ot") == strpbrk(str, "ot"));
	cr_assert(my_strpbrk(str, "t") == strpbrk(str, "t"));
    cr_assert(my_strpbrk(str, "") == strpbrk(str, ""));
	cr_assert(my_strpbrk("", "xylopohone") == strpbrk("", "xylopohone"));
	cr_assert(my_strpbrk("", "") == strpbrk("", ""));
	cr_assert(my_strpbrk("", "toto") == strpbrk("", "toto"));
}

Test(strpbrk, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str = "full stack";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strpbrk = dlsym(handle, "strpbrk");

    cr_assert(my_strpbrk(str, str) == strpbrk(str, str));
	cr_assert(my_strpbrk(str, "stack") == strpbrk(str, "stack"));
	cr_assert(my_strpbrk(str, "t") == strpbrk(str, "t"));
    cr_assert(my_strpbrk(str, "") == strpbrk(str, ""));
	cr_assert(my_strpbrk("", "xylopohone") == strpbrk("", "xylopohone"));
	cr_assert(my_strpbrk("full stack", "full stack") == strpbrk("full stack", "full stack"));
	cr_assert(my_strpbrk("aze", "toto") == strpbrk("aze", "toto"));
}
