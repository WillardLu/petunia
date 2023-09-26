// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <stdio.h>
#include <string.h>

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
  FILE * f = fopen(toml_file, "r");
  if (f == NULL) {
    printf("-- TOML配置文件打开失败！\n\n");
    return 1;
  }
  fclose(f);
  return 0;
}