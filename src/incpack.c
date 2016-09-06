// incpack utility
// Takes a file
// Dumps an equivalent C array to a .inc file.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHUNK 1024

int main(int argc, char *argv[])
{
	unsigned char in[CHUNK];

	puts("incdump");

	const char *file = "Wave100.dat";
	if (argc > 1)
		file = argv[1];

	FILE *source = fopen(file, "rb");
	if (!source)
	{
		printf("File '%s' not found.", file);
		return EXIT_FAILURE;
	}

	char asset_name[64];
	{
		const char *fp = file + strlen(file);
		while (--fp > file && *fp != '/' && *fp != '\\');
		if (*fp == '/' || *fp == '\\') ++fp;
		strncpy(asset_name, fp, 63);
		asset_name[63] = '\0';
		char *ap = asset_name;
		while (*ap++) { if (*ap == '.') *ap = '\0'; }
		strcpy(&asset_name[strlen(asset_name)], ".inc");
	}

	printf("Compressing '%s' to '%s'\n", file, asset_name);

	FILE *dest = fopen(asset_name, "w");
	asset_name[strlen(asset_name)-4]='\0';
	fprintf(dest, "static const unsigned char %s[] = {", asset_name);

	unsigned len = 0;
	do {
		len = fread(in, 1, CHUNK, source);
		for (unsigned i = 0; i < len; i++)
		{
			if (i%16 == 0)
				fprintf(dest,"\n\t");
			fprintf(dest,"0x%02X,",in[i]);
		}
	} while (len > 0);
	fclose(source);
	fputs("};", dest);
	fclose(dest);

	puts("Done!");
	return EXIT_SUCCESS;
}
