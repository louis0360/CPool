int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned int res;
	res=(red<<16)|(green<<8)|blue;
	return res;
}
