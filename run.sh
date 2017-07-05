rm fdf
gcc -o fdf src/drawslopes.c src/fdf.c src/cord_plane.c src/drawlines.c libft/megalibft.a  minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -g
