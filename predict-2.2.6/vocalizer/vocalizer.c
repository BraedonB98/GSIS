/****************************************************************************
*                  VOCALIZER: A speech articulation program                 *
*		 Copyright John A. Magliacane, KD2BD 1999-2020              *
*  		     Modified on 05-Apr-2020 to use ALSA.                   *
*	   		  Last update: 17-May-2020                          *
*****************************************************************************
* This program is used by PREDICT to annunciate satellite coordinates       *
* using the Advanced Linux Sound Architecture (ALSA).  .wav audio files     *
* containing uncompressed "raw" PCM data are read during PREDICT execution  *
* as a background process.                                                  *
*****************************************************************************
*                                                                           *
* This program is free software; you can redistribute it and/or modify it   *
* under the terms of the GNU General Public License as published by the     *
* Free Software Foundation; either version 2 of the License or any later    *
* version.                                                                  *
*                                                                           *
* This program is distributed in the hope that it will useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or     *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License     *
* for more details.                                                         *
*                                                                           *
*****************************************************************************/

#define ALSA_PCM_NEW_HW_PARAMS_API

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alsa/asoundlib.h>
#include "vocalizer.h"

char numstr[20][10];
unsigned char buffer[65536];

unsigned long buffer2long(int indx)
{
	unsigned long byte0, byte1, byte2, byte3;

	if ((indx+3)<65536)
	{
		byte0=(unsigned long)buffer[indx];
		byte1=(unsigned long)buffer[indx+1];
		byte2=(unsigned long)buffer[indx+2];
		byte3=(unsigned long)buffer[indx+3];

		return (byte0|(byte1<<8)|(byte2<<16)|(byte3<<24));
	}
	else
		return 0L;
}

unsigned int buffer2int(int indx)
{
	unsigned int byte0, byte1;

	if ((indx+1)<65536)
	{
		byte0=(unsigned int)buffer[indx];
		byte1=(unsigned int)buffer[indx+1];

		return (byte0|(byte1<<8));
	}
	else
		return 0;
}

int wavplay(char *filename)
{
	int x, y, format, bytes, channels, rc, fd;
	unsigned long total_samples=0L, running_total=0L;
	unsigned int rate=0;
	char filenpath[255];
	snd_pcm_t *handle;
	snd_pcm_hw_params_t *params;

	strncpy(filenpath,path,254);
	strncat(filenpath,filename,254);
	strncat(filenpath,".wav",254);

	fd=open(filenpath,O_RDONLY);

	if (fd==-1)
	{
		fprintf(stderr,"*** vocalizer: Cannot open \"%s\"\n",filenpath);
		return -1;
	}

	bytes=read(fd,&buffer,65536);

	y=((buffer[0]^'R')  | (buffer[1]^'I') |
  	   (buffer[2]^'F')  | (buffer[3]^'F') |
	   (buffer[8]^'W')  | (buffer[9]^'A') |
	   (buffer[10]^'V') | (buffer[11]^'E'));

	if (y)
	{
		fprintf(stderr,"*** vocalizer: No RIFF header found!\n");
		return -1;
	}

	for (x=12, y=1; x<65535 && y; x++)
		y=((buffer[x]^'f')  | (buffer[x+1]^'m') |
		  (buffer[x+2]^'t') | (buffer[x+3]^' '));

	if (y==0)
	{
		x+=3;
		x+=4;
		format=buffer2int(x);
		x+=2;
		channels=buffer2int(x);
		x+=2;
		rate=buffer2long(x);
		x+=4;
		x+=4;
		/* int block_size=buffer2int(x); */
		buffer2int(x);
		x+=2;
		buffer2int(x);  /* bits = */
		x+=2;

		if (format!=1)
		{
			fprintf(stderr,"*** vocalizer: Not PCM Wave Format.\n");
			return -1;
		}

		for (x=0, y=1; x<65535 && y; x++)
			y=((buffer[x]^'d') | (buffer[x+1]^'a') |
			 (buffer[x+2]^'t') | (buffer[x+3]^'a'));

		if (y==0)
		{
			x+=3;
			total_samples=buffer2long(x);

			if (total_samples!=0L)
			{

				/* Open PCM device for playback. */
				rc=snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);

				/* Allocate a hardware parameters object. */
				snd_pcm_hw_params_alloca(&params);

				/* Fill it in with default values. */
				snd_pcm_hw_params_any(handle, params);

				/* Set the desired hardware parameters. */

				/* Interleaved mode */
				snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

				/* Signed 16-bit little-endian format */
				snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);

				/* Set the number of audio channels */
				snd_pcm_hw_params_set_channels(handle, params, channels);

				/* Set the sampling rate (in Hz) */
				snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0);

				/* Set the buffer size */
				snd_pcm_hw_params_set_buffer_size(handle, params, 65536);

				/* Write the parameters to the driver */
				rc=snd_pcm_hw_params(handle, params);

				if (rc<0)
			        {
       				    	fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
               				exit(1);
       				}

				lseek(fd,(long)(x+4),SEEK_SET);
				bytes=read(fd,&buffer,65536);
				running_total+=bytes;

				if (running_total>total_samples)
					bytes-=(running_total-total_samples);

				while (bytes>0)
				{
					/* write(dsp,&buffer,bytes); */
					rc=snd_pcm_writei(handle, buffer, ((bytes/2)/channels));

					bytes=read(fd,&buffer,65536);
					running_total+=bytes;

					if (running_total>total_samples)
						bytes-=(running_total-total_samples);
				}

				/* close(dsp); */
				snd_pcm_drain(handle);
				snd_pcm_close(handle);
				close(fd);
			}
		}
		else
			fprintf(stderr,"*** vocalizer: Could not find 'data' chunk.\n");
	}
	else
		fprintf(stderr,"*** vocalizer: Could not extract format from header.\n");

	return 0;
}

void saynumber(int num)
{
	char string[10];

	sprintf(string,"%4d",num);

	if (string[1]!=32)
	{
		wavplay(numstr[string[1]-'0']);
		wavplay("hundred");
	}

	switch (string[2])
	{
		case '1':
			wavplay(numstr[(10+(string[3]-'0'))]);
			break;

		case '2':	
			wavplay("twenty");
			break;

		case '3':
			wavplay("thirty");
			break;

		case '4':
			wavplay("forty");
			break;

		case '5':
			wavplay("fifty");
			break;

		case '6':
			wavplay("sixty");
			break;

		case '7':
			wavplay("seventy");
			break;

		case '8':
			wavplay("eighty");
			break;

		case '9':
			wavplay("ninety");
			break;
	}

	if (string[3]!=32 && string[3]!=0 && string[2]!='1' && string[3]!='0')
		wavplay(numstr[string[3]-'0']);

	if (string[3]=='0' && string[2]==32 && string[1]==32)
		wavplay("zero"); 
}

int main(int argc, char *argv[])
{
	int number;

	strcpy(numstr[1], "one\0");
	strcpy(numstr[2], "two\0");
	strcpy(numstr[3], "three\0");
     	strcpy(numstr[4], "four\0");
	strcpy(numstr[5], "five\0");
	strcpy(numstr[6], "six\0");
     	strcpy(numstr[7], "seven\0");
	strcpy(numstr[8], "eight\0");
	strcpy(numstr[9], "nine\0");
     	strcpy(numstr[0], "zero\0");
	strcpy(numstr[10],"ten\0");
	strcpy(numstr[11],"eleven\0");
	strcpy(numstr[12],"twelve\0");
	strcpy(numstr[13],"thirteen\0");
	strcpy(numstr[14],"fourteen\0");
	strcpy(numstr[15],"fifteen\0");
	strcpy(numstr[16],"sixteen\0");
	strcpy(numstr[17],"seventeen\0");
	strcpy(numstr[18],"eighteen\0");
	strcpy(numstr[19],"nineteen\0");

	/* Start talking! */

	if (argc==2)
	{
		if (strncmp(argv[1],"eclipse",7)==0)
		{
			wavplay("alarm");
			wavplay("eclipse");
		}

		if (strncmp(argv[1],"sunlight",8)==0)
		{
			wavplay("alarm");
			wavplay("sunlight");
		}

		if (strncmp(argv[1],"los",3)==0)
			wavplay("los");
	}

	if (argc>=3)
	{
		wavplay("intro");

		number=atoi(argv[1]);
		saynumber(number);
		wavplay("azimuth");

		number=atoi(argv[2]);
		saynumber(number);
		wavplay("elevation");

		if (argc>=4)
		{
			if (argv[3][0]=='+')
				wavplay("approaching");

			if (argv[3][0]=='-')
				wavplay("receding");
		}

		if (argc==5)
		{
			if (argv[4][0]=='V')
				wavplay("visible");
		}
	}

	return 0;
}
