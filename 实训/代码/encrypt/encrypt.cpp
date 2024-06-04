#include <stdio.h>
#include <errno.h>
#include <string.h>

void encryptFile(FILE *inputFile, FILE *outputFile,char key) {
	int ch;
	while (ch = fgetc(inputFile)!= EOF) {
		// 对每个字节进行1异或
		fputc(ch ^ key, outputFile);
	}
}

int main() {
	char inputFile[] = "test.txt";   // 输入文件名
	char outputFile[] = "encrypt.txt"; // 输出文件名
	const char key='k';
	FILE *input = fopen(inputFile, "r");
	FILE *output = fopen(outputFile, "w");

	if (input == NULL || output == NULL) {
		printf("%s\n", strerror(errno));
		return 1;
	}

	encryptFile(input, output,key);

	fclose(input);
	fclose(output);

	printf("文件加密完成。\n");
	
	return 0;
}

