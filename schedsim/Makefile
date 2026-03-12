all: schedsim

schedsim: main.o fcfs.o sjf.o process.o utils.o -o schedsim
	@gcc main.o fcfs.o sjf.o process.o utils.o -o schedsim

main.o: src/main.c
	@gcc -c src/main.c

fcfs.o: src/fcfs.c
	@gcc -c src/fcfs.c

sjf.o: src/sjf.c
	@gcc -c src/sjf.c

process.o: src/process.c
	@gcc -c src/process.c

utils.o: src/utils.c
	@gcc -c src/utils.c

run: all
@./schedsim --algorithm= --processes="A:0:240,B:10:180,C:20:150"

runFCFS: all
	@./schedsim --algorithm=FCFS --processes="A:0:240,B:10:180,C:20:150"

runSJF: all
	@./schedsim --algorithm=SJF --processes="A:0:240,B:10:180,C:20:150"

# runTest: all
# 	@./lab1 tester.txt

clean:
	@echo "removed object and program files"
	@rm -f *.o schedsim