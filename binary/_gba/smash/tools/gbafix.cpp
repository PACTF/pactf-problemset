//////////////////////////////////////////////////////////////////////////////
// gbafix.cpp                                                               //
//////////////////////////////////////////////////////////////////////////////
/*
	Gameboy Advance ROM fixer (by Dark Fader / BlackThunder)
	Validates header of GBA roms.

	History
	-------
	v1.03 - header.fixed, header.device_type
	v1.02 - redefined the options (rgbfix style), checksum=0
	v1.01 - fix in parameters
	v1.00 - logo, complement
*/

//////////////////////////////////////////////////////////////////////////////
// Pragmas                                                                  //
//////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

//////////////////////////////////////////////////////////////////////////////
// Includes                                                                 //
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////////
// Defines                                                                  //
//////////////////////////////////////////////////////////////////////////////
#define VER		"1.03"
#define ARGV	argv[arg]
#define VALUE	(ARGV+2)
#define NUMBER	strtoul(VALUE, NULL, 0)

//////////////////////////////////////////////////////////////////////////////
// Typedefs                                                                 //
//////////////////////////////////////////////////////////////////////////////
typedef struct
{
	unsigned long	start_code;		// B instruction
	unsigned char	logo[0xA0-0x04];	// logo data
	char			title[0xC];		// game title name
	unsigned long	game_code;		//
	unsigned short	maker_code;		//
	unsigned char	fixed;			// 0x96
	unsigned char	unit_code;		// 0x00
	unsigned char	device_type;	// 0x80
	unsigned char	unused[7];		//
	unsigned char	game_version;	// 0x00
	unsigned char	complement;		// 800000A0..800000BC
	unsigned short	checksum;		// 0x0000
} Header;

//////////////////////////////////////////////////////////////////////////////
// Variables                                                                //
//////////////////////////////////////////////////////////////////////////////
Header header;
unsigned short checksum_without_header = 0;

const Header good_header =
{
	// start_code
	0xEA00002E,
	// logo
	0x24,0xFF,0xAE,0x51,0x69,0x9A,0xA2,0x21,0x3D,0x84,0x82,0x0A,0x84,0xE4,0x09,0xAD,
	0x11,0x24,0x8B,0x98,0xC0,0x81,0x7F,0x21,0xA3,0x52,0xBE,0x19,0x93,0x09,0xCE,0x20,
	0x10,0x46,0x4A,0x4A,0xF8,0x27,0x31,0xEC,0x58,0xC7,0xE8,0x33,0x82,0xE3,0xCE,0xBF,
	0x85,0xF4,0xDF,0x94,0xCE,0x4B,0x09,0xC1,0x94,0x56,0x8A,0xC0,0x13,0x72,0xA7,0xFC,
	0x9F,0x84,0x4D,0x73,0xA3,0xCA,0x9A,0x61,0x58,0x97,0xA3,0x27,0xFC,0x03,0x98,0x76,
	0x23,0x1D,0xC7,0x61,0x03,0x04,0xAE,0x56,0xBF,0x38,0x84,0x00,0x40,0xA7,0x0E,0xFD,
	0xFF,0x52,0xFE,0x03,0x6F,0x95,0x30,0xF1,0x97,0xFB,0xC0,0x85,0x60,0xD6,0x80,0x25,
	0xA9,0x63,0xBE,0x03,0x01,0x4E,0x38,0xE2,0xF9,0xA2,0x34,0xFF,0xBB,0x3E,0x03,0x44,
	0x78,0x00,0x90,0xCB,0x88,0x11,0x3A,0x94,0x65,0xC0,0x7C,0x63,0x87,0xF0,0x3C,0xAF,
	0xD6,0x25,0xE4,0x8B,0x38,0x0A,0xAC,0x72,0x21,0xD4,0xF8,0x07,
	// title
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	// game code
	0x00000000,
	// maker code
	0x3130,
	// fixed
	0x96,
	// unit_code
	0x00,
	// device type
	0x80,
	// unused
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	// game version
	0x00,
	// complement
	0x00,
	// checksum
	0x0000,
};

//////////////////////////////////////////////////////////////////////////////
// HeaderComplement                                                         //
//////////////////////////////////////////////////////////////////////////////
char HeaderComplement()
{
	char c = 0;
	char *p = (char *)&header + 0xA0;
	for (int n=0; n<0xBD-0xA0; n++)
	{
		c += *p++;
	}
	return -(0x19+c);
}

//////////////////////////////////////////////////////////////////////////////
// HeaderChecksum                                                           //
//////////////////////////////////////////////////////////////////////////////
/*unsigned short HeaderChecksum()
{
	unsigned short c = 0;
	unsigned char *p = (unsigned char *)&header;
	for (int n=0; n<sizeof(header); n++)
	{
		c += *p++;
	}
	return -c;
}*/

//////////////////////////////////////////////////////////////////////////////
// main                                                                     //
//////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	// show syntax
	if (argc <= 1)
	{
		printf("GBA ROM fixer v"VER" by Dark Fader / BlackThunder\n");
		printf("Syntax: gbafix <rom.gba> [-p] [-s<start>] [-t[title]] [-g<game_code>] [-m<maker_code>] [-v<version>]\n");
		printf("\n");
		printf("parameters:\n");
		printf("	-p              Pad to next exact power of 2. No minimum size!\n");
		printf("	-t[<title>]     Patch title. Stripped filename if none given.\n");
		printf("	-c<game_code>   Patch game code (four characters)\n");
		printf("	-m<maker_code>  Patch maker code (two characters)\n");
		printf("	-r<version>     Patch game version (number)\n");
		return -1;
	}

	// get filename
	char *argfile = 0;
	for (int arg=1; arg<argc; arg++)
	{
		if ((ARGV[0] != '-') && (ARGV[0] != '/')) { argfile=ARGV; break; }
	}

	// check filename
	if (!argfile)
	{
		printf("Filename needed!\n");
		return -1;
	}

	// read file
	FILE *f = fopen(argfile, "r+b");
	if (!f) { printf("Error opening input file!\n"); return -1; }
	fseek(f, 0, SEEK_SET);
	fread(&header, sizeof(header), 1, f);
	// get checksum without header
	/*while (1)
	{
		unsigned char c;
		if (!fread(&c, 1, 1, f)) break;
		checksum_without_header += c;
	}*/
	//fseek(f, 0, SEEK_SET);

	// parse command line
	for (arg=1; arg<argc; arg++)
	{
		if ((ARGV[0] == '-') || (ARGV[0] == '/'))
		{
			switch (ARGV[1])
			{
				case 'p':	// pad
				{
					fseek(f, 0, SEEK_END);
					int size = ftell(f);
					int bit;
					for (bit=31; bit>=0; bit--) if (size & (1<<bit)) break;
					if (size != (1<<bit))
					{
						int todo = (1<<(bit+1)) - size;
						while (todo--) fputc(0xFF, f);
					}
					fseek(f, 0, SEEK_SET);
					break;
				}

				case 't':	// title
				{
					char title[256];
					memset(title, 0, sizeof(title));
					if (VALUE[0])
					{
						strncpy(title, VALUE, sizeof(header.title));
					}
					else
					{
						// use filename
						char s[256], *begin=s, *t; strcpy(s, argfile);
						t = strrchr(s, '\\'); if (t) begin = t;
						t = strrchr(s, '/'); if (t) begin = t;
						t = strrchr(s, '.'); if (t) *t = 0;
						strncpy(title, t, sizeof(header.title));
					}
					memcpy(header.title, title, sizeof(header.title));	// copy
					break;
				}

				case 'c':	// game code
				{
					//if (!VALUE[0]) { printf("Need value for %s\n", ARGV); break; }
					//header.game_code = NUMBER;
					header.game_code = VALUE[0] | VALUE[1]<<8 | VALUE[2]<<16 | VALUE[3]<<24;
					break;
				}

				case 'm':	// maker code
				{
					//if (!VALUE[0]) { printf("Need value for %s\n", ARGV); break; }
					//header.maker_code = (unsigned short)NUMBER;
					header.maker_code = VALUE[0] | VALUE[1]<<8;
					break;
				}

				case 'v':	// ignored, compatability with other gbafix
				{
					break;
				}

				case 'r':	// version
				{
					if (!VALUE[0]) { printf("Need value for %s\n", ARGV); break; }
					header.game_version = (unsigned char)NUMBER;
					break;
				}

				default:
				{
					printf("Invalid option: %s\n", ARGV);
				}
			}
		}
	}

	// fix some more data
	memcpy(header.logo, good_header.logo, sizeof(header.logo));
	memcpy(&header.fixed, &good_header.fixed, sizeof(header.fixed));
	memcpy(&header.device_type, &good_header.device_type, sizeof(header.device_type));
		
	// update complement check & total checksum
	header.complement = 0;
	header.checksum = 0;	// must be 0
	header.complement = HeaderComplement();
	//header.checksum = checksum_without_header + HeaderChecksum();

	fseek(f, 0, SEEK_SET);
	fwrite(&header, sizeof(header), 1, f);
	fclose(f);
	
	printf("ROM fixed!\n");

	return 0;
}
