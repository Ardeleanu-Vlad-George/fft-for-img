TARGET := fft

OBJECT := obj/main.o obj/io.o obj/cpx_op.o obj/fft_comp.o
OBJECT += obj/fft_prep_bit.o obj/fft_prep_cpx.o obj/btr_fly.o

$(TARGET): $(OBJECT)
	g++ -o $@ $^ -lm

$(OBJECT): obj/%.o: src/%.cpp
	g++ -std=c++98 -I inc/ -c -o $@ $^

clean:
	rm $(OBJECT) $(TARGET)
