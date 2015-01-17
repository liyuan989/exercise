#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char* buf = getenv("QUERY_STRING");
	if (buf == NULL)
	{
		exit(0);
	}
	std::string buffer(buf);
	int position = buffer.find('&');
	std::string::iterator iter = buffer.begin() + position;
	std::string param1(buffer.begin(), iter);
	std::string param2(iter + 1, buffer.end());
	int nparam1 = atoi(param1.c_str());
	int nparam2 = atoi(param2.c_str());

	std::vector<char> content(1024*64);
	sprintf(&content[0], "Welcome to add.com: ");
	sprintf(&content[0], "%sTHE Internet addition portal.\r\n<p>", &content[0]);
	sprintf(&content[0], "%sThe answer is: %d + %d = %d \r\n<p>", &content[0], nparam1, nparam2, nparam1 + nparam2);
	sprintf(&content[0], "%sThanks for visiting!\r\n", &content[0]);

	printf("Content-length: %d\r\n", strlen(&content[0]));
	printf("Content-type: text/html\r\n\r\n");
	printf("%s\n", &content[0]);
	fflush(stdout);
	return 0;
}
