#include "libasm.h"
#include "test1.c"

void test_ft_strcmp(void)
{
    char *s1;
    char *s2;

    s1 = "";
    s2 = "";
    if (strcmp(s1, s2) != ft_strcmp(s1, s2))
        printf("zero");
    s1 = "qwe";
    s2 = "";
    if (strcmp(s1, s2) != ft_strcmp(s1, s2))
        printf("qwe");
    s1 = "";
    s2 = "qwe";
    if (strcmp(s1, s2) != ft_strcmp(s1, s2))
        printf("qwe2");
    s1 = "123";
    s2 = "qwe";
    if (strcmp(s1, s2) != ft_strcmp(s1, s2))
        printf("not equal str");
    s1 = "123\tasd\n";
    s2 = "123\tasd\n";
    if (strcmp(s1, s2) != ft_strcmp(s1, s2))
        printf("equal str");
    printf("SUCCESS: ft_strcmp\n");
}

void test_ft_strcpy(void)
{
    char dest1[30];
    char dest2[30];
    char *src0;

    src0 = "";
    printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0),
           strcpy(dest2, src0));
    if (strcmp(dest1, dest2) != 0)
        printf("zero str");
    src0 = "123456789";
    printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0),
           strcpy(dest2, src0));
    if (strcmp(dest1, dest2) != 0)
        printf("123456789");
    src0 = "abc";
    printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0),
           strcpy(dest2, src0));
    if (strcmp(dest1, dest2) != 0)
        printf("abc");

    src0 = "qwertyuiop[dsdfghjklmnbvcx";
    printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0),
           strcpy(dest2, src0));
    if (strcmp(dest1, dest2) != 0)
        printf("long str");
    printf("SUCCESS: ft_strcpy\n");
}

void test_ft_strdup(void)
{
    char *src0;
    char *sys;
    char *ft;

    src0 = "";
    printf("ft_strdup: |%s|\n   strdup: |%s|\n", (ft = ft_strdup(src0)),
           (sys = strdup(src0)));
    if (strcmp(sys, ft) != 0)
        printf("zero str");
    free(sys);
    free(ft);

    src0 = "123456789";
    printf("ft_strdup: |%s|\n   strdup: |%s|\n", (ft = ft_strdup(src0)),
           (sys = strdup(src0)));
    if (strcmp(sys, ft) != 0)
        printf("123456789");
    free(sys);
    free(ft);

    src0 = "qwertyuiopasdfghjklzxcvbnm";
    printf("ft_strdup: |%s|\n   strdup: |%s|\n", (ft = ft_strdup(src0)),
           (sys = strdup(src0)));
    if (strcmp(sys, ft) != 0)
        printf("long str");
    free(sys);
    free(ft);
    printf("SUCCESS: ft_strdup\n");
}

int main()
{
    test_ft_strcmp();
    test_ft_strcpy();
    test_ft_strdup();
    test_ft_strlen();
    test_ft_read();
    test_ft_write();
    return 0;
}
