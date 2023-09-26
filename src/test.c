// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "toml_parser/src/toml_parser.h"

int main(int argc, char *argv[]) {
  printf("-- 读入TOML配置文件；\n\n");
  char * file = argv[1];
  char toml_file[100] = {0};
  // 如果用户未指定具体的配置文件，就默认读取当前目录下的config.toml文件。
  if (file == NULL) {
    strcat(toml_file, "config.toml");
  } else {
    strcat(toml_file, file);
  }
  FILE * fp = fopen(toml_file, "r");
  if (fp == NULL) {
    printf("-- TOML配置文件打开失败！\n\n");
    return 1;
  }
  // 设置文件指针至末尾
  fseek(fp, 0L, SEEK_END);
  // 通过文件指针的当前位置计算出文件大小
  int res = ftell(fp);
  printf("size of file: %d\n", res);
  // 定义字符串指针并分配空间，用于存放文件内容。
  char * content = NULL;
  content = (char *)malloc(res * sizeof(char));
  if (content == NULL){
    printf("-- 内存分配失败！\n\n");
    fclose(fp);
    return 1;
  }
  // 把文件指针调回文件开头，否则后面什么内容都读不到。
  fseek(fp, 0L, SEEK_SET);
  fread(content, sizeof(char), res, fp);
  fclose(fp);
  printf("-------------- 文件内容 --------------\n");
  printf("%s\n", content);
  printf("-------------------------------------\n\n");
  // 解析
  // TOMLParser(content);
  free(content);
  return 0;
}