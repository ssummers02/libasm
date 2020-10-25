#include "libasm.h"

void test_ft_strlen(void)
{
    if ((ft_strlen("")) != strlen(""))
        printf("zero str");
    printf("len = %ld\n", (ft_strlen("")));
    if ((ft_strlen("\0")) != strlen("\0"))
        printf("zero str");
    printf("len = %ld\n", (ft_strlen("\0")));
    if ((ft_strlen("\0\0")) != strlen("\0\0"))
        printf("zero str");
    printf("len = %ld\n", (ft_strlen("\0\0")));
    if ((ft_strlen("123")) != strlen("123"))
        printf("str 123");
    printf("len = %ld\n", (ft_strlen("123")));
    if ((ft_strlen("abc")) != strlen("abc"))
        printf("str abc");
    printf("len = %ld\n", (ft_strlen("abc")));
    if ((ft_strlen("123456789098765432123456789098765432")) !=
        strlen("123456789098765432123456789098765432"))
        printf("long str");
    printf("len = %ld\n", (ft_strlen("123456789098765432123456789098765432")));
    printf("SUCCESS: ft_strlen\n");

}

void test_ft_read(void)
{
    int fd;
    int ret[2];
    char buf[30];

    errno = 0;
    fd = open("main.c", O_RDONLY);
    bzero(buf, sizeof(buf));
    ret[0] = read(fd, buf, 20);
    buf[20] = '\0';
    printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[0], buf,
           errno);
    close(fd);

    errno = 0;
    fd = open("main.c", O_RDONLY);
    bzero(buf, sizeof(buf));
    ret[1] = ft_read(fd, buf, 20);
    buf[20] = '\0';
    printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[1], buf,
           errno);
    close(fd);
    if (ret[0] != ret[1])
        printf("normal read");

    errno = 0;
    fd = open("-1", O_RDONLY);
    bzero(buf, sizeof(buf));
    ret[0] = read(fd, buf, 20);
    buf[20] = '\0';
    printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[0], buf,
           errno);

    errno = 0;
    fd = open("-1", O_RDONLY);
    bzero(buf, sizeof(buf));
    ret[1] = ft_read(fd, buf, 20);
    buf[20] = '\0';
    printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[1], buf,
           errno);
    if (ret[0] != ret[1])
        printf("fake read");
    printf("SUCCESS: ft_read\n");
}

void test_ft_write(void)
{
    int fd;
    ssize_t ret;
    char *str = "string";

    ret = ft_write(1, str, strlen(str));
    ret += ft_write(1, &"", 1);
    ret += ft_write(1, &"\n", 1);
    ret -= write(1, str, strlen(str));
    ret -= write(1, &"", 1);
    ret -= write(1, &"\n", 1);
    if (ret != 0)
        printf("return error");

    errno = 0;
    fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
    ft_write(fd, str, strlen(str));
    write(fd, str, strlen(str));
    close(fd);
    if (errno != 0)
        printf("errno wtf");
    printf("SUCCESS: ft_write\n");
}