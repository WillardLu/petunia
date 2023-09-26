// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef FILE_HANDLING_SRC_FILE_HANDLING_H_
#define FILE_HANDLING_SRC_FILE_HANDLING_H_

#include <stdio.h>

int GetFileSize(const char *file_name);
int GetWholeFile(const char *file_name, char *buffer);

#endif  // FILE_HANDLING_SRC_FILE_HANDLING_H_