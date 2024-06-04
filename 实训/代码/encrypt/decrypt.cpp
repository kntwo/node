#include <stdio.h>
#include <errno.h>
#include <string.h>

void encryptFile(FILE *inputFile, FILE *outputFile,char key) {
	int ch;
	while (ch = fgetc(inputFile) != EOF) {
		// ��ÿ���ֽڽ���1���
		fputc(ch ^ key, outputFile);
	}
}

int main() {
	char inputFile[] = "encrypt.txt";   // �����ļ���
	char outputFile[] = "decrypt.txt"; // ����ļ���
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

	printf("�ļ�������ɡ�\n");

	return 0;
}

