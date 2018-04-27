all: hazirla calistir

hazirla:
	gcc -I ./include/ -o ./lib/siparis -c ./src/siparis.c -I./libfdr
	gcc -I ./include/ -o ./bin/main ./lib/siparis ./src/main.c -I./libfdr -L./libfdr -lfdr 
calistir:
	./bin/main
