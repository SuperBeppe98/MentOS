///                MentOS, The Mentoring Operating system project
/// @file touch.c
/// @brief
/// @copyright (c) 2014-2021 This file is distributed under the MIT License.
/// See LICENSE.md for details.

#include <sys/unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("%s: missing operand.\n", argv[0]);
        printf("Try '%s --help' for more information.\n\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "--help") == 0) {
        printf(
            "Updates modification times of a given fine. If the does not"
            "exists, it creates it.\n"
        );
        printf("Usage:\n");
        printf("    touch <filename>\n");
        return 0;
    }
    int fd = open(argv[1], O_RDONLY, 0);
    if (fd < 0) {
        fd = open(argv[1], O_CREAT, 0);
        if (fd >= 0) {
            close(fd);
        }
    }
    printf("\n");
    return 0;
}
