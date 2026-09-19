all:
	gcc src/ettr.c src/ettrmain.c -o ettr

clean:
	rm -f ettr ponto.bin
