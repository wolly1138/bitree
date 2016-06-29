objects = main.o bitree.o

test : $(objects)
	cc -o main $(objects)

#bitree.o : bitree.h


.PHONY : clean
clean :
	rm main $(objects)
