// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <stdlib.h>
#include <string.h>
#include "file_handling/src/file_handling.h"

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
  // 获取文件大小，用于确定存放文件内容变量所需申请的空间大小
  int file_size = GetFileSize(toml_file);
  // 定义字符串指针并分配空间，用于存放文件内容。
  char * contents = NULL;
  contents = (char *)malloc(file_size * sizeof(char));
  if (contents == NULL){
    printf("-- 内存分配失败！\n\n");
    return -1;
  }
  // 获取文件的所有内容
  if (GetWholeFile(toml_file, contents) == -1) {
    free(contents);
    return -1;
  }
  printf("-------------- 文件内容 --------------\n");
  printf("%s\n", contents);
  printf("-------------------------------------\n\n");
  // 解析
  // TOMLParser(content);
  free(contents);
  return 0;
}