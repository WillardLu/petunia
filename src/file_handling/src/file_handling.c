// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "file_handling.h"

/// @brief 获取文件大小
/// @param file_name 带路径的文件名称
/// @return 成功：文件大小，失败：-1
int GetFileSize(const char *file_name) {
  FILE * fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("-- 文件 %s 打开失败！\n\n", file_name);
    return -1;
  }
  // 设置文件指针至末尾
  fseek(fp, 0L, SEEK_END);
  // 通过文件指针的当前位置计算出文件大小
  int res = ftell(fp);
  fclose(fp);
  return res;
}

/// @brief 获取文件的所有内容
/// @param file_name 带路径的文件名称
/// @param buffer 存放文件内容的指针
/// @return 成功：0，失败：-1
int GetWholeFile(const char *file_name, char *buffer) {
  int file_size = GetFileSize(file_name);
  if (file_size == -1) {
    return -1;
  }
  FILE * fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("-- 文件 %s 打开失败！\n\n", file_name);
    return -1;
  }
  fseek(fp, 0L, SEEK_SET);
  fread(buffer, sizeof(char), file_size, fp);
  fclose(fp);
  return 0;
}