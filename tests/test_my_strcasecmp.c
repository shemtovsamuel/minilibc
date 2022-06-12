/*
** EPITECH PROJECT, 2022
** B-ASM-400-PAR-4-1-asmminilibc-samuel.shemtov
** File description:
** test_my_strcasecmp.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

int (*my_strcasecmp)(const char *str1, const char *str2);

Test(my_strcasecmp, test1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "toto";
    char *str2 = "";
    char *str3 = "TOTO";
    char *str4 = "toTo";
    char *str5 = "POopdzdzidjzedzedzd";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strcasecmp = dlsym(handle, "strcasecmp");

    cr_assert(strcasecmp(str1, str2) == my_strcasecmp(str1, str2));
    cr_assert(strcasecmp(str3, str4) == my_strcasecmp(str3, str4));
    cr_assert(strcasecmp(str4, str2) == my_strcasecmp(str4, str2));
    cr_assert(strcasecmp(str1, str3) == my_strcasecmp(str1, str3));
    cr_assert(strcasecmp(str4, str1) == my_strcasecmp(str4, str1));
    cr_assert(strcasecmp(str5, str3) == my_strcasecmp(str5, str3));
    cr_assert(strcasecmp(str2, str2) == my_strcasecmp(str2, str2));
}

Test(my_strcasecmp, test2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *str1 = "BONJOUR";
    char *str2 = "ONjour";
    char *str3 = "iiiiiiiiiii";
    char *str4 = "bonjour";
    char *str5 = "bonjurazez";

    if (!handle) {
    write(2, "./libasm.so: Not found\n", 23);
        return;
    }
    my_strcasecmp = dlsym(handle, "strcasecmp");

    cr_assert(strcasecmp(str1, str2) == my_strcasecmp(str1, str2));
    cr_assert(strcasecmp(str3, str4) == my_strcasecmp(str3, str4));
    cr_assert(strcasecmp(str4, str2) == my_strcasecmp(str4, str2));
    cr_assert(strcasecmp(str1, str3) == my_strcasecmp(str1, str3));
    cr_assert(strcasecmp(str4, str1) == my_strcasecmp(str4, str1));
    cr_assert(strcasecmp(str5, str3) == my_strcasecmp(str5, str3));
    cr_assert(strcasecmp(str2, str2) == my_strcasecmp(str2, str2));
    cr_assert(strcasecmp(str1, str4) == my_strcasecmp(str1, str4));
    cr_assert(strcasecmp(str4, str1) == my_strcasecmp(str4, str1));
}
