#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define GLU_INVALID_ENUM 100900
#define GLU_OUT_OF_MEMORY 100902

#define FIXED(x)	((int)((x) * 65536))
#define INT(x)		((x) / 65536)
#define FRAC(x)		((x) & 0xffff)

#define RGBA(r,g,b,a)	((((a)&0xff) << 24) | \
			 (((b)&0xff) << 16) | \
			 (((g)&0xff) <<  8) | \
			 (((r)&0xff) <<  0))

#define R(rgba)	(((rgba) & 0x000000ff) >> 0)
#define G(rgba)	(((rgba) & 0x0000ff00) >> 8)
#define B(rgba)	(((rgba) & 0x00ff0000) >>16)
#define A(rgba)	(((rgba) & 0xff000000) >>24)

#define GLfloat float
#define GLubyte unsigned char
#define GLushort unsigned short

#define GL_RED 0x1903

struct format;
typedef unsigned pix_t;

typedef void (*unpack_t)(const struct format *fmt, const void *src, pix_t *dst, int count);
typedef void (*pack_t)(const struct format *fmt, const pix_t *src, void *dst, int count);

struct format {
	GLenum format;
	GLenum type;

	GLubyte channels;
	GLubyte size;

	unpack_t unpack;
	pack_t pack;
};

static void unpack_8888(const struct format *fmt, const void *src, pix_t *dst,
			int count)
{
	memcpy(dst, src, count*fmt->size);
}

static void pack_8888(const struct format *fmt, const pix_t *src, void *dst,
		      int count)
{
	memcpy(dst, src, count*fmt->size);
}

static void unpack_888(const struct format *fmt, const void *src, pix_t *dst,
		       int count)
{
	const GLubyte *srcp = (GLubyte*)src;

	while(count--) {
		*dst++ = RGBA(srcp[0], srcp[1], srcp[2], 255);
		srcp += 3;
	}
}

static void pack_888(const struct format *fmt, const pix_t *src, void *dst, int count)
{
	GLubyte *dstp = (GLubyte*)dst;

	while(count--) {
		pix_t p = *src++;
		dstp[0] = R(p);
		dstp[1] = G(p);
		dstp[2] = B(p);
		dstp += 3;
	}
}

static void unpack_5551(const struct format *fmt, const void *src, pix_t *dst,
			int count)
{
	const GLushort *srcp = (GLushort*)src;
	pix_t alpha = 0;
	if (fmt->channels == 3)
		alpha = RGBA(0,0,0,0xff);

	while(count--) {
		GLushort p = *srcp++;
		pix_t a = (p & 0x0001) >>  0;
		pix_t r = (p & 0xf800) >> 11;
		pix_t g = (p & 0x07c0) >>  6;
		pix_t b = (p & 0x0036) >>  1;

		*dst++ = RGBA(r * 255 / 31,
			      g * 255 / 31,
			      b * 255 / 31,
			      a * 255 / 1) | alpha;
	}
}

static void pack_5551(const struct format *fmt, const pix_t *src, void *dst,
		      int count)
{
	GLushort *dstp = (GLushort*)dst;

	while(count--) {
		pix_t p = *src++;

		*dstp++=(((R(p) * 31 / 255) << 11) & 0xf800) |
			(((G(p) * 31 / 255) <<  6) & 0x07c0) |
			(((B(p) * 31 / 255) <<  1) & 0x0036) |
			(((A(p) *  1 / 255) <<  0) & 0x0001);
	}
}

static void unpack_1555(const struct format *fmt, const void *src, pix_t *dst,
			int count)
{
	const GLushort *srcp = (GLushort*)src;
	pix_t alpha = 0;
	if (fmt->channels == 3)
		alpha = RGBA(0,0,0,0xff);

	while(count--) {
		GLushort p = *srcp++;
		pix_t a = (p & 0x8000) >> 15;
		pix_t r = (p & 0x001f) >>  0;
		pix_t g = (p & 0x03e0) >>  5;
		pix_t b = (p & 0x7c00) >> 10;

		*dst++ = RGBA(r * 255 / 31,
			      g * 255 / 31,
			      b * 255 / 31,
			      a * 255 / 1) | alpha;
	}
}

static void pack_1555(const struct format *fmt, const pix_t *src, void *dst,
		      int count)
{
	GLushort *dstp = (GLushort*)dst;

	while(count--) {
		pix_t p = *src++;

		*dstp++=(((R(p) * 31 / 255) <<  0) & 0x001f) |
			(((G(p) * 31 / 255) <<  5) & 0x03e0) |
			(((B(p) * 31 / 255) << 10) & 0x7c00) |
			(((A(p) *  1 / 255) << 15) & 0x8000);
	}
}

static void unpack_565(const struct format *fmt, const void *src, pix_t *dst,
		       int count)
{
	const GLushort *srcp = (GLushort*)src;

	while(count--) {
		GLushort p = *srcp++;
		pix_t r = (p & 0xf800) >> 11;
		pix_t g = (p & 0x07e0) >> 5;
		pix_t b = (p & 0x001f) >> 0;

		*dst++ = RGBA(r * 255 / 31,
			      g * 255 / 63,
			      b * 255 / 31,
			      255);
	}
}

static void pack_565(const struct format *fmt, const pix_t *src, void *dst,
		       int count)
{
	GLushort *dstp = (GLushort*)dst;

	while(count--) {
		pix_t p = *src++;

		*dstp++=(((R(p) * 31 / 255) << 11) & 0xf800) |
			(((G(p) * 63 / 255) <<  5) & 0x07e0) |
			(((B(p) * 31 / 255) <<  0) & 0x001f);
	}
}

static void unpack_4444(const struct format *fmt, const void *src, pix_t *dst,
			int count)
{
	const GLushort *srcp = (GLushort*)src;
	pix_t alpha = 0;
	if (fmt->channels == 3)
		alpha = RGBA(0,0,0,255);

	while(count--) {
		GLushort p = *srcp++;
		pix_t a = (p & 0xf000) >> 12;
		pix_t r = (p & 0x000f) >>  0;
		pix_t g = (p & 0x00f0) >>  4;
		pix_t b = (p & 0x0f00) >>  8;

		*dst++ = RGBA(r * 255 / 15,
			      g * 255 / 15,
			      b * 255 / 15,
			      a * 255 / 15) | alpha;
	}
}

static void pack_4444(const struct format *fmt, const pix_t *src, void *dst,
		      int count)
{
	GLushort *dstp = (GLushort*)dst;

	while(count--) {
		pix_t p = *src++;

		*dstp++=(((R(p) * 15 / 255) <<  0) & 0x000f) |
			(((G(p) * 15 / 255) <<  4) & 0x00f0) |
			(((B(p) * 15 / 255) <<  8) & 0x0f00) |
			(((A(p) * 15 / 255) << 12) & 0xf000);
	}
}

static void unpack_R32(const struct format *fmt, const void *src, pix_t *dst,
		     int count)
{
	const GLfloat *srcp = (GLfloat*)src;

	while(count--)
		*(dst+=4) = *srcp++; // TODO: not yet correct, maybe not possible to process float data here
}

static void pack_R32(const struct format *fmt, const pix_t *src, void *dst,
		   int count)
{
	GLfloat *dstp = (GLfloat*)dst;

	while(count--)
		*dstp++ = *(src+=4); // TODO: not yet correct, maybe not possible to process float data here
}

static void unpack_R(const struct format *fmt, const void *src, pix_t *dst,
		     int count)
{
	const GLubyte *srcp = (GLubyte*)src;

	while(count--)
		*dst++ = RGBA(*srcp++,0,0,255);
}

static void pack_R(const struct format *fmt, const pix_t *src, void *dst,
		   int count)
{
	GLubyte *dstp = (GLubyte*)dst;

	while(count--)
		*dstp++ = R(*src++);
}

static void unpack_A(const struct format *fmt, const void *src, pix_t *dst,
		     int count)
{
	const GLubyte *srcp = (GLubyte*)src;

	while(count--)
		*dst++ = RGBA(0,0,0,*srcp++);
}

static void pack_A(const struct format *fmt, const pix_t *src, void *dst,
		   int count)
{
	GLubyte *dstp = (GLubyte*)dst;

	while(count--)
		*dstp++ = A(*src++);
}

static void unpack_L(const struct format *fmt, const void *src, pix_t *dst, int count) {
	const GLubyte *srcp = (GLubyte*)src;
	while(count--) {
		GLubyte p = *srcp++;
		*dst++ = RGBA(p,p,p,255);
	}
}

static void pack_L(const struct format *fmt, const pix_t *src, void *dst, int count) {
	GLubyte *dstp = (GLubyte*)dst;
	while(count--) *dstp++ = R(*src++);
}

static void unpack_LA(const struct format *fmt, const void *src, pix_t *dst, int count) {
	const GLubyte *srcp = (GLubyte*)src;
	while(count--) {
		GLubyte l = *srcp++;
		GLubyte a = *srcp++;
		*dst++ = RGBA(l,l,l,a);
	}
}

static void pack_LA(const struct format *fmt, const pix_t *src, void *dst, int count) {
	GLubyte *dstp = (GLubyte*)dst;
	while(count--) {
		pix_t p = *src++;
		*dstp++ = R(p);
		*dstp++ = A(p);
	}
}

const static struct format formats[] = {
	{ GL_RGBA, GL_UNSIGNED_BYTE,			4, 4, unpack_8888, pack_8888 },
	{ GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1,		4, 2, unpack_5551, pack_5551 },
	{ GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4,		4, 2, unpack_4444, pack_4444 },
	{ GL_RGBA, GL_UNSIGNED_SHORT_1_5_5_5_REV,	4, 2, unpack_1555, pack_1555 },
	{ GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4_REV,	4, 2, unpack_4444, pack_4444 },
//	{ GL_ABGR_EXT, GL_UNSIGNED_SHORT_4_4_4_4,	4, 2, unpack_4444, pack_4444 },

	{ GL_RGB,  GL_UNSIGNED_BYTE,			3, 3, unpack_888, pack_888 },
	{ GL_RGB,  GL_UNSIGNED_SHORT_5_6_5,		3, 2, unpack_565, pack_565 },
	{ GL_RGB,  GL_UNSIGNED_SHORT_5_6_5_REV,		3, 2, unpack_565, pack_565 },
	{ GL_RGB,  GL_UNSIGNED_SHORT_5_5_5_1,		3, 2, unpack_5551, pack_5551 },
	{ GL_RGB , GL_UNSIGNED_SHORT_1_5_5_5_REV,	3, 2, unpack_1555, pack_1555 },
	{ GL_RGB,  GL_UNSIGNED_SHORT_4_4_4_4,		3, 2, unpack_4444, pack_4444 },
	{ GL_RGB,  GL_UNSIGNED_SHORT_4_4_4_4_REV,	3, 2, unpack_4444, pack_4444 },

	{ GL_LUMINANCE,		GL_UNSIGNED_BYTE,	1, 1, unpack_L,  pack_L },
	{ GL_LUMINANCE_ALPHA,	GL_UNSIGNED_BYTE,	1, 1, unpack_LA, pack_LA },
	{ GL_ALPHA,		GL_UNSIGNED_BYTE,	1, 1, unpack_A,  pack_A },
	{ GL_RED,		GL_UNSIGNED_BYTE,	1, 1, unpack_R,  pack_R },

	{ GL_RED,		GL_FLOAT,	        1, 4, unpack_R32, pack_R32 },

	{0,0}
};

const struct format *__pspglu_getformat(GLenum format, GLenum type)
{
	const struct format *ret;

	for(ret = formats; ret->format != 0; ret++) {
		if (ret->format == format && ret->type == type)
			return ret;
        }

	return NULL;
}

/* weight is a 1.16 fixed-point fraction */
static inline pix_t lerp(pix_t a, pix_t b, unsigned weight)
{
	unsigned omw = FIXED(1) - weight;

	return RGBA(INT(R(a) * omw + R(b) * weight),
		    INT(G(a) * omw + G(b) * weight),
		    INT(B(a) * omw + B(b) * weight),
		    INT(A(a) * omw + A(b) * weight));
}

static void rescale_horiz_up(const pix_t *image, pix_t *ret,
			     GLsizei src_width, GLsizei dst_width, GLsizei height)
{
	unsigned scale = FIXED(src_width) / dst_width;
	unsigned y;

	if (0)
		printf("\nscale %dx%d -> %dx%d, scale=%g 1/scale=%g\n",
		       src_width, height, dst_width, height,
		       scale / 65536., 65536. / scale);

	for(y = 0; y < height; y++, image += src_width) {
		unsigned src_x, dst_x;

		for(src_x = dst_x = 0; dst_x < dst_width; dst_x++, src_x += scale) {
			unsigned frac_src_x = FRAC(src_x);
			const pix_t *pix = &image[INT(src_x)];
			int next = 0;
			if (INT(src_x) + 1 < src_width)
				next = 1;

			*ret++ = lerp(pix[0], pix[next], frac_src_x);
		}
	}
}

static void rescale_horiz_down(const pix_t *image, pix_t *ret,
			       GLsizei src_width, GLsizei dst_width, GLsizei height)
{
	unsigned scale = FIXED(src_width) / dst_width;
	unsigned y;

	for(y = 0; y < height; y++, image += src_width) {
		unsigned src_x, dst_x;

		for(src_x = dst_x = 0; dst_x < dst_width; dst_x++, src_x += scale) {
			unsigned r,g,b,a;
			unsigned int_src_x = INT(src_x);
			int i, count;

			r=g=b=a = 0;

			count = 0;
			for(i = int_src_x; i < INT(src_x + scale + 65535); i++) {
				int c = (i >= src_width) ? src_width-1 : i;

				count++;
				r += R(image[c]);
				g += G(image[c]);
				b += B(image[c]);
				a += A(image[c]);
			}

			*ret++ = RGBA(r / count,
				      g / count,
				      b / count,
				      a / count);
		}
	}
}

static pix_t *rescale_horiz(pix_t *image,
			    GLsizei src_width, GLsizei dst_width, GLsizei height)
{
	pix_t *ret;

	if (image == NULL)
		return NULL;

	ret = (pix_t*)malloc(dst_width * height * sizeof(pix_t));

	if (ret == NULL)
		goto out;

	if (dst_width < src_width)
		rescale_horiz_down(image, ret, src_width, dst_width, height);
	else
		rescale_horiz_up(image, ret, src_width, dst_width, height);

  out:
	free(image);
	return ret;
}

static void rescale_vert_up(const pix_t *image, pix_t *ret,
			     GLsizei width, GLsizei src_height, GLsizei dst_height)
{
	unsigned scale = FIXED(src_height) / dst_height;
	unsigned src_y, dst_y;

	for(dst_y = src_y = 0; dst_y < dst_height; dst_y++, src_y += scale) {
		unsigned int_src_y = INT(src_y);
		unsigned frac_src_y = FRAC(src_y);
		unsigned x;
		const pix_t *row, *next;

		row = &image[int_src_y * width];
		next = row;
		if (int_src_y+1 < src_height)
			next = row+width;

		for(x = 0; x < width; x++)
			*ret++ = lerp(*row++, *next++, frac_src_y);
	}
}

static void rescale_vert_down(const pix_t *image, pix_t *ret,
			      GLsizei width, GLsizei src_height, GLsizei dst_height)
{
	unsigned scale = FIXED(src_height) / dst_height;
	unsigned r_scale = (FIXED(dst_height) / src_height) / 256;
	unsigned src_y, dst_y;

	if (0)
		printf("\nscale %dx%d -> %dx%d, scale=%g 1/scale=%g\n",
		       width, src_height, width, dst_height,
		       scale / 65536., 65536. / scale);

	for(dst_y = src_y = 0;
	    dst_y < dst_height;
	    dst_y++, src_y += scale) {
		int x;
		unsigned box_start = FIXED(1) - FRAC(src_y);
		unsigned box_middle = INT(src_y + scale) - INT(src_y + FIXED(1));
		unsigned box_end = FRAC(src_y + scale);

		if (0)
			printf("dst_y=%d src_y=%g - %g; box start=%g middle=%d end=%g sum=%g\n",
			       dst_y,
			       src_y / 65536., (src_y + scale) / 65536.,
			       box_start / 65536.,
			       box_middle,
			       box_end / 65536.,
			       (box_start + FIXED(box_middle) + box_end) / 65536.);

		for(x = 0; x < width; x++) {
			unsigned r,g,b,a;
			const pix_t *row;
			int i;

			r=g=b=a = 0;

			/*
			               s-----e
			   src   |----|----|----|----|----|----|
			   dst   |-----|-----|-----|-----|-----
			                   s--mm-mm--e
			   src   |--|--|--|--|--|--|--|--|--|--|
			   dst   |---------|---------|---------
			   dst = box filter over src pixels
			 */

			row = &image[(INT(src_y) * width) + x];

			if (box_start) {
				r += R(*row) * box_start;
				g += G(*row) * box_start;
				b += B(*row) * box_start;
				a += A(*row) * box_start;
				row += width;
			}

			for(i = 0; i < box_middle; i++) {
				r += FIXED(R(*row));
				g += FIXED(G(*row));
				b += FIXED(B(*row));
				a += FIXED(A(*row));
				row += width;
			}

			if (box_end) {
				r += R(*row) * box_end;
				g += G(*row) * box_end;
				b += B(*row) * box_end;
				a += A(*row) * box_end;
			}

			*ret++ = RGBA(INT((r / 256) * r_scale),
				      INT((g / 256) * r_scale),
				      INT((b / 256) * r_scale),
				      INT((a / 256) * r_scale));

		}
	}
}

static pix_t *rescale_vert(pix_t *image,
			   GLsizei width, GLsizei src_height, GLsizei dst_height)
{
	pix_t *ret;

	if (image == NULL)
		return NULL;

	ret = (pix_t*)malloc(width * dst_height * sizeof(pix_t));

	if (ret == NULL)
		goto out;

	if (dst_height < src_height)
		rescale_vert_down(image, ret, width, src_height, dst_height);
	else
		rescale_vert_up(image, ret, width, src_height, dst_height);

  out:
	free(image);
	return ret;
}


GLint gluScaleImage(GLenum format,
		    GLsizei src_width, GLsizei src_height,
		    GLenum src_type, const GLvoid *src,
		    GLsizei dst_width, GLsizei dst_height,
		    GLenum dst_type, GLvoid *dst)
{
	const struct format *srcfmt = __pspglu_getformat(format, src_type);
	const struct format *dstfmt = __pspglu_getformat(format, dst_type);
	pix_t *image;
	int i;

	if (srcfmt == NULL || dstfmt == NULL)
		return GLU_INVALID_ENUM;

	if (src_width == dst_width &&
	    src_height == dst_height &&
	    src_type == dst_type) {
		memcpy(dst, src, dst_width * dst_height * dstfmt->size);
		return 0;
	}

	image = (pix_t*)malloc(src_width * src_height * sizeof(pix_t));
	if (image == NULL)
		return GLU_OUT_OF_MEMORY;
	for(i = 0; i < src_height; i++)
		(*srcfmt->unpack)(srcfmt,
				  (char*)src + i * src_width * srcfmt->size,
				  &image[i * src_width],
				  src_width);

	if (src_width != dst_width)
		image = rescale_horiz(image, src_width, dst_width, src_height);

	if (src_height != dst_height)
		image = rescale_vert(image, dst_width, src_height, dst_height);

	if (image == NULL)
		return GL_OUT_OF_MEMORY;

	for(i = 0; i < dst_height; i++)
		(*dstfmt->pack)(dstfmt,
				&image[i * dst_width],
				(char*)dst + i * dst_width * dstfmt->size,
				dst_width);
	free(image);

	return 0;
}
