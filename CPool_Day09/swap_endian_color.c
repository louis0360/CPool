union u_color {
	unsigned int color;
	char rgb[4];
};

int swap_endian_color(int color)
{
	union u_color uc;
	uc.rgb[0] = 0;
	uc.rgb[1] = 0;
	uc.rgb[2] = 0;
	uc.rgb[3] = 0;
	uc.rgb[3] += color & 0xFF;
	color = color >> 8;
	uc.rgb[2] += color & 0xFF;
	color = color >> 8;
	uc.rgb[1] += color & 0xFF;
	color = color >> 8;
	uc.rgb[0] = color & 0xff;
	return(uc.color);
}
