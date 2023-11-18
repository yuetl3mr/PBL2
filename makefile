#LMS config

all: compile run

compile:
	g++ Book.cpp Loan.cpp Reader.cpp LMS.cpp Main.cpp -o main.exe
clean:
	erase -f main *.o
run:
	.\main.exe

