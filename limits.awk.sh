#!/usr/bin/awk -f
BEGIN {
  printf("#include \"apue.h\"\n")
  printf("#include <errno.h>\n")
  printf("#include <limits.h>\n")
  printf "\n"
  printf "static void pr_sysconf(char *, int);\n"
  printf "static void pr_pathconf(char *, char *, int);\n"
  printf "\n"
  printf "int main(int argc, char *argv[]){\n"

  printf "\n"
  printf ""
}