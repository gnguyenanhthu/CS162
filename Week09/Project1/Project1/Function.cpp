#include "header.h"

bool isBmpFile(FILE *f)
{
	if (f == NULL) return false;

	BmpSignature signature;
	fseek(f, 0, 0L);
	fread(&signature, sizeof(BmpSignature), 1, f);
	return signature.data[0] == 'B' && signature.data[1] == 'M';
}
void readBmpHeader(FILE *f, BmpHeader &header)
{
	if (f == NULL) return;
	fseek(f, 0, 0L);
	fread(&header, sizeof(BmpHeader), 1, f);
}
void printBmpHeader(BmpHeader header)
{
	cout << "*** BMP Header ***" << endl;
	cout << "- File Size  : " << header.fileSize << " byte(s) " << endl;
	cout << "- Reserved1  : " << header.reserved1 << endl;
	cout << "- Reserved2  : " << header.reserved2 << endl;
	cout << "- Data Offset: " << header.dataOffset << " byte(s) " << endl;
}
void readBmpDib(FILE *f, BmpDib &dib)
{
	if (f == NULL) return;
	fseek(f, sizeof(BmpHeader), 0L);
	fread(&dib, sizeof(BmpDib), 1, f);
}
void printBmpDib(BmpDib dib)
{
	cout << "*** BMP Dib ***" << endl;
	cout << "- DIB Size                   : " << dib.dibSize <<" byte(s) "<< endl;
	cout << "- Image Width                : " << dib.imageWidth << endl;
	cout << "- Image Height               : " << dib.imageHeight << endl;
	cout << "- Number of Color Planes     : " << dib.colorPlaneCount << endl;
	cout << "- Pixel Size                 : " << dib.pixelSize << " bit(s) " << endl;
	cout << "- Compress Method            : " << dib.compressMethod << endl;
	cout << "- Bitmap Size                : " << dib.bitmapByteCount << " byte(s) " << endl;
	cout << "- Horizontal Resolution      : " << dib.horizontalResolution << endl;
	cout << "- Vertical Resolution        : " << dib.verticalResolution <<endl;
	cout << "- Number of Colors           : " << dib.colorCount << endl;
	cout << "- Number of Important Colors : " << dib.importantColorCount << endl;
}
void readBmpPixelArray(FILE *f, BmpHeader header, BmpDib dib, PixelArray &data)
{
	if (f == NULL) return;
	data.rowCount = dib.imageHeight;
	data.columnCount = dib.imageWidth;
	data.pixels = new Color*[data.rowCount];
	char paddingCount = (4 - (dib.imageWidth * (dib.pixelSize / 8) % 4)) % 4;
	fseek(f, header.dataOffset, 0L);
	for (int i = 0; i < data.rowCount; i++)
	{
		scanBmpPixelLine(f, data.pixels[data.rowCount - 1 - i], dib.imageWidth);
		skipBmpPadding(f, paddingCount);
	}
}
void scanBmpPixelLine(FILE *f, Color *&line, uint32_t length)
{
	if (f == NULL) return;
	line = new Color[length];
	fread(line, sizeof(Color), length, f);
}
void skipBmpPadding(FILE *f, char count)
{
	if (f == NULL) return;
	if (count == 0) return;
	char padding[3];
	fread(padding, count, 1, f);
}
void releaseBmpPixelArray(PixelArray data)
{
	for (int i = 0; i < data.rowCount; i++)
		delete[]data.pixels[i];
	delete[]data.pixels;
}
