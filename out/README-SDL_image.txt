
SDL_image 1.1

The latest version of this library is available from:
http://www.devolution.com/~slouken/SDL/projects/SDL_image/

This is a simple library to load images of various formats as SDL surfaces.
This library supports BMP, PNM (PPM/PGM/PBM), XPM, PCX, GIF, JPEG, PNG,
TGA, and TIFF formats.

API:
#include "SDL_image.h"

	SDL_Surface *IMG_Load(const char *file);
or
	SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc);
or
	SDL_Surface *IMG_LoadTyped_RW(SDL_RWops *src, int freesrc, char *type);

where type is a string specifying the format (i.e. "PNG" or "pcx").
Note that IMG_Load_RW cannot load TGA images.

An example program 'showimage' is included, with source in showimage.c

JPEG support requires the JPEG library: http://www.ijg.org/
PNG support requires the PNG library: http://www.cdrom.com/pub/png/
    and the Zlib library: http://www.cdrom.com/pub/infozip/zlib/
TIFF support requires the TIFF library: ftp://ftp.sgi.com/graphics/tiff/

This library is under the GNU Library General Public License, see the file
"COPYING" for details.  Certain image loaders may be under a different
license, see the individual image loader source files for details.
