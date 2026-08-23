#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_whitespace(char c){
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
        
void trim_trailing_whitespace(char *str) {
    if (str == NULL) return;
    int len = strlen(str);
    while (len > 0 && is_whitespace(str[len -1]) ) {
        len--;
    }
    str[len] = '\0';
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("请输入文本（完成后按 Ctrl+D 或 Ctrl+Z 结束）：\n");

    // 逐行读取
    while ((read = getline(&line, &len, stdin)) != -1) {
        // 清理行尾空白字符（包含行尾的 \n、空格和 \t）
        trim_trailing_whitespace(line);
        
        // 输出处理后的内容（加上明确的标记方便观察尾部已被清理）
        printf("%s<LINE_END>\n", line);
    }

    free(line);
    return 0;
}